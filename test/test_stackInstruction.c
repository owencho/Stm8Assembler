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


void test_assembleInstruction_given_push_A_OPERAND_expect_0x88(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x88,END};

    Try{
        tokenizer = createTokenizer("  PUSH A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_push_CC_OPERAND_expect_0x8A(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x8A,END};

    Try{
        tokenizer = createTokenizer("  PUSH CC ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_push_Byte_OPERAND_expect_0x4B55(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x4B,0x55,END};

    Try{
        tokenizer = createTokenizer("  PUSH #$55 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_push_longmem_OPERAND_expect_0x3B0077(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x3B,0x00,0x77,END};

    Try{
        tokenizer = createTokenizer("  PUSH $77 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_pop_A_OPERAND_expect_0x84(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x84,END};

    Try{
        tokenizer = createTokenizer("  pop A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_pop_CC_OPERAND_expect_0x86(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x86,END};

    Try{
        tokenizer = createTokenizer("  pop CC ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_pop_longmem_OPERAND_expect_0x323354(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x32,0x33,0x54,END};

    Try{
        tokenizer = createTokenizer("  pop $3354 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_popw_x_OPERAND_expect_0x85(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x85,END};

	Try{
		tokenizer = createTokenizer("  popw x ");
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

void test_assembleInstruction_given_popw_y_OPERAND_expect_0x9085(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x85,END};

	Try{
		tokenizer = createTokenizer("  popw y ");
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

void test_assembleInstruction_given_pushw_x_OPERAND_expect_0x89(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x89,END};

	Try{
		tokenizer = createTokenizer("  pushw x ");
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

void test_assembleInstruction_given_pushw_y_OPERAND_expect_0x9089(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x89,END};

	Try{
		tokenizer = createTokenizer("  pushw y ");
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
