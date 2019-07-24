#include "conditionCodeFlagModificationInstruction.h"

ExtensionCodeAndCode ccfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8c}
};

CodeInfo ccfCodeInfo={"ccf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, ccfCodeTable
};

ExtensionCodeAndCode rcfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x98}
};

CodeInfo rcfCodeInfo={"rcf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, rcfCodeTable
};

ExtensionCodeAndCode rimCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9a}
};

CodeInfo rimCodeInfo={"rim",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, rimCodeTable
};

ExtensionCodeAndCode simCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9b}
};

CodeInfo simCodeInfo={"sim",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, simCodeTable
};

ExtensionCodeAndCode rvfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9c}
};

CodeInfo rvfCodeInfo={"rvf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, rvfCodeTable
};

ExtensionCodeAndCode scfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x99}
};

CodeInfo scfCodeInfo={"scf",assembleNoOperand,{
    //First operand
    0 ,
    //Second operand
    0,
    //Third operand
    0
  }, scfCodeTable
};
