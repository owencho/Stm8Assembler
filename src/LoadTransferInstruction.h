#ifndef LoadTransferInstruction_H
#define LoadTransferInstruction_H

#include "AssembleAllInstruction.h"
CodeInfo exgCodeInfo;
CodeInfo ldCodeInfo;
CodeInfo ldfCodeInfo;
CodeInfo ldwCodeInfo;
CodeInfo clrCodeInfo;
CodeInfo movCodeInfo;
CodeInfo clrwCodeInfo;
CodeInfo exgwCodeInfo;

#define  LD1ST_SUPPORTED_OPERANDS                       \
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
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND          |     \
    1<<XL_OPERAND                                 |     \
    1<<YL_OPERAND                                 |     \
    1<<XH_OPERAND                                 |     \
    1<<YH_OPERAND)

#define  LD_A_SUPPORTED_OPERANDS                       \
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

#define  LDF_COMP_SUPPORTED_OPERANDS                    \
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

#define  EXG_SUPPORTED_OPERANDS                       \
    (1<<XL_OPERAND                              |     \
    1<<LONG_MEM_OPERAND                         |     \
    1<<YL_OPERAND)

#define  CLRW_SUPPORTED_OPERANDS                        \
    (1<<X_OPERAND                                    |     \
    1<<Y_OPERAND)

#define  LDW_X_SUPPORTED_OPERANDS                        \
    (1<<WORD_OPERAND                                |     \
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
    1<<Y_OPERAND                                    |     \
    1<<SP_OPERAND)

#define  LDW_Y_SUPPORTED_OPERANDS                         \
    (1<<WORD_OPERAND                                |     \
    1<<SHORT_MEM_OPERAND                            |     \
    1<<LONG_MEM_OPERAND                             |     \
    1<<BRACKETED_Y_OPERAND                          |     \
    1<<SHORTOFF_Y_OPERAND                           |     \
    1<<LONGOFF_Y_OPERAND                            |     \
    1<<SHORTOFF_SP_OPERAND                          |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND             |     \
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND            |     \
    1<<X_OPERAND                                    |     \
    1<<SP_OPERAND)

#define  LDW_XY_SUPPORTED_OPERANDS                         \
    (1<<X_OPERAND                                    |     \
    1<<Y_OPERAND)

#define  CLR_SUPPORTED_OPERANDS                           \
    (1<<A_OPERAND                                   |     \
    1<<SHORT_MEM_OPERAND                            |     \
    1<<LONG_MEM_OPERAND                             |     \
    1<<BRACKETED_X_OPERAND                          |     \
    1<<SHORTOFF_X_OPERAND                           |     \
    1<<LONGOFF_X_OPERAND                            |     \
    1<<BRACKETED_Y_OPERAND                          |     \
    1<<SHORTOFF_Y_OPERAND                           |     \
    1<<LONGOFF_Y_OPERAND                            |     \
    1<<SHORTOFF_SP_OPERAND                          |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND             |     \
    1<<BRACKETED_LONGPTR_DOT_W_OPERAND              |     \
    1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND            |     \
    1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND             |     \
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND)



#endif // LoadTransferInstruction_H
