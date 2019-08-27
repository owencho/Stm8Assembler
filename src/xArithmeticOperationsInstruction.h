#ifndef ArithmeticOperationsInstruction_H
#define ArithmeticOperationsInstruction_H
#include "AssembleAllInstruction.h"
CodeInfo adcCodeInfo;
CodeInfo addCodeInfo;
CodeInfo addwCodeInfo;
CodeInfo subCodeInfo;
CodeInfo divCodeInfo;
CodeInfo subwCodeInfo;
CodeInfo sbcCodeInfo;
CodeInfo negCodeInfo;
CodeInfo mulCodeInfo;
CodeInfo negwCodeInfo;

#define  NEG_SUPPORTED_OPERANDS                         \
    (1<<A_OPERAND                                 |     \
    1<<SHORT_MEM_OPERAND                          |     \
    1<<LONG_MEM_OPERAND                           |     \
    1<<BRACKETED_X_OPERAND                        |     \
    1<<SHORTOFF_X_OPERAND                         |     \
    1<<LONGOFF_X_OPERAND                          |     \
    1<<BRACKETED_Y_OPERAND                        |     \
    1<<SHORTOFF_Y_OPERAND                         |     \
    1<<LONGOFF_Y_OPERAND                          |     \
    1<<SHORTOFF_SP_OPERAND                        |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND           |     \
    1<<BRACKETED_LONGPTR_DOT_W_OPERAND            |     \
    1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND          |     \
    1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND           |     \
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND)

#define  ADC_SUPPORTED_OPERANDS                         \
    (1<<BYTE_OPERAND                              |     \
    1<<SHORT_MEM_OPERAND                          |     \
    1<<LONG_MEM_OPERAND                           |     \
    1<<BRACKETED_X_OPERAND                        |     \
    1<<SHORTOFF_X_OPERAND                         |     \
    1<<LONGOFF_X_OPERAND                          |     \
    1<<BRACKETED_Y_OPERAND                        |     \
    1<<SHORTOFF_Y_OPERAND                         |     \
    1<<LONGOFF_Y_OPERAND                          |     \
    1<<SHORTOFF_SP_OPERAND                        |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND           |     \
    1<<BRACKETED_LONGPTR_DOT_W_OPERAND            |     \
    1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND          |     \
    1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND           |     \
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND)

#define  SUBW_SUPPORTED_OPERANDS                        \
    (1<<WORD_OPERAND                              |     \
    1<<LONG_MEM_OPERAND                           |     \
    1<<SHORTOFF_SP_OPERAND)

#define  ADDW_XY_SUPPORTED_OPERANDS                     \
    (1<<LONG_MEM_OPERAND                          |     \
    1<<WORD_OPERAND                               |     \
    1<<SHORTOFF_SP_OPERAND)



#endif // ArithmeticOperationsInstruction_H
