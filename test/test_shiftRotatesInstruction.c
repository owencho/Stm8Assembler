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
CEXCEPTION_T ex;

void setUp(void){}
void tearDown(void){}


void test_assembleInstruction_given_sllw_x_OPERAND_expect_0x58(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x58,END};

	Try{
		tokenizer = createTokenizer("  sllw x ");
		configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

		mcode = assembleInstruction(tokenizer);
		TEST_ASSERT_NOT_NULL(mcode);
		TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_y_OPERAND_expect_0x9058(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x58,END};

	Try{
		tokenizer = createTokenizer("  sllw y ");
		configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

		mcode = assembleInstruction(tokenizer);
		TEST_ASSERT_NOT_NULL(mcode);
		TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_y_commar_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  sllw y , ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  sllw ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_XL_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  sllw XL ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_Z_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  sllw Z ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_slaw_x_OPERAND_expect_0x58(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x58,END};

	Try{
		tokenizer = createTokenizer("  slaw x ");
		configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

		mcode = assembleInstruction(tokenizer);
		TEST_ASSERT_NOT_NULL(mcode);
		TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_slaw_y_OPERAND_expect_0x9058(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x58,END};

	Try{
		tokenizer = createTokenizer("  slaw y ");
		configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

		mcode = assembleInstruction(tokenizer);
		TEST_ASSERT_NOT_NULL(mcode);
		TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_X1_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  slaw X 1 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_slaw_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  slaw ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_slaw_dollarsign10_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  slaw $10 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_slaw_Q_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  slaw Q ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}
