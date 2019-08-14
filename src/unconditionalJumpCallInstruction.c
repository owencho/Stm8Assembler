#include "unconditionalJumpCallInstruction.h"

ExtensionCodeAndCode jraCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x20}
};

ConversionData jraFlagTable[]={
    {SHORT_OFF_OPERAND,jraCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo jraCodeInfo={"jra",(1 << SHORT_OFF_OPERAND) ,assembleJRXXOperand,jraFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrfCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x21}
};

ConversionData jrfFlagTable[]={
    {SHORT_OFF_OPERAND,jrfCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo jrfCodeInfo={"jrf",(1 << SHORT_OFF_OPERAND) ,assembleJRXXOperand,jrfFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jrtCodeTable[] = {
    [SHORT_OFF_OPERAND]         ={NA,0x20}
};

ConversionData jrtFlagTable[]={
    {SHORT_OFF_OPERAND,jrtCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo jrtCodeInfo={"jrt",(1 << SHORT_OFF_OPERAND) ,assembleJRXXOperand,jrtFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jpCodeTable[] = {
    [LONG_MEM_OPERAND]                         ={NA,0xCC},
    [BRACKETED_X_OPERAND]                      ={NA,0xFC},
    [SHORTOFF_X_OPERAND]                       ={NA,0xEC},
    [LONGOFF_X_OPERAND]                        ={NA,0xDC},
    [BRACKETED_Y_OPERAND]                      ={0x90,0xFC},
    [SHORTOFF_Y_OPERAND]                       ={0x90,0xEC},
    [LONGOFF_Y_OPERAND]                        ={0x90,0xDC},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]         ={0x92,0xCC},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]          ={0x72,0xCC},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]        ={0x92,0xDC},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x72,0xDC},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]        ={0x91,0xDC},
};

ConversionData jpFlagTable[]={
    {LONG_MEM_OPERAND,jpCodeTable,NA,0},
    {BRACKETED_X_OPERAND,jpCodeTable,NA,0},
    {SHORTOFF_X_OPERAND,jpCodeTable,NA,0},
    {LONGOFF_X_OPERAND,jpCodeTable,NA,0},
    {BRACKETED_Y_OPERAND,jpCodeTable,NA,0},
    {SHORTOFF_Y_OPERAND,jpCodeTable,NA,0},
    {LONGOFF_Y_OPERAND,jpCodeTable,NA,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,jpCodeTable,NA,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,jpCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,jpCodeTable,NA,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,jpCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,jpCodeTable,NA,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo jpCodeInfo={"jp",UNCONJUMP_SUPPORTED_OPERANDS ,assembleOneOperand,jpFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode jpfCodeTable[] = {
    [EXT_MEM_OPERAND]                         ={NA,0xAC},
    [BRACKETED_LONGPTR_DOT_E_OPERAND]         ={0x92,0xAC}
};

ConversionData jpfFlagTable[]={
    {EXT_MEM_OPERAND,jpfCodeTable,0,0},
    {BRACKETED_LONGPTR_DOT_E_OPERAND,jpfCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo jpfCodeInfo={"jpf",XXF_SUPPORTED_OPERANDS,assembleOneOperand,jpfFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
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

ConversionData callFlagTable[]={
    {LONG_MEM_OPERAND,callCodeTable,NA,0},
    {BRACKETED_X_OPERAND,callCodeTable,NA,0},
    {SHORTOFF_X_OPERAND,callCodeTable,NA,0},
    {LONGOFF_X_OPERAND,callCodeTable,NA,0},
    {BRACKETED_Y_OPERAND,callCodeTable,NA,0},
    {SHORTOFF_Y_OPERAND,callCodeTable,NA,0},
    {LONGOFF_Y_OPERAND,callCodeTable,NA,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,callCodeTable,NA,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,callCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,callCodeTable,NA,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,callCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,callCodeTable,NA,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo callCodeInfo={"call",UNCONJUMP_SUPPORTED_OPERANDS,assembleOneOperand,callFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode callrCodeTable[] = {
    [SHORT_OFF_OPERAND]     ={NA,0xad},

};

ConversionData callrFlagTable[]={
    {SHORT_OFF_OPERAND,callrCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo callrCodeInfo={"callr",(1<< SHORT_OFF_OPERAND),assembleJRXXOperand,callrFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode callfCodeTable[] = {
    [EXT_MEM_OPERAND]                         ={NA,0x8D},
    [BRACKETED_LONGPTR_DOT_E_OPERAND]         ={0x92,0x8D}

};

ConversionData callfFlagTable[]={
    {EXT_MEM_OPERAND,callfCodeTable,0,0},
    {BRACKETED_LONGPTR_DOT_E_OPERAND,callfCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo callfCodeInfo={"callf",XXF_SUPPORTED_OPERANDS,assembleOneOperand,callfFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode retCodeTable[] = {
  [NO_OPERAND]         ={NA,0x81}
};
ConversionData retFlagTable[]={
    {NO_OPERAND,retCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo retCodeInfo={"ret",0,assembleNoOperand,retFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode retfCodeTable[] = {
  [NO_OPERAND]         ={NA,0x87}
};
ConversionData retfFlagTable[]={
    {NO_OPERAND,retfCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo retfCodeInfo={"retf",0,assembleNoOperand,retfFlagTable};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode nopCodeTable[] = {
  [NO_OPERAND]         ={NA,0x9d}
};

ConversionData nopFlagTable[]={
    {NO_OPERAND,nopCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo nopCodeInfo={"nop",0,assembleNoOperand,nopFlagTable};
