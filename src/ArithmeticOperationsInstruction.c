#include "ArithmeticOperationsInstruction.h"

ExtensionCodeAndCode adcCodeTable[] = {
    [BYTE_OPERAND]         ={NA,0xa9},
    [SHORT_MEM_OPERAND]    ={NA,0xb9},
    [LONG_MEM_OPERAND]     ={NA,0xc9},
    [BRACKETED_X_OPERAND] ={NA,0xf9},
    [SHORTOFF_X_OPERAND] ={NA,0xe9},
    [LONGOFF_X_OPERAND] ={NA,0xd9},
    [BRACKETED_Y_OPERAND] ={0x90,0xf9},
    [SHORTOFF_Y_OPERAND] ={0x90,0xe9},
    [LONGOFF_Y_OPERAND] ={0x90,0xd9},
    [SHORTOFF_SP_OPERAND] ={NA,0x19},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc9},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc9},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd9},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd9},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd9},
};

ConversionData adcFlagTable[]={
    {A_OPERAND,adcCodeTable,ADC_SUPPORTED_OPERANDS,0},
    {0,NULL,0,0},
};

CodeInfo adcCodeInfo={"adc",(1 << A_OPERAND),
                      assembleSymbolComplexOperand,adcFlagTable};

ExtensionCodeAndCode addCodeTable[] = {
    [BYTE_OPERAND]         ={NA,0xab},
    [SHORT_MEM_OPERAND]    ={NA,0xbb},
    [LONG_MEM_OPERAND]     ={NA,0xcb},
    [BRACKETED_X_OPERAND] ={NA,0xfb},
    [SHORTOFF_X_OPERAND] ={NA,0xeb},
    [LONGOFF_X_OPERAND] ={NA,0xdb},
    [BRACKETED_Y_OPERAND] ={0x90,0xfb},
    [SHORTOFF_Y_OPERAND] ={0x90,0xeb},
    [LONGOFF_Y_OPERAND] ={0x90,0xdb},
    [SHORTOFF_SP_OPERAND] ={NA,0x1b},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xcb},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xcb},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xdb},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xdb},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xdb},
};

ConversionData addFlagTable[]={
    {A_OPERAND,addCodeTable,ADC_SUPPORTED_OPERANDS,0},
    {0,NULL,0,0},
};

CodeInfo addCodeInfo={"add",(1 << A_OPERAND),
                      assembleSymbolComplexOperand,addFlagTable};


ExtensionCodeAndCode addwXCodeTable[] = {
    [WORD_OPERAND]={NA,0x1c},
    [LONG_MEM_OPERAND] ={0x72,0xbb},
    [SHORTOFF_SP_OPERAND]={0x72,0xfb}
};
ExtensionCodeAndCode addwYCodeTable[] = {
    [WORD_OPERAND] ={0x72,0xa9},
    [LONG_MEM_OPERAND] ={0x72,0xb9},
    [SHORTOFF_SP_OPERAND] ={0x72,0xf9}
};
ExtensionCodeAndCode addwSPCodeTable[] = {
    [BYTE_OPERAND] ={NA,0x5b}
};

ConversionData addwFlagTable[]={
    {X_OPERAND,addwXCodeTable,ADDW_XY_SUPPORTED_OPERANDS,0},
    {Y_OPERAND,addwYCodeTable,ADDW_XY_SUPPORTED_OPERANDS,0},
    {SP_OPERAND,addwSPCodeTable,(1<<BYTE_OPERAND),0},
    {0,NULL,0,0},
};

CodeInfo addwCodeInfo={"addw",(1 << X_OPERAND | 1<< SP_OPERAND | 1 << Y_OPERAND ),
                      assembleSymbolComplexOperand,addwFlagTable};


ExtensionCodeAndCode subACodeTable[] = {
    [BYTE_OPERAND]         ={NA,0xa0},
    [SHORT_MEM_OPERAND]    ={NA,0xb0},
    [LONG_MEM_OPERAND]     ={NA,0xc0},
    [BRACKETED_X_OPERAND] ={NA,0xf0},
    [SHORTOFF_X_OPERAND] ={NA,0xe0},
    [LONGOFF_X_OPERAND] ={NA,0xd0},
    [BRACKETED_Y_OPERAND] ={0x90,0xf0},
    [SHORTOFF_Y_OPERAND] ={0x90,0xe0},
    [LONGOFF_Y_OPERAND] ={0x90,0xd0},
    [SHORTOFF_SP_OPERAND] ={NA,0x10},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc0},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc0},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd0},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd0},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd0},
};
ExtensionCodeAndCode subSPCodeTable[] = {
    [BYTE_OPERAND]         ={NA,0x52}
};

ConversionData subFlagTable[]={
    {A_OPERAND,subACodeTable,ADC_SUPPORTED_OPERANDS,0},
    {SP_OPERAND,subSPCodeTable,(1<<BYTE_OPERAND),0},
    {0,NULL,0,0},
};

CodeInfo subCodeInfo={"sub",(1 << A_OPERAND | 1<< SP_OPERAND ),
                      assembleSymbolComplexOperand,subFlagTable};



ExtensionCodeAndCode divXCodeTable[] = {
    [A_OPERAND]    ={NA,0x62},
    [Y_OPERAND]    ={NA,0x65}
};
ExtensionCodeAndCode divYCodeTable[] = {
    [A_OPERAND]    ={0x90,0x62}
};

ConversionData divFlagTable[]={
    {X_OPERAND,divXCodeTable,(1 << A_OPERAND | 1 << Y_OPERAND),0},
    {Y_OPERAND,divYCodeTable,(1 << A_OPERAND),0},
    {0,NULL,0,0},
};

CodeInfo divCodeInfo={"div",(1 << X_OPERAND | 1<< Y_OPERAND ),
                      assembleSymbolComplexOperand,divFlagTable};

/////////////////////////////////////////////////////////////////
ExtensionCodeAndCode subwXCodeTable[] = {
    [WORD_OPERAND]         ={NA,0x1d},
    [LONG_MEM_OPERAND]     ={0x72,0xb0},
    [SHORTOFF_SP_OPERAND] ={0x72,0xf0}
};
ExtensionCodeAndCode subwYCodeTable[] = {
    [WORD_OPERAND]         ={0x72,0xa2},
    [LONG_MEM_OPERAND]     ={0x72,0xb2},
    [SHORTOFF_SP_OPERAND] ={0x72,0xf2}
};

ConversionData subwFlagTable[]={
    {X_OPERAND,subwXCodeTable,SUBW_SUPPORTED_OPERANDS,0},
    {Y_OPERAND,subwYCodeTable,SUBW_SUPPORTED_OPERANDS,0},
    {0,NULL,0,0},
};

CodeInfo subwCodeInfo={"subw",(1 << X_OPERAND | 1<< Y_OPERAND ),
                      assembleSymbolComplexOperand,subwFlagTable};


ExtensionCodeAndCode sbcCodeTable[] = {
    [BYTE_OPERAND]         ={NA,0xa2},
    [SHORT_MEM_OPERAND]    ={NA,0xb2},
    [LONG_MEM_OPERAND]     ={NA,0xc2},
    [BRACKETED_X_OPERAND] ={NA,0xf2},
    [SHORTOFF_X_OPERAND] ={NA,0xe2},
    [LONGOFF_X_OPERAND] ={NA,0xd2},
    [BRACKETED_Y_OPERAND] ={0x90,0xf2},
    [SHORTOFF_Y_OPERAND] ={0x90,0xe2},
    [LONGOFF_Y_OPERAND] ={0x90,0xd2},
    [SHORTOFF_SP_OPERAND] ={NA,0x12},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0xc2},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0xc2},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0xd2},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0xd2},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0xd2},
};

ConversionData sbcFlagTable[]={
    {A_OPERAND,sbcCodeTable,ADC_SUPPORTED_OPERANDS,0},
    {0,NULL,0,0},
};

CodeInfo sbcCodeInfo={"sbc",(1 << A_OPERAND),
                      assembleSymbolComplexOperand,sbcFlagTable};

ExtensionCodeAndCode negcodeTable[] = {
    [A_OPERAND]         ={NA,0x40},
    [SHORT_MEM_OPERAND]    ={NA,0x30},
    [LONG_MEM_OPERAND]     ={0x72,0x50},
    [BRACKETED_X_OPERAND] ={NA,0x70},
    [SHORTOFF_X_OPERAND] ={NA,0x60},
    [LONGOFF_X_OPERAND] ={0x72,0x40},
    [BRACKETED_Y_OPERAND] ={0x90,0x70},
    [SHORTOFF_Y_OPERAND] ={0x90,0x60},
    [LONGOFF_Y_OPERAND] ={0x90,0x40},
    [SHORTOFF_SP_OPERAND] ={NA,0x00},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]={0x92,0x30},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]={0x72,0x30},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]={0x92,0x60},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]={0x72,0x60},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]={0x91,0x60},
};

ConversionData negFlagTable[]={
    {A_OPERAND,negcodeTable,0,0},
    {SHORT_MEM_OPERAND,negcodeTable,0,0},
    {LONG_MEM_OPERAND,negcodeTable,0,0},
    {BRACKETED_X_OPERAND,negcodeTable,0,0},
    {SHORTOFF_X_OPERAND,negcodeTable,0,0},
    {LONGOFF_X_OPERAND,negcodeTable,0,0},
    {BRACKETED_Y_OPERAND,negcodeTable,0,0},
    {SHORTOFF_Y_OPERAND,negcodeTable,0,0},
    {LONGOFF_Y_OPERAND,negcodeTable,0,0},
    {SHORTOFF_SP_OPERAND,negcodeTable,0,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,negcodeTable,0,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,negcodeTable,0,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,negcodeTable,0,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,negcodeTable,0,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,negcodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo negCodeInfo={"neg",NEG_SUPPORTED_OPERANDS,
                      assembleOneOperand,negFlagTable};


ExtensionCodeAndCode mulXCodeTable[] = {
    [A_OPERAND]         ={NA,0x42},
};

ExtensionCodeAndCode mulYCodeTable[] = {
    [A_OPERAND]         ={0x90,0x42},
};

ConversionData mulFlagTable[]={
    {X_OPERAND,mulXCodeTable,(1<<A_OPERAND),0},
    {Y_OPERAND,mulYCodeTable,(1<<A_OPERAND),0},
    {0,NULL,0,0},
};

CodeInfo mulCodeInfo={"mul",(1 << X_OPERAND | 1<< Y_OPERAND ),
                    assembleSymbolComplexOperand,mulFlagTable};

ExtensionCodeAndCode negwcodeTable[] = {
    [X_OPERAND]    ={NA,0x50},
    [Y_OPERAND]    ={0x90,0x50},

};

ConversionData negwFlagTable[]={
    {X_OPERAND,negwcodeTable,0,0},
    {Y_OPERAND,negwcodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo negwCodeInfo={"negw",(1 << X_OPERAND | 1<< Y_OPERAND ),
                      assembleOneOperand,negwFlagTable};
