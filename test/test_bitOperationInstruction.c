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

void test_assembleInstruction_given_BSET_dollarsign5643_expect_0x72125643(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x12,0x56,0x43,END};
    Try{
        tokenizer = createTokenizer("  BSET $5643,#1 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
  }

void test_assembleInstruction_given_BSET_dollarsign5643_expect_0x721A0021(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x1A,0x00,0x21,END};
    Try{
        tokenizer = createTokenizer("  BSET $21,#5 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_bSET_word_expect_exception_thrown(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  BSET #$1230,#7 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_bSET_longmem_zzzz_expect_exception_thrown(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  BSET $1230,zzzzzz");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_bSET_without_commar_expect_exception_thrown(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  BSET $1230 #7 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_bSET_n_larger_than7_expect_exception_thrown(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  BSET $1230,#8  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_NVALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BRES_longmem1230_hash7_expect_0x721F1230(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x1F,0x12,0x30,END};

    Try{
        tokenizer = createTokenizer("  BRES $1230,#7 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_BRES_shortmem30_hash7_expect_0x721F0030(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x15,0x0,0x30,END};

    Try{
        tokenizer = createTokenizer("  BRES $30,#2 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BRES_longmem310_hash7_expect_0x72110310(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x11,0x03,0x10,END};

    Try{
        tokenizer = createTokenizer("  BRES $310,#0 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_bres_n_larger_than7_expect_exception_thrown(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  BRES $1230,#8  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_NVALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BCPL_dollarsign1233_expect_0x90141233(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x14,0x12,0x33,END};

    Try{
        tokenizer = createTokenizer("  BCPL $1233,#2  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BCPL_shortmem12_expect_0x90140012(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x14,0x00,0x12,END};

    Try{
        tokenizer = createTokenizer("  BCPL $12,#2  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BCPL_shortmem24_expect_0x90100024(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x10,0x00,0x24,END};

    Try{
        tokenizer = createTokenizer("  BCPL $24,#0  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BCPL_extmem_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  BCPL $234422,#0  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BCCM_dollarsign7749_n0_expect_0x90111233(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x11,0x77,0x49,END};

    Try{
        tokenizer = createTokenizer("  BCCM $7749,#0 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BCCM_dollarsign7749_expect_0x90141233(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x17,0x77,0x49,END};

    Try{
        tokenizer = createTokenizer("  BCCM $7749,#3 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_BCcm_brackX_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  BCcm (X),#0  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
	  freeTokenizer(tokenizer);
}
