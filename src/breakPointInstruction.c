#include "breakPointInstruction.h"

ExtensionCodeAndCode breakCodeTable[] = {
    [NO_OPERAND]         ={NA,0x8b}
};

ConversionData breakFlagTable[]={
    {NO_OPERAND,breakCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo breakCodeInfo={"break",0 ,assembleNoOperand,breakFlagTable};
