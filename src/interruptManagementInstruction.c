#include "interruptManagementInstruction.h"

ExtensionCodeAndCode trapCodeTable[] = {
    [NO_OPERAND]         ={NA,0x83}
};

ConversionData trapFlagTable[]={
    {"trap",trapCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo trapCodeInfo={"trap",0,assembleNoOperand,trapFlagTable};

ExtensionCodeAndCode wfiCodeTable[] = {
    [NO_OPERAND]         ={NA,0x8f}
};

ConversionData wfiFlagTable[]={
    {"wfi",wfiCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo wfiCodeInfo={"wfi",0,assembleNoOperand,wfiFlagTable};


ExtensionCodeAndCode haltCodeTable[] = {
    [NO_OPERAND]         ={NA,0x8e}
};

ConversionData haltFlagTable[]={
    {"halt",haltCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo haltCodeInfo={"halt",0,assembleNoOperand,haltFlagTable};

ExtensionCodeAndCode iretCodeTable[] = {
    [NO_OPERAND]         ={NA,0x80}
};

ConversionData iretFlagTable[]={
    {"iret",iretCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo iretCodeInfo={"iret",0,assembleNoOperand,iretFlagTable};

ExtensionCodeAndCode intCodeTable[] = {
    [EXT_MEM_OPERAND]    ={NA,0x82},

};

ConversionData intFlagTable[]={
    {"COMP",intCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo intCodeInfo={"int",(1 << EXT_MEM_OPERAND),
                      assembleOneOperand,intFlagTable};
