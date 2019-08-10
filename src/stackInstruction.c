#include "stackInstruction.h"

ExtensionCodeAndCode pushCodeTable[] = {
    [A_OPERAND]         ={NA,0x88},
    [CC_OPERAND]        ={NA,0x8a},
    [BYTE_OPERAND]      ={NA,0x4B},
    [LONG_MEM_OPERAND]  ={NA,0x3B},
};

ConversionData pushFlagTable[]={
    {"A",pushCodeTable,0,0},
    {"CC",pushCodeTable,0,0},
    {"COMP",pushCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo pushCodeInfo={"push",PUSH_SUPPORTED_OPERANDS,
                        assembleOneOperand,pushFlagTable};

ExtensionCodeAndCode popCodeTable[] = {
    [A_OPERAND]         ={NA,0x84},
    [CC_OPERAND]        ={NA,0x86},
    [LONG_MEM_OPERAND]  ={NA,0x32},
};

ConversionData popFlagTable[]={
    {"A",popCodeTable,0,0},
    {"CC",popCodeTable,0,0},
    {"COMP",popCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo popCodeInfo={"pop",POP_SUPPORTED_OPERANDS,
                      assembleOneOperand,popFlagTable};

ExtensionCodeAndCode pushwCodeTable[] = {
    [X_OPERAND]         ={NA,0x89},
    [Y_OPERAND]         ={0x90,0x89},
};

ConversionData pushwFlagTable[]={
    {"X",pushwCodeTable,0,0},
    {"Y",pushwCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo pushwCodeInfo={"pushw",STACKWORD_SUPPORTED_OPERANDS,
                        assembleOneOperand,pushwFlagTable};


ExtensionCodeAndCode popwCodeTable[] = {
    [X_OPERAND]         ={NA,0x85},
    [Y_OPERAND]         ={0x90,0x85},
};

ConversionData popwFlagTable[]={
    {"X",popwCodeTable,0,0},
    {"Y",popwCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo popwCodeInfo={"popw",STACKWORD_SUPPORTED_OPERANDS,
                        assembleOneOperand,popwFlagTable};
