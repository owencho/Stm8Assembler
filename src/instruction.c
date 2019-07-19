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
[BYTE_OPERAND]         ={NA,0xa9};
[SHORT_MEM_OPERAND]    ={NA,0xb9};
[LONG_MEM_OPERAND]     ={NA,0xc9};
[BRACKETED_X_OPERAND] ={NA,0xf9};
[SHORTOFF_X_OPERAND] ={NA,0xe9};
[LONGOFF_X_OPERAND] ={NA,0xd9};
[BRACKETED_Y_OPERAND] ={0x90,0xf9};
[SHORTOFF_Y_OPERAND] ={0x90,0xe9};
[LONGOFF_Y_OPERAND] ={0x90,0xd9};
[SHORTOFF_SP_OPERAND] ={NA,0x19};
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x91,0xc9};
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc9};
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd9};
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd9};
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd9};
};

CodeInfo* adcCodeInfo={"adc",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, adcCodeTable
};

InstructionTable instructionTable[]={
  {"adc",&adcCodeInfo},
  //{"add",addCodeInfo},
//  {"and",andCodeInfo},
  {NULL,NULL}
};

MachineCode* outputMachineCode(stm8Operand * operand,ExtensionCodeAndCode code, int size){
  MachineCode*mcode = NULL;
  if(code->extCode== NA){
    if(size = 4){
      mcode->code[0] = code->code;
      mcode->code[1] = operand->dataSize.ms;
      mcode->code[2] = operand->dataSize.ls;
      mcode->code[3] = operand->dataSize.extB;
    }
    else if (size = 3){
      mcode->code[0] = code->code;
      mcode->code[1] = operand->dataSize.ms;
      mcode->code[2] = operand->dataSize.ls;
      mcode->code[3] = operand->dataSize.extB;
    }
  }


int machineCodeLengthFinder(stm8Operand * operand,ExtensionCodeAndCode code){
  int i=0;
    if(code->code !=NA){
      i++;
    }
    if(code->extCode !=NA){
      i++;
    }
    if(operand->dataSize.ls != NA){
      i++;
    }
    if(operand->dataSize.ms != NA){
      i++;
    }
    if(operand->dataSize.extB != NA){
      i++;
    }

    return i;
}


MachineCode* assembleAOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    IntegerToken * token;
    IntegerToken * initToken;
    stm8Operand * operand;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    int i =0;
    int a =0;
    int z=0;
    token =(IntegerToken*)getToken(tokenizer);
    initToken = token;
    token =(IntegerToken*)getToken(tokenizer);
    operand = operandHandleFirstSymbol(token, tokenizer ,codeInfo->operandExistenceFlags[0]);
    // detect eg: ,#$55
    token =(IntegerToken*)getToken(tokenizer);
    nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected ,");
    if(strcmp(token->str,",")==0)
      operand = getOperand(tokenizer , codeInfo->operandExistenceFlags[1]);
    else
      //Throw Exception if not ,
    token =(IntegerToken*)getToken(tokenizer);
    if(token->str==NULL){
      code = codeInfo->codeTable[operand->type];
      a = machineCodeLengthFinder(operand,code);
      mcode =malloc(sizeof(MachineCode)+1+ a);







}

/*
MachineCode *assembleInstruction(Tokenizer *tokenizer){
   IntegerToken *token = NULL;
   CodeInfo codeInfo = NULL;
   stm8Operand * operand;
   int i =0;
   int a =0;

    //find codeInfo on instructionTable
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken() here
    if(TOKEN_IDENTIFIER_TYPE != token-> type)
      return NULL;

    do{
      if(strcasecmp(instructionTable[i]->name,token->str)==0){
        codeInfo = instructionTable[i]->codeInfo;
        break;
      }
      i++;
    }while(instructionTable[i]->name != NULL)
    // find if the middle operand is legit on this
    operand = operandHandleFirstSymbol(token, tokenizer ,codeInfo->operandExistenceFlags[0]);
    // detect eg: ,#$55
    nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected ,");
    if(strcmp(token->str,",")==0){
      operand = getOperand(tokenizer , codeInfo->operandExistenceFlags[1]);
    }
    else{
      //Throw Exception if not ,
    }
// find extValue on adcCodeTable
    do{
      if(strcasecmp(instructionTable[i]->name,token->str)==0){
        codeInfo = instructionTable[i]->codeInfo;
        break;
      }
      i++;
    }while(instructionTable[i]->name != NULL)

    token =getToken(tokenizer);
    if(token->str==NULL){
      a = machineCodeLengthFinder(stm8Operand * operand);
      MachineCode* mcode =malloc(sizeof(MachineCode)+1+a);
      mcode -> length = 1+a;

    }

}
*/
