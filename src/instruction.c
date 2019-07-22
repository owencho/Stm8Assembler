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

ExtensionCodeAndCode sbcCodeTable[] = {
[BYTE_OPERAND]         ={NA,0xa2},
[SHORT_MEM_OPERAND]    ={NA,0xb2},
[LONG_MEM_OPERAND]     ={NA,0xc2},
[BRACKETED_X_OPERAND] ={NA,0xf2},
[SHORTOFF_X_OPERAND] ={NA,0xe2},
[LONGOFF_X_OPERAND] ={NA,0xd2},
[BRACKETED_Y_OPERAND] ={0x90,0xf2},
[SHORTOFF_Y_OPERAND] ={0x90,0xe2},
[LONGOFF_Y_OPERAND] ={0x90,0xd2},
[SHORTOFF_SP_OPERAND] ={NA,0x12},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc2},
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc2},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd2},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd2},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd2},
};

CodeInfo sbcCodeInfo={"sbc",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, sbcCodeTable
};

ExtensionCodeAndCode xorCodeTable[] = {
[BYTE_OPERAND]         ={NA,0xa8},
[SHORT_MEM_OPERAND]    ={NA,0xb8},
[LONG_MEM_OPERAND]     ={NA,0xc8},
[BRACKETED_X_OPERAND] ={NA,0xf8},
[SHORTOFF_X_OPERAND] ={NA,0xe8},
[LONGOFF_X_OPERAND] ={NA,0xd8},
[BRACKETED_Y_OPERAND] ={0x90,0xf8},
[SHORTOFF_Y_OPERAND] ={0x90,0xe8},
[LONGOFF_Y_OPERAND] ={0x90,0xd8},
[SHORTOFF_SP_OPERAND] ={NA,0x18},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc8},
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc8},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd8},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd8},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd8},
};

CodeInfo xorCodeInfo={"xor",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, xorCodeTable
};

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

CodeInfo addwCodeInfo={"addw",assembleAddwOperand,{
    //First operand
    1 << X_OPERAND | 1<< SP_OPERAND | 1 << Y_OPERAND ,
    //Second operand
    0,
    //Third operand
    0
  }, NULL
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


CodeInfo subCodeInfo={"sub",assembleSubOperand,{
    //First operand
    1 << A_OPERAND | 1<< SP_OPERAND ,
    //Second operand
    0,
    //Third operand
    0
  }, NULL
};

//


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

CodeInfo cpwCodeInfo={"cpw",assembleCPWOperand,{
    //First operand
    1 << X_OPERAND | 1<< Y_OPERAND ,
    //Second operand
    0,
    //Third operand
    0
  }, NULL
};


ExtensionCodeAndCode divXCodeTable[] = {
  [A_OPERAND]    ={NA,0x62},
};

ExtensionCodeAndCode divYCodeTable[] = {
  [A_OPERAND]    ={0x90,0x62}
};
CodeInfo divCodeInfo={"div",assembleDivOperand,{
    //First operand
    1 << X_OPERAND | 1<< Y_OPERAND ,
    //Second operand
    1 << A_OPERAND,
    //Third operand
    0
  }, NULL
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

CodeInfo subwCodeInfo={"subw",assembleSubWOperand,{
    //First operand
    1 << X_OPERAND | 1<< Y_OPERAND ,
    //Second operand
    SUBW_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, NULL
};

/////////////////////NO OPERAND
ExtensionCodeAndCode breakCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8b}
};

CodeInfo breakCodeInfo={"break",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, breakCodeTable
};

ExtensionCodeAndCode ccfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8c}
};

CodeInfo ccfCodeInfo={"ccf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, ccfCodeTable
};

ExtensionCodeAndCode haltCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8e}
};

CodeInfo haltCodeInfo={"halt",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, haltCodeTable
};

ExtensionCodeAndCode iretCodeTable[] = {
  [NO_OPERAND]         ={NA,0x80}
};

CodeInfo iretCodeInfo={"iret",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, iretCodeTable
};

ExtensionCodeAndCode nopCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9d}
};

CodeInfo nopCodeInfo={"nop",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, nopCodeTable
};

ExtensionCodeAndCode rcfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x98}
};

CodeInfo rcfCodeInfo={"rcf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, rcfCodeTable
};

ExtensionCodeAndCode retCodeTable[] = {
  [NO_OPERAND]         ={NA,0x81}
};

CodeInfo retCodeInfo={"ret",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, retCodeTable
};

ExtensionCodeAndCode retfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x87}
};

CodeInfo retfCodeInfo={"retf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, retfCodeTable
};

ExtensionCodeAndCode rimCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9a}
};

CodeInfo rimCodeInfo={"rim",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, rimCodeTable
};

ExtensionCodeAndCode rvfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9c}
};

CodeInfo rvfCodeInfo={"rvf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, rvfCodeTable
};

ExtensionCodeAndCode scfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x99}
};

CodeInfo scfCodeInfo={"scf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, scfCodeTable
};

ExtensionCodeAndCode simCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9b}
};

CodeInfo simCodeInfo={"sim",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, simCodeTable
};

ExtensionCodeAndCode trapCodeTable[] = {
  [NO_OPERAND]         ={NA,0x83}
};

CodeInfo trapCodeInfo={"trap",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, trapCodeTable
};

ExtensionCodeAndCode wfeCodeTable[] = {
  [NO_OPERAND]         ={0x72,0x8f}
};

CodeInfo wfeCodeInfo={"wfe",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, wfeCodeTable
};

ExtensionCodeAndCode wfiCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8f}
};

CodeInfo wfiCodeInfo={"wfi",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, wfiCodeTable
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
  {"sbc",&sbcCodeInfo},
  {"xor",&xorCodeInfo},
  //assembleASPOperandAndComplexOperand
  {"sub",&subCodeInfo},
  //assembleXYSPOperandAndComplexOperand
  {"addw",&addwCodeInfo},
  //assembleXYOperandAndComplexOperand
  {"cpw",&cpwCodeInfo},
  {"div",&divCodeInfo},
  {"subw",&subwCodeInfo},
  //assembleNoOperand
  {"break",&breakCodeInfo},
  {"ccf",&ccfCodeInfo},
  {"halt",&haltCodeInfo},
  {"iret",&iretCodeInfo},
  {"nop",&nopCodeInfo},
  {"rcf",&rcfCodeInfo},
  {"ret",&retCodeInfo},
  {"retf",&retfCodeInfo},
  {"rim",&rimCodeInfo},
  {"rvf",&rvfCodeInfo},
  {"scf",&scfCodeInfo},
  {"sim",&simCodeInfo},
  {"trap",&trapCodeInfo},
  {"wfe",&wfeCodeInfo},
  {"wfi",&wfiCodeInfo},
  {NULL,NULL}
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
        mcode = codeInfo->assembler(codeInfo,tokenizer);
        break;
      }
      i++;
    }while(instructionTable[i].name != NULL);


    return mcode ;
}
