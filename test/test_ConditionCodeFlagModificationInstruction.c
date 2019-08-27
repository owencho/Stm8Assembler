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
* This is conditionCodeFlagModificationInstruction test file which test
*  SIM RIM SCF RCF CCF RVF
* these instruction supports no operand
*
*can refer STM8 instruction set (docs\PM0044Programmingmanual.pdf) for more information
**/

//rcf instruction test ////////////////////////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_rcf_0x98(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x98,END};
    Try{
        tokenizer = createTokenizer("  rcF ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_rcF_t0t0_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  rcF t0t0 ");
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
//ccf instruction test ////////////////////////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_ccf_0x8c(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x8c,END};
    Try{
        tokenizer = createTokenizer("  cCf ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_ccf_abcd123_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  CcF abcd123 ");
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

//rim instruction test ////////////////////////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_rIm_0x9a(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x9a,END};
    Try{
        tokenizer = createTokenizer("  rIm ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_Rim_ironman_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  Rim IronMan ");
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
//rvf instruction test ////////////////////////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_rvf_0x9c(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x9c,END};
    Try{
        tokenizer = createTokenizer("  rvf ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_rvf_12789_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  rvf 12789 ");
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
//scf instruction test ////////////////////////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_scf_0x99(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x99,END};
    Try{
        tokenizer = createTokenizer("  ScF ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_SCF_symbol_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  SCF ! ");
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
//sim instruction test ////////////////////////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_sim_0x9b(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x9b,END};

    Try{
        tokenizer = createTokenizer("  sim ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
    freeMachineCode(mcode);
}

void test_assembleInstruction_given_sim_symbol_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  sim @ ");
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
