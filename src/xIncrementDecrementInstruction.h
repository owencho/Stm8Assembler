#ifndef IncrementDecrementInstruction_H
#define IncrementDecrementInstruction_H

#include "AssembleAllInstruction.h"
CodeInfo incCodeInfo;
CodeInfo decCodeInfo;
CodeInfo incwCodeInfo;
CodeInfo decwCodeInfo;
#define  INCDEC_SUPPORTED_OPERANDS                       \
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

#define  INCDECWORD_SUPPORTED_OPERANDS                  \
    (1<<X_OPERAND                                 |     \
    1<<Y_OPERAND )
#endif // IncrementDecrementInstruction_H
