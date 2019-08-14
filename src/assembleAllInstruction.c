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

stm8Operand * oneOperandHandler(Tokenizer * tokenizer , uint64_t flags){
    IntegerToken* token;
    stm8Operand* operand ;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL");
    pushBackToken(tokenizer,(Token*)token);
    operand= getOperand(tokenizer ,flags);
    pushBackToken(tokenizer,(Token*)token);
    return operand;
}

ConversionData getDataFlag(CodeInfo *codeInfo,Tokenizer * tokenizer,stm8Operand* operand){
    int i = 0;
    IntegerToken *token;
    ConversionData  dataTable;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected valid name");
    do{
      if(codeInfo->conDataTable[i].type==operand->type){
        dataTable = codeInfo->conDataTable[i];
        break;
      }
      i++;
    }while(codeInfo->conDataTable[i].codeTable != NULL);
    if(codeInfo->conDataTable[i].codeTable != NULL){
        throwException(ERR_DATATABLE_NULL,token,"expected table are null");
    }
    return dataTable;
}

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
      if(strcasecmp(codeInfo->conDataTable[i].name,str)==0){
          dataTable = codeInfo->conDataTable[i];
          break;
      }
      i++;
    }while(codeInfo->conDataTable[i].codeTable != NULL);
    if(codeInfo->conDataTable[i].codeTable != NULL){
      dataTable = codeInfo->conDataTable[i];
    }
    return dataTable;
}

ConversionData getMOVDataFlag(CodeInfo *codeInfo,stm8Operand * operand){
    int i = 0;
    ConversionData  dataTable;
    IntegerToken *token;
    char * str;
    if(operand->type == LONG_MEM_OPERAND){
      str = "LONG";
    }
    else if(operand->type == SHORT_MEM_OPERAND){
      str = "SHORT";
    }
    do{
      if(strcasecmp(codeInfo->conDataTable[i].name,str)==0){
        dataTable = codeInfo->conDataTable[i];
        break;
      }
      i++;
    }while(codeInfo->conDataTable[i].name != NULL);
    if(codeInfo->conDataTable[i].name == NULL){
      dataTable = codeInfo->conDataTable[i];
    }
    return dataTable;
}


stm8Operand * getMOVOpcode(stm8Operand * dst ,stm8Operand * src ){
    stm8Operand * operand;
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
      operand = createOperand(NO_OPERAND,NA,NA,NA,NA,NA);
    }
    return operand;
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
    else if(cmpType ==1 ){
      nvalue = 1 + 2*operand->dataSize.ms;
    }
    else if (cmpType ==0){
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
    if(token->str==NULL){
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
    }
    else{
        throwException(ERR_INVALID_SYNTAX,token,"expected nothing after that");
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

int getJRXX2ndCompLength(ConversionData dataFlag,stm8Operand * operand,Tokenizer * tokenizer){
    int a;
    int value =operand->dataSize.ms;
    int orivalue;
    ExtensionCodeAndCode code;
    IntegerToken * token;
    token =(IntegerToken*)getToken(tokenizer);
    code = dataFlag.codeTable[operand->type];
    a = machineCodeLengthFinder(operand,code);
    orivalue = operand->dataSize.ms ;
    if(value >= 128 ){
      value = value + a;
      if(value >= 256){
        value = value - 256;
      }
    }
    else{
      value = value+ a;
    }
    if((orivalue < 128) && (value >= 128 )|| (orivalue > 128) && (value >= 255 )){
      throwException(ERR_INTEGER_TOO_LARGE,token,"Expected signed value as your size is %d and your value is %x which more than 128",a,orivalue);
    }
    return value;
}

int getBTJX2ndCompLength(stm8Operand * operand,IntegerToken * token){
    int value;
    int orivalue;
    value = operand->dataSize.ms;
    orivalue = operand->dataSize.ms;
    if(value >= 128 ){
      value = value + 5;
      if(value >= 256){
        value = value - 256;
      }
    }
    else{
      value = value+ 5;
    }
    if((orivalue < 128) && (value >= 128 )|| (orivalue > 128) && (value >= 255 )){
      throwException(ERR_INTEGER_TOO_LARGE,token,"Expected signed value as your size is 5 and your value is %x which more than 128",orivalue);
    }
    return value;
}

// assemblerHandler
/*
MachineCode* assembleLDFLDOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    int cmpType;
    IntegerToken * token;
    stm8Operand * operand;
    stm8Operand * operand2nd;
    stm8OperandType operandType;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    cmpType =(strcasecmp(token->str,"LD")==0);
    freeToken(token);
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    if(isalpha(token->str[0])){
        operandType = symbolOperandCheck(token);
        operandFlagCheck(codeInfo->firstFlags, token ,operandType);
        pushBackToken(tokenizer,(Token*)token);
        dataFlag = getDataFlag(codeInfo,tokenizer);
        commarCheck(tokenizer);
        operand= getOperand(tokenizer ,dataFlag.secondFlags);
        if(operandType != A_OPERAND && cmpType)
            operand->type = operandType;
    }
    else{
        pushBackToken(tokenizer,(Token*) token);
        dataFlag = getDataFlag(codeInfo,tokenizer);
        pushBackToken(tokenizer,(Token*) token);
        operand = getOperand(tokenizer ,codeInfo->firstFlags);
        commarCheck(tokenizer);
        operand2nd= getOperand(tokenizer ,dataFlag.secondFlags);
    }
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    notNullCheck(tokenizer);
    return mcode;
}

MachineCode* assembleBTJXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    stm8Operand * operand;
    stm8Operand * operand2nd;
    MachineCode* mcode;
    int cmpType = 0;
    int nvalue;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_OPERAND_NULL,token,"Expected not NULL ");
    cmpType = (strcasecmp(token->str,"BTJF")==0);
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    pushBackToken(tokenizer,(Token*) token);
    dataFlag = getDataFlag(codeInfo,tokenizer);
    pushBackToken(tokenizer,(Token*) token);
    operand = getOperand(tokenizer ,codeInfo->firstFlags);
    commarCheck(tokenizer);
    nvalue = hashNValueReturn(tokenizer ,cmpType);
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*) token);
    commarCheck(tokenizer);
    operand2nd= getOperand(tokenizer ,dataFlag.thirdFlags);
    operand->dataSize.extB=getBTJX2ndCompLength(operand2nd,token);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag ,operand,nvalue,NA);
    notNullCheck(tokenizer);
    return mcode;
}

MachineCode* assembleTwowithNOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    stm8Operand * operand;
    MachineCode* mcode;
    int cmpType = 0;
    int nvalue;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    cmpType = (strcasecmp(token->str,"BCCM")==0) || (strcasecmp(token->str,"BRES")==0);
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    pushBackToken(tokenizer,(Token*) token);
    dataFlag = getDataFlag(codeInfo,tokenizer);
    pushBackToken(tokenizer,(Token*) token);
    operand = getOperand(tokenizer ,codeInfo->firstFlags);
    commarCheck(tokenizer);
    nvalue = hashNValueReturn(tokenizer ,cmpType);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,nvalue,NA);
    notNullCheck(tokenizer);
    return mcode;
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
        dataFlag = getDataFlag(codeInfo,tokenizer);
        commarCheck(tokenizer);
        operand= getOperand(tokenizer ,dataFlag.secondFlags);
    }
    else{
        pushBackToken(tokenizer,(Token*) token);
        dataFlag = getDataFlag(codeInfo,tokenizer);
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

MachineCode* assembleMOVperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    stm8Operand * operand;
    stm8Operand * operand2nd;
    MachineCode* mcode;
    int cmpType = 0;
    int nvalue;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    freeToken(token);
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    pushBackToken(tokenizer,(Token*) token);
    operand = getOperand(tokenizer ,codeInfo->firstFlags);
    dataFlag = getMOVDataFlag(codeInfo,operand);
    commarCheck(tokenizer);
    operand2nd= getOperand(tokenizer ,dataFlag.secondFlags);
    if(operand->type == SHORT_MEM_OPERAND && (operand2nd->type ==BYTE_OPERAND ||operand2nd->type ==LONG_MEM_OPERAND )){
        operand = createOperand(LONG_MEM_OPERAND,NA,NA,0x00,operand->dataSize.ms,NA);
    }
    else if(operand->type == LONG_MEM_OPERAND && operand2nd->type == SHORT_MEM_OPERAND){
        operand2nd = createOperand(LONG_MEM_OPERAND,NA,NA,0x00,operand2nd->dataSize.ms,NA);
    }
    operand = getMOVOpcode(operand , operand2nd);
    if(operand->type == NO_OPERAND){
        throwException(ERR_INVALID_MOV_OPERAND,token,"invalid mov operand ");
    }
    cmpType =(operand->type == LONG_MEM_OPERAND && operand2nd->type == LONG_MEM_OPERAND);
    if(cmpType ==1 ){
      mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,operand2nd->dataSize.ms);
    }
    else{
        mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    }
    notNullCheck(tokenizer);
    return mcode;
}

MachineCode* assembleJRXXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * integerToken ;
    IntegerToken * firstToken;
    stm8Operand * operand;
    MachineCode* mcode;
    ConversionData  dataFlag;
    int a ;
    int orivalue;

    firstToken =(IntegerToken*)getToken(tokenizer);
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected complex operand eg sllw X  ");
    dataFlag = getDataFlag(codeInfo,tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    operand = getOperand(tokenizer ,codeInfo->firstFlags);
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)firstToken);
    integerToken =(IntegerToken*)getToken(tokenizer);
    operand->dataSize.ms=getJRXX2ndCompLength(dataFlag,operand,tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    notNullCheck(tokenizer);
    return mcode;
}

MachineCode* assembleOneOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType operandType;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    freeToken(token);
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected complex operand eg sllw X  ");
    pushBackToken(tokenizer,(Token*)token);
    dataFlag = getDataFlag(codeInfo,tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    operand = getOperand(tokenizer ,codeInfo->firstFlags);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    notNullCheck(tokenizer);
    return mcode;
}
*/
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
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    notNullCheck(tokenizer);
    return mcode;
}

MachineCode* assembleSymbolComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType operandType;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    freeToken(token);
    operand = oneOperandHandler(tokenizer ,codeInfo->firstFlags);
    dataFlag = getDataFlag(codeInfo,tokenizer,operand);
    commarCheck(tokenizer);
    operand = oneOperandHandler(tokenizer ,dataFlag.secondFlags);
    token =(IntegerToken*)getToken(tokenizer);
    freeToken(token);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA,NA);
    notNullCheck(tokenizer);
    return mcode;
}
