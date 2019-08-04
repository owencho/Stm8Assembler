#include "breakPointInstruction.h"

ExtensionCodeAndCode breakCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8b}
};

ConversionData breakFlagTable[]={
{"break",breakCodeTable,0,0},
{NULL,NULL,0,0},
};

CodeInfo breakCodeInfo={"break",0 ,assembleNoOperand,breakFlagTable};
