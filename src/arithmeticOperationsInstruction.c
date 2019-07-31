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
  }, {adcCodeTable ,0,0,0,0}
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
  }, {addCodeTable,0,0,0,0}
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
  }, {addwXCodeTable,addwYCodeTable,addwSPCodeTable,0,0}
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
  }, {subACodeTable,subSPCodeTable,0,0,0}
};
ExtensionCodeAndCode divXCodeTable[] = {
    [A_OPERAND]    ={NA,0x62}
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
  }, {divXCodeTable,divYCodeTable,0,0,0}
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
  },{subwXCodeTable,subwYCodeTable,0,0,0}
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
  }, {sbcCodeTable,0,0,0,0}
};
