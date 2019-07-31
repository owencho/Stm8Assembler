#include "interruptManagementInstruction.h"

ExtensionCodeAndCode trapCodeTable[] = {
  [NO_OPERAND]         ={NA,0x83}
};

CodeInfo trapCodeInfo={"trap",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, {trapCodeTable,0,0,0,0}
};

ExtensionCodeAndCode wfiCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8f}
};

CodeInfo wfiCodeInfo={"wfi",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, {wfiCodeTable,0,0,0,0}
};

ExtensionCodeAndCode haltCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8e}
};

CodeInfo haltCodeInfo={"halt",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, {haltCodeTable,0,0,0,0}
};

ExtensionCodeAndCode iretCodeTable[] = {
  [NO_OPERAND]         ={NA,0x80}
};

CodeInfo iretCodeInfo={"iret",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, {iretCodeTable,0,0,0,0}
};
