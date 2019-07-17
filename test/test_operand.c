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


CEXCEPTION_T ex;

void setUp(void) {}

void tearDown(void) {}
//Sub module Test
void test_nullCheck_given_empty_expect_error_thrown(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;

  Try{
    tokenizer = createTokenizer("    ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    nullCheck(ERR_INVALID_STM8_OPERAND,token,"NULL detected");
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_nullCheck_given_w_expect_pass(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;

  Try{
    tokenizer = createTokenizer("w");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected w after .");
    TEST_ASSERT_NOT_NULL(token->str);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

/*operandCheck return value as it detect which symbol
  as the condition that bring inside this module is
  when condition is 2 means it support X Y SP A
  when condition is 1 means it support X Y SP
  else only support X Y
  /////////////////////////
  return 1 when detect X
  return 2 when detect Y
  return 3 when detect SP
  return 4 when detect A
*/
void test_operandCheck_given_X_expect_return_1(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("X");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 0);
    TEST_ASSERT_EQUAL(1,a);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}
void test_operandCheck_given_Y_expect_return_2(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("Y");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 0);
    TEST_ASSERT_EQUAL(2,a);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}
void test_operandCheck_given_SP_condition_1_expect_return_3(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("SP");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 1);
    TEST_ASSERT_EQUAL(3,a);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}
void test_operandCheck_given_SP_condition_2_expect_return_3(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("SP");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 2);
    TEST_ASSERT_EQUAL(3,a);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_operandCheck_given_A_condition_2_expect_return_4(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("A");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 2);
    TEST_ASSERT_EQUAL(4,a);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_operandCheck_given_A_condition_1_expect_to_fail(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("A");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 1);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_operandCheck_given_A_condition_0_expect_to_fail(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("A");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 0);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_operandCheck_given_SP_condition_0_expect_to_fail(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("SP");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 0);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_operandCheck_given_XY_expect_to_fail(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("XY");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 2);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_operandCheck_given_22_expect_to_fail(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("22");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = operandCheck(token, 2);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}
//valueCheck is used to check is this value ls or ms
// ls will return 1 <256
// ms will return 2 >256

void test_operandCheck_given_23_expect_return_1(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("$23");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = valueCheck(token);
    TEST_ASSERT_EQUAL(1,a);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_operandCheck_given_2543_expect_return_2(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("$2543");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = valueCheck(token);
    TEST_ASSERT_EQUAL(2,a);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_operandCheck_given_negative_1234_expect_fail(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;
  IntegerToken *token ;
  int a;

  Try{
    tokenizer = createTokenizer("$-1234");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    token = (IntegerToken *)getToken(tokenizer);
    int a = valueCheck(token);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_NEGATIVE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INTEGER_NEGATIVE, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}


//Main Test Check
void test_getOperand_given_A_expect_A_register_type_is_returned(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  A  ");
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(A_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    //freeOperand(operand);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}


void test_getOperand_given_hash55_expect_BYTE_OPERAND_register_type_is_with_ms_equals_55(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  #55  ");
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(BYTE_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
  TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(55, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
  TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_dollarsign_3a_expect_shortmem_OPERAND_register_type_is_with_ms_equals_55(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  $3a  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(SHORT_MEM_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x3a, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_33_expect_shortmem_OPERAND_register_type_is_with_ms_equals_33(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  33  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(SHORT_MEM_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(33, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_hash_1000_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  #1000  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 93);
    TEST_ASSERT_EQUAL(ERR_INTEGER_HASH_TOO_LARGE, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_doublehash_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  ##  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}



void test_getOperand_given_dollarsign_3a7d_expect_shortmem_OPERAND_register_type_is_with_ms_equals_55(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  $3a7d  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x3a, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(0x7d, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  }Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_negative_3_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  $-3  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INTEGER_NEGATIVE, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_dollarsign_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  $$  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}


void test_getOperand_given_bracketedX_expect_BracX_Operand(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  (X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(BRACKETED_X_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracX1234_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   (X1234)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_bracX_commar_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   (X,)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}


void test_getOperand_given_bracX_without_closing_bracket_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   (X  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_bracX_without_opening_bracket_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   X )  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketA_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   ( A )  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 211);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_Space_X_expect_BracX_Operand(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ( X ) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(BRACKETED_X_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_161_X_expect_Brac_OPERAND_register_type_is_with_ms_equals_161(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  (161,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(SHORTOFF_X_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(161, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracX_171_without_closing_bracket_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   (171,X  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_bracX_value_zzzz_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   ($zzzz,X)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INVALID_INTEGER, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_881_bracX_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   (X ,881)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 288);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_bracX_neg_311_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("   (-311,X)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 154);
    TEST_ASSERT_EQUAL(ERR_INTEGER_NEGATIVE, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_517d_X_expect_Brac_OPERAND_register_type_is_with_ms_equals_51_ls_equal_7d(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($517d,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(LONGOFF_X_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x51, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(0x7d, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketedY_expect_BracY_Operand(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  (Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(BRACKETED_Y_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_207_Y_expect_SHORTOFFY_OPERAND_register_type_is_with_ms_equals_207(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  (207,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(SHORTOFF_Y_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(207, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_dollarsign_678d_y_expect_longoffY_OPERAND_register_type_is_with_ms_equals_67_ls_equal_8d(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($678d,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(LONGOFF_Y_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x67, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(0x8d, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}
//done until here

void test_getOperand_given_bracketed_dollarsign_10_SP_expect_SP_OPERAND_register_type_is_with_ms_equals_10(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($10,SP) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(SHORTOFF_SP_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x10, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_negative_256_sp_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  ($-256,SP) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INTEGER_NEGATIVE, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_77_dot_w_expect_shortptrw_OPERAND_register_type_is_with_ms_equals_77(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  [$77.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(BRACKETED_SHORTPTR_DOT_W_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x77, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_dollarsign_123d_dot_w_expect_longptrw_OPERAND_register_type_is_with_ms_equals_12_ls_equal_3d(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  [$123d.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(BRACKETED_LONGPTR_DOT_W_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(0x3d, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_negative_256_w_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  [$-256.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_HASH_TOO_LARGE exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INTEGER_NEGATIVE, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_getOperand_given_734_Square_Brac_128_expect_error(void) {
  CEXCEPTION_T ex;
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  [$128] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_STM8_OPERAND exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}


void test_getOperand_given_bracketed_dollarsign_84_dot_w_and_X_expect_shortptrwX_OPERAND_register_type_is_with_ms_equals_84(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ([$84.w],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(SHORTPTR_DOT_W_BRACKETEDX_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x84, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_dollarsign_679d_dot_w_and_X_expect_longptrwX_OPERAND_register_type_is_with_ms_equals_67_ls_equal_9d(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ([$679d.w],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(LONGPTR_DOT_W_BRACKETEDX_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x67, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(0x9d, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_dollarsign_76_dot_w_and_Y_expect_shortptrwY_OPERAND_register_type_is_with_ms_equals_76(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ([$76.w],Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(SHORTPTR_DOT_W_BRACKETEDY_OPERAND, operand->type);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL_UINT16(0x76, operand->dataSize.ms);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_7766_longptr_dot_w_bracY_expect_it_to_fail_on_value(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer(" ([$7766.w],Y)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_734_Square_BracX_without_closing_bracket_expect_to_fail(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  [$734.w  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS);

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
}


void test_getOperand_given_A_expect_A_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  A  ");
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<A_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_SP_expect_SP_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  SP  ");
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SP_OPERAND));
    TEST_FAIL_MESSAGE("Expecting ERR_INVALID_UNSUPPORTED_OPERAND exeception to be thrown.");
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_X_expect_X_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  X  ");
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<X_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_Y_expect_Y_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  Y  ");
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<Y_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_Byte_expect_Byte_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  #$12  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BYTE_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_SHORT_MEM_expect_SHORT_MEM_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  $13  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORT_MEM_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_LONG_MEM_expect_LONG_MEM_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  $1344  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<LONG_MEM_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_BracketX_expect_BracketX_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  (X)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BRACKETED_X_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_SHORTOFF_X_expect_SHORTOFF_X_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($10,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORTOFF_X_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_LONGOFF_X_expect_LONGOFF_X_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($1120,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<LONGOFF_X_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_BracketY_expect_BracketY_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  (Y)  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BRACKETED_Y_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_SHORTOFF_Y_expect_SHORTOFF_Y_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($21,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORTOFF_Y_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_LONGOFF_Y_expect_LONGOFF_Y_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($7749,Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<LONGOFF_Y_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_SHORTOFF_SP_expect_SHORTOFF_SP_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($44,SP) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORTOFF_SP_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_SHORTOFF_DOT_W_expect_SHORTOFF_DOT_W_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  [$23.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BRACKETED_SHORTPTR_DOT_W_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_LONGOFF_DOT_W_expect_LONGOFF_DOT_W_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  [$764.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BRACKETED_LONGPTR_DOT_W_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_SHORTPTR_DOT_W_BRACKETEDX_expect_SHORTPTR_DOT_W_BRACKETEDX_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ([$87.w],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_LONGPTR_DOT_W_BRACKETEDX_expect_LONGPTR_DOT_W_BRACKETEDX_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ([$8677.w],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_SHORTPTR_DOT_W_BRACKETEDY_expect_SHORTPTR_DOT_W_BRACKETEDY_to_fail_on_flags(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ([$66.w],Y) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND));

    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
}






/*
void test_error_throwing(void) {
  Tokenizer *tokenizer;
  Token *token;
  Try {
    tokenizer = createTokenizer(" 45 abu bakar ");
    token = getToken(tokenizer);
		token->affix = INFIX;
    throwException(ERR_SYSTEM_ERROR, token, "Just for fun: Do not expect a number here: %s", token->str);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
  }
}
*/
