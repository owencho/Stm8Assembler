#include "conditionalBranchExecutionInstruction.h"
ExtensionCodeAndCode jrcCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x25}
};

ConversionData jrcFlagTable[]={
    {"COMP",jrcCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrcCodeInfo={"jrc",(1 << SHORT_OFF_OPERAND),
                      assembleJRXXOperand,jrcFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jreqCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x27}
};

ConversionData jreqFlagTable[]={
    {"COMP",jreqCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jreqCodeInfo={"jreq",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jreqFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrhCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x29}
};

ConversionData jrhFlagTable[]={
    {"COMP",jrhCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrhCodeInfo={"jrh",(1 << SHORT_OFF_OPERAND) ,
                       assembleJRXXOperand,jrhFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrihCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x2F}
};

ConversionData jrihFlagTable[]={
    {"COMP",jrihCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrihCodeInfo={"jrih",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrihFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrilCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x2E}
};

ConversionData jrilFlagTable[]={
    {"COMP",jrilCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrilCodeInfo={"jril",(1 << SHORT_OFF_OPERAND) ,
                      assembleJRXXOperand,jrilFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrmCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x2D}
};

ConversionData jrmFlagTable[]={
    {"COMP",jrmCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrmCodeInfo={"jrm",(1 << SHORT_OFF_OPERAND) ,
                      assembleJRXXOperand,jrmFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrmiCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2B}
};

ConversionData jrmiFlagTable[]={
    {"COMP",jrmiCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrmiCodeInfo={"jrmi",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrmiFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrncCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x24}
};

ConversionData jrncFlagTable[]={
    {"COMP",jrncCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrncCodeInfo={"jrnc",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrncFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrneCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x26}
};

ConversionData jrneFlagTable[]={
    {"COMP",jrneCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrneCodeInfo={"jrne",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrneFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrnhCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x28}
};

ConversionData jrnhFlagTable[]={
    {"COMP",jrnhCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrnhCodeInfo={"jrnh",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrnhFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrnmCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={0x90,0x2C}
};

ConversionData jrnmFlagTable[]={
    {"COMP",jrnmCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrnmCodeInfo={"jrnm",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrnmFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrnvCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x28}
};

ConversionData jrnvFlagTable[]={
    {"COMP",jrnvCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrnvCodeInfo={"jrnv",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrnvFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrplCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2A}
};

ConversionData jrplFlagTable[]={
    {"COMP",jrplCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrplCodeInfo={"jrpl",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrplFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrsgeCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2E}
};

ConversionData jrsgeFlagTable[]={
    {"COMP",jrsgeCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrsgeCodeInfo={"jrsge",(1 << SHORT_OFF_OPERAND) ,
                         assembleJRXXOperand,jrsgeFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrsgtCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2C}
};

ConversionData jrsgtFlagTable[]={
    {"COMP",jrsgtCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrsgtCodeInfo={"jrsgt",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrsgtFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrsleCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2D}
};

ConversionData jrsleFlagTable[]={
    {"COMP",jrsleCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrsleCodeInfo={"jrsle",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrsleFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrsltCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x2F}
};

ConversionData jrsltFlagTable[]={
    {"COMP",jrsltCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrsltCodeInfo={"jrslt",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jrsltFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrugeCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x24}
};

ConversionData jrugeFlagTable[]={
    {"COMP",jrugeCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrugeCodeInfo={"jruge",(1 << SHORT_OFF_OPERAND) ,
                          assembleJRXXOperand,jrugeFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrugtCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x22}
};

ConversionData jrugtFlagTable[]={
    {"COMP",jrugtCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrugtCodeInfo={"jrugt",(1 << SHORT_OFF_OPERAND) ,
                          assembleJRXXOperand,jrugtFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jruleCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x23}
};

ConversionData jruleFlagTable[]={
    {"COMP",jruleCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrulecodeInfo={"jrule",(1 << SHORT_OFF_OPERAND) ,
                        assembleJRXXOperand,jruleFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrultCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x25}
};

ConversionData jrultFlagTable[]={
    {"COMP",jrultCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrultCodeInfo={"jrult",(1 << SHORT_OFF_OPERAND),
                        assembleJRXXOperand,jrultFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrvCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x29}
};

ConversionData jrvFlagTable[]={
    {"COMP",jrvCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo jrvCodeInfo={"jrv",(1 << SHORT_OFF_OPERAND),
                        assembleJRXXOperand,jrvFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

ExtensionCodeAndCode wfeCodeTable[] = {
    [NO_OPERAND]         ={0x72,0x8f}
};

ConversionData wfeFlagTable[]={
    {"wfe",wfeCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo wfeCodeInfo={"wfe",0 ,assembleNoOperand,wfeFlagTable};
