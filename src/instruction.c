#include "instruction.h"
#include "unity.h"
#include "Common.h"
#include "Token.h"
#include "Error.h"
#include "Tokenizer.h"
#include "CException.h"
#include "Exception.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include "operand.h"

ExtensionCodeAndCode adcCodeTable[] = {
[BYTE_OPERAND]         ={NA,0xa9},
[SHORT_MEM_OPERAND]    ={NA,0xb9},
[LONG_MEM_OPERAND]     ={NA,0xc9},
[BRACKETED_X_OPERAND] ={NA,0xf9},
[SHORTOFF_X_OPERAND] ={NA,0xe9},
[LONGOFF_X_OPERAND] ={NA,0xd9},
[BRACKETED_Y_OPERAND] ={0x90,0xf9},
[SHORTOFF_Y_OPERAND] ={0x90,0xe9},
[LONGOFF_Y_OPERAND] ={0x90,0xd9},
[SHORTOFF_SP_OPERAND] ={NA,0x19},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc9},
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc9},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd9},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd9},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd9},
};

CodeInfo adcCodeInfo={"adc",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, adcCodeTable
};

ExtensionCodeAndCode addCodeTable[] = {
[BYTE_OPERAND]         ={NA,0xab},
[SHORT_MEM_OPERAND]    ={NA,0xbb},
[LONG_MEM_OPERAND]     ={NA,0xcb},
[BRACKETED_X_OPERAND] ={NA,0xfb},
[SHORTOFF_X_OPERAND] ={NA,0xeb},
[LONGOFF_X_OPERAND] ={NA,0xdb},
[BRACKETED_Y_OPERAND] ={0x90,0xfb},
[SHORTOFF_Y_OPERAND] ={0x90,0xeb},
[LONGOFF_Y_OPERAND] ={0x90,0xdb},
[SHORTOFF_SP_OPERAND] ={NA,0x1b},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xcb},
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xcb},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xdb},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xdb},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xdb},
};

CodeInfo addCodeInfo={"add",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, addCodeTable
};

ExtensionCodeAndCode andCodeTable[] = {
[BYTE_OPERAND]         ={NA,0xa4},
[SHORT_MEM_OPERAND]    ={NA,0xb4},
[LONG_MEM_OPERAND]     ={NA,0xc4},
[BRACKETED_X_OPERAND] ={NA,0xf4},
[SHORTOFF_X_OPERAND] ={NA,0xe4},
[LONGOFF_X_OPERAND] ={NA,0xd4},
[BRACKETED_Y_OPERAND] ={0x90,0xf4},
[SHORTOFF_Y_OPERAND] ={0x90,0xe4},
[LONGOFF_Y_OPERAND] ={0x90,0xd4},
[SHORTOFF_SP_OPERAND] ={NA,0x14},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc4},
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc4},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd4},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd4},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd4},
};

CodeInfo andCodeInfo={"and",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, andCodeTable
};

ExtensionCodeAndCode bcpCodeTable[] = {
[BYTE_OPERAND]         ={NA,0xa5},
[SHORT_MEM_OPERAND]    ={NA,0xb5},
[LONG_MEM_OPERAND]     ={NA,0xc5},
[BRACKETED_X_OPERAND] ={NA,0xf5},
[SHORTOFF_X_OPERAND] ={NA,0xe5},
[LONGOFF_X_OPERAND] ={NA,0xd5},
[BRACKETED_Y_OPERAND] ={0x90,0xf5},
[SHORTOFF_Y_OPERAND] ={0x90,0xe5},
[LONGOFF_Y_OPERAND] ={0x90,0xd5},
[SHORTOFF_SP_OPERAND] ={NA,0x15},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc5},
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc5},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd5},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd5},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd5},
};

CodeInfo bcpCodeInfo={"bcp",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, bcpCodeTable
};

ExtensionCodeAndCode cpCodeTable[] = {
[BYTE_OPERAND]         ={NA,0xa1},
[SHORT_MEM_OPERAND]    ={NA,0xb1},
[LONG_MEM_OPERAND]     ={NA,0xc1},
[BRACKETED_X_OPERAND] ={NA,0xf1},
[SHORTOFF_X_OPERAND] ={NA,0xe1},
[LONGOFF_X_OPERAND] ={NA,0xd1},
[BRACKETED_Y_OPERAND] ={0x90,0xf1},
[SHORTOFF_Y_OPERAND] ={0x90,0xe1},
[LONGOFF_Y_OPERAND] ={0x90,0xd1},
[SHORTOFF_SP_OPERAND] ={NA,0x11},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc1},
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc1},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd1},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd1},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd1},
};

CodeInfo cpCodeInfo={"cp",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, cpCodeTable
};

ExtensionCodeAndCode exgCodeTable[] = {
[XL_OPERAND]         ={NA,0x41},
[YL_OPERAND]         ={NA,0x61},
[LONG_MEM_OPERAND]   ={NA,0x31},
};

CodeInfo exgCodeInfo={"exg",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    EXG_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, exgCodeTable
};

ExtensionCodeAndCode orCodeTable[] = {
[BYTE_OPERAND]         ={NA,0xaa},
[SHORT_MEM_OPERAND]    ={NA,0xba},
[LONG_MEM_OPERAND]     ={NA,0xca},
[BRACKETED_X_OPERAND] ={NA,0xfa},
[SHORTOFF_X_OPERAND] ={NA,0xea},
[LONGOFF_X_OPERAND] ={NA,0xda},
[BRACKETED_Y_OPERAND] ={0x90,0xfa},
[SHORTOFF_Y_OPERAND] ={0x90,0xea},
[LONGOFF_Y_OPERAND] ={0x90,0xda},
[SHORTOFF_SP_OPERAND] ={NA,0x1a},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xca},
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xca},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xda},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xda},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xda},
};

CodeInfo orCodeInfo={"or",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, orCodeTable
};


InstructionTable instructionTable[]={
  //assembleAOperandAndComplexOperand
  {"adc",&adcCodeInfo},
  {"add",&addCodeInfo},
  {"and",&andCodeInfo},
  {"bcp",&bcpCodeInfo},
  {"cp",&cpCodeInfo},
  {"exg",&exgCodeInfo},
  {"or",&orCodeInfo},
  //{"sbc",&andCodeInfo},
  //{"xor",&andCodeInfo},
  //{"sub",&bcpCodeInfo},
  //assembleASPOperandAndComplexOperand
  //{"cp",&andCodeInfo},
  //assembleNoOperand
  //.....
  {NULL,NULL}
};

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
    if(operand->dataSize.ls != 65535){
      i++;
    }
    if(operand->dataSize.ms != 65535){
      i++;
    }
    if(operand->dataSize.extB != 65535){
      i++;
    }

    return i;
}

MachineCode* machineCodeAllocateOutput(CodeInfo * codeInfo , stm8Operand *operand ){
  ExtensionCodeAndCode code;
  MachineCode* mcode;
  int a =0;
  code = codeInfo->codeTable[operand->type];
  a = machineCodeLengthFinder(operand,code);
  mcode =malloc(sizeof(MachineCode)+1+ a);
  mcode = outputMachineCode(operand,code,a);
 return mcode;
}

MachineCode* assembleXYSPOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    stm8OperandType type;
    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected ,");
    if(strcasecmp(token->str,"X")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,X_OPERAND);
        type = X_OPERAND;
    }
    else if(strcasecmp(token->str,"Y")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,Y_OPERAND);
        type = Y_OPERAND;
    }
    else if(strcasecmp(token->str,"SP")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,SP_OPERAND);
        type = SP_OPERAND;
    }
    else{
      throwException(ERR_INVALID_STM8_OPERAND,token,"expected X Y SP");
    }
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_INVALID_SYNTAX,token,"Expected ,");
    if(strcmp(token->str,",")==0){
      operand = getOperand(tokenizer ,codeInfo->operandExistenceFlags[1]);
      pushBackToken(tokenizer,(Token*)token);
    }
    else
      throwException(ERR_INVALID_SYNTAX,token,"expected ,");



    token =(IntegerToken*)getToken(tokenizer);
    if(token->str==NULL){
      mcode=machineCodeAllocateOutput(codeInfo , operand );
    }else{
      throwException(ERR_INVALID_SYNTAX,token,"expected nothing after that");
    }
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
    nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected A");
    if(strcasecmp(token->str,"A")==0){
        operandFlagCheck(codeInfo->operandExistenceFlags[0],token,A_OPERAND);
    }
    else{
      throwException(ERR_INVALID_STM8_OPERAND,token,"expected A");
    }
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_INVALID_SYNTAX,token,"Expected ,");
    if(strcmp(token->str,",")==0)
      operand = getOperand(tokenizer ,codeInfo->operandExistenceFlags[1]);
    else
      throwException(ERR_INVALID_SYNTAX,token,"expected ,");

    token =(IntegerToken*)getToken(tokenizer);
    if(token->str==NULL){
      mcode=machineCodeAllocateOutput(codeInfo , operand );
    }else{
      throwException(ERR_INVALID_SYNTAX,token,"expected nothing after that");
    }
    return mcode;
}


MachineCode *assembleInstruction(Tokenizer *tokenizer){
   IntegerToken *token = NULL;
   CodeInfo *codeInfo = NULL;
   MachineCode* mcode = NULL;
   int i =0;
   int a =0;

    //find codeInfo on instructionTable
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*) token);
    if(TOKEN_IDENTIFIER_TYPE != token-> type)
      return NULL;

    do{
      nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected valid name");
      if(strcasecmp(instructionTable[i].name,token->str)==0){
        codeInfo = instructionTable[i].codeInfo;
        break;
      }
      i++;
    }while(instructionTable[i].name != NULL);
    mcode = codeInfo->assembler(codeInfo,tokenizer);

    return mcode ;
}
