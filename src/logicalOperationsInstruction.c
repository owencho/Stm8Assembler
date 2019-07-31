#include "logicalOperationsInstruction.h"

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
  }, {andCodeTable,0,0,0,0}
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
  }, {orCodeTable,0,0,0,0}
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
  }, {xorCodeTable,0,0,0,0}
};
