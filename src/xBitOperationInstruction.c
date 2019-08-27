#include "BitOperationInstruction.h"


ExtensionCodeAndCode bccmCodeTable[] = {
    [LONG_MEM_OPERAND]     ={0x90,0x10},
};

ConversionData bccmFlagTable[]={
    {LONG_MEM_OPERAND,bccmCodeTable,(1 <<BYTE_OPERAND),0},
    {0,NULL,0,0},
};

CodeInfo bccmCodeInfo={"bccm",(1 << LONG_MEM_OPERAND),
                      assembleTwoComplexOperand,bccmFlagTable};

ExtensionCodeAndCode bcplCodeTable[] = {
    [LONG_MEM_OPERAND]     ={0x90,0x10},
};

ConversionData bcplFlagTable[]={
    {LONG_MEM_OPERAND,bcplCodeTable,(1 <<BYTE_OPERAND),0},
    {0,NULL,0,0},
};

CodeInfo bcplCodeInfo={"bcpl",(1 << LONG_MEM_OPERAND),
                      assembleTwoComplexOperand,bcplFlagTable};

ExtensionCodeAndCode bresCodeTable[] = {
    [LONG_MEM_OPERAND]     ={0x72,0x10},
};

ConversionData bresFlagTable[]={
    {LONG_MEM_OPERAND,bresCodeTable,(1 <<BYTE_OPERAND),0},
    {0,NULL,0,0},
};

CodeInfo bresCodeInfo={"bres",(1 << LONG_MEM_OPERAND),
                      assembleTwoComplexOperand,bresFlagTable};

ExtensionCodeAndCode bsetCodeTable[] = {
    [LONG_MEM_OPERAND]     ={0x72,0x10},
};

ConversionData bsetFlagTable[]={
    {LONG_MEM_OPERAND,bsetCodeTable,(1 <<BYTE_OPERAND),0},
    {0,NULL,0,0},
};

CodeInfo bsetCodeInfo={"bset",(1 << LONG_MEM_OPERAND),
                      assembleTwoComplexOperand,bsetFlagTable};
