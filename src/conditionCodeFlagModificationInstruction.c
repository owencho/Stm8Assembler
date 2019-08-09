#include "conditionCodeFlagModificationInstruction.h"

ExtensionCodeAndCode ccfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8c}
};

ConversionData ccfFlagTable[]={
    {"CCF",ccfCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo ccfCodeInfo={"neg",NO_OPERAND,assembleNoOperand,ccfFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rcfCodeTable[] = {
    [NO_OPERAND]         ={NA,0x98}
};


ConversionData rcfFlagTable[]={
    {"RCF",rcfCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo rcfCodeInfo={"rcf",NO_OPERAND,assembleNoOperand,rcfFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rimCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9a}
};


ConversionData rimFlagTable[]={
    {"rim",rimCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo rimCodeInfo={"rim",NO_OPERAND,assembleNoOperand,rimFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode simCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9b}
};

ConversionData simFlagTable[]={
    {"sim",simCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo simCodeInfo={"sim",NO_OPERAND,assembleNoOperand,simFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rvfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9c}
};

ConversionData rvfFlagTable[]={
    {"rvf",rvfCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo rvfCodeInfo={"rvf",NO_OPERAND,assembleNoOperand,rvfFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode scfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x99}
};

ConversionData scfFlagTable[]={
    {"scf",scfCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo scfCodeInfo={"scf",NO_OPERAND,assembleNoOperand,scfFlagTable};
