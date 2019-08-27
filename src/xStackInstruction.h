#ifndef StackInstruction_H
#define StackInstruction_H

#include "AssembleAllInstruction.h"

#define  PUSH_SUPPORTED_OPERANDS                        \
    (1<<A_OPERAND                                 |     \
    1<<CC_OPERAND                                 |     \
    1<<BYTE_OPERAND                               |     \
    1<<LONG_MEM_OPERAND)

#define  POP_SUPPORTED_OPERANDS                        \
    (1<<A_OPERAND                                 |     \
    1<<CC_OPERAND                                 |     \
    1<<LONG_MEM_OPERAND)

#define  STACKWORD_SUPPORTED_OPERANDS                  \
    (1<<X_OPERAND                                 |     \
    1<<Y_OPERAND )

CodeInfo pushCodeInfo;
CodeInfo popCodeInfo;
CodeInfo pushwCodeInfo;
CodeInfo popwCodeInfo;


#endif // StackInstruction_H
