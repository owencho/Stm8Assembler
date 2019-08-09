#include "conditionalBitTestBranchInstruction.h"

ExtensionCodeAndCode btjXCodeTable[] = {
    [LONG_MEM_OPERAND]         ={0x72,0x00},

};

ConversionData btjXFlagTable[]={
    {"COMP", btjXCodeTable,(1<<BYTE_OPERAND),(1<<SHORT_OFF_OPERAND)},
    {NULL,NULL,0,0},
};

CodeInfo btjtCodeInfo={"btjt",(1 << LONG_MEM_OPERAND),
                      assembleBTJXOperand,btjXFlagTable};

CodeInfo btjfCodeInfo={"btjf",(1 << LONG_MEM_OPERAND),
                      assembleBTJXOperand,btjXFlagTable};
