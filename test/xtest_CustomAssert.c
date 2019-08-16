#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "unity.h"
#include "Common.h"
#include "Token.h"
#include "Error.h"
#include "Tokenizer.h"
#include "CException.h"
#include "Exception.h"
#include "operand.h"
#include "instruction.h"
#include "mcode.h"
#include "CustomAssert.h"

void setUp(void){}
void tearDown(void){}

CEXCEPTION_T ex;

/*
* This is CustomAssert test file which test
* TEST_ASSERT_EQUAL_MACHINECODE
* this CustomAssert is used to compare the expected machine code
* and output machine code
* This test file is not enabled default
* please remove x from the test file name to conduct the testing
**/

void test_customAssert_given_length4_machineCode_to_Compare_with_expectedMcode_with_one_more_expect_fail(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+4);
    mcode -> length = 4;
    mcode -> code[0] = 0x44;
    mcode -> code[1] = 0xdd;
    mcode -> code[2] = 0x21;
    mcode -> code[3] = 0x44;
    mcode -> code[4] = 0x55;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x44,0xdd,0x21,0x44,0x55,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_length5_machineCode_to_Compare_with_expectedMcode_expect_pass(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+4);
    mcode -> length = 5;
    mcode -> code[0] = 0x44;
    mcode -> code[1] = 0xdd;
    mcode -> code[2] = 0x21;
    mcode -> code[3] = 0x44;
    mcode -> code[4] = 0x55;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x44,0xdd,0x21,0x44,0x55,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_length5_machineCode_to_Compare_with_different_code5_expectedMcode_expect_fail(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+4);
    mcode -> length = 5;
    mcode -> code[0] = 0x14;
    mcode -> code[1] = 0x2d;
    mcode -> code[2] = 0x31;
    mcode -> code[3] = 0x54;
    mcode -> code[4] = 0x45;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x14,0x2d,0x31,0x54,0x35,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}


void test_customAssert_given_length4_machineCode_to_Compare_with_expectedMcode_expect_pass(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+4);
    mcode -> length = 4;
    mcode -> code[0] = 0x90;
    mcode -> code[1] = 0xdb;
    mcode -> code[2] = 0x77;
    mcode -> code[3] = 0x49;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xdb,0x77,0x49,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_length4_machineCode_to_Compare_with_expectedMcode_with_one_different_expect_fail(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+4);
    mcode -> length = 4;
    mcode -> code[0] = 0x90;
    mcode -> code[1] = 0xdb;
    mcode -> code[2] = 0x77;
    mcode -> code[3] = 0x49;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xdb,0x77,0x48,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_length3_machineCode_to_Compare_with_expectedMcode_expect_pass(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+3);
    mcode -> length = 3;
    mcode -> code[0] = 0x21;
    mcode -> code[1] = 0x34;
    mcode -> code[2] = 0x55;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x21,0x34,0x55,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_length3_machineCode_to_Compare_with_different_code3_expectedMcode_expect_fail(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+3);
    mcode -> length = 3;
    mcode -> code[0] = 0x22;
    mcode -> code[1] = 0x35;
    mcode -> code[2] = 0x66;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x22,0x35,0x77,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_length2_machineCode_to_Compare_with_expectedMcode_expect_pass(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+2);
    mcode -> length = 2;
    mcode -> code[0] = 0x77;
    mcode -> code[1] = 0x49;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x77,0x49,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}
//Ceedling will throw error when it is NULL, wrong length ,and wrong machine code compare
void test_customAssert_given_length2_machineCode_to_Compare_with_different_code1_expectedMcode_expect_fail(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+2);
    mcode -> length = 2;
    mcode -> code[0] = 0x88;
    mcode -> code[1] = 0x65;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x88,0x44,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_length1_machineCode_to_Compare_with_expectedMcode_expect_pass(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+1);
    mcode -> length = 1;
    mcode -> code[0] = 0x55;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x55,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_length1_machineCode_to_Compare_with_different_expectedMcode_expect_fail(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+1);
    mcode -> length = 1;
    mcode -> code[0] = 0x54;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x55,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_NULL_machineCode_expect_fail(void) {
    MachineCode *mcode = NULL;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x55,END};

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_customAssert_given_NULL_expectedmachineCode__expect_fail(void) {
    MachineCode *mcode ;
    mcode=malloc(sizeof(MachineCode)+1+1);
    mcode -> length = 1;
    mcode -> code[0] = 0x55;
    int expectedMcode[]={END};
    Tokenizer *tokenizer = NULL;

    Try{
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}
