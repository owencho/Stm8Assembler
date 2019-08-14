#include "compareAndTestsInstruction.h"

ExtensionCodeAndCode cpCodeTable[] = {
    [BYTE_OPERAND]         ={NA,0xa1},
    [SHORT_MEM_OPERAND]    ={NA,0xb1},
    [LONG_MEM_OPERAND]     ={NA,0xc1},
    [BRACKETED_X_OPERAND] ={NA,0xf1},
    [SHORTOFF_X_OPERAND] ={NA,0xe1},
    [LONGOFF_X_OPERAND] ={NA,0xd1},
    [BRACKETED_Y_OPERAND] ={0x90,0xf1},
    [SHORTOFF_Y_OPERAND] ={0x90,0xe1},
    [LONGOFF_Y_OPERAND] ={0x90,0xd1},
    [SHORTOFF_SP_OPERAND] ={NA,0x11},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc1},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc1},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd1},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd1},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd1},
};

ConversionData cpFlagTable[]={
    {A_OPERAND,cpCodeTable,COMPARE_SUPPORTED_OPERANDS,0},
    {0,NULL,0,0},
};

CodeInfo cpCodeInfo={"cp",(1 << A_OPERAND),
                      assembleSymbolComplexOperand,cpFlagTable};
////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode tnzCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x4D},
    [SHORT_MEM_OPERAND]                         ={NA,0x3D},
    [LONG_MEM_OPERAND]                          ={0x72,0x5D},
    [BRACKETED_X_OPERAND]                       ={NA,0x7D},
    [SHORTOFF_X_OPERAND]                        ={NA,0x6D},
    [LONGOFF_X_OPERAND]                         ={0x72,0x4D},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x7D},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x6D},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x4D},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x0D},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x3D},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x3D},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x6D},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x6D},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x6D},
};

ConversionData tnzFlagTable[]={
    {A_OPERAND,tnzCodeTable,0,0},
    {SHORT_MEM_OPERAND,tnzCodeTable,0,0},
    {LONG_MEM_OPERAND,tnzCodeTable,0,0},
    {BRACKETED_X_OPERAND,tnzCodeTable,0,0},
    {SHORTOFF_X_OPERAND,tnzCodeTable,0,0},
    {LONGOFF_X_OPERAND,tnzCodeTable,0,0},
    {BRACKETED_Y_OPERAND,tnzCodeTable,0,0},
    {SHORTOFF_Y_OPERAND,tnzCodeTable,0,0},
    {LONGOFF_Y_OPERAND,tnzCodeTable,0,0},
    {SHORTOFF_SP_OPERAND,tnzCodeTable,0,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,tnzCodeTable,0,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,tnzCodeTable,0,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,tnzCodeTable,0,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,tnzCodeTable,0,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,tnzCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo tnzCodeInfo={"tnz",TNZ_SUPPORTED_OPERANDS,
                      assembleOneOperand,tnzFlagTable};
////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode bcpCodeTable[] = {
    [BYTE_OPERAND]         ={NA,0xa5},
    [SHORT_MEM_OPERAND]    ={NA,0xb5},
    [LONG_MEM_OPERAND]     ={NA,0xc5},
    [BRACKETED_X_OPERAND] ={NA,0xf5},
    [SHORTOFF_X_OPERAND] ={NA,0xe5},
    [LONGOFF_X_OPERAND] ={NA,0xd5},
    [BRACKETED_Y_OPERAND] ={0x90,0xf5},
    [SHORTOFF_Y_OPERAND] ={0x90,0xe5},
    [LONGOFF_Y_OPERAND] ={0x90,0xd5},
    [SHORTOFF_SP_OPERAND] ={NA,0x15},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc5},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc5},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd5},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd5},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd5},
};

ConversionData bcpFlagTable[]={
    {A_OPERAND,bcpCodeTable,COMPARE_SUPPORTED_OPERANDS,0},
    {0,NULL,0,0},
};

CodeInfo bcpCodeInfo={"bcp",(1 << A_OPERAND),
                      assembleSymbolComplexOperand,bcpFlagTable};
////////////////////////////////////////////////////////////////////////////////

ExtensionCodeAndCode cpwXCodeTable[] = {
    [WORD_OPERAND]         ={NA,0xa3},
    [SHORT_MEM_OPERAND]    ={NA,0xb3},
    [LONG_MEM_OPERAND]     ={NA,0xc3},
    [BRACKETED_Y_OPERAND] ={0x90,0xf3},
    [SHORTOFF_Y_OPERAND] ={0x90,0xe3},
    [LONGOFF_Y_OPERAND] ={0x90,0xd3},
    [SHORTOFF_SP_OPERAND] ={NA,0x13},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND] ={0x92,0xc3},
    [BRACKETED_LONGPTR_DOT_W_OPERAND] ={0x72,0xc3},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND] ={0x91,0xd3},
};
ExtensionCodeAndCode cpwYCodeTable[] ={
    [WORD_OPERAND]={0x90,0xa3},
    [SHORT_MEM_OPERAND]={0x90,0xb3},
    [LONG_MEM_OPERAND]={0x90,0xc3},
    [BRACKETED_X_OPERAND]={NA,0xf3},
    [SHORTOFF_X_OPERAND]={NA,0xe3},
    [LONGOFF_X_OPERAND]={NA,0xd3},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x91,0xc3},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd3},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd3}
};

ConversionData cpwFlagTable[]={
    {X_OPERAND,cpwXCodeTable,CPW_X_SUPPORTED_OPERANDS,0},
    {Y_OPERAND,cpwYCodeTable,CPW_Y_SUPPORTED_OPERANDS,0},
    {0,NULL,0,0},
};

CodeInfo cpwCodeInfo={"cpw",COMPAREWORD_SUPPORTED_OPERANDS,
                      assembleSymbolComplexOperand,cpwFlagTable};
////////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode tnzwCodeTable[] = {
    [X_OPERAND]         ={NA,0x5D},
    [Y_OPERAND]         ={0x90,0x5D},
};

ConversionData tnzwFlagTable[]={
    {X_OPERAND,tnzwCodeTable,0,0},
    {Y_OPERAND,tnzwCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo tnzwCodeInfo={"tnzw",COMPAREWORD_SUPPORTED_OPERANDS,
                       assembleOneOperand,tnzwFlagTable};
