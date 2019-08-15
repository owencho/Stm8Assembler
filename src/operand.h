#ifndef _OPERAND_H
#define _OPERAND_H
#include "Tokenizer.h"
typedef struct stm8Operand stm8Operand ;


   //used for opcode below
#define ALL_OPERANDS -1
//#define

typedef enum {
    A_OPERAND,
    BYTE_OPERAND,
    WORD_OPERAND,
    EXT_MEM_OPERAND,
    SHORT_MEM_OPERAND,
    LONG_MEM_OPERAND,
    SHORT_OFF_OPERAND,
    BRACKETED_X_OPERAND,
    SHORTOFF_X_OPERAND,
    LONGOFF_X_OPERAND,
    EXTOFF_X_OPERAND,
    BRACKETED_Y_OPERAND,
    SHORTOFF_Y_OPERAND,
    LONGOFF_Y_OPERAND,
    EXTOFF_Y_OPERAND,
    SHORTOFF_SP_OPERAND,
    BRACKETED_SHORTPTR_DOT_W_OPERAND,
    BRACKETED_LONGPTR_DOT_W_OPERAND,
    BRACKETED_LONGPTR_DOT_E_OPERAND,
    SHORTPTR_DOT_W_BRACKETEDX_OPERAND,
    LONGPTR_DOT_W_BRACKETEDX_OPERAND,
    SHORTPTR_DOT_W_BRACKETEDY_OPERAND,
    LONGPTR_DOT_E_BRACKETEDX_OPERAND,
    LONGPTR_DOT_E_BRACKETEDY_OPERAND,
    SP_OPERAND,
    X_OPERAND,
    Y_OPERAND,
    XL_OPERAND,
    YL_OPERAND,
    XH_OPERAND,
    YH_OPERAND,
    CC_OPERAND,
    NO_OPERAND,
    NO_TABLE_OPERAND,
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
stm8Operand *createLsOperand( stm8OperandType type,
                              int value,
                              IntegerToken *token);
stm8Operand *createMsOperand( stm8OperandType type,
                              int value,
                              IntegerToken *token);
stm8Operand *createExtMemOperand( stm8OperandType type,
                                  int value,
                                  IntegerToken *token);

stm8Operand *getOperand(Tokenizer *tokenizer ,  uint64_t flags); //maincode
void nullCheck(int errorCode, IntegerToken* token , char *message);
void operandFlagCheck(uint64_t flags, IntegerToken* token ,stm8OperandType type);
void squareBracketFlagCheck(IntegerToken *token, stm8Operand * operand ,uint64_t flags);
IntegerToken* extendTokenStr(IntegerToken *tokenToExtend , IntegerToken *tokenToCover );
stm8Operand *operandHandleFirstSymbol(Tokenizer* tokenizer ,uint64_t flags);
stm8Operand *operandHandleValue(Tokenizer* tokenizer ,uint64_t flags);
stm8Operand *operandHandleHash(Tokenizer* tokenizer ,uint64_t flags);
stm8Operand *operandHandleSquareBracket( Tokenizer *tokenizer ,uint64_t flags);
int operandCheck(IntegerToken* token, int condition);
int valueCheck(IntegerToken* token);
int signedIntCheck(Tokenizer *tokenizer);
stm8OperandType symbolOperandCheck(IntegerToken * token);

#endif
