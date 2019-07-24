#include "unconditionalJumpCallInstruction.h"

ExtensionCodeAndCode nopCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9d}
};

CodeInfo nopCodeInfo={"nop",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, nopCodeTable
};


ExtensionCodeAndCode retCodeTable[] = {
  [NO_OPERAND]         ={NA,0x81}
};

CodeInfo retCodeInfo={"ret",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, retCodeTable
};

ExtensionCodeAndCode retfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x87}
};

CodeInfo retfCodeInfo={"retf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, retfCodeTable
};
