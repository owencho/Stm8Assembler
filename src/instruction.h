#include "Tokenizer.h"
#include "operand.h"
#include "arithmeticOperationsInstruction.h"
#include "bitOperationInstruction.h"
#include "breakPointInstruction.h"
#include "compareAndTestsInstruction.h"
#include "conditionalBitTestBranchInstruction.h"
#include "conditionalBranchExecutionInstruction.h"
#include "conditionCodeFlagModificationInstruction.h"
#include "incrementDecrementInstruction.h"
#include "interruptManagementInstruction.h"
#include "loadTransferInstruction.h"
#include "logicalOperationsInstruction.h"
#include "shiftRotatesInstruction.h"
#include "unconditionalJumpCallInstruction.h"
#include "stackInstruction.h"
#ifndef instruction_H
#define instruction_H


MachineCode *assembleInstruction(Tokenizer *tokenizer);

#define freeMachineCode(mcode)                                      \
                          do{if(mcode) free(mcode);}while(0)



#endif // instruction_H
