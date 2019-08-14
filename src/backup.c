#include <stdio.h>
#include "unity.h"
#include "CustomAssert.h"
#include "Common.h"

#define _STRINGIFY(x)     #x
#define STRINGIFY(x)     _STRINGIFY(x)

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











void assertEqualOperand (const int expectedOperand[],
                         const stm8Operand* actualOperand,
                         const UNITY_LINE_TYPE lineNumber);

#define TEST_ASSERT_EQUAL_OPERAND(expectedOperand,operand)                                          \
                              assertEqualOperand(expectedOperand,operand,__LINE__)
