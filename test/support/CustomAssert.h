#ifndef CustomAssert_H
#define CustomAssert_H
#include "unity.h"
#include "Instruction.h"

#define MAX_CODE_LENGTH  10


void assertEqualMCode (const int expectedCode[],
                      const MachineCode* actualMcode,
                      const UNITY_LINE_TYPE lineNumber);


#define TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode)                                          \
                              assertEqualMCode(expectedMcode,mcode,__LINE__)


#endif // CustomAssert_H
