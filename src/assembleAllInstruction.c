#include "AssembleAllInstruction.h"
#include "unity.h"
#include "Common.h"
#include "Token.h"
#include "Error.h"
#include "Tokenizer.h"
#include "CException.h"
#include "Exception.h"
#include "operand.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
//movOpcode havent test yet
//confirm required
stm8Operand * oneOperandHandler(Tokenizer * tokenizer , uint64_t flags){
    IntegerToken* token;
    stm8Operand* operand ;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL");
    pushBackToken(tokenizer,(Token*)token);
    operand= getOperand(tokenizer ,flags);
    return operand;
}

ConversionData getDataFlag(CodeInfo *codeInfo,Tokenizer * tokenizer,stm8Operand* operand){
    int i = 0;
    IntegerToken *token;
    ConversionData  dataTable;
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    do{
      if(codeInfo->conDataTable[i].type==operand->type){
        dataTable = codeInfo->conDataTable[i];
        break;
      }
      i++;
    }while(codeInfo->conDataTable[i].codeTable != NULL);
    if(codeInfo->conDataTable[i].codeTable == NULL){
        throwException(ERR_DATATABLE_NULL,token,"expected table are null");
    }
    return dataTable;
}

void commarCheck(Tokenizer* tokenizer){
    IntegerToken *token;
    stm8Operand * operand;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_INVALID_SYNTAX,token,"Expected ,");
    if(strcmp(token->str,",")!=0){
      throwException(ERR_INVALID_SYNTAX,token,"expected ,");
    }
}

int bitOperationCheck(IntegerToken * token){
  int mul2Type;
  int mul2plus1Type;
  mul2Type = (strcasecmp(token->str,"BCPL")==0) || (strcasecmp(token->str,"BSET")==0) || (strcasecmp(token->str,"btjt")==0);
  mul2plus1Type = (strcasecmp(token->str,"BCCM")==0) || (strcasecmp(token->str,"BRES")==0) || (strcasecmp(token->str,"btjf")==0);
  if(mul2Type == 1)
    return 1;
  else if (mul2plus1Type ==1)
    return 2;
  else
    return 0;
}

int hashNValueReturn(Tokenizer* tokenizer , int cmpType){
    IntegerToken *token;
    stm8Operand * operand;
    int nvalue;
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*) token);
    operand = getOperand(tokenizer ,(1<<BYTE_OPERAND));
    if(!(operand->dataSize.ms >= 0 && operand->dataSize.ms <= 7)){
      pushBackToken(tokenizer,(Token*) token);
      token =(IntegerToken*)getToken(tokenizer);
      throwException(ERR_INVALID_NVALUE,token,"Expected eg BCCM $1000,#n , n less than equal to 7 and positive");
    }
    else if(cmpType ==2 ){
      nvalue = 1 + 2*operand->dataSize.ms;
    }
    else if (cmpType ==1){
      nvalue = 2*operand->dataSize.ms;
    }
    else{
      throwException(ERR_INVALID_INPUT,token,"invalid compare Type");
    }
    return nvalue;

}

MachineCode* outputMachineCode(stm8Operand * operand,ExtensionCodeAndCode code, int length){
    MachineCode* mcode = NULL;
    int totalLength =0;
    mcode =malloc(sizeof(MachineCode)+1+ length);
    mcode->length = length;
    if(code.extCode== 65535){
      if((operand->dataSize.ls != 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB == 65535){
        mcode->code[0] = code.code;
        mcode->code[1] = operand->dataSize.ms;
        mcode->code[2] = operand->dataSize.ls;
        totalLength=3;
      }
      else if((operand->dataSize.ls == 65535 && operand->dataSize.ms == 65535 )&& operand->dataSize.extB == 65535){
        mcode->code[0] = code.code;
        totalLength=1;
      }
      else if((operand->dataSize.ls == 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB == 65535){
        mcode->code[0] = code.code;
        mcode->code[1] = operand->dataSize.ms;
        totalLength=2;
      }
      else if((operand->dataSize.ls != 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB != 65535){
        mcode->code[0] = code.code;
        mcode->code[1] = operand->dataSize.ms;
        mcode->code[2] = operand->dataSize.ls;
        mcode->code[3] = operand->dataSize.extB;
        totalLength=4;
      }
    }
    else{
      if((operand->dataSize.ls != 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB == 65535){
        mcode->code[0] = code.extCode;
        mcode->code[1] = code.code;
        mcode->code[2] = operand->dataSize.ms;
        mcode->code[3] = operand->dataSize.ls;
        totalLength=4;
      }
      else if((operand->dataSize.ls == 65535 && operand->dataSize.ms == 65535 )&& operand->dataSize.extB == 65535){
        mcode->code[0] = code.extCode;
        mcode->code[1] = code.code;
        totalLength=2;
      }
      else if((operand->dataSize.ls == 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB == 65535){
        mcode->code[0] = code.extCode;
        mcode->code[1] = code.code;
        mcode->code[2] = operand->dataSize.ms;
        totalLength=3;
      }
      else if((operand->dataSize.ls != 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB != 65535){
        mcode->code[0] = code.extCode;
        mcode->code[1] = code.code;
        mcode->code[2] = operand->dataSize.ms;
        mcode->code[3] = operand->dataSize.ls;
        mcode->code[4] = operand->dataSize.extB;
        totalLength=5;
      }
    }
    if(totalLength != length){
      return NULL;
    }
    return mcode;
}

int machineCodeLengthFinder(stm8Operand * operand,ExtensionCodeAndCode code){
  int i=0;
    if(code.code !=65535){
      i++;
    }
    if(code.extCode !=65535){
      i++;
    }
    if(operand->dataSize.ls != 65535 ){
      i++;
    }
    if(operand->dataSize.ms != 65535 ){
      i++;
    }
    if(operand->dataSize.extB != 65535){
      i++;
    }

    return i;
}

MachineCode* machineCodeAllocateOutput(Tokenizer* tokenizer,ConversionData  dataFlag , stm8Operand *operand, int nvalue , int movMs2ndOpValue){
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    int a =0;
    IntegerToken * token;
    IntegerToken * initToken;
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*) token);
    if(dataFlag.type != NO_TABLE_OPERAND && (movMs2ndOpValue != NA && movMs2ndOpValue <= 255)){
      code = dataFlag.codeTable[operand->type];
      code.code=movMs2ndOpValue;
    }
    else if(dataFlag.type != NO_TABLE_OPERAND)
        code = dataFlag.codeTable[operand->type];
    else
      throwException(ERR_DATATABLE_NULL,token,"couldnt locate the data Table");

    if(nvalue >= 0 && nvalue <= 15){
      code.code =code.code + nvalue;
    }

    if(code.extCode ==0 && code.code ==0){
      throwException(ERR_CODE_NULL,token,"couldnt locate the ExtensionCode And Code");
    }
    else{
      a = machineCodeLengthFinder(operand,code);
      mcode =malloc(sizeof(MachineCode)+1+ a);
      mcode = outputMachineCode(operand,code,a);
      if(mcode == NULL){
        throwException(ERR_MCODE_NULL,token,"length generated are different");
      }
    }
   return mcode;
}

int get2ndCompValue(ConversionData dataFlag,stm8Operand * operand,Tokenizer * tokenizer){
    int mCodeLength;
    int value;
    ExtensionCodeAndCode code;
    IntegerToken * token;
    token =(IntegerToken*)getToken(tokenizer);
    code = dataFlag.codeTable[operand->type];
    mCodeLength = machineCodeLengthFinder(operand,code);
    value =additionValueWithLength(operand,mCodeLength,token);
    return value;
}

int additionValueWithLength(stm8Operand * operand,int length,IntegerToken *token){
    int value;
    int orivalue;
    value = operand->dataSize.ms;
    orivalue = operand->dataSize.ms ;
    if(value >= 128 ){
      value = value + length;
      if(value >= 256){
        value = value - 256;
      }
    }
    else{
      value = value+ length;
    }
    if((orivalue < 128) && (value >= 128 )|| (orivalue > 128) && (value >= 255 )){
      throwException(ERR_INTEGER_TOO_LARGE,token,"Expected signed value as your size is %d and your value is %x which more than 128",length,orivalue);
    }
    return value;
}

stm8Operand * getMOVOperand(Tokenizer* tokenizer,stm8Operand * dst ,stm8Operand * src ){
    IntegerToken *token;
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*) token);
    stm8Operand * operand;
    if(dst->type == SHORT_MEM_OPERAND && (src->type ==BYTE_OPERAND ||src->type ==LONG_MEM_OPERAND )){
        dst = createOperand(LONG_MEM_OPERAND,NA,NA,0x00,dst->dataSize.ms,NA);
    }
    else if(dst->type == LONG_MEM_OPERAND && src->type == SHORT_MEM_OPERAND){
        src = createOperand(LONG_MEM_OPERAND,NA,NA,0x00,src->dataSize.ms,NA);
    }

    if(dst->type == LONG_MEM_OPERAND){
      if(src->type == BYTE_OPERAND){
      operand = createOperand(BYTE_OPERAND,NA,NA,src->dataSize.ms,dst->dataSize.ms,dst->dataSize.ls);
      }
      else if(src->type == LONG_MEM_OPERAND){
      operand = createOperand(LONG_MEM_OPERAND,NA,NA,src->dataSize.ls,dst->dataSize.ms,dst->dataSize.ls);
      }
      else{
        operand = createOperand(NO_OPERAND,NA,NA,NA,NA,NA);
      }
    }
    else if(dst->type == SHORT_MEM_OPERAND){
      if(src->type == SHORT_MEM_OPERAND){
        operand = createOperand(SHORT_MEM_OPERAND,NA,NA,src->dataSize.ms,dst->dataSize.ms,NA);
      }
      else{
        operand = createOperand(NO_OPERAND,NA,NA,NA,NA,NA);
      }
    }
    else{
        throwException(ERR_INVALID_MOV_OPERAND,token,"invalid mov operand ");
    }
    return operand;
}

////////////////////////////////////////////////////////////////////////////////////////////

ConversionData getLDWComplexDataFlag(CodeInfo *codeInfo,stm8Operand * operand){
    int i = 0;
    IntegerToken *token;
    ConversionData  dataTable;
    char * str;
    if(operand->type == X_OPERAND){
      str = "COMPX";
    }
    else if(operand->type == Y_OPERAND){
      str = "COMPY";
    }
    do{
      if(codeInfo->conDataTable[i].type==operand->type){
          dataTable = codeInfo->conDataTable[i];
          break;
      }
      i++;
    }while(codeInfo->conDataTable[i].codeTable != NULL);
    if(codeInfo->conDataTable[i].codeTable == NULL){
      dataTable = codeInfo->conDataTable[i];
    }
    return dataTable;
}


MachineCode* assembleLDWOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    int cmpType;
    IntegerToken * token;
    stm8Operand * operand;
    stm8Operand * operand2nd;
    stm8OperandType operandType;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    if(isalpha(token->str[0])){
        operandType = symbolOperandCheck(token);
        operandFlagCheck(codeInfo->firstFlags, token ,operandType);
        pushBackToken(tokenizer,(Token*)token);
        dataFlag = getDataFlag(codeInfo,tokenizer,operand);
        commarCheck(tokenizer);
        operand= getOperand(tokenizer ,dataFlag.secondFlags);
    }
    else{
        pushBackToken(tokenizer,(Token*) token);
        dataFlag = getDataFlag(codeInfo,tokenizer,operand);
        pushBackToken(tokenizer,(Token*) token);
        operand = getOperand(tokenizer ,codeInfo->firstFlags);
        commarCheck(tokenizer);
        operand2nd= getOperand(tokenizer ,dataFlag.secondFlags);
        dataFlag = getLDWComplexDataFlag(codeInfo,operand2nd);
    }
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    notNullCheck(tokenizer);
    return mcode;

}



// assemblerHandler
MachineCode* assembleBTJXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    stm8Operand * operand;
    MachineCode* firstMcode;
    MachineCode* mcode;
    int value;
    ConversionData  dataFlag;

    firstMcode = assembleTwoComplexOperand(codeInfo ,tokenizer);
    commarCheck(tokenizer);
    operand = oneOperandHandler(tokenizer ,(1<< SHORT_OFF_OPERAND));
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    value =additionValueWithLength(operand,5,token);
    mcode =malloc(sizeof(MachineCode)+6);
    mcode= firstMcode;
    mcode->code[4] = value;
    mcode->length = mcode->length+1;
    notNullCheck(tokenizer);
    return mcode;
}

MachineCode* assembleLDXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    MachineCode* mcode;
    IntegerToken * token;
    IntegerToken * initToken;
    int condition;
    initToken=(IntegerToken*)getToken(tokenizer);
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    condition = strcasecmp(token->str,"A")==0 || strcasecmp(token->str,"X")==0 ||
                strcasecmp(token->str,"Y")==0 || strcasecmp(token->str,"SP")==0;
    if(condition ==1 ){
      pushBackToken(tokenizer,(Token*) initToken);
      mcode = assembleSymbolComplexOperand(codeInfo ,tokenizer);
    }
    else{
      pushBackToken(tokenizer,(Token*) initToken);
      mcode= assembleTwoComplexOperand(codeInfo ,tokenizer);
    }
    return mcode;
}


//must use
MachineCode* assembleOneOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    int conditionShortOff = 0;
    IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType operandType;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    conditionShortOff=(strncasecmp(token->str,"JR",2)==0 ||strcasecmp(token->str,"CALLR")==0);
    freeToken(token);
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    operand = oneOperandHandler(tokenizer ,codeInfo->firstFlags);
    dataFlag = getDataFlag(codeInfo,tokenizer,operand);
    if(conditionShortOff ==1){
        token =(IntegerToken*)getToken(tokenizer);
        operand->dataSize.ms=get2ndCompValue(dataFlag,operand,tokenizer);
        pushBackToken(tokenizer,(Token*)token);
    }
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    notNullCheck(tokenizer);
    return mcode;
}

MachineCode* assembleNoOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    stm8Operand * operand ;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    operand = createOperand(NO_OPERAND,NA,NA,NA,NA,NA);
    dataFlag = getDataFlag(codeInfo,tokenizer,operand);
    token =(IntegerToken*)getToken(tokenizer);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    notNullCheck(tokenizer);
    return mcode;
}

MachineCode* assembleTwoComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    int bitOPCheck =0;
    int btjXCheck =0;
    int ldwCheck =0;
    int movOPCheck =0;
    int cmpType=0;
    int nvalue = NA;
    IntegerToken * token;
    stm8Operand * operand2nd = NULL;
    stm8Operand * operand = NULL;
    stm8OperandType operandType;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    btjXCheck = (strncasecmp(token->str,"btj",3)==0);
    ldwCheck = (strcasecmp(token->str,"ldw")==0);
    bitOPCheck= bitOperationCheck(token);
    movOPCheck= (strcasecmp(token->str,"MOV")==0);
    freeToken(token);
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    operand = oneOperandHandler(tokenizer ,codeInfo->firstFlags);
    dataFlag = getDataFlag(codeInfo,tokenizer,operand);
    commarCheck(tokenizer);
    if(bitOPCheck != 0){
        nvalue = hashNValueReturn(tokenizer ,bitOPCheck);
        mcode=machineCodeAllocateOutput(tokenizer,dataFlag ,operand,nvalue,NA);
    }
    else if (movOPCheck ==1){
        operand2nd = oneOperandHandler(tokenizer ,dataFlag.secondFlags);
        operand = getMOVOperand(tokenizer,operand , operand2nd);
        cmpType =(operand->type == LONG_MEM_OPERAND && operand2nd->type == LONG_MEM_OPERAND);
        if(cmpType ==1 )
            mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,operand2nd->dataSize.ms);
        else
            mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    }
    else if(ldwCheck ==1){
      operand2nd = oneOperandHandler(tokenizer ,dataFlag.secondFlags);
      operand->type = operand2nd->type;
      mcode=machineCodeAllocateOutput(tokenizer,dataFlag ,operand,NA,NA);
    }
    else{
      operand2nd = oneOperandHandler(tokenizer ,dataFlag.secondFlags);
      mcode=machineCodeAllocateOutput(tokenizer,dataFlag ,operand,NA,NA);
    }
    if(btjXCheck =0){
      notNullCheck(tokenizer);
    }
    return mcode;
}

MachineCode* assembleSymbolComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    int bitOPCheck =0;
    int nvalue = NA;
    IntegerToken * token;
    stm8Operand * operand;
    stm8Operand * operand1st;
    stm8OperandType operandType;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    freeToken(token);
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    operand1st = oneOperandHandler(tokenizer ,codeInfo->firstFlags);
    pushBackToken(tokenizer,(Token*)token);
    dataFlag = getDataFlag(codeInfo,tokenizer,operand1st);
    token =(IntegerToken*)getToken(tokenizer);
    commarCheck(tokenizer);
    operand = oneOperandHandler(tokenizer ,dataFlag.secondFlags);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag ,operand,NA,NA);
    notNullCheck(tokenizer);
    return mcode;
}
