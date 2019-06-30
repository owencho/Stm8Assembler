#include "Tokenizer.h"
#ifndef _OPERAND_H
#define _OPERAND_H

typedef struct stm8Operand stm8Operand ;


#define NA      -1      //used for opcode below

typedef enum {
  A_OPERAND,
  BYTE_OPERAND,
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

stm8Operand *getOperand(Tokenizer *tokenizer); //maincode
int squareBracketCheck(char * str);
int roundBracketCheck(char * str);

#endif
