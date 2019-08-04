#include "mcode.h"
#include "operand.h"
#ifndef AssembleAllInstruction_H
#define AssembleAllInstruction_H


#define NA      -1
#define ALL_OPERANDS -1



#define  EXG_SUPPORTED_OPERANDS                       \
    (1<<XL_OPERAND                              |     \
    1<<LONG_MEM_OPERAND                         |     \
    1<<YL_OPERAND)


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

#define  LDW_Y_SUPPORTED_OPERANDS                        \
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

#define  LDW_SP_SUPPORTED_OPERANDS                        \
    (1<<X_OPERAND                                    |     \
    1<<Y_OPERAND)

ConversionData  getDataFlag(CodeInfo *codeInfo,Tokenizer* tokenizer);
stm8Operand * complexOperandReturn(Tokenizer* tokenizer ,ConversionData  dataFlag);
MachineCode* outputMachineCode(stm8Operand * operand,ExtensionCodeAndCode code, int length);
int machineCodeLengthFinder(stm8Operand * operand,ExtensionCodeAndCode code);
MachineCode* machineCodeAllocateOutput(Tokenizer* tokenizer,ConversionData  dataFlag , stm8Operand *operand, int nvalue);
MachineCode* assembleOneOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleXYOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleXOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleAOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleASPComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleXYSPComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleNoOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleTwowithNOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);




#endif // AssembleAllInstruction_H
