#include "Tokenizer.h"
#ifndef instruction_H
#define instruction_H

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

#define  ADDW_SUPPORTED_OPERANDS                        \
    (1<<BYTE_OPERAND                              |     \
    1<<LONG_MEM_OPERAND                           |     \
    1<<WORD_OPERAND                               |     \
    1<<SHORTOFF_SP_OPERAND)





typedef struct InstructionTable InstructionTable;
typedef struct MachineCode MachineCode;
typedef struct CodeInfo CodeInfo;
typedef struct ExtensionCodeAndCode ExtensionCodeAndCode;
typedef  MachineCode*(*Assembler)(CodeInfo *CodeInfo , Tokenizer *tokenizer);


MachineCode* assembleAOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);


struct MachineCode{
  uint8_t length;
  uint8_t code[0];
};

struct ExtensionCodeAndCode{
  uint16_t extCode;
  uint16_t code;
};

struct CodeInfo{
  char* name;
  Assembler assembler;
  uint32_t operandExistenceFlags[3];
  ExtensionCodeAndCode *codeTable;
};

struct InstructionTable{
  char* name;
  CodeInfo *codeInfo;
};

#define freeMachineCode(mcode)                                      \
                          do{if(mcode) free(mcode);}while(0)








#endif // instruction_H
