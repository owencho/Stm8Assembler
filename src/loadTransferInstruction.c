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


CodeInfo ldCodeInfo={"ld",assembleLDOperand,{
    //First operand
    LD1ST_SUPPORTED_OPERANDS,
    //Second operand
    LD2ND_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, NULL
};

CodeInfo ldfCodeInfo={"ldf",assembleLDFOperand,{
    //First operand
    LDF_SUPPORTED_OPERANDS,
    //Second operand
    LDF_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, NULL
};

CodeInfo ldwCodeInfo={"ldw",assembleLDWOperand,{
    //First operand
    LDW_1ST_SUPPORTED_OPERANDS,
    //Second operand
    0,
    //Third operand
    0
  }, NULL
};
