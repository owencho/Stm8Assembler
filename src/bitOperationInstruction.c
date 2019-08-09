#include "bitOperationInstruction.h"


ExtensionCodeAndCode bccmCodeTable[] = {
    [LONG_MEM_OPERAND]     ={0x90,0x10},
};

ConversionData bccmFlagTable[]={
    {"COMP",bccmCodeTable,(1 <<BYTE_OPERAND),0},
    {NULL,NULL,0,0},
};

CodeInfo bccmCodeInfo={"bccm",(1 << LONG_MEM_OPERAND),
                      assembleTwowithNOperand,bccmFlagTable};

ExtensionCodeAndCode bcplCodeTable[] = {
    [LONG_MEM_OPERAND]     ={0x90,0x10},
};

ConversionData bcplFlagTable[]={
    {"COMP",bcplCodeTable,(1 <<BYTE_OPERAND),0},
    {NULL,NULL,0,0},
};

CodeInfo bcplCodeInfo={"bcpl",(1 << LONG_MEM_OPERAND),
                      assembleTwowithNOperand,bcplFlagTable};

ExtensionCodeAndCode bresCodeTable[] = {
    [LONG_MEM_OPERAND]     ={0x72,0x10},
};

ConversionData bresFlagTable[]={
    {"COMP",bresCodeTable,(1 <<BYTE_OPERAND),0},
    {NULL,NULL,0,0},
};

CodeInfo bresCodeInfo={"bres",(1 << LONG_MEM_OPERAND),
                      assembleTwowithNOperand,bresFlagTable};

ExtensionCodeAndCode bsetCodeTable[] = {
    [LONG_MEM_OPERAND]     ={0x72,0x10},
};

ConversionData bsetFlagTable[]={
    {"COMP",bsetCodeTable,(1 <<BYTE_OPERAND),0},
    {NULL,NULL,0,0},
};

CodeInfo bsetCodeInfo={"bset",(1 << LONG_MEM_OPERAND),
                      assembleTwowithNOperand,bsetFlagTable};
