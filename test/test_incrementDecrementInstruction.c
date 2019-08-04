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

void test_assembleInstruction_given_inc_A_OPERAND_expect_0x4C(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x4C,END};

	Try{
		tokenizer = createTokenizer("  inc A ");
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

void test_assembleInstruction_given_dec_bracX_OPERAND_expect_0x7C(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x7C,END};

	Try{
		tokenizer = createTokenizer("  inc (X) ");
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

void test_assembleInstruction_given_inc_longptrw_OPERAND_expect_0x723C1512(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x72,0x3C,0x15,0x12 ,END};
	Try{
		tokenizer = createTokenizer("  INC [$1512] ");
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

void test_assembleInstruction_given_dec_longmem_OPERAND_expect_0x725A7749(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x72,0x5A,0x77,0x49 ,END};

	Try{
		tokenizer = createTokenizer("  DEC $7749 ");
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

void test_assembleInstruction_given_dec_shortoffY_OPERAND_expect_0x906A56(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x6A,0x56,END};

	Try{
		tokenizer = createTokenizer("  DEC($56,Y) ");
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

void test_assembleInstruction_given_dec_longptrwX_OPERAND_expect_0x725A7749(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x72,0x6A,0x44,0x31 ,END};
	Try{
		tokenizer = createTokenizer("  DEC([$4431],X) ");
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

void test_assembleInstruction_given_incw_x_OPERAND_expect_0x5C(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x5C,END};

	Try{
		tokenizer = createTokenizer("  incw x ");
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

void test_assembleInstruction_given_incw_y_OPERAND_expect_0x905C(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x5C,END};

	Try{
		tokenizer = createTokenizer("  incw y ");
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

void test_assembleInstruction_given_decw_x_OPERAND_expect_0x5A(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x5A,END};

	Try{
		tokenizer = createTokenizer("  decw x ");
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

void test_assembleInstruction_given_decw_y_OPERAND_expect_0x905A(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x5A,END};

	Try{
		tokenizer = createTokenizer("  decw y ");
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
