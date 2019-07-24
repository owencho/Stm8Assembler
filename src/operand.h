#include "Tokenizer.h"
#ifndef _OPERAND_H
#define _OPERAND_H

typedef struct stm8Operand stm8Operand ;


#define NA      -1      //used for opcode below
#define ALL_OPERANDS -1

typedef enum {
  NO_OPERAND,
  A_OPERAND,
  BYTE_OPERAND,
  WORD_OPERAND,
  EXT_MEM_OPERAND,
  SHORT_MEM_OPERAND,
  LONG_MEM_OPERAND,
  BRACKETED_X_OPERAND,
  SHORTOFF_X_OPERAND,
  LONGOFF_X_OPERAND,
  BRACKETED_Y_OPERAND,
  SHORTOFF_Y_OPERAND,
  LONGOFF_Y_OPERAND,
  SHORTOFF_SP_OPERAND,
  BRACKETED_SHORTPTR_DOT_W_OPERAND,
  BRACKETED_LONGPTR_DOT_W_OPERAND,
  SHORTPTR_DOT_W_BRACKETEDX_OPERAND,
  LONGPTR_DOT_W_BRACKETEDX_OPERAND,
  SHORTPTR_DOT_W_BRACKETEDY_OPERAND,
  X_OPERAND,
  Y_OPERAND,
  XL_OPERAND,
  YL_OPERAND,
  SP_OPERAND
} stm8OperandType ;


typedef struct Opcode Opcode ;
struct Opcode{
  uint16_t extCode;
  uint16_t code;
  uint16_t ms;
  uint16_t ls;
  uint16_t extB;

};

struct stm8Operand {       //struct for stm8operand
  stm8OperandType type;
  Opcode dataSize;

};

#define isOperandNeeded(flag,op)                          \
                          ((flag) & (1 << (op)))


stm8Operand *createOperand( stm8OperandType type,
                            uint16_t extCode,
                            uint16_t code,
                            uint16_t ms,
                            uint16_t ls,
                            uint16_t extB);
stm8Operand *getOperand(Tokenizer *tokenizer ,  uint32_t flags); //maincode
void nullCheck(int errorCode, IntegerToken* token , char *message);
void operandFlagCheck(uint32_t flags, IntegerToken* token ,stm8OperandType type);
stm8Operand *operandHandleFirstSymbol(Tokenizer* tokenizer ,uint32_t flags);
int operandCheck(IntegerToken* token, int condition);
int valueCheck(IntegerToken* token);

#endif
