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

void test_assembleInstruction_given_and_LONGOFF5432_Y_OPERAND_expect_0x90d45432(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  And a, ($5432,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(4, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x90, mcode->code[0]);
    TEST_ASSERT_EQUAL_HEX8(0xd4, mcode->code[1]);
    TEST_ASSERT_EQUAL_HEX8(0x54, mcode->code[2]);
    TEST_ASSERT_EQUAL_HEX8(0x32, mcode->code[3]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_or_BYTE_OPERAND_expect_0xaa44(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  oR A,#$44 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(2, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0xaa, mcode->code[0]);
    TEST_ASSERT_EQUAL_HEX8(0x44, mcode->code[1]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}


void test_assembleInstruction_given_or_SHORTPTR_DOT_W_BRACKETEDX_OPERAND_expect_0x92da85(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  OR A,([$85.w],X)");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(3, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x92, mcode->code[0]);
    TEST_ASSERT_EQUAL_HEX8(0xda, mcode->code[1]);
    TEST_ASSERT_EQUAL_HEX8(0x85, mcode->code[2]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_or_expect_exception(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  or ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_xor_a_BRACKETED_SHORTPTR_DOT_W_OPERAND_hash5_expect_0xe205(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  xor A,($5,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(2, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0xe8, mcode->code[0]);
    TEST_ASSERT_EQUAL_HEX8(0x05, mcode->code[1]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}
