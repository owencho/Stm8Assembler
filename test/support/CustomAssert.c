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
