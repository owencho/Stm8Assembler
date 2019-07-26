#include "mcode.h"
#include "operand.h"
#ifndef AssembleAllInstruction_H
#define AssembleAllInstruction_H


#define NA      -1
#define ALL_OPERANDS -1

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

#define  CPW_X_SUPPORTED_OPERANDS                       \
    (1<<WORD_OPERAND                              |     \
    1<<SHORT_MEM_OPERAND                          |     \
    1<<LONG_MEM_OPERAND                           |     \
    1<<BRACKETED_Y_OPERAND                        |     \
    1<<SHORTOFF_Y_OPERAND                         |     \
    1<<LONGOFF_Y_OPERAND                          |     \
    1<<SHORTOFF_SP_OPERAND                        |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND           |     \
    1<<BRACKETED_LONGPTR_DOT_W_OPERAND            |     \
    1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND)

#define  CPW_Y_SUPPORTED_OPERANDS                       \
    (1<<WORD_OPERAND                              |     \
    1<<SHORT_MEM_OPERAND                          |     \
    1<<LONG_MEM_OPERAND                           |     \
    1<<BRACKETED_X_OPERAND                        |     \
    1<<SHORTOFF_X_OPERAND                         |     \
    1<<LONGOFF_X_OPERAND                          |     \
    1<<BRACKETED_SHORTPTR_DOT_W_OPERAND           |     \
    1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND          |     \
    1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND)


#define  ADDW_XY_SUPPORTED_OPERANDS                     \
    (1<<LONG_MEM_OPERAND                          |     \
    1<<WORD_OPERAND                               |     \
    1<<SHORTOFF_SP_OPERAND)

#define  EXG_SUPPORTED_OPERANDS                       \
    (1<<XL_OPERAND                              |     \
    1<<LONG_MEM_OPERAND                         |     \
    1<<YL_OPERAND)

#define  SUBW_SUPPORTED_OPERANDS                        \
    (1<<WORD_OPERAND                              |     \
    1<<LONG_MEM_OPERAND                           |     \
    1<<SHORTOFF_SP_OPERAND)

stm8Operand * complexOperandReturn(Tokenizer* tokenizer ,CodeInfo * codeInfo);
MachineCode* outputMachineCode(stm8Operand * operand,ExtensionCodeAndCode code, int length);
int machineCodeLengthFinder(stm8Operand * operand,ExtensionCodeAndCode code);
MachineCode* machineCodeAllocateOutput(Tokenizer* tokenizer,CodeInfo * codeInfo , stm8Operand *operand);
MachineCode* assembleNoOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleOneOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleAOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleXOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleSubOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleAddwOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleCPWOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleDivOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleSubWOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);

#endif // AssembleAllInstruction_H
