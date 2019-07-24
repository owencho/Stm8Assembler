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

ExtensionCodeAndCode addwXCodeTable[] = {
    [WORD_OPERAND]={NA,0x1c},
    [LONG_MEM_OPERAND] ={72,0xbb},
    [SHORTOFF_SP_OPERAND]={72,0xfb}
};
ExtensionCodeAndCode addwYCodeTable[] = {
    [WORD_OPERAND] ={72,0xa9},
    [LONG_MEM_OPERAND] ={72,0xb9},
    [SHORTOFF_SP_OPERAND] ={72,0xf9}
};
ExtensionCodeAndCode addwSPCodeTable[] = {
    [BYTE_OPERAND] ={NA,0x5b}
};

ExtensionCodeAndCode subwXCodeTable[] = {
  [WORD_OPERAND]         ={NA,0x1d},
  [LONG_MEM_OPERAND]     ={0x72,0xb0},
  [SHORTOFF_SP_OPERAND] ={0x72,0xf0}
};
ExtensionCodeAndCode subwYCodeTable[] = {
  [WORD_OPERAND]         ={0x72,0xa2},
  [LONG_MEM_OPERAND]     ={0x72,0xb2},
  [SHORTOFF_SP_OPERAND] ={0x72,0xf2}
};
ExtensionCodeAndCode cpwXCodeTable[] = {
  [WORD_OPERAND]         ={NA,0xa3},
  [SHORT_MEM_OPERAND]    ={NA,0xb3},
  [LONG_MEM_OPERAND]     ={NA,0xc3},
  [BRACKETED_Y_OPERAND] ={0x90,0xf3},
  [SHORTOFF_Y_OPERAND] ={0x90,0xe3},
  [LONGOFF_Y_OPERAND] ={0x90,0xd3},
  [SHORTOFF_SP_OPERAND] ={NA,0x13},
  [BRACKETED_SHORTPTR_DOT_W_OPERAND] ={0x92,0xc3},
  [BRACKETED_LONGPTR_DOT_W_OPERAND] ={0x72,0xc3},
  [SHORTPTR_DOT_W_BRACKETEDY_OPERAND] ={0x91,0xd3},
};
ExtensionCodeAndCode cpwYCodeTable[] ={
  [WORD_OPERAND]={0x90,0xc0},
  [SHORT_MEM_OPERAND]={0x90,0xc0},
  [LONG_MEM_OPERAND]={0x90,0xd0},
  [BRACKETED_X_OPERAND]={NA,0xd0},
  [SHORTOFF_X_OPERAND]={NA,0xd0},
  [LONGOFF_X_OPERAND]={NA,0xc0},
  [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x91,0xc3},
  [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd3},
  [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd3}
};
ExtensionCodeAndCode subACodeTable[] = {
  [BYTE_OPERAND]         ={NA,0xa0},
  [SHORT_MEM_OPERAND]    ={NA,0xb0},
  [LONG_MEM_OPERAND]     ={NA,0xc0},
  [BRACKETED_X_OPERAND] ={NA,0xf0},
  [SHORTOFF_X_OPERAND] ={NA,0xe0},
  [LONGOFF_X_OPERAND] ={NA,0xd0},
  [BRACKETED_Y_OPERAND] ={0x90,0xf0},
  [SHORTOFF_Y_OPERAND] ={0x90,0xe0},
  [LONGOFF_Y_OPERAND] ={0x90,0xd0},
  [SHORTOFF_SP_OPERAND] ={NA,0x10},
  [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc0},
  [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc0},
  [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd0},
  [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd0},
  [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd0},
};
ExtensionCodeAndCode subSPCodeTable[] = {
  [BYTE_OPERAND]         ={NA,0x52}
};
ExtensionCodeAndCode divXCodeTable[] = {
  [A_OPERAND]    ={NA,0x62},
};

ExtensionCodeAndCode divYCodeTable[] = {
  [A_OPERAND]    ={0x90,0x62}
};

stm8Operand * complexOperandReturn(Tokenizer* tokenizer ,CodeInfo * codeInfo){
    IntegerToken *token;
    stm8Operand * operand;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_INVALID_SYNTAX,token,"Expected ,");
    if(strcmp(token->str,",")==0){
        operand = getOperand(tokenizer ,codeInfo->operandExistenceFlags[1]);
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

MachineCode* machineCodeAllocateOutput(Tokenizer* tokenizer,CodeInfo * codeInfo , stm8Operand *operand){
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    int a =0;
    IntegerToken * token;
    IntegerToken * initToken;
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    if(token->str==NULL){
            code = codeInfo->codeTable[operand->type];
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

MachineCode* assembleAddwOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DST_NULL,token,"Expected not NULL and operand X ,Y,SP eg ADDW X,($10,SP) ");
    if(strcasecmp(token->str,"X")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,X_OPERAND);
        codeInfo->codeTable = addwXCodeTable;
        codeInfo->operandExistenceFlags[1]=ADDW_XY_SUPPORTED_OPERANDS;
    }
    else if(strcasecmp(token->str,"Y")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,Y_OPERAND);
        codeInfo->codeTable = addwYCodeTable;
        codeInfo->operandExistenceFlags[1]=ADDW_XY_SUPPORTED_OPERANDS;
    }
    else if(strcasecmp(token->str,"SP")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,SP_OPERAND);
        codeInfo->codeTable = addwSPCodeTable;
        codeInfo->operandExistenceFlags[1]=(1<<BYTE_OPERAND);
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected X ,Y,SP eg ADDW X,($10,SP)");
    }
    operand= complexOperandReturn(tokenizer ,codeInfo);
    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand);
    return mcode;
}

MachineCode* assembleSubOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DST_NULL,token,"Expected not NULL and operand A ,SP eg SUB SP,#$9  ");
    if(strcasecmp(token->str,"A")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,X_OPERAND);
        codeInfo->codeTable = subACodeTable;
        codeInfo->operandExistenceFlags[1]=ADC_SUPPORTED_OPERANDS;
    }
    else if(strcasecmp(token->str,"SP")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,SP_OPERAND);
        codeInfo->codeTable = subSPCodeTable;
        codeInfo->operandExistenceFlags[1]=(1<<BYTE_OPERAND);
    }
    else{
        throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected operand A ,SP eg SUB SP,#$9 ");
    }
    operand= complexOperandReturn(tokenizer ,codeInfo);
    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand );
    return mcode;
}

MachineCode* assembleCPWOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DST_NULL,token,"Expected not NULL and operand X ,Y eg CPW Y,($1000,X) ");
    if(strcasecmp(token->str,"X")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,X_OPERAND);
        codeInfo->codeTable = cpwXCodeTable;
        codeInfo->operandExistenceFlags[1]=CPW_X_SUPPORTED_OPERANDS;
    }
    else if(strcasecmp(token->str,"Y")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,Y_OPERAND);
        codeInfo->codeTable = cpwYCodeTable;
        codeInfo->operandExistenceFlags[1]=CPW_Y_SUPPORTED_OPERANDS ;
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected X ,Y eg CPW Y,($1000,X)");
    }
    operand= complexOperandReturn(tokenizer ,codeInfo);
    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand);
    return mcode;
}

MachineCode* assembleDivOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DST_NULL,token,"Expected not NULL and operand X ,Y eg div X,A ");
    if(strcasecmp(token->str,"X")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,X_OPERAND);
        codeInfo->codeTable = divXCodeTable;
    }
    else if(strcasecmp(token->str,"Y")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,Y_OPERAND);
        codeInfo->codeTable = divYCodeTable;
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected X ,Y eg div X,A");
    }
    operand= complexOperandReturn(tokenizer ,codeInfo);
    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand);
    return mcode;
}

MachineCode* assembleSubWOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DST_NULL,token,"Expected not NULL and operand X ,Y eg SUBW X,#$5500 ");
    if(strcasecmp(token->str,"X")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,X_OPERAND);
        codeInfo->codeTable = subwXCodeTable;
    }
    else if(strcasecmp(token->str,"Y")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,Y_OPERAND);
        codeInfo->codeTable = subwYCodeTable;
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected X ,Y eg SUBW X,#$5500");
    }
    operand= complexOperandReturn(tokenizer ,codeInfo);
    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand);
    return mcode;
}

MachineCode* assembleXOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_DST_NULL,token,"Expected not NULL operand X eg EXGW X,Y ");
    if(strcasecmp(token->str,"X")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,X_OPERAND);
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected operand X eg EXGW X,Y ");
    }
    operand= complexOperandReturn(tokenizer ,codeInfo);
    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand );
    return mcode;
}

MachineCode* assembleAOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
        nullCheck(ERR_DST_NULL,token,"Expected not NULL operand A eg ADD A,($1000,X) ");
    if(strcasecmp(token->str,"A")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,A_OPERAND);
    }
    else{
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected operand A eg ADD A,($1000,X)");
    }
    operand= complexOperandReturn(tokenizer ,codeInfo);
    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand);
    return mcode;
}

MachineCode* assembleNoOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand ;
    ExtensionCodeAndCode code;
    MachineCode* mcode;

    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    operand = createOperand(NO_OPERAND,NA,NA,NA,NA,NA);
    mcode=machineCodeAllocateOutput(tokenizer,codeInfo , operand);
    return mcode;
}
