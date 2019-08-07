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

void test_assembleInstruction_given_BTJF_OPERAND_expect_0x720F681016(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x0F,0x68,0x10,0x16,END};

    Try{
        tokenizer = createTokenizer("  BTJF $6810,#7,$11");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BTJF_OPERAND_expect_0x720300330A(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x03,0x00,0x33,0x0A,END};

    Try{
        tokenizer = createTokenizer(" BTJF $33,#1,$5");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BTJF_OPERAND_expect_0x72030033F3(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x03,0x00,0x33,0xF3,END};

    Try{
        tokenizer = createTokenizer(" BTJF $33,#1,-$12");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BTJF_OPERAND_error_on_signedint(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" BTJF $72,#1,$81");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BTJF_OPERAND_error_on_n_value(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" BTJF $23,#8,$01");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_INVALID_NVALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BTJF_OPERAND_error_on_unsupportedOperand(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" BTJF (X),#8,$22");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BTJF_OPERAND_error_on_secondOperand_unsupportedOperand(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" BTJF $23,($23,X),$01");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
