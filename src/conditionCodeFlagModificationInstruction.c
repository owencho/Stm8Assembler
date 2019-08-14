#include "conditionCodeFlagModificationInstruction.h"

ExtensionCodeAndCode ccfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x8c}
};

ConversionData ccfFlagTable[]={
    {NO_OPERAND,ccfCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo ccfCodeInfo={"neg",NO_OPERAND,assembleNoOperand,ccfFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rcfCodeTable[] = {
    [NO_OPERAND]         ={NA,0x98}
};


ConversionData rcfFlagTable[]={
    {NO_OPERAND,rcfCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo rcfCodeInfo={"rcf",NO_OPERAND,assembleNoOperand,rcfFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rimCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9a}
};


ConversionData rimFlagTable[]={
    {NO_OPERAND,rimCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo rimCodeInfo={"rim",NO_OPERAND,assembleNoOperand,rimFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode simCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9b}
};

ConversionData simFlagTable[]={
    {NO_OPERAND,simCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo simCodeInfo={"sim",NO_OPERAND,assembleNoOperand,simFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rvfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9c}
};

ConversionData rvfFlagTable[]={
    {NO_OPERAND,rvfCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo rvfCodeInfo={"rvf",NO_OPERAND,assembleNoOperand,rvfFlagTable};
///////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode scfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x99}
};

ConversionData scfFlagTable[]={
    {NO_OPERAND,scfCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo scfCodeInfo={"scf",NO_OPERAND,assembleNoOperand,scfFlagTable};
