#include "loadTransferInstruction.h"
ExtensionCodeAndCode exgCodeTable[] = {
[XL_OPERAND]         ={NA,0x41},
[YL_OPERAND]         ={NA,0x61},
[LONG_MEM_OPERAND]   ={NA,0x31},
};

CodeInfo exgCodeInfo={"exg",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    EXG_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, exgCodeTable
};
