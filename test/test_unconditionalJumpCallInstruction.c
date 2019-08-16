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

/*
* This is unconditionalJumpCallInstruction test file which test
* JRA JRT JRF JP JPF CALL CALLR CALLF RET RETF NOP
* these instruction supports one operand
*can refer STM8 instruction set for more information
**/

//JRA instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_jra_shortoffAA_0x207E(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x20,0x7E,END};
  Try{
      tokenizer = createTokenizer("  jra $7C ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jra_negHex20_0x20E2(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x20,0xE2,END};
  Try{
      tokenizer = createTokenizer("  jra -$20 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jra_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  jra  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

//JRT instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_jrt_shortoffAA_0x206E(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x20,0x6E,END};
  Try{
      tokenizer = createTokenizer("  jrt $6C ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jrt_negHex10_0x20F2(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x20,0xF2,END};
  Try{
      tokenizer = createTokenizer("  jrt -$10 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jra_bracX_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  jrt (X)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jra_roundBRac_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  jrt (  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

//JRF instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_jrf_shortoffAA_0x210F(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x21,0x0F,END};
  Try{
      tokenizer = createTokenizer("  jrf $D ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jrf_negHex10_0x21EE(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x21,0xEE,END};
  Try{
      tokenizer = createTokenizer("  jrf -$14 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      mcode = assembleInstruction(tokenizer);
      TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}
//JP instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_jp_longmem71_expect_0xcc0071(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xcc,0x00,0x71,END};

  Try{
    tokenizer = createTokenizer("  jp $71 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_bracketedX_expect_0xfd(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xfc,END};

  Try{
    tokenizer = createTokenizer("  jp (X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_bracketed_shortoff_X_expect_0xec22(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xec,0x22,END};

  Try{
    tokenizer = createTokenizer("  jp ($22,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_bracketed_longoff_X_expect_0xdc1122(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xdc,0x11,0x22,END};

  Try{
    tokenizer = createTokenizer("  jp ($1122,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_bracketedY_expect_0x90fc(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x90,0xfc,END};

  Try{
    tokenizer = createTokenizer("  jp (Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_bracketed_shortoff_Y_expect_0x90ec73(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x90,0xec,0x73,END};

  Try{
    tokenizer = createTokenizer("  jp ($73,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_bracketed_longoff_Y_expect_0x90dc5223(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x90,0xdc,0x52,0x23,END};

  Try{
    tokenizer = createTokenizer("  jp ($5223,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_BRACKETED_SHORTPTR_DOT_W_OPERAND_expect_0x92cc12(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x92,0xcc,0x12,END};

  Try{
    tokenizer = createTokenizer("  jp [$12.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_BRACKETED_LONGPTR_DOT_W_OPERAND_expect_0x72cc1152(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x72,0xcc,0x11,0x52,END};

  Try{
    tokenizer = createTokenizer("  jp [$1152.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_SHORTPTR_DOT_W_BRACKETEDX_OPERAND_expect_0x92dc03(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x92,0xdc,0x3,END};

  Try{
    tokenizer = createTokenizer("  jp ([$3.w],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_LONGPTR_DOT_W_BRACKETEDX_OPERAND_expect_0x72dc0313(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x72,0xdc,0x03,0x13,END};

  Try{
    tokenizer = createTokenizer("  jp([$313],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_SHORTPTR_DOT_W_BRACKETEDY_OPERAND_expect_0x91dc22(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x91,0xdc,0x22,END};

  Try{
    tokenizer = createTokenizer("  jp([$22],Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_longptrw_Y_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  jp([$2212],Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_z_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  jp z ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jp_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  jp  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

//JPF instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_jpf_extmem_expect_0xac2ffffc(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xac,0x2f,0xff,0xfc,END};

  Try{
    tokenizer = createTokenizer("  JPF $2FFFFC ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jpf_extmem_expect_0xac00ffff(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xac,0x0,0xff,0xff,END};

  Try{
    tokenizer = createTokenizer("  JPF $FFFF ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_jpf_extmem_expect_0xac00001(void){
MachineCode *mcode =NULL ;
Tokenizer *tokenizer = NULL;
int expectedMcode[]={0xac,0x0,0x0,0x01,END};

Try{
  tokenizer = createTokenizer("  JPF $1 ");
  configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
  mcode = assembleInstruction(tokenizer);
  TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
} Catch(ex){
  dumpTokenErrorMessage(ex, __LINE__);
  TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
}
  freeTokenizer(tokenizer);
}


void test_assembleInstruction_given_jpf_longptre_expect_0x92ac2ffc(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x92,0xac,0x2f,0xfc,END};

  Try{
    tokenizer = createTokenizer("  JPF [$2FFC.e]  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jpf_longptre_expect_0x92ac00fc(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x92,0xac,0x00,0xfc,END};

  Try{
    tokenizer = createTokenizer("  JPF [$FC.e]  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  } Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_jpf_brackX_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  JPF (X)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

//CALL instruction test ////////////////////////////////////////////////////////////////////////////////////////////

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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
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
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}
//CALLR instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_callr_shortmem_expect_0xad14(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xad,0x14,END};

  Try{
    tokenizer = createTokenizer("  CALLr $12 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_callr_negshortmem_expect_0xade1(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0xad,0xE1,END};

  Try{
    tokenizer = createTokenizer("  CALLr -$21 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_callr_brackX_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  CALLr (X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}
//CALLF instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_callf_extmem_expect_0x8D35BB20(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x8d,0x35,0xBB,0x20,END};

  Try{
    tokenizer = createTokenizer("  CALLF $35BB20 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_callf_longptre_expect_0x928D2FAC(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x92,0x8d,0x2F,0xAC,END};

  Try{
    tokenizer = createTokenizer("  CALLF [$2FAC.e] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_callf_ggwp_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  CALLf ggwp ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

//RET instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_ret_0x81(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x81,END};

  Try{
    tokenizer = createTokenizer("  ret ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

//RETF instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_retf_0x87(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x87,END};

  Try{
    tokenizer = createTokenizer("  retf ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

//NOP instruction test ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_nop_0x9d(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;
  int expectedMcode[]={0x9d,END};

  Try{
    tokenizer = createTokenizer("  nop ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    mcode = assembleInstruction(tokenizer);
    TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
  }Catch(ex){
    dumpTokenErrorMessage(ex, __LINE__);
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
    dumpTokenErrorMessage(ex, __LINE__);
    TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}
