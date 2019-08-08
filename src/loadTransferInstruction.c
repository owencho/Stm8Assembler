#include "loadTransferInstruction.h"

ExtensionCodeAndCode ldACodeTable[] = {
    [BYTE_OPERAND]                             ={NA,0xA6},
    [SHORT_MEM_OPERAND]                        ={NA,0xB6},
    [LONG_MEM_OPERAND]                         ={NA,0xC6},
    [BRACKETED_X_OPERAND]                      ={NA,0xF6},
    [SHORTOFF_X_OPERAND]                       ={NA,0xE6},
    [LONGOFF_X_OPERAND]                        ={NA,0xD6},
    [BRACKETED_Y_OPERAND]                      ={0x90,0xF6},
    [SHORTOFF_Y_OPERAND]                       ={0x90,0xE6},
    [LONGOFF_Y_OPERAND]                        ={0x90,0xD6},
    [SHORTOFF_SP_OPERAND]                      ={NA,0x7B},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]         ={0x92,0xC6},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]          ={0x72,0xC6},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]        ={0x92,0xD6},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x72,0xD6},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]        ={0x91,0xD6},
    [XL_OPERAND]                               ={NA,0x9F},
    [YL_OPERAND]                               ={0x90,0x9F},
    [XH_OPERAND]                               ={NA,0x9E},
    [YH_OPERAND]                               ={0x90,0x9E},
};

ExtensionCodeAndCode ldComplexCodeTable[] = {
    [SHORT_MEM_OPERAND]                        ={NA,0xB7},
    [LONG_MEM_OPERAND]                         ={NA,0xC7},
    [BRACKETED_X_OPERAND]                      ={NA,0xF7},
    [SHORTOFF_X_OPERAND]                       ={NA,0xE7},
    [LONGOFF_X_OPERAND]                        ={NA,0xD7},
    [BRACKETED_Y_OPERAND]                      ={0x90,0xF7},
    [SHORTOFF_Y_OPERAND]                       ={0x90,0xE7},
    [LONGOFF_Y_OPERAND]                        ={0x90,0xD7},
    [SHORTOFF_SP_OPERAND]                      ={NA,0x6B},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]         ={0x92,0xC7},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]          ={0x72,0xC7},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]        ={0x92,0xD7},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x72,0xD7},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]        ={0x91,0xD7},
    [XL_OPERAND]                               ={NA,0x97},
    [YL_OPERAND]                               ={0x90,0x97},
    [XH_OPERAND]                               ={NA,0x95},
    [YH_OPERAND]                               ={0x90,0x95},
};



ConversionData ldFlagTable[]={
    {"A",ldACodeTable,LD2ND_SUPPORTED_OPERANDS,0},
    {"COMP",ldComplexCodeTable,(1<< A_OPERAND),0},
    {NULL,NULL,0,0},
};

CodeInfo ldCodeInfo={"ld",LD1ST_SUPPORTED_OPERANDS,
                      assembleLDandLDFOperand,ldFlagTable};

ExtensionCodeAndCode ldfComplexCodeTable[] = {
    [EXT_MEM_OPERAND]                             ={NA,0xBD},
    [EXTOFF_X_OPERAND]                            ={NA,0xA7},
    [EXTOFF_Y_OPERAND]                            ={0x90,0xA7},
    [LONGPTR_DOT_E_BRACKETEDX_OPERAND]            ={0x92,0xA7},
    [LONGPTR_DOT_E_BRACKETEDY_OPERAND]            ={0x91,0xA7},
    [BRACKETED_LONGPTR_DOT_E_OPERAND]             ={0x92,0xBD},
};

ExtensionCodeAndCode ldfACodeTable[] = {
  [EXT_MEM_OPERAND]                             ={NA,0xBC},
  [EXTOFF_X_OPERAND]                            ={NA,0xAF},
  [EXTOFF_Y_OPERAND]                            ={0x90,0xAF},
  [LONGPTR_DOT_E_BRACKETEDX_OPERAND]            ={0x92,0xAF},
  [LONGPTR_DOT_E_BRACKETEDY_OPERAND]            ={0x91,0xAF},
  [BRACKETED_LONGPTR_DOT_E_OPERAND]             ={0x92,0xBC},
};

ConversionData ldfFlagTable[]={
    {"A",ldfACodeTable,LDF_COMP_SUPPORTED_OPERANDS,0},
    {"COMP",ldfComplexCodeTable,(1<< A_OPERAND),0},
    {NULL,NULL,0,0},
};

CodeInfo ldfCodeInfo={"ldf",LDF_SUPPORTED_OPERANDS,
                      assembleLDandLDFOperand,ldfFlagTable};

ExtensionCodeAndCode ldwComXCodeTable[] = {
    [SHORT_MEM_OPERAND]                        ={NA,0xBF},
    [LONG_MEM_OPERAND]                         ={NA,0xCF},
    [SHORTOFF_SP_OPERAND]                      ={NA,0x1F},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]         ={0x92,0xCF},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]          ={0x72,0xCF},
    [BRACKETED_Y_OPERAND]                      ={0x90,0xFF},
    [SHORTOFF_Y_OPERAND]                       ={0x90,0xEF},
    [LONGOFF_Y_OPERAND]                        ={0x90,0xDF},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]        ={0x91,0xDF},
};

ExtensionCodeAndCode ldwComYCodeTable[] = {
    [BRACKETED_X_OPERAND]                  ={NA,0xFF},
    [SHORTOFF_X_OPERAND]                   ={NA,0xEF},
    [LONGOFF_X_OPERAND]                    ={NA,0xDF},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]    ={0x92,0xDF},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]     ={0x72,0xDF},
    [SHORT_MEM_OPERAND]                    ={0x90,0xBF},
    [LONG_MEM_OPERAND]                     ={0x90,0xCF},
    [SHORTOFF_SP_OPERAND]                  ={NA,0x17},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]     ={0x91,0xDF},
};

ExtensionCodeAndCode ldwSPCodeTable[] = {
    [X_OPERAND]                        ={NA,0x94},
    [Y_OPERAND]                        ={0x90,0x94},
};

ExtensionCodeAndCode ldwXCodeTable[] = {
    [WORD_OPERAND]                        ={NA,0xAE},
    [SHORT_MEM_OPERAND]                   ={NA,0xBE},
    [LONG_MEM_OPERAND]                    ={NA,0xCE},
    [BRACKETED_X_OPERAND]                 ={NA,0xFE},
    [SHORTOFF_X_OPERAND]                  ={NA,0xEE},
    [LONGOFF_X_OPERAND]                   ={NA,0xDE},
    [SHORTOFF_SP_OPERAND]                 ={NA,0x1E},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]    ={0x92,0xCE},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]     ={0x72,0xCE},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]   ={0x92,0xDE},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]    ={0x72,0xDE},
    [Y_OPERAND]                           ={NA,0x93},
    [SP_OPERAND]                          ={NA,0x96},
};

ExtensionCodeAndCode ldwYCodeTable[] = {
    [WORD_OPERAND]                        ={0x90,0xAE},
    [SHORT_MEM_OPERAND]                   ={0x90,0xBE},
    [LONG_MEM_OPERAND]                    ={0x90,0xCE},
    [BRACKETED_Y_OPERAND]                 ={0x90,0xFE},
    [SHORTOFF_Y_OPERAND]                  ={0x90,0xEE},
    [LONGOFF_Y_OPERAND]                   ={0x90,0xDE},
    [SHORTOFF_SP_OPERAND]                 ={NA,0x16},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]    ={0x91,0xCE},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]   ={0x91,0xDE},
    [X_OPERAND]                           ={0x90,0x93},
    [SP_OPERAND]                          ={0x90,0x96},
};

ConversionData ldwFlagTable[]={
    {"X",ldwXCodeTable,LDW_X_SUPPORTED_OPERANDS,0},
    {"Y",ldwYCodeTable,LDW_Y_SUPPORTED_OPERANDS,0},
    {"SP",ldwSPCodeTable,LDW_SP_SUPPORTED_OPERANDS,0},
    {"COMP",0,(1<< X_OPERAND| 1<< Y_OPERAND),0},
    {"COMPX",ldwComXCodeTable,0,0},
    {"COMPY",ldwComYCodeTable,0,0},
    {NULL,NULL,0,0},
};

CodeInfo ldwCodeInfo={"ldw",LDW_1ST_SUPPORTED_OPERANDS,
                      assembleLDWOperand,ldwFlagTable};

ExtensionCodeAndCode clrCodeTable[] = {
[A_OPERAND]                           ={NA,0x4f},
[SHORT_MEM_OPERAND]                   ={NA,0x3f},
[LONG_MEM_OPERAND]                    ={0x72,0x5f},
[BRACKETED_X_OPERAND]                 ={NA,0x7f},
[SHORTOFF_X_OPERAND]                  ={NA,0x6f},
[LONGOFF_X_OPERAND]                   ={0x72,0x4f},
[BRACKETED_Y_OPERAND]                 ={0x90,0x7f},
[SHORTOFF_Y_OPERAND]                  ={0x90,0x6f},
[LONGOFF_Y_OPERAND]                   ={0x90,0x4f},
[SHORTOFF_SP_OPERAND]                 ={NA,0x0f},
[BRACKETED_SHORTPTR_DOT_W_OPERAND]    ={0x92,0x3f},
[BRACKETED_LONGPTR_DOT_W_OPERAND]     ={0x72,0x3f},
[SHORTPTR_DOT_W_BRACKETEDX_OPERAND]   ={0x92,0x6f},
[LONGPTR_DOT_W_BRACKETEDX_OPERAND]    ={0x72,0x6f},
[SHORTPTR_DOT_W_BRACKETEDY_OPERAND]   ={0x91,0x6f},
};

ConversionData clrFlagTable[]={
{"A",clrCodeTable,0,0},
{"COMP",clrCodeTable,0,0},
{NULL,NULL,0,0},
};

CodeInfo clrCodeInfo={"clr",CLR_SUPPORTED_OPERANDS,
                      assembleAOperandAndComplexOperand,clrFlagTable};

/*
ExtensionCodeAndCode exgCodeTable[] = {
[XL_OPERAND]         ={NA,0x41},
[YL_OPERAND]         ={NA,0x61},
[LONG_MEM_OPERAND]   ={NA,0x31},
};

CodeInfo exgCodeInfo={"exg",assembleAOperandAndComplexOperand,{
    //First operand
    1 << A_OPERAND ,
    //Second operand
    EXG_SUPPORTED_OPERANDS,
    //Third operand
    0
  }, {exgCodeTable,0,0,0,0}
};




*/
