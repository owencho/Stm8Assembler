#ifndef stackInstruction_H
#define stackInstruction_H

#include "assembleAllInstruction.h"

ExtensionCodeAndCode pushCodeTable[] = {
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

CodeInfo adCodeInfo={"adc",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND,
    //Second operand
    ADC_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, adcCodeTable
};
#endif // stackInstruction_H
