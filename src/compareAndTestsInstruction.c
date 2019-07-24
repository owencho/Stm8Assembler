#include "compareAndTestsInstruction.h"

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


CodeInfo cpwCodeInfo={"cpw",assembleCPWOperand,{
    //First operand
    1 << X_OPERAND | 1<< Y_OPERAND ,
    //Second operand
    0,
    //Third operand
    0
  }, NULL
};
