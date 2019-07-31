#include "unconditionalJumpCallInstruction.h"


ExtensionCodeAndCode callCodeTable[] = {
[LONG_MEM_OPERAND]     ={NA,0xcd},
[BRACKETED_X_OPERAND] ={NA,0xfd},
[SHORTOFF_X_OPERAND] ={NA,0xed},
[LONGOFF_X_OPERAND] ={NA,0xdd},
[BRACKETED_Y_OPERAND] ={0x90,0xfd},
[SHORTOFF_Y_OPERAND] ={0x90,0xed},
[LONGOFF_Y_OPERAND] ={0x90,0xdd},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xcd},
[BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xcd},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xdd},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xdd},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xdd},
};

CodeInfo callCodeInfo={"call",assembleOneOperand,{
    //First operand
    CALL_SUPPORTED_OPERANDS,
    //Second operand
    0,
    //Third operand
    0
  }, {callCodeTable,0,0,0,0}
};
/*
ExtensionCodeAndCode callrCodeTable[] = {
[EXT_MEM_OPERAND]     ={NA,0xcd},
[BRACKETED_X_OPERAND] ={NA,0xfd},

};

CodeInfo callrCodeInfo={"callr",assembleOneOperand,{
    //First operand
    CALL_SUPPORTED_OPERANDS,
    //Second operand
    0,
    //Third operand
    0
  }, {callCodeTable,0,0,0,0}
};
*/
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
  }, {nopCodeTable,0,0,0,0}
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
  }, {retCodeTable,0,0,0,0}
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
  }, {retfCodeTable,0,0,0,0}
};
