#include "BreakPointInstruction.h"

ExtensionCodeAndCode breakCodeTable[] = {
    [NO_OPERAND]         ={NA,0x8b}
};

ConversionData breakFlagTable[]={
    {NO_OPERAND,breakCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo breakCodeInfo={"break",0 ,assembleNoOperand,breakFlagTable};
