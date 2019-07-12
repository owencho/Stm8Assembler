void nullCheck(int errorCode, IntegerToken* token , char *message)
void operandFlagCheck(uint32_t flags, IntegerToken* token ,stm8OperandType type)
int OperandCheck(IntegerToken* token, int condition)
int valueCheck(IntegerToken* token)
stm8Operand *createOperand( stm8OperandType type,
  uint16_t code,
  uint16_t ms,
  uint16_t ls,
  uint16_t extB)

  stm8Operand *createLsOperand( stm8OperandType type,
      int value,
      IntegerToken *token)

  stm8Operand *createMsOperand( stm8OperandType type,
          int value,
          IntegerToken *token)

  stm8Operand *operandHandleFirstSymbol(IntegerToken *token, Tokenizer* tokenizer ,uint32_t flags)

  stm8Operand *comparingLastOperand(uint32_t flags,IntegerToken* token,Tokenizer* tokenizer , int value, int valueCount , int squarecount)

  stm8Operand *operandHandleSquareBracket( Tokenizer *tokenizer ,uint32_t flags)

  stm8Operand *operandHandleRoundBracket( Tokenizer *tokenizer , uint32_t flags)
