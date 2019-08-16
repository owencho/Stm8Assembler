#include <stdio.h>
#include "unity.h"
#include "CustomAssert.h"
#include "Common.h"

#define _STRINGIFY(x)     #x
#define STRINGIFY(x)     _STRINGIFY(x)

/*
* This is incrementDecrementInstruction test file which test
* INC DEC INCW DECW
* these instruction supports one operand
*can refer STM8 instruction set for more information
**/

//cp testing ////////////////////////////////////////////////////////////////////////////////////////////


void test_valueCheck_given_z_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("z");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        int a = valueCheck(token);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}


int getExpectedCodeLength(const int expectedCode[] , int length){
    int i=0;

    while(expectedCode[i]!=END && (i != length)){
      i++;
    }
    return i;
}

int getExpectedOperandCodeLength(const int expectedCode[] , int length){
    int i=0;

    while(expectedCode[i]!=ENDOPERAND && (i != length)){
      i++;
    }
    return i;
}

void assertEqualOperand (const int expectedOperand[],
                         const stm8Operand* actualOperand,
                         const UNITY_LINE_TYPE lineNumber){

    int length;
    char msg[1024];
    if(actualOperand == NULL){
      UNITY_TEST_FAIL(lineNumber,"The actual Operand is NULL");
    }
    if(expectedOperand == NULL){
      UNITY_TEST_FAIL(lineNumber,"The expected Operand is NULL");
    }
    length =getExpectedOperandCodeLength(expectedOperand,MAX_CODE_LENGTH + 1);
    UNITY_TEST_ASSERT_EQUAL_INT(length,6,lineNumber,
                                "The Length of expectedOperand are not the same");
    if(expectedOperand[0] != actualOperand->type) {
      sprintf(msg,"Expected %u but encountered %u , the operand type is not the same",expectedOperand[0], actualOperand->type );
      UNITY_TEST_FAIL(lineNumber,msg);
    }
    else if(expectedOperand[1] != actualOperand->dataSize.extCode){
        sprintf(msg,"Expected 0x%x but encountered 0x%x , the code at index 1 is not the same",expectedOperand[1], actualOperand->dataSize.extCode );
        UNITY_TEST_FAIL(lineNumber,msg);
    }
    else if(expectedOperand[2] != actualOperand->dataSize.code){
        sprintf(msg,"Expected 0x%x but encountered 0x%x , the code at index 2 is not the same",expectedOperand[2], actualOperand->dataSize.code );
        UNITY_TEST_FAIL(lineNumber,msg);
    }
    else if(expectedOperand[3] != actualOperand->dataSize.ms){
        sprintf(msg,"Expected 0x%x but encountered 0x%x , the code at index 3 is not the same",expectedOperand[3], actualOperand->dataSize.ms );
        UNITY_TEST_FAIL(lineNumber,msg);
    }
    else if(expectedOperand[4] != actualOperand->dataSize.ls){
        sprintf(msg,"Expected 0x%x but encountered 0x%x , the code at index 4 is not the same",expectedOperand[4], actualOperand->dataSize.ls );
        UNITY_TEST_FAIL(lineNumber,msg);
    }
    else if(expectedOperand[5] != actualOperand->dataSize.extB){
        sprintf(msg,"Expected 0x%x but encountered 0x%x , the code at index 5 is not the same",expectedOperand[5], actualOperand->dataSize.extB );
        UNITY_TEST_FAIL(lineNumber,msg);
    }
}


void assertEqualMCode (const int expectedMCode[],
                      const MachineCode* actualMcode,
                      const UNITY_LINE_TYPE lineNumber){

    char msg[1024];
    int length;
    int i;

    if(actualMcode == NULL){
      UNITY_TEST_FAIL(lineNumber,"The actual Machine code is NULL");
    }
    if(expectedMCode == NULL){
      UNITY_TEST_FAIL(lineNumber,"The expected Mcode is NULL");
    }

    length =getExpectedCodeLength(expectedMCode,MAX_CODE_LENGTH + 1);
    if(length > MAX_CODE_LENGTH){
      UNITY_TEST_FAIL(lineNumber,"The length is too long (>="STRINGIFY(MAX_CODE_LENGTH)").");
    }
     UNITY_TEST_ASSERT_EQUAL_INT(length,actualMcode->length,lineNumber,
                                 "The Length of Machine code are not the same");
    for(i=0;i<length;i++){
      if(expectedMCode[i]!=actualMcode->code[i]) {
        sprintf(msg,"Expected 0x%x but encountered 0x%x , the code at index %d is not the same",expectedMCode[i],actualMcode->code[i],i );
        UNITY_TEST_FAIL(lineNumber,msg);
      }
    }
}

MachineCode* assembleSymbolComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer){
    int bitOPCheck =0;
    int nvalue = NA;
    IntegerToken * token;
    stm8Operand * operand;
    stm8Operand * operand1st;
    stm8OperandType operandType;
    ExtensionCodeAndCode code;
    MachineCode* mcode;
    ConversionData  dataFlag;

    token =(IntegerToken*)getToken(tokenizer);
    bitOPCheck= bitOperationCheck(token);
    freeToken(token);
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*)token);
    operand1st = oneOperandHandler(tokenizer ,codeInfo->firstFlags);
    pushBackToken(tokenizer,(Token*)token);
    dataFlag = getDataFlag(codeInfo,tokenizer,operand1st);
    token =(IntegerToken*)getToken(tokenizer);
    commarCheck(tokenizer);
    operand = oneOperandHandler(tokenizer ,dataFlag.secondFlags);
    if(bitOPCheck != 0){
        nvalue = hashNValueReturn(tokenizer , operand,bitOPCheck);
        mcode=machineCodeAllocateOutput(tokenizer,dataFlag ,operand1st,nvalue,NA);
    }
    else{
      mcode=machineCodeAllocateOutput(tokenizer,dataFlag ,operand,NA,NA);
    }
    notNullCheck(tokenizer);
    return mcode;
}

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

ExtensionCodeAndCode ldwShortMemCodeTable[] = {
    [X_OPERAND]                        ={NA,0xBF},
    [Y_OPERAND]                        ={0x90,0xBF},
};

ExtensionCodeAndCode ldwLongMemCodeTable[] = {
    [X_OPERAND]                        ={NA,0xCF},
    [Y_OPERAND]                        ={0x90,0xCF},
};

ExtensionCodeAndCode ldwShortOffSPCodeTable[] = {
    [X_OPERAND]                        ={NA,0x1F},
    [Y_OPERAND]                        ={NA,0x17},
};

ExtensionCodeAndCode ldwBracXCodeTable[] = {
    [Y_OPERAND]                        ={NA,0xFF},
};

ExtensionCodeAndCode ldwShortOffBracXCodeTable[] = {
    [Y_OPERAND]                        ={NA,0xEF},
};

ExtensionCodeAndCode ldwLongOffBracXCodeTable[] = {
    [Y_OPERAND]                        ={NA,0xDF},
};

ExtensionCodeAndCode ldwBracYCodeTable[] = {
    [X_OPERAND]                        ={0x90,0xFF},
};

ExtensionCodeAndCode ldwShortOffBracYCodeTable[] = {
    [X_OPERAND]                        ={0x90,0xEF},
};

ExtensionCodeAndCode ldwLongOffBracYCodeTable[] = {
    [X_OPERAND]                        ={0x90,0xDF},
};

ExtensionCodeAndCode ldwBracShortPtrWCodeTable[] = {
    [X_OPERAND]                        ={0x92,0xCF},
    [Y_OPERAND]                        ={0x91,0xCF},
};

ExtensionCodeAndCode ldwBraclongPtrWCodeTable[] = {
    [X_OPERAND]                        ={0x72,0xCF},
};

ExtensionCodeAndCode ldwShortPtrWBracXCodeTable[] = {
    [Y_OPERAND]                        ={0x92,0xDF},
};

ExtensionCodeAndCode ldwLongPtrWBracXCodeTable[] = {
    [Y_OPERAND]                        ={0x72,0xDF},
};

ExtensionCodeAndCode ldwShortPtrWBracYCodeTable[] = {
    [X_OPERAND]                        ={0x91,0xDF},
};

ConversionData ldwFlagTable[]={
    {X_OPERAND,ldwXCodeTable,LDW_X_SUPPORTED_OPERANDS,0},
    {Y_OPERAND,ldwYCodeTable,LDW_Y_SUPPORTED_OPERANDS,0},
    {SP_OPERAND,ldwSPCodeTable,LDW_XY_SUPPORTED_OPERANDS,0},
    {SHORT_MEM_OPERAND,ldwShortMemCodeTable,LDW_XY_SUPPORTED_OPERANDS,0},
    {LONG_MEM_OPERAND,ldwLongMemCodeTable,LDW_XY_SUPPORTED_OPERANDS,0},
    {SHORTOFF_SP_OPERAND,ldwShortOffSPCodeTable,LDW_XY_SUPPORTED_OPERANDS,0},
    {BRACKETED_X_OPERAND,ldwBracXCodeTable,(1<<Y_OPERAND),0},
    {SHORTOFF_X_OPERAND,ldwShortOffBracXCodeTable,(1<<Y_OPERAND),0},
    {LONGOFF_X_OPERAND,ldwLongOffBracXCodeTable,(1<<Y_OPERAND),0},
    {BRACKETED_Y_OPERAND,ldwBracYCodeTable,(1<<X_OPERAND),0},
    {SHORTOFF_Y_OPERAND,ldwShortOffBracYCodeTable,(1<<X_OPERAND),0},
    {LONGOFF_Y_OPERAND,ldwLongOffBracYCodeTable,(1<<X_OPERAND),0},
    {BRACKETED_SHORTPTR_DOT_W_OPERAND,ldwBracShortPtrWCodeTable,LDW_XY_SUPPORTED_OPERANDS,0},
    {BRACKETED_LONGPTR_DOT_W_OPERAND,ldwBraclongPtrWCodeTable,(1<<X_OPERAND),0},
    {SHORTPTR_DOT_W_BRACKETEDX_OPERAND,ldwShortPtrWBracXCodeTable,(1<<Y_OPERAND),0},
    {LONGPTR_DOT_W_BRACKETEDX_OPERAND,ldwLongPtrWBracXCodeTable,(1<<Y_OPERAND),0},
    {SHORTPTR_DOT_W_BRACKETEDY_OPERAND,ldwShortPtrWBracYCodeTable,(1<<X_OPERAND),0},
    {0,NULL,0,0},
};









void assertEqualOperand (const int expectedOperand[],
                         const stm8Operand* actualOperand,
                         const UNITY_LINE_TYPE lineNumber);

#define TEST_ASSERT_EQUAL_OPERAND(expectedOperand,operand)                                          \
                              assertEqualOperand(expectedOperand,operand,__LINE__)
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
                                  [SHORT_MEM_OPERAND]                    ={0x90,0xBF},
                                  [LONG_MEM_OPERAND]                     ={0x90,0xCF},
                                  [SHORTOFF_SP_OPERAND]                  ={NA,0x17},
                                  [BRACKETED_X_OPERAND]                  ={NA,0xFF},
                                  [SHORTOFF_X_OPERAND]                   ={NA,0xEF},
                                  [LONGOFF_X_OPERAND]                    ={NA,0xDF},
                                  [SHORTPTR_DOT_W_BRACKETEDX_OPERAND]    ={0x92,0xDF},
                                  [LONGPTR_DOT_W_BRACKETEDX_OPERAND]     ={0x72,0xDF},
                                  [BRACKETED_SHORTPTR_DOT_W_OPERAND]     ={0x91,0xCF},
                              };



                              ConversionData ldwFlagTable[]={
                                  {X_OPERAND,ldwXCodeTable,LDW_X_SUPPORTED_OPERANDS,0},
                                  {Y_OPERAND,ldwYCodeTable,LDW_Y_SUPPORTED_OPERANDS,0},
                                  {SP_OPERAND,ldwSPCodeTable,LDW_XY_SUPPORTED_OPERANDS,0},
                                  {X_OPERAND,0,(1<< X_OPERAND| 1<< Y_OPERAND),0},  //comp
                                  {Y_OPERAND,ldwComXCodeTable,0,0},                // compx
                                  {X_OPERAND,ldwComYCodeTable,0,0},                // compy
                                  {0,NULL,0,0},
                              };

                              CodeInfo ldwCodeInfo={"ldw",LDW_1ST_SUPPORTED_OPERANDS,
                                                    assembleLDWOperand,ldwFlagTable};
