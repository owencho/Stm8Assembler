#include "breakPointInstruction.h"

ExtensionCodeAndCode breakCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8b}
};

CodeInfo breakCodeInfo={"break",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, breakCodeTable
};
