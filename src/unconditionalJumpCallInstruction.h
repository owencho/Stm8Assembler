#ifndef unconditionalJumpCallInstruction_H
#define unconditionalJumpCallInstruction_H
#include "assembleAllInstruction.h"
CodeInfo jraCodeInfo;
CodeInfo jrtCodeInfo;
CodeInfo jrfCodeInfo;
CodeInfo jpCodeInfo;
CodeInfo jpfCodeInfo;
CodeInfo callCodeInfo;
CodeInfo callrCodeInfo;
CodeInfo callfCodeInfo;
CodeInfo retCodeInfo;
CodeInfo retfCodeInfo;
CodeInfo nopCodeInfo;



#define  UNCONJUMP_SUPPORTED_OPERANDS                   \
    (1<<LONG_MEM_OPERAND                          |     \
    1<<BRACKETED_X_OPERAND                        |     \
    1<<SHORTOFF_X_OPERAND                         |     \
    1<<LONGOFF_X_OPERAND                          |     \
    1<<BRACKETED_Y_OPERAND                        |     \
    1<<SHORTOFF_Y_OPERAND                         |     \
    1<<LONGOFF_Y_OPERAND                          |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND           |     \
    1<<BRACKETED_LONGPTR_DOT_W_OPERAND            |     \
    1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND          |     \
    1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND           |     \
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND)

#define  XXF_SUPPORTED_OPERANDS                         \
    (1<<BRACKETED_LONGPTR_DOT_E_OPERAND           |     \
    1<<EXT_MEM_OPERAND)
#endif // unconditionalJumpCallInstruction_H
