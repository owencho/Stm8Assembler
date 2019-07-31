#include "bitOperationInstruction.h"


ExtensionCodeAndCode bccmCodeTable[] = {
[LONG_MEM_OPERAND]     ={0x90,0x10},
};

CodeInfo bccmCodeInfo={"bccm",assembleTwowithNOperand,{
    //First operand
    1 << LONG_MEM_OPERAND,
    //Second operand
    1 <<BYTE_OPERAND,
    //Third operand
    0
  }, {bccmCodeTable,0,0,0,0}
};

ExtensionCodeAndCode bcplCodeTable[] = {
[LONG_MEM_OPERAND]     ={0x90,0x10},
};

CodeInfo bcplCodeInfo={"bcpl",assembleTwowithNOperand,{
    //First operand
    1 << LONG_MEM_OPERAND,
    //Second operand
    1 <<BYTE_OPERAND,
    //Third operand
    0
  }, {bcplCodeTable,0,0,0,0}
};

ExtensionCodeAndCode bresCodeTable[] = {
[LONG_MEM_OPERAND]     ={0x72,0x10},
};

CodeInfo bresCodeInfo={"bres",assembleTwowithNOperand,{
    //First operand
    1 << LONG_MEM_OPERAND,
    //Second operand
    1 <<BYTE_OPERAND,
    //Third operand
    0
    }, {bresCodeTable,0,0,0,0}
};

ExtensionCodeAndCode bsetCodeTable[] = {
[LONG_MEM_OPERAND]     ={0x72,0x10},
};

CodeInfo bsetCodeInfo={"bset",assembleTwowithNOperand,{
    //First operand
    1 << LONG_MEM_OPERAND,
    //Second operand
    1 <<BYTE_OPERAND,
    //Third operand
    0
    }, {bsetCodeTable,0,0,0,0}
};
