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

void setUp(void)
{
}

void tearDown(void)
{
}

void test_assembleInstruction_given_adc_SHORTOFF_X_OPERAND_expect_0xe9c1(void) {
  MachineCode *mcode ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  AdC a, ($c1,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(2, mcode->length);
    TEST_ASSERT_EQUAL_UINT8(0xe9, mcode->code[0]);
		TEST_ASSERT_EQUAL_UINT8(0xc1, mcode->code[1]);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}
