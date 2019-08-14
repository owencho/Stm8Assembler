#include "conditionalBranchExecutionInstruction.h"
ExtensionCodeAndCode jrcCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x25}
};

ConversionData jrcFlagTable[]={
    {SHORT_OFF_OPERAND,jrcCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrcCodeInfo={"jrc",(1 << SHORT_OFF_OPERAND),
                      assembleOneOperand,jrcFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jreqCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x27}
};

ConversionData jreqFlagTable[]={
    {SHORT_OFF_OPERAND,jreqCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jreqCodeInfo={"jreq",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jreqFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrhCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x29}
};

ConversionData jrhFlagTable[]={
    {SHORT_OFF_OPERAND,jrhCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrhCodeInfo={"jrh",(1 << SHORT_OFF_OPERAND) ,
                       assembleOneOperand,jrhFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrihCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x2F}
};

ConversionData jrihFlagTable[]={
    {SHORT_OFF_OPERAND,jrihCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrihCodeInfo={"jrih",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrihFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrilCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x2E}
};

ConversionData jrilFlagTable[]={
    {SHORT_OFF_OPERAND,jrilCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrilCodeInfo={"jril",(1 << SHORT_OFF_OPERAND) ,
                      assembleOneOperand,jrilFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrmCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x2D}
};

ConversionData jrmFlagTable[]={
    {SHORT_OFF_OPERAND,jrmCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrmCodeInfo={"jrm",(1 << SHORT_OFF_OPERAND) ,
                      assembleOneOperand,jrmFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrmiCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2B}
};

ConversionData jrmiFlagTable[]={
    {SHORT_OFF_OPERAND,jrmiCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrmiCodeInfo={"jrmi",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrmiFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrncCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x24}
};

ConversionData jrncFlagTable[]={
    {SHORT_OFF_OPERAND,jrncCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrncCodeInfo={"jrnc",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrncFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrneCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x26}
};

ConversionData jrneFlagTable[]={
    {SHORT_OFF_OPERAND,jrneCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrneCodeInfo={"jrne",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrneFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrnhCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x28}
};

ConversionData jrnhFlagTable[]={
    {SHORT_OFF_OPERAND,jrnhCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrnhCodeInfo={"jrnh",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrnhFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrnmCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x2C}
};

ConversionData jrnmFlagTable[]={
    {SHORT_OFF_OPERAND,jrnmCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrnmCodeInfo={"jrnm",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrnmFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrnvCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x28}
};

ConversionData jrnvFlagTable[]={
    {SHORT_OFF_OPERAND,jrnvCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrnvCodeInfo={"jrnv",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrnvFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrplCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2A}
};

ConversionData jrplFlagTable[]={
    {SHORT_OFF_OPERAND,jrplCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrplCodeInfo={"jrpl",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrplFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrsgeCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2E}
};

ConversionData jrsgeFlagTable[]={
    {SHORT_OFF_OPERAND,jrsgeCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrsgeCodeInfo={"jrsge",(1 << SHORT_OFF_OPERAND) ,
                         assembleOneOperand,jrsgeFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrsgtCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2C}
};

ConversionData jrsgtFlagTable[]={
    {SHORT_OFF_OPERAND,jrsgtCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrsgtCodeInfo={"jrsgt",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrsgtFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrsleCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2D}
};

ConversionData jrsleFlagTable[]={
    {SHORT_OFF_OPERAND,jrsleCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrsleCodeInfo={"jrsle",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrsleFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrsltCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2F}
};

ConversionData jrsltFlagTable[]={
    {SHORT_OFF_OPERAND,jrsltCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrsltCodeInfo={"jrslt",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jrsltFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrugeCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x24}
};

ConversionData jrugeFlagTable[]={
    {SHORT_OFF_OPERAND,jrugeCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrugeCodeInfo={"jruge",(1 << SHORT_OFF_OPERAND) ,
                          assembleOneOperand,jrugeFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrugtCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x22}
};

ConversionData jrugtFlagTable[]={
    {SHORT_OFF_OPERAND,jrugtCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrugtCodeInfo={"jrugt",(1 << SHORT_OFF_OPERAND) ,
                          assembleOneOperand,jrugtFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jruleCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x23}
};

ConversionData jruleFlagTable[]={
    {SHORT_OFF_OPERAND,jruleCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrulecodeInfo={"jrule",(1 << SHORT_OFF_OPERAND) ,
                        assembleOneOperand,jruleFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrultCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x24}
};

ConversionData jrultFlagTable[]={
    {SHORT_OFF_OPERAND,jrultCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrultCodeInfo={"jrult",(1 << SHORT_OFF_OPERAND),
                        assembleOneOperand,jrultFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrvCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x29}
};

ConversionData jrvFlagTable[]={
    {SHORT_OFF_OPERAND,jrvCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo jrvCodeInfo={"jrv",(1 << SHORT_OFF_OPERAND),
                        assembleOneOperand,jrvFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ExtensionCodeAndCode wfeCodeTable[] = {
    [NO_OPERAND]         ={0x72,0x8f}
};

ConversionData wfeFlagTable[]={
    {NO_OPERAND,wfeCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo wfeCodeInfo={"wfe",0 ,assembleNoOperand,wfeFlagTable};
