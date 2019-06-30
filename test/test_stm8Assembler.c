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

CEXCEPTION_T ex;

void setUp(void) {}

void tearDown(void) {}

void test_getOperand_given_A_expect_A_register_type_is_returned(void) {
  Token *token = NULL;
  IdentifierToken *token = NULL;
  Tokenizer *tokenizer = NULL;

  Try {
    tokenizer = createTokenizer("  A  ");
    configureTokenizer(tokenizer, TOKENIZER_DOLLAR_SIGN_HEX);

    token = getOperand(tokenizer);
    TEST_ASSERT_NOT_NULL(token);
    freeToken(token);

    token = getToken(tokenizer);
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE, token->type);
    TEST_ASSERT_EQUAL_STRING(":", token->str);
    TEST_ASSERT_EQUAL(8, tokenizer->index);
    freeToken(token);

    intToken = (IntegerToken *)getToken(tokenizer);
    TEST_ASSERT_NOT_NULL(intToken);
    TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, intToken->type);
    TEST_ASSERT_EQUAL_STRING("$abc123", intToken->str);
    TEST_ASSERT_EQUAL_HEX(0xabc123, intToken->value);
    TEST_ASSERT_EQUAL(17, tokenizer->index);
    freeToken(intToken);

    // Should return NULL token because no more operator
    token = getToken(tokenizer);
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL(TOKEN_NULL_TYPE, token->type);
    freeToken(token);
    // Should return NULL token because no more operator
    token = getToken(tokenizer);
    TEST_ASSERT_NOT_NULL(token);
    TEST_ASSERT_EQUAL(TOKEN_NULL_TYPE, token->type);
    freeToken(token);
    freeTokenizer(tokenizer);
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 1);
    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown.");
  }
}

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

