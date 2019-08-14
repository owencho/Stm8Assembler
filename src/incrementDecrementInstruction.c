#include "incrementDecrementInstruction.h"

ExtensionCodeAndCode incCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x4C},
    [SHORT_MEM_OPERAND]                         ={NA,0x3C},
    [LONG_MEM_OPERAND]                          ={0x72,0x5C},
    [BRACKETED_X_OPERAND]                       ={NA,0x7C},
    [SHORTOFF_X_OPERAND]                        ={NA,0x6C},
    [LONGOFF_X_OPERAND]                         ={0x72,0x4C},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x7C},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x6C},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x4C},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x0C},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x3C},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x3C},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x6C},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x6C},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x6C},
};

ConversionData incFlagTable[]={
    {A_OPERAND,incCodeTable,0,0},
    {SHORT_MEM_OPERAND,incCodeTable,0,0},
    {LONG_MEM_OPERAND,incCodeTable,0,0},
    {BRACKETED_X_OPERAND,incCodeTable,0,0},
    {SHORTOFF_X_OPERAND,incCodeTable,0,0},
    {LONGOFF_X_OPERAND,incCodeTable,0,0},
    {BRACKETED_Y_OPERAND,incCodeTable,0,0},
    {SHORTOFF_Y_OPERAND,incCodeTable,0,0},
    {LONGOFF_Y_OPERAND,incCodeTable,0,0},
    {SHORTOFF_SP_OPERAND,incCodeTable,0,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,incCodeTable,0,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,incCodeTable,0,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,incCodeTable,0,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,incCodeTable,0,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,incCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo incCodeInfo={"inc",INCDEC_SUPPORTED_OPERANDS,
                      assembleOneOperand,incFlagTable};

ExtensionCodeAndCode decCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x4A},
    [SHORT_MEM_OPERAND]                         ={NA,0x3A},
    [LONG_MEM_OPERAND]                          ={0x72,0x5A},
    [BRACKETED_X_OPERAND]                       ={NA,0x7A},
    [SHORTOFF_X_OPERAND]                        ={NA,0x6A},
    [LONGOFF_X_OPERAND]                         ={0x72,0x4A},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x7A},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x6A},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x4A},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x0A},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x3A},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x3A},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x6A},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x6A},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x6A},
};

ConversionData decFlagTable[]={
    {A_OPERAND,decCodeTable,0,0},
    {SHORT_MEM_OPERAND,decCodeTable,0,0},
    {LONG_MEM_OPERAND,decCodeTable,0,0},
    {BRACKETED_X_OPERAND,decCodeTable,0,0},
    {SHORTOFF_X_OPERAND,decCodeTable,0,0},
    {LONGOFF_X_OPERAND,decCodeTable,0,0},
    {BRACKETED_Y_OPERAND,decCodeTable,0,0},
    {SHORTOFF_Y_OPERAND,decCodeTable,0,0},
    {LONGOFF_Y_OPERAND,decCodeTable,0,0},
    {SHORTOFF_SP_OPERAND,decCodeTable,0,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,decCodeTable,0,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,decCodeTable,0,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,decCodeTable,0,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,decCodeTable,0,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,decCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo decCodeInfo={"dec",INCDEC_SUPPORTED_OPERANDS,
                    assembleOneOperand,decFlagTable};

ExtensionCodeAndCode incwCodeTable[] = {
    [X_OPERAND]         ={NA,0x5C},
    [Y_OPERAND]         ={0x90,0x5C},
};

ConversionData incwFlagTable[]={
    {X_OPERAND,incwCodeTable,0,0},
    {Y_OPERAND,incwCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo incwCodeInfo={"incw",INCDECWORD_SUPPORTED_OPERANDS,
                     assembleOneOperand,incwFlagTable};


ExtensionCodeAndCode decwCodeTable[] = {
    [X_OPERAND]         ={NA,0x5A},
    [Y_OPERAND]         ={0x90,0x5A},
};

ConversionData decwFlagTable[]={
    {X_OPERAND,decwCodeTable,0,0},
    {Y_OPERAND,decwCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo decwCodeInfo={"decw",INCDECWORD_SUPPORTED_OPERANDS,
                  assembleOneOperand,decwFlagTable};
