#include "logicalOperationsInstruction.h"

ExtensionCodeAndCode andCodeTable[] = {
    [BYTE_OPERAND]         ={NA,0xa4},
    [SHORT_MEM_OPERAND]    ={NA,0xb4},
    [LONG_MEM_OPERAND]     ={NA,0xc4},
    [BRACKETED_X_OPERAND] ={NA,0xf4},
    [SHORTOFF_X_OPERAND] ={NA,0xe4},
    [LONGOFF_X_OPERAND] ={NA,0xd4},
    [BRACKETED_Y_OPERAND] ={0x90,0xf4},
    [SHORTOFF_Y_OPERAND] ={0x90,0xe4},
    [LONGOFF_Y_OPERAND] ={0x90,0xd4},
    [SHORTOFF_SP_OPERAND] ={NA,0x14},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc4},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc4},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd4},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd4},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd4},
};


ConversionData andFlagTable[]={
    {A_OPERAND,andCodeTable,LOGICAL_SUPPORTED_OPERANDS,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo andCodeInfo={"and",(1 << A_OPERAND),
                      assembleSymbolComplexOperand,andFlagTable};


ExtensionCodeAndCode orCodeTable[] = {
    [BYTE_OPERAND]         ={NA,0xaa},
    [SHORT_MEM_OPERAND]    ={NA,0xba},
    [LONG_MEM_OPERAND]     ={NA,0xca},
    [BRACKETED_X_OPERAND] ={NA,0xfa},
    [SHORTOFF_X_OPERAND] ={NA,0xea},
    [LONGOFF_X_OPERAND] ={NA,0xda},
    [BRACKETED_Y_OPERAND] ={0x90,0xfa},
    [SHORTOFF_Y_OPERAND] ={0x90,0xea},
    [LONGOFF_Y_OPERAND] ={0x90,0xda},
    [SHORTOFF_SP_OPERAND] ={NA,0x1a},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xca},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xca},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xda},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xda},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xda},
};

ConversionData orFlagTable[]={
    {A_OPERAND,orCodeTable,LOGICAL_SUPPORTED_OPERANDS,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo orCodeInfo={"or",(1 << A_OPERAND),
                      assembleSymbolComplexOperand,orFlagTable};


ExtensionCodeAndCode xorCodeTable[] = {
    [BYTE_OPERAND]         ={NA,0xa8},
    [SHORT_MEM_OPERAND]    ={NA,0xb8},
    [LONG_MEM_OPERAND]     ={NA,0xc8},
    [BRACKETED_X_OPERAND] ={NA,0xf8},
    [SHORTOFF_X_OPERAND] ={NA,0xe8},
    [LONGOFF_X_OPERAND] ={NA,0xd8},
    [BRACKETED_Y_OPERAND] ={0x90,0xf8},
    [SHORTOFF_Y_OPERAND] ={0x90,0xe8},
    [LONGOFF_Y_OPERAND] ={0x90,0xd8},
    [SHORTOFF_SP_OPERAND] ={NA,0x18},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc8},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc8},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd8},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd8},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd8},
};


ConversionData xorFlagTable[]={
    {A_OPERAND,xorCodeTable,LOGICAL_SUPPORTED_OPERANDS,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo xorCodeInfo={"xor",(1 << A_OPERAND),
                      assembleSymbolComplexOperand,xorFlagTable};

ExtensionCodeAndCode cplCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x43},
    [SHORT_MEM_OPERAND]                         ={NA,0x33},
    [LONG_MEM_OPERAND]                          ={0x72,0x53},
    [BRACKETED_X_OPERAND]                       ={NA,0x73},
    [SHORTOFF_X_OPERAND]                        ={NA,0x63},
    [LONGOFF_X_OPERAND]                         ={0x72,0x43},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x73},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x63},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x43},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x03},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x33},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x33},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x63},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x63},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x63},
};

ConversionData cplFlagTable[]={
    {A_OPERAND,cplCodeTable,0,0},
    {SHORT_MEM_OPERAND,cplCodeTable,NA,0},
    {LONG_MEM_OPERAND,cplCodeTable,NA,0},
    {BRACKETED_X_OPERAND,cplCodeTable,NA,0},
    {SHORTOFF_X_OPERAND,cplCodeTable,NA,0},
    {LONGOFF_X_OPERAND,cplCodeTable,NA,0},
    {BRACKETED_Y_OPERAND,cplCodeTable,NA,0},
    {SHORTOFF_Y_OPERAND,cplCodeTable,NA,0},
    {LONGOFF_Y_OPERAND,cplCodeTable,NA,0},
    {SHORTOFF_SP_OPERAND,cplCodeTable,NA,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,cplCodeTable,NA,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,cplCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,cplCodeTable,NA,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,cplCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,cplCodeTable,NA,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo cplCodeInfo={"cpl",CPL_SUPPORTED_OPERANDS,
                  assembleOneOperand,cplFlagTable};

ExtensionCodeAndCode cplwCodeTable[] = {
    [X_OPERAND]         ={NA,0x53},
    [Y_OPERAND]         ={0x90,0x53},
};

ConversionData cplwFlagTable[]={
    {X_OPERAND,cplwCodeTable,0,0},
    {Y_OPERAND,cplwCodeTable,0,0},
    {NO_TABLE_OPERAND,NULL,0,0},
};

CodeInfo cplwCodeInfo={"cplw",CPLW_SUPPORTED_OPERANDS,
                     assembleOneOperand,cplwFlagTable};
