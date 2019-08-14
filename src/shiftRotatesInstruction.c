#include "shiftRotatesInstruction.h"

ExtensionCodeAndCode sllAndSlaCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x48},
    [SHORT_MEM_OPERAND]                         ={NA,0x38},
    [LONG_MEM_OPERAND]                          ={0x72,0x58},
    [BRACKETED_X_OPERAND]                       ={NA,0x78},
    [SHORTOFF_X_OPERAND]                        ={NA,0x68},
    [LONGOFF_X_OPERAND]                         ={0x72,0x48},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x78},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x68},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x48},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x08},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x38},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x38},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x68},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x68},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x68},
};

ConversionData sllSlaFlagTable[]={
    {A_OPERAND,sllAndSlaCodeTable,0,0},
    {SHORT_MEM_OPERAND,sllAndSlaCodeTable,NA,0},
    {LONG_MEM_OPERAND,sllAndSlaCodeTable,NA,0},
    {BRACKETED_X_OPERAND,sllAndSlaCodeTable,NA,0},
    {SHORTOFF_X_OPERAND,sllAndSlaCodeTable,NA,0},
    {LONGOFF_X_OPERAND,sllAndSlaCodeTable,NA,0},
    {BRACKETED_Y_OPERAND,sllAndSlaCodeTable,NA,0},
    {SHORTOFF_Y_OPERAND,sllAndSlaCodeTable,NA,0},
    {LONGOFF_Y_OPERAND,sllAndSlaCodeTable,NA,0},
    {SHORTOFF_SP_OPERAND,sllAndSlaCodeTable,NA,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,sllAndSlaCodeTable,NA,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,sllAndSlaCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,sllAndSlaCodeTable,NA,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,sllAndSlaCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,sllAndSlaCodeTable,NA,0},
    {0,NULL,0,0},
};

CodeInfo sllCodeInfo={"sll",SHIFT_SUPPORTED_OPERANDS,
                      assembleOneOperand,sllSlaFlagTable};


CodeInfo slaCodeInfo={"sla",SHIFT_SUPPORTED_OPERANDS,
                      assembleOneOperand,sllSlaFlagTable};
///////////////////////////////////////////////////////////////////
ExtensionCodeAndCode srlCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x44},
    [SHORT_MEM_OPERAND]                         ={NA,0x34},
    [LONG_MEM_OPERAND]                          ={0x72,0x54},
    [BRACKETED_X_OPERAND]                       ={NA,0x74},
    [SHORTOFF_X_OPERAND]                        ={NA,0x64},
    [LONGOFF_X_OPERAND]                         ={0x72,0x44},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x74},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x64},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x44},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x04},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x34},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x34},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x64},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x64},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x64},
};

ConversionData srlFlagTable[]={
    {A_OPERAND,srlCodeTable,0,0},
    {SHORT_MEM_OPERAND,srlCodeTable,NA,0},
    {LONG_MEM_OPERAND,srlCodeTable,NA,0},
    {BRACKETED_X_OPERAND,srlCodeTable,NA,0},
    {SHORTOFF_X_OPERAND,srlCodeTable,NA,0},
    {LONGOFF_X_OPERAND,srlCodeTable,NA,0},
    {BRACKETED_Y_OPERAND,srlCodeTable,NA,0},
    {SHORTOFF_Y_OPERAND,srlCodeTable,NA,0},
    {LONGOFF_Y_OPERAND,srlCodeTable,NA,0},
    {SHORTOFF_SP_OPERAND,srlCodeTable,NA,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,srlCodeTable,NA,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,srlCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,srlCodeTable,NA,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,srlCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,srlCodeTable,NA,0},
    {0,NULL,0,0},
};

CodeInfo srlCodeInfo={"srl",SHIFT_SUPPORTED_OPERANDS,
                      assembleOneOperand,srlFlagTable};
///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode sraCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x47},
    [SHORT_MEM_OPERAND]                         ={NA,0x37},
    [LONG_MEM_OPERAND]                          ={0x72,0x57},
    [BRACKETED_X_OPERAND]                       ={NA,0x77},
    [SHORTOFF_X_OPERAND]                        ={NA,0x67},
    [LONGOFF_X_OPERAND]                         ={0x72,0x47},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x77},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x67},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x47},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x07},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x37},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x37},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x67},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x67},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x67},
};

ConversionData sraFlagTable[]={
    {A_OPERAND,sraCodeTable,0,0},
    {SHORT_MEM_OPERAND,sraCodeTable,NA,0},
    {LONG_MEM_OPERAND,sraCodeTable,NA,0},
    {BRACKETED_X_OPERAND,sraCodeTable,NA,0},
    {SHORTOFF_X_OPERAND,sraCodeTable,NA,0},
    {LONGOFF_X_OPERAND,sraCodeTable,NA,0},
    {BRACKETED_Y_OPERAND,sraCodeTable,NA,0},
    {SHORTOFF_Y_OPERAND,sraCodeTable,NA,0},
    {LONGOFF_Y_OPERAND,sraCodeTable,NA,0},
    {SHORTOFF_SP_OPERAND,sraCodeTable,NA,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,sraCodeTable,NA,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,sraCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,sraCodeTable,NA,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,sraCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,sraCodeTable,NA,0},
    {0,NULL,0,0},
};

CodeInfo sraCodeInfo={"sra",SHIFT_SUPPORTED_OPERANDS,
                      assembleOneOperand,sraFlagTable};

///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rlcCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x49},
    [SHORT_MEM_OPERAND]                         ={NA,0x39},
    [LONG_MEM_OPERAND]                          ={0x72,0x59},
    [BRACKETED_X_OPERAND]                       ={NA,0x79},
    [SHORTOFF_X_OPERAND]                        ={NA,0x69},
    [LONGOFF_X_OPERAND]                         ={0x72,0x49},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x79},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x69},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x49},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x09},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x39},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x39},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x69},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x69},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x69},
};

ConversionData rlcFlagTable[]={
    {A_OPERAND,rlcCodeTable,0,0},
    {SHORT_MEM_OPERAND,rlcCodeTable,NA,0},
    {LONG_MEM_OPERAND,rlcCodeTable,NA,0},
    {BRACKETED_X_OPERAND,rlcCodeTable,NA,0},
    {SHORTOFF_X_OPERAND,rlcCodeTable,NA,0},
    {LONGOFF_X_OPERAND,rlcCodeTable,NA,0},
    {BRACKETED_Y_OPERAND,rlcCodeTable,NA,0},
    {SHORTOFF_Y_OPERAND,rlcCodeTable,NA,0},
    {LONGOFF_Y_OPERAND,rlcCodeTable,NA,0},
    {SHORTOFF_SP_OPERAND,rlcCodeTable,NA,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,rlcCodeTable,NA,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,rlcCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,rlcCodeTable,NA,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,rlcCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,rlcCodeTable,NA,0},
    {0,NULL,0,0},
};

CodeInfo rlcCodeInfo={"rlc",SHIFT_SUPPORTED_OPERANDS,
                      assembleOneOperand,rlcFlagTable};

///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rrcCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x46},
    [SHORT_MEM_OPERAND]                         ={NA,0x36},
    [LONG_MEM_OPERAND]                          ={0x72,0x56},
    [BRACKETED_X_OPERAND]                       ={NA,0x76},
    [SHORTOFF_X_OPERAND]                        ={NA,0x66},
    [LONGOFF_X_OPERAND]                         ={0x72,0x46},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x76},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x66},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x46},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x06},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x36},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x36},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x66},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x66},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x66},
};

ConversionData rrcFlagTable[]={
    {A_OPERAND,rrcCodeTable,0,0},
    {SHORT_MEM_OPERAND,rrcCodeTable,NA,0},
    {LONG_MEM_OPERAND,rrcCodeTable,NA,0},
    {BRACKETED_X_OPERAND,rrcCodeTable,NA,0},
    {SHORTOFF_X_OPERAND,rrcCodeTable,NA,0},
    {LONGOFF_X_OPERAND,rrcCodeTable,NA,0},
    {BRACKETED_Y_OPERAND,rrcCodeTable,NA,0},
    {SHORTOFF_Y_OPERAND,rrcCodeTable,NA,0},
    {LONGOFF_Y_OPERAND,rrcCodeTable,NA,0},
    {SHORTOFF_SP_OPERAND,rrcCodeTable,NA,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,rrcCodeTable,NA,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,rrcCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,rrcCodeTable,NA,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,rrcCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,rrcCodeTable,NA,0},
    {0,NULL,0,0},
};

CodeInfo rrcCodeInfo={"rrc",SHIFT_SUPPORTED_OPERANDS,
                      assembleOneOperand,rrcFlagTable};

///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode swapCodeTable[] = {
    [A_OPERAND]                                 ={NA,0x4E},
    [SHORT_MEM_OPERAND]                         ={NA,0x3E},
    [LONG_MEM_OPERAND]                          ={0x72,0x5E},
    [BRACKETED_X_OPERAND]                       ={NA,0x7E},
    [SHORTOFF_X_OPERAND]                        ={NA,0x6E},
    [LONGOFF_X_OPERAND]                         ={0x72,0x4E},
    [BRACKETED_Y_OPERAND]                       ={0x90,0x7E},
    [SHORTOFF_Y_OPERAND]                        ={0x90,0x6E},
    [LONGOFF_Y_OPERAND]                         ={0x90,0x4E},
    [SHORTOFF_SP_OPERAND]                       ={NA,0x0E},
    [BRACKETED_SHORTPTR_DOT_W_OPERAND]          ={0x92,0x3E},
    [BRACKETED_LONGPTR_DOT_W_OPERAND]           ={0x72,0x3E},
    [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]         ={0x92,0x6E},
    [LONGPTR_DOT_W_BRACKETEDX_OPERAND]          ={0x72,0x6E},
    [SHORTPTR_DOT_W_BRACKETEDY_OPERAND]         ={0x91,0x6E},
};

ConversionData swapFlagTable[]={
    {A_OPERAND,swapCodeTable,0,0},
    {SHORT_MEM_OPERAND,swapCodeTable,NA,0},
    {LONG_MEM_OPERAND,swapCodeTable,NA,0},
    {BRACKETED_X_OPERAND,swapCodeTable,NA,0},
    {SHORTOFF_X_OPERAND,swapCodeTable,NA,0},
    {LONGOFF_X_OPERAND,swapCodeTable,NA,0},
    {BRACKETED_Y_OPERAND,swapCodeTable,NA,0},
    {SHORTOFF_Y_OPERAND,swapCodeTable,NA,0},
    {LONGOFF_Y_OPERAND,swapCodeTable,NA,0},
    {SHORTOFF_SP_OPERAND,swapCodeTable,NA,0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,swapCodeTable,NA,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,swapCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,swapCodeTable,NA,0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,swapCodeTable,NA,0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,swapCodeTable,NA,0},
    {0,NULL,0,0},
};

CodeInfo swapCodeInfo={"swap",SHIFT_SUPPORTED_OPERANDS,
                       assembleOneOperand,swapFlagTable};
///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode slXwCodeTable[] = {
    [X_OPERAND]         ={NA,0x58},
    [Y_OPERAND]         ={0x90,0x58},
};

ConversionData slXwFlagTable[]={
    {X_OPERAND,slXwCodeTable,0,0},
    {Y_OPERAND,slXwCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo sllwCodeInfo={"sllw",SHIFTWORD_SUPPORTED_OPERANDS,
                       assembleOneOperand,slXwFlagTable};


CodeInfo slawCodeInfo={"slaw",SHIFTWORD_SUPPORTED_OPERANDS,
                       assembleOneOperand,slXwFlagTable};
///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode srlwCodeTable[] = {
    [X_OPERAND]         ={NA,0x54},
    [Y_OPERAND]         ={0x90,0x54},
};

ConversionData srlwFlagTable[]={
    {X_OPERAND,srlwCodeTable,0,0},
    {Y_OPERAND,srlwCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo srlwCodeInfo={"srlw",SHIFTWORD_SUPPORTED_OPERANDS,
                       assembleOneOperand,srlwFlagTable};

///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode srawCodeTable[] = {
    [X_OPERAND]         ={NA,0x57},
    [Y_OPERAND]         ={0x90,0x57},
};

ConversionData srawFlagTable[]={
    {X_OPERAND,srawCodeTable,0,0},
    {Y_OPERAND,srawCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo srawCodeInfo={"sraw",SHIFTWORD_SUPPORTED_OPERANDS,
                       assembleOneOperand,srawFlagTable};
///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rlcwCodeTable[] = {
    [X_OPERAND]         ={NA,0x59},
    [Y_OPERAND]         ={0x90,0x59},
};

ConversionData rlcwFlagTable[]={
    {X_OPERAND,rlcwCodeTable,0,0},
    {Y_OPERAND,rlcwCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo rlcwCodeInfo={"rlcw",SHIFTWORD_SUPPORTED_OPERANDS,
                       assembleOneOperand,rlcwFlagTable};
///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rrcwCodeTable[] = {
    [X_OPERAND]         ={NA,0x56},
    [Y_OPERAND]         ={0x90,0x56},
};

ConversionData rrcwFlagTable[]={
    {X_OPERAND,rrcwCodeTable,0,0},
    {Y_OPERAND,rrcwCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo rrcwCodeInfo={"rrcw",SHIFTWORD_SUPPORTED_OPERANDS,
                       assembleOneOperand,rrcwFlagTable};
///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode swapwCodeTable[] = {
    [X_OPERAND]         ={NA,0x5E},
    [Y_OPERAND]         ={0x90,0x5E},
};

ConversionData swapwFlagTable[]={
    {X_OPERAND,swapwCodeTable,0,0},
    {Y_OPERAND,swapwCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo swapwCodeInfo={"swapw",SHIFTWORD_SUPPORTED_OPERANDS,
                        assembleOneOperand,swapwFlagTable};
///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rlwaCodeTable[] = {
    [X_OPERAND]         ={NA,0x02},
    [Y_OPERAND]         ={0x90,0x02},
};

ConversionData rlwaFlagTable[]={
    {X_OPERAND,rlwaCodeTable,0,0},
    {Y_OPERAND,rlwaCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo rlwaCodeInfo={"rlwa",SHIFTWORD_SUPPORTED_OPERANDS,
                       assembleOneOperand,rlwaFlagTable};
///////////////////////////////////////////////////////////////////////////////
ExtensionCodeAndCode rrwaCodeTable[] = {
    [X_OPERAND]         ={NA,0x01},
    [Y_OPERAND]         ={0x90,0x01},
};

ConversionData rrwaFlagTable[]={
    {X_OPERAND,rrwaCodeTable,0,0},
    {Y_OPERAND,rrwaCodeTable,0,0},
    {0,NULL,0,0},
};

CodeInfo rrwaCodeInfo={"rrwa",SHIFTWORD_SUPPORTED_OPERANDS,
                       assembleOneOperand,rrwaFlagTable};
