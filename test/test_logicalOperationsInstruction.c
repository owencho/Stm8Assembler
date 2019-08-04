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

void test_assembleInstruction_given_and_LONGOFF5432_Y_OPERAND_expect_0x90d45432(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xd4,0x54,0x32,END};

    Try{
      tokenizer = createTokenizer("  And a, ($5432,Y) ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_and_A_longmem_OPERAND_expect_0xc45133(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xc4,0x51,0x33,END};

    Try{
      tokenizer = createTokenizer("  AND A,$5133 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_or_BYTE_OPERAND_expect_0xaa44(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xaa,0x44,END};

    Try{
      tokenizer = createTokenizer("  oR A,#$44 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_or_shortoffX_OPERAND_expect_0xea33(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xea,0x33,END};

    Try{
      tokenizer = createTokenizer("  OR A,($33,X) ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_or_SHORTPTR_DOT_W_BRACKETEDX_OPERAND_expect_0x92da85(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xda,0x85,END};

    Try{
      tokenizer = createTokenizer("  OR A,([$85.w],X) ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_xor_a_BRACKETED_SHORTPTR_DOT_W_OPERAND_hash5_expect_0xe205(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xe8,0x05,END};

    Try{
      tokenizer = createTokenizer("  xor A,($5,X) ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_xor_a_shortoffY_OPERAND_expect_0x906371(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xe8,0x71,END};

    Try{
      tokenizer = createTokenizer("  XOR A,($71,Y) ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_cpl_shortoffX_OPERAND_expect_0xe205(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x43,0x01,0x00,END};

    Try{
      tokenizer = createTokenizer("  CPL ($100,X) ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_cpl_shortoffY_OPERAND_expect_0xe205(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x43,0x01,0x00,END};

    Try{
      tokenizer = createTokenizer("  CPL ($100,Y) ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_cpl_longptrwX_OPERAND_hash5_expect_0x72634567(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x63,0x45,0x67,END};

    Try{
      tokenizer = createTokenizer("  CPL([$4567.w],X) ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_cplw_X_OPERAND_expect_0x53(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x53,END};

    Try{
      tokenizer = createTokenizer("  CPLw X ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_cplw_Y_expect_0x9053(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x53,END};

    Try{
      tokenizer = createTokenizer("  CPLw Y ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_xor_w_operand_expect_exception(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   XOR W,($71,Y)");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}


void test_assembleInstruction_given_cpl_with_extra_operand_expect_exception(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  CPL([$4567.w],X) Z");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_cpl_extmemY_operand_expect_exception(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   CPL ($100100,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_cplw_expect_exception(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  CPLw  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL , ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_cplw_1_expect_exception(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  CPLw 1 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND , ex->errorCode);
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
