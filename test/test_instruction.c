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

CEXCEPTION_T ex;

void setUp(void) {}

void tearDown(void) {}

void test_assembleInstruction_given_adc_SHORTOFF_X_OPERAND_expect_0xe9c1(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  AdC a, ($c1,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(2, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0xe9, mcode->code[0]);
		TEST_ASSERT_EQUAL_HEX8(0xc1, mcode->code[1]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_adc_hash33_expect_0xa933(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  AdC a, #$33 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(2, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0xa9, mcode->code[0]);
		TEST_ASSERT_EQUAL_HEX8(0x33, mcode->code[1]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_adc_z_hash77_expect_exception_thrown(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  AdC z , #$77  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
}

void test_assembleInstruction_given_adc_z_BracketedY_without_commar_expect_exception_thrown(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  AdC a (Y)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
}

void test_assembleInstruction_given_adc_z_expect_exception_thrown(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  AdC a ,  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_SRC_NULL, ex->errorCode);
  }
}

void test_assembleInstruction_given_add_bracketed_X_OPERAND_expect_0xfb(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  ADd a, (X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(1, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0xfb, mcode->code[0]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_add_LONGOFF7749_Y_OPERAND_expect_0x90db7749(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  ADd a, ($7749,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(4, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x90, mcode->code[0]);
    TEST_ASSERT_EQUAL_HEX8(0xdb, mcode->code[1]);
    TEST_ASSERT_EQUAL_HEX8(0x77, mcode->code[2]);
    TEST_ASSERT_EQUAL_HEX8(0x49, mcode->code[3]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

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

void test_assembleInstruction_given_bcp_BRACKETED_Y_OPERAND_expect_0x90f5(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  bCp A, (Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(2, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x90, mcode->code[0]);
    TEST_ASSERT_EQUAL_HEX8(0xf5, mcode->code[1]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_exg_XL_OPERAND_expect_0x41(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  eXg A,XL ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(1, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x41, mcode->code[0]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_exg_YL_OPERAND_expect_0x61(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  eXg A,YL ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(1, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x61, mcode->code[0]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_exg_LONG_MEM_OPERAND_1234_expect_0x311234(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  exg A, $1234 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(3, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x31, mcode->code[0]);
    TEST_ASSERT_EQUAL_HEX8(0x12, mcode->code[1]);
    TEST_ASSERT_EQUAL_HEX8(0x34, mcode->code[2]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_exg_z_XL_OPERAND_expect_exception(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  eXg Z,XL ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
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
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_or_commar_expect_exception(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  or ,");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}
