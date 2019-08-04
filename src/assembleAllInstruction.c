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


ConversionData getDataFlag(CodeInfo *codeInfo,Tokenizer* tokenizer){
    int i = 0;
    IntegerToken *token;
    ConversionData  dataTable;
    token =(IntegerToken*)getToken(tokenizer);
    do{
      nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected valid name");
      if(strcasecmp(codeInfo->conDataTable[i].name,token->str)==0){
        dataTable = codeInfo->conDataTable[i];
        break;
      }
      else if (!isalpha(token->str[0])){
        if(strcasecmp(codeInfo->conDataTable[i].name,"COMP")==0){
          dataTable = codeInfo->conDataTable[i];
          break;
        }
      }
      i++;
    }while(codeInfo->conDataTable[i].name != NULL);
    return dataTable;
}

stm8Operand * complexOperandReturn(Tokenizer* tokenizer ,ConversionData  dataFlag){
    IntegerToken *token;
    stm8Operand * operand;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_INVALID_SYNTAX,token,"Expected ,");
    if(strcmp(token->str,",")==0){
        operand = getOperand(tokenizer ,dataFlag.secondFlags);
    }
    else{
      throwException(ERR_INVALID_SYNTAX,token,"expected ,");
    }
    return operand;

}

MachineCode* outputMachineCode(stm8Operand * operand,ExtensionCodeAndCode code, int length){
    MachineCode* mcode = NULL;
    mcode =malloc(sizeof(MachineCode)+1+ length);
    mcode->length = length;
    if(code.extCode== 65535){
      if((operand->dataSize.ls != 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB == 65535){
        mcode->code[0] = code.code;
        mcode->code[1] = operand->dataSize.ms;
        mcode->code[2] = operand->dataSize.ls;
      }
      else if((operand->dataSize.ls == 65535 && operand->dataSize.ms == 65535 )&& operand->dataSize.extB == 65535){
        mcode->code[0] = code.code;
      }
      else if((operand->dataSize.ls == 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB == 65535){
        mcode->code[0] = code.code;
        mcode->code[1] = operand->dataSize.ms;
      }
      else if((operand->dataSize.ls != 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB != 65535){
        mcode->code[0] = code.code;
        mcode->code[1] = operand->dataSize.ms;
        mcode->code[2] = operand->dataSize.ls;
        mcode->code[3] = operand->dataSize.extB;
      }
      }
      else{
        if((operand->dataSize.ls != 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB == 65535){
          mcode->code[0] = code.extCode;
          mcode->code[1] = code.code;
          mcode->code[2] = operand->dataSize.ms;
          mcode->code[3] = operand->dataSize.ls;
        }
        else if((operand->dataSize.ls == 65535 && operand->dataSize.ms == 65535 )&& operand->dataSize.extB == 65535){
          mcode->code[0] = code.extCode;
          mcode->code[1] = code.code;
        }
        else if((operand->dataSize.ls == 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB == 65535){
          mcode->code[0] = code.extCode;
          mcode->code[1] = code.code;
          mcode->code[2] = operand->dataSize.ms;
        }
        else if((operand->dataSize.ls != 65535 && operand->dataSize.ms != 65535 )&& operand->dataSize.extB != 65535){
          mcode->code[0] = code.extCode;
          mcode->code[1] = code.code;
          mcode->code[2] = operand->dataSize.ms;
          mcode->code[3] = operand->dataSize.ls;
          mcode->code[4] = operand->dataSize.extB;
        }
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

MachineCode* machineCodeAllocateOutput(Tokenizer* tokenizer,ConversionData  dataFlag , stm8Operand *operand, int nvalue){
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    int a =0;
    IntegerToken * token;
    IntegerToken * initToken;
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    if(token->str==NULL){
            code = dataFlag.codeTable[operand->type];

            if(nvalue >= 0 && nvalue <= 15){
              code.code =code.code + nvalue;
            }
    }
    else{
        throwException(ERR_INVALID_SYNTAX,token,"expected nothing after that");
    }

    if(code.extCode ==0 && code.code ==0){
      throwException(ERR_UNSUPPORTED_OPERAND,initToken,"This operand doesnt supported ");
    }
    else{
      a = machineCodeLengthFinder(operand,code);
      mcode =malloc(sizeof(MachineCode)+1+ a);
      mcode = outputMachineCode(operand,code,a);
    }
   return mcode;
}



// assemblerHandler

MachineCode* assembleOneOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected complex operand eg sllw X  ");
    dataFlag = getDataFlag(codeInfo,tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    operand = getOperand(tokenizer ,codeInfo->firstFlags);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA);
    token =(IntegerToken*)getToken(tokenizer);
    if(token->str !=NULL){
      throwException(ERR_INVALID_STM8_OPERAND,token,"Expected nothing after ");
    }
    return mcode;
}

MachineCode* assembleXYOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL and operand X ,Y eg SUBW X,#$5500 ");
    if(strcasecmp(token->str,"X")==0){
      dataFlag = getDataFlag(codeInfo,tokenizer);
      operandFlagCheck(codeInfo->firstFlags,token,X_OPERAND);
    }
    else if(strcasecmp(token->str,"Y")==0){
      dataFlag = getDataFlag(codeInfo,tokenizer);
      operandFlagCheck(codeInfo->firstFlags,token,Y_OPERAND);
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected X ,Y eg SUBW X,#$5500");
    }
    operand= complexOperandReturn(tokenizer ,dataFlag);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA);
    return mcode;
}

MachineCode* assembleXOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
  IntegerToken * token;
  IntegerToken * initToken;
  stm8Operand * operand;
  ExtensionCodeAndCode code;
  MachineCode* mcode;
  ConversionData  dataFlag;

  token =(IntegerToken*)getToken(tokenizer);
  initToken = token;
  token =(IntegerToken*)getToken(tokenizer);
  pushBackToken(tokenizer,(Token*)token);
  nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL operand A eg ADD A,($1000,X) ");

  if(strcasecmp(token->str,"X")==0){
      dataFlag = getDataFlag(codeInfo,tokenizer);
      operandFlagCheck(codeInfo->firstFlags,token,X_OPERAND);
  }
  else{
    throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected operand A eg ADD A,($1000,X)");
  }
  operand= complexOperandReturn(tokenizer ,dataFlag);
  mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA);
  return mcode;
}

MachineCode* assembleAOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;
    int tableloc =0 ;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL operand A eg ADD A,($1000,X) ");

    if(strcasecmp(token->str,"A")==0){
        dataFlag = getDataFlag(codeInfo,tokenizer);
        operandFlagCheck(codeInfo->firstFlags,token,A_OPERAND);
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected operand A eg ADD A,($1000,X)");
    }
    operand= complexOperandReturn(tokenizer ,dataFlag);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA);
    return mcode;
}

MachineCode* assembleNoOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand ;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    pushBackToken(tokenizer,(Token*)token);
    operand = createOperand(NO_OPERAND,NA,NA,NA,NA,NA);
    dataFlag = getDataFlag(codeInfo,tokenizer);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA);
    return mcode;
}

MachineCode* assembleXYSPComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL and operand X ,Y,SP eg ADDW X,($10,SP) ");
    if(strcasecmp(token->str,"X")==0){
      dataFlag = getDataFlag(codeInfo,tokenizer);
      operandFlagCheck(codeInfo->firstFlags,token,X_OPERAND);
    }
    else if(strcasecmp(token->str,"Y")==0){
      dataFlag = getDataFlag(codeInfo,tokenizer);
      operandFlagCheck(codeInfo->firstFlags,token,Y_OPERAND);
    }
    else if(strcasecmp(token->str,"SP")==0){
      dataFlag = getDataFlag(codeInfo,tokenizer);
      operandFlagCheck(codeInfo->firstFlags,token,SP_OPERAND);
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected X ,Y,SP eg ADDW X,($10,SP)");
    }
    operand= complexOperandReturn(tokenizer ,dataFlag);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA);
    return mcode;
}

MachineCode* assembleASPComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL and operand A,SP eg SUB SP,#$9 ");
    if(strcasecmp(token->str,"A")==0){
      dataFlag = getDataFlag(codeInfo,tokenizer);
      operandFlagCheck(codeInfo->firstFlags,token,A_OPERAND);
    }
    else if(strcasecmp(token->str,"SP")==0){
      dataFlag = getDataFlag(codeInfo,tokenizer);
      operandFlagCheck(codeInfo->firstFlags,token,SP_OPERAND);
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected A,SP eg SUB SP,#$9)");
    }
    operand= complexOperandReturn(tokenizer ,dataFlag);
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag , operand,NA);
    return mcode;
}

MachineCode* assembleTwowithNOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    stm8Operand * operand2nd;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    int cmpType = 0;
    int nvalue;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    cmpType = (strcasecmp(token->str,"BCCM")==0) || (strcasecmp(token->str,"BRES")==0);
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    pushBackToken(tokenizer,(Token*) token);
    dataFlag = getDataFlag(codeInfo,tokenizer);
    pushBackToken(tokenizer,(Token*) token);
    operand = getOperand(tokenizer ,codeInfo->firstFlags);
    operand2nd = complexOperandReturn(tokenizer ,dataFlag);
    if(!(operand2nd->dataSize.ms >= 0 && operand2nd->dataSize.ms <= 7)){
      token =(IntegerToken*)getToken(tokenizer);
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected eg BCCM $1000,#n , n less than 7 and larger than 0");
    }

    else if(cmpType ==1 ){
      nvalue = 1 + 2*operand2nd->dataSize.ms;
    }
    else{
      nvalue = 2*operand2nd->dataSize.ms;
    }
    mcode=machineCodeAllocateOutput(tokenizer,dataFlag ,operand,nvalue);
    return mcode;
}




/*
MachineCode* assembleLDOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    stm8Operand * operand2nd;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    int tableloc;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    if(strcasecmp(token->str,"A")==0){
        tableloc =0;
        operand= complexOperandReturn(tokenizer ,codeInfo);
        if(operand->type == A_OPERAND)
          throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected not A as src for LD if A is dst eg LD A,#$55");
    }
    else{
        pushBackToken(tokenizer,(Token*) token);
        tableloc =1;
        operand = getOperand(tokenizer ,codeInfo->operandExistenceFlags[0]);
        operand2nd = complexOperandReturn(tokenizer ,codeInfo);
        if(operand2nd->type != A_OPERAND)
          throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected A as src for LD eg LD $50,A");
    }

    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand,NA,tableloc);
    return mcode;

}

MachineCode* assembleLDWOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    stm8Operand * operand2nd;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    int tableloc =0;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    if(strcasecmp(token->str,"X")==0){
        tableloc =0;
        codeInfo->operandExistenceFlags[1]= LDW_X_SUPPORTED_OPERANDS;
        operand= complexOperandReturn(tokenizer ,codeInfo);
    }
    else if(strcasecmp(token->str,"Y")==0){
      tableloc =1;
      codeInfo->operandExistenceFlags[1]= LDW_Y_SUPPORTED_OPERANDS;
      operand= complexOperandReturn(tokenizer ,codeInfo);
    }
    else if(strcasecmp(token->str,"SP")==0){
      tableloc =2;
      codeInfo->operandExistenceFlags[1]= LDW_SP_SUPPORTED_OPERANDS;
      operand= complexOperandReturn(tokenizer ,codeInfo);
    }
    else{
        pushBackToken(tokenizer,(Token*) token);
        operand = getOperand(tokenizer ,codeInfo->operandExistenceFlags[0]);
        codeInfo->operandExistenceFlags[1]= LDW_SP_SUPPORTED_OPERANDS;
        operand2nd = complexOperandReturn(tokenizer ,codeInfo);
        if(operand2nd->type == X_OPERAND)
            tableloc =3;
        else if(operand2nd->type == Y_OPERAND)
            tableloc =4;
      }

    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand,NA,tableloc);
    return mcode;

}

MachineCode* assembleLDFOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    stm8Operand * operand2nd;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    int tableloc;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DSTSRC_NULL,token,"Expected not NULL ");
    if(strcasecmp(token->str,"A")==0){
        tableloc =0;
        operand= complexOperandReturn(tokenizer ,codeInfo);
        if(operand->type == A_OPERAND)
          throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected not A as src for LDF if A is dst eg LDF A,($500000,Y)");
    }
    else{
        pushBackToken(tokenizer,(Token*) token);
        tableloc =1;
        operand = getOperand(tokenizer ,codeInfo->operandExistenceFlags[0]);
        operand2nd = complexOperandReturn(tokenizer ,codeInfo);
        if(operand2nd->type != A_OPERAND)
            throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected A as src for LD eg LD $50,A");
      }

    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand,NA,tableloc);
    return mcode;

}
*/
