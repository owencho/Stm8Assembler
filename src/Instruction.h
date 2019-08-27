#ifndef Instruction_H
#define Instruction_H
#include "Tokenizer.h"
#include "Operand.h"
#include "ArithmeticOperationsInstruction.h"
#include "BitOperationInstruction.h"
#include "BreakPointInstruction.h"
#include "CompareAndTestsInstruction.h"
#include "ConditionalBitTestBranchInstruction.h"
#include "ConditionalBranchExecutionInstruction.h"
#include "ConditionCodeFlagModificationInstruction.h"
#include "IncrementDecrementInstruction.h"
#include "InterruptManagementInstruction.h"
#include "LoadTransferInstruction.h"
#include "LogicalOperationsInstruction.h"
#include "ShiftRotatesInstruction.h"
#include "UnconditionalJumpCallInstruction.h"
#include "StackInstruction.h"



MachineCode *assembleInstruction(Tokenizer *tokenizer);

#define freeMachineCode(mcode)                                      \
                          do{if(mcode) free(mcode);}while(0)



#endif // Instruction_H
