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

void test_assembleInstruction_given_ld_A_hash77_expect_0xA677(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xA6,0x77,END};

  Try{
    tokenizer = createTokenizer("  LD A,#$77 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_longptrX_expect_0x72D67700(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x72,0xD6,0x77,0x00,END};

  Try{
    tokenizer = createTokenizer("  LD A,([$7700.w],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_shortoff_SP_A_expect_0x6B15(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x6B,0x15,END};

  Try{
    tokenizer = createTokenizer("  LD ($15,SP),A ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_shortptr_w_A_expect_0x92C725(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x92,0xC7,0x25,END};

  Try{
    tokenizer = createTokenizer("  LD [$25.w],A ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_extmem_expect_0xBC341256(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xBC,0x34,0x56,0x12,END};

  Try{
    tokenizer = createTokenizer("  LDF A,$345612 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_EXTOFF_X_OPERAND_expect_0xAF678967(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xAF,0x67,0x89,0x67,END};

  Try{
    tokenizer = createTokenizer("  LDF A,($678967,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_longptre_A_expect_0x92BD3421(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x92,0xBD,0x34,0x21,END};

  Try{
    tokenizer = createTokenizer("  LDF [$3421.e],A ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_y_word_A_expect_0x90AE55BB(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x90,0xAE,0x55,0xBB,END};

  Try{
    tokenizer = createTokenizer("  LDW Y,#$55BB ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_y_word_A_expect_0xEE51(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xEE,0x51,END};

  Try{
    tokenizer = createTokenizer("  LDW X,($51,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_y_word_A_expect_0x1F(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x1F,END};

  Try{
    tokenizer = createTokenizer(" LDW ($50,SP),X ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
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
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}
