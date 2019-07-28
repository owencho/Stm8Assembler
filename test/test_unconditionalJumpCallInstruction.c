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

void test_assembleInstruction_given_call_longmem11_expect_0xcd0011(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xcd,0x00,0x11,END};

  Try{
    tokenizer = createTokenizer("  call $11 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_bracketedX_expect_0xfd(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xfd,END};

  Try{
    tokenizer = createTokenizer("  call (X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_bracketed_shortoff_X_expect_0xed32(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xed,0x32,END};

  Try{
    tokenizer = createTokenizer("  call ($32,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_bracketed_longoff_X_expect_0xdd1011(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xdd,0x10,0x11,END};

  Try{
    tokenizer = createTokenizer("  call ($1011,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_bracketedY_expect_0x90fd(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x90,0xfd,END};

  Try{
    tokenizer = createTokenizer("  call (Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_bracketed_shortoff_Y_expect_0x90ed77(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x90,0xed,0x77,END};

  Try{
    tokenizer = createTokenizer("  call ($77,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_bracketed_longoff_Y_expect_0x90dd5566(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x90,0xdd,0x55,0x66,END};

  Try{
    tokenizer = createTokenizer("  call ($5566,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_BRACKETED_SHORTPTR_DOT_W_OPERAND_expect_0x92cd12(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x92,0xcd,0x12,END};

  Try{
    tokenizer = createTokenizer("  call [$12.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_BRACKETED_LONGPTR_DOT_W_OPERAND_expect_0x72cd4152(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x72,0xcd,0x41,0x52,END};

  Try{
    tokenizer = createTokenizer("  call [$4152.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_SHORTPTR_DOT_W_BRACKETEDX_OPERAND_expect_0x92cd12(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x92,0xdd,0x55,END};

  Try{
    tokenizer = createTokenizer("  call ([$55.w],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_LONGPTR_DOT_W_BRACKETEDX_OPERAND_expect_0x72dd3137(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x72,0xdd,0x31,0x37,END};

  Try{
    tokenizer = createTokenizer("  CALL([$3137.w],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_SHORTPTR_DOT_W_BRACKETEDY_OPERAND_expect_0x91dd22(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x91,0xdd,0x22,END};

  Try{
    tokenizer = createTokenizer("  CALL([$22],Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}



void test_assembleInstruction_given_call_z_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  call z ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_call_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  call  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}


void test_assembleInstruction_given_ret_0x81(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  ret ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(1, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x81, mcode->code[0]);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ret_z_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  ret z ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_retf_0x87(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  retf ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(1, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x87, mcode->code[0]);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_retf_yamaha_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  retf yamaha ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_nop_0x9d(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  nop ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_NOT_NULL(mcode);
    TEST_ASSERT_EQUAL_UINT8(1, mcode->length);
    TEST_ASSERT_EQUAL_HEX8(0x9d, mcode->code[0]);
  }Catch(ex){
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_nop_symbol_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  nop * ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}
