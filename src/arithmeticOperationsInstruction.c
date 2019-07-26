#include "arithmeticOperationsInstruction.h"

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

CodeInfo addwCodeInfo={"addw",assembleAddwOperand,{
    //First operand
    1 << X_OPERAND | 1<< SP_OPERAND | 1 << Y_OPERAND ,
    //Second operand
    0,
    //Third operand
    0
  }, NULL
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

CodeInfo divCodeInfo={"div",assembleDivOperand,{
    //First operand
    1 << X_OPERAND | 1<< Y_OPERAND ,
    //Second operand
    1 << A_OPERAND,
    //Third operand
    0
  }, NULL
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
