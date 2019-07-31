#include "shiftRotatesInstruction.h"

ExtensionCodeAndCode sllwCodeTable[] = {
[X_OPERAND]         ={NA,0x58},
[Y_OPERAND]         ={0x90,0x58},
};

CodeInfo sllwCodeInfo={"sllw",assembleOneOperand,{
    //First operand
    1 << X_OPERAND | 1<< Y_OPERAND,
    //Second operand
    0,
    //Third operand
    0
  }, {sllwCodeTable,0,0,0,0}
};

ExtensionCodeAndCode slawCodeTable[] = {
[X_OPERAND]         ={NA,0x58},
[Y_OPERAND]         ={0x90,0x58},
};

CodeInfo slawCodeInfo={"slaw",assembleOneOperand,{
    //First operand
    1 << X_OPERAND | 1<< Y_OPERAND,
    //Second operand
    0,
    //Third operand
    0
  }, {slawCodeTable,0,0,0,0}
};
