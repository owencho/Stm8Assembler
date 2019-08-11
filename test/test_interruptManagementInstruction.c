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
#include "arithmeticOperationsInstruction.h"
#include "bitOperationInstruction.h"
#include "breakPointInstruction.h"
#include "compareAndTestsInstruction.h"
#include "conditionalBitTestBranchInstruction.h"
#include "conditionalBranchExecutionInstruction.h"
#include "conditionCodeFlagModificationInstruction.h"
#include "incrementDecrementInstruction.h"
#include "interruptManagementInstruction.h"
#include "loadTransferInstruction.h"
#include "logicalOperationsInstruction.h"
#include "shiftRotatesInstruction.h"
#include "unconditionalJumpCallInstruction.h"
#include "assembleAllInstruction.h"
#include "CustomAssert.h"
#include "stackInstruction.h"
CEXCEPTION_T ex;
void setUp(void){}
void tearDown(void){}


void test_assembleInstruction_given_halt_0x8c(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x8e,END};

    Try{
        tokenizer = createTokenizer("  halt ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_halt_ggmu_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  halt ggmu ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_iret_0x80(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x80,END};

    Try{
        tokenizer = createTokenizer("  IreT ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_iret_m12m_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  iret m12m ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}


void test_assembleInstruction_given_trap_0x83(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x83,END};

    Try{
        tokenizer = createTokenizer("  trap ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_trap_1_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  trap 1 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_wfi_0x8f(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x8f,END};

    Try{
        tokenizer = createTokenizer("  wfi ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_wfi_54_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  wfi 54 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_int_0x82773121(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x82,0x77,0x31,0x21,END};

    Try{
        tokenizer = createTokenizer("  int $773121 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_int_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("   int");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_int_A_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("   int A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
