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
#include "AssignValue.h"
#include "StringLib.h"


CEXCEPTION_T ex;

void setUp(void) {}

void tearDown(void) {}

void test_getOperand_given_A_expect_A_register_type_is_returned(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  A  ");
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL_UINT16(A_OPERAND, operand->type);
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


void test_getOperand_given_hash55_expect_BYTE_OPERAND_register_type_is_with_ms_equals_55(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  #55  ");
    operand = getOperand(tokenizer);
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
    operand = getOperand(tokenizer);
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

void test_getOperand_given_dollarsign_3a7d_expect_shortmem_OPERAND_register_type_is_with_ms_equals_55(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  $3a7d  ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer);
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


void test_getOperand_given_bracketedX_expect_BracX_Operand(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  (X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(BRACKETED_X_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_Space_X_expect_BracX_Operand(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ( X ) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(BRACKETED_X_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
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
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(SHORTOFF_X_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(0x161, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_dollarsign_517d_X_expect_Brac_OPERAND_register_type_is_with_ms_equals_51_ls_equal_7d(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($517d,X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(LONGOFF_X_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(0x51, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(0x7d, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
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
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(BRACKETED_Y_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(0x90, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
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
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(SHORTOFF_Y_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(0x90, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(0x207, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
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
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(LONGOFF_Y_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(0x90, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(0x67, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(0x8d, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_dollarsign_678d_SP_expect_SP_OPERAND_register_type_is_with_ms_equals_10(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ($10,SP) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(SHORTOFF_SP_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(0x10, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}

void test_getOperand_given_bracketed_dollarsign_77_dot_w_expect_shortptrw_OPERAND_register_type_is_with_ms_equals_77(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  [$77.w] ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(BRACKETED_SHORTPTR_DOT_W_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(0x92, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(0x77, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
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
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(BRACKETED_LONGPTR_DOT_W_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(0x72, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(0x12, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(0x3d, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
  }
}


void test_getOperand_given_bracketed_dollarsign_84_dot_w_and_X_expect_shortptrwX_OPERAND_register_type_is_with_ms_equals_84(void) {
  stm8Operand *operand = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  ([$84d.w],X) ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(SHORTPTR_DOT_W_BRACKETEDX_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(0x92, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(0x84, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
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
    operand = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(operand);
    TEST_ASSERT_EQUAL(LONGPTR_DOT_W_BRACKETEDX_OPERAND, operand->type);
    TEST_ASSERT_EQUAL(0x72, operand->dataSize.extCode);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.code);
    TEST_ASSERT_EQUAL(0x67, operand->dataSize.ms);
    TEST_ASSERT_EQUAL(0x9d, operand->dataSize.ls);
    TEST_ASSERT_EQUAL(NA, operand->dataSize.extB);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
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
