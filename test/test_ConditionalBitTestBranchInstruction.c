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
#include "Operand.h"
#include "Instruction.h"
#include "ArithmeticOperationsInstruction.h"
#include "BitOperationInstruction.h"
#include "BreakPointInstruction.h"
#include "CompareAndTestsInstruction.h"
#include "ConditionalBitTestBranchInstruction.h"
#include "ConditionalBranchExecutionInstruction.h"
#include "ConditionCodeFlagModificationInstruction.h"
#include "IncrementDecrementInstruction.h"
#include "InterruptManagementInstruction.h"
#include "LoadTransferInstruction.h"
#include "LogicalOperationsInstruction.h"
#include "ShiftRotatesInstruction.h"
#include "UnconditionalJumpCallInstruction.h"
#include "AssembleAllInstruction.h"
#include "CustomAssert.h"
#include "StackInstruction.h"
CEXCEPTION_T ex;

void setUp(void){}
void tearDown(void){}

/*
* This is ConditionalBitTestBranchInstruction test file which test
* BTJT and BTJF instruction
* this both instruction support the third operand as short_off operand which supports
* negative and positive value (-128 <= x <= 127)
* (BTJF $6810,#7,loop) english like address for third operand are NOT SUPPORTED
*can refer STM8 instruction set (docs\PM0044Programmingmanual.pdf) for more information
**/


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
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
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
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
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
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}
//exception thrown due to 81 is more than 127 for second compliment
void test_assembleInstruction_given_BTJF_OPERAND_error_on_signedint(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" BTJF $72,#1,$81");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SIGNEDINT_VALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
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
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_NVALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
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
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_BTJF_OPERAND_error_on_thirdOperand_unsupportedOperand(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" BTJF $23,($23,X),$01");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_BTJF_OPERAND_error_on_secondOperand_unsupportedOperand(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" BTJF $23,#7,(Y)");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_BTJF_OPERAND_error_on_extra_symbol(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" BTJF $23,#7,$22 x");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_BTJT_OPERAND_expect_0x720E44553d(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x0E,0x44,0x55,0x3d,END};

    Try{
        tokenizer = createTokenizer("  BTJT $4455,#7,$38");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_BTJt_OPERAND_expect_0x7202004508(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x02,0x00,0x45,0x08,END};

    Try{
        tokenizer = createTokenizer(" BTJT $45,#1,$3");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_BTJT_OPERAND_expect_0x7202003392(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x02,0x00,0x33,0x92,END};

    Try{
        tokenizer = createTokenizer(" BTJT $33,#1,-$73");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}
