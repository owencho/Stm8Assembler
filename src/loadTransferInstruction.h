#ifndef loadTransferInstruction_H
#define loadTransferInstruction_H

#include "assembleAllInstruction.h"
CodeInfo exgCodeInfo;
CodeInfo ldCodeInfo;
CodeInfo ldfCodeInfo;
CodeInfo ldwCodeInfo;


#define  LD1ST_SUPPORTED_OPERANDS                       \
    (1<<A_OPERAND                                 |     \
    1<<SHORT_MEM_OPERAND                          |     \
    1<<LONG_MEM_OPERAND                           |     \
    1<<BRACKETED_X_OPERAND                        |     \
    1<<SHORTOFF_X_OPERAND                         |     \
    1<<BRACKETED_Y_OPERAND                        |     \
    1<<SHORTOFF_Y_OPERAND                         |     \
    1<<LONGOFF_Y_OPERAND                          |     \
    1<<SHORTOFF_SP_OPERAND                        |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND           |     \
    1<<BRACKETED_LONGPTR_DOT_W_OPERAND            |     \
    1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND          |     \
    1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND           |     \
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND          |     \
    1<<XL_OPERAND                                 |     \
    1<<YL_OPERAND                                 |     \
    1<<XH_OPERAND                                 |     \
    1<<YH_OPERAND)

#define  LD2ND_SUPPORTED_OPERANDS                       \
    (1<<A_OPERAND                                 |     \
    1<<BYTE_OPERAND                               |     \
    1<<SHORT_MEM_OPERAND                          |     \
    1<<LONG_MEM_OPERAND                           |     \
    1<<BRACKETED_X_OPERAND                        |     \
    1<<SHORTOFF_X_OPERAND                         |     \
    1<<BRACKETED_Y_OPERAND                        |     \
    1<<SHORTOFF_Y_OPERAND                         |     \
    1<<LONGOFF_Y_OPERAND                          |     \
    1<<SHORTOFF_SP_OPERAND                        |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND           |     \
    1<<BRACKETED_LONGPTR_DOT_W_OPERAND            |     \
    1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND          |     \
    1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND           |     \
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND          |     \
    1<<XL_OPERAND                                 |     \
    1<<YL_OPERAND                                 |     \
    1<<XH_OPERAND                                 |     \
    1<<YH_OPERAND)

#define  LDF_SUPPORTED_OPERANDS                         \
    (1<<A_OPERAND                                 |     \
    1<<EXT_MEM_OPERAND                            |     \
    1<<EXTOFF_X_OPERAND                           |     \
    1<<EXTOFF_Y_OPERAND                           |     \
    1<<LONGPTR_DOT_E_BRACKETEDX_OPERAND           |     \
    1<<LONGPTR_DOT_E_BRACKETEDY_OPERAND           |     \
    1<<BRACKETED_LONGPTR_DOT_E_OPERAND)

#define  LDW_1ST_SUPPORTED_OPERANDS                        \
    (1<<X_OPERAND                                   |     \
    1<<Y_OPERAND                                    |     \
    1<<SHORT_MEM_OPERAND                            |     \
    1<<LONG_MEM_OPERAND                             |     \
    1<<BRACKETED_X_OPERAND                          |     \
    1<<SHORTOFF_X_OPERAND                           |     \
    1<<LONGOFF_X_OPERAND                            |     \
    1<<SHORTOFF_SP_OPERAND                          |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND             |     \
    1<<BRACKETED_LONGPTR_DOT_W_OPERAND              |     \
    1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND            |     \
    1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND             |     \
    1<<BRACKETED_Y_OPERAND                          |     \
    1<<SHORTOFF_Y_OPERAND                           |     \
    1<<LONGOFF_Y_OPERAND                            |     \
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND            |     \
    1<<SP_OPERAND)



#endif // loadTransferInstruction_H
