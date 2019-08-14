#include "stackInstruction.h"

ExtensionCodeAndCode pushCodeTable[] = {
    [A_OPERAND]         ={NA,0x88},
    [CC_OPERAND]        ={NA,0x8a},
    [BYTE_OPERAND]      ={NA,0x4B},
    [LONG_MEM_OPERAND]  ={NA,0x3B},
};

ConversionData pushFlagTable[]={
    {A_OPERAND,pushCodeTable,0,0},
    {CC_OPERAND,pushCodeTable,0,0},
    {BYTE_OPERAND,pushCodeTable,0,0},
    {LONG_MEM_OPERAND,pushCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo pushCodeInfo={"push",PUSH_SUPPORTED_OPERANDS,
                        assembleOneOperand,pushFlagTable};

ExtensionCodeAndCode popCodeTable[] = {
    [A_OPERAND]         ={NA,0x84},
    [CC_OPERAND]        ={NA,0x86},
    [LONG_MEM_OPERAND]  ={NA,0x32},
};

ConversionData popFlagTable[]={
    {A_OPERAND,popCodeTable,0,0},
    {CC_OPERAND,popCodeTable,0,0},
    {LONG_MEM_OPERAND,popCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo popCodeInfo={"pop",POP_SUPPORTED_OPERANDS,
                      assembleOneOperand,popFlagTable};

ExtensionCodeAndCode pushwCodeTable[] = {
    [X_OPERAND]         ={NA,0x89},
    [Y_OPERAND]         ={0x90,0x89},
};

ConversionData pushwFlagTable[]={
    {X_OPERAND,pushwCodeTable,0,0},
    {Y_OPERAND,pushwCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo pushwCodeInfo={"pushw",STACKWORD_SUPPORTED_OPERANDS,
                        assembleOneOperand,pushwFlagTable};


ExtensionCodeAndCode popwCodeTable[] = {
    [X_OPERAND]         ={NA,0x85},
    [Y_OPERAND]         ={0x90,0x85},
};

ConversionData popwFlagTable[]={
    {X_OPERAND,popwCodeTable,0,0},
    {Y_OPERAND,popwCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo popwCodeInfo={"popw",STACKWORD_SUPPORTED_OPERANDS,
                        assembleOneOperand,popwFlagTable};
