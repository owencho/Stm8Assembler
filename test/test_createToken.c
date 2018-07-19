#include <stdlib.h>
#include <errno.h>
#include "unity.h"
#include "Common.h"
#include "Token.h"
#include "Error.h"
#include "Tokenizer.h"
#include "CException.h"
#include "Exception.h"

void setUp(void) {}

void tearDown(void) {}

void test_createNullToken() {
  Token *token;

  token = createNullToken();

  TEST_ASSERT_NOT_NULL(token);
  TEST_ASSERT_EQUAL(TOKEN_NULL_TYPE, token->type);
  TEST_ASSERT_NULL(token->originalStr);
  freeToken(token);
}

void test_createIntegerToken_given_value_123() {
  Token *token;
  IntegerToken *intToken;

  token = createIntegerToken(123, "123");
  intToken = (IntegerToken *)token;

  TEST_ASSERT_NOT_NULL(intToken);
  TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, intToken->type);
  TEST_ASSERT_EQUAL(123, intToken->value);
  TEST_ASSERT_EQUAL_STRING("123", intToken->originalStr);
  freeToken(intToken);
}

void test_createFloatToken_given_1234_5678e_minus4() {
  Token *token;
  FloatToken *floatToken;

  token = createFloatToken(1234.5678e-4, "1234.5678e-4");
  floatToken = (FloatToken *)token;

  TEST_ASSERT_NOT_NULL(floatToken);
  TEST_ASSERT_EQUAL(TOKEN_FLOAT_TYPE, floatToken->type);
  TEST_ASSERT_FLOAT_WITHIN(1.0e-7, 1234.5678e-4, floatToken->value);
  TEST_ASSERT_EQUAL_STRING("1234.5678e-4", floatToken->originalStr);
  freeToken(floatToken);
}

void test_createIdentifierToken_given_Hello_string() {
  Token *token;
  IdentifierToken *idToken;

  token = createIdentifierToken("Hello", "Hello");
  idToken = (IdentifierToken *)token;

  TEST_ASSERT_NOT_NULL(idToken);
  TEST_ASSERT_EQUAL(TOKEN_IDENTIFIER_TYPE, idToken->type);
  TEST_ASSERT_EQUAL_STRING("Hello", idToken->str);
  TEST_ASSERT_EQUAL_STRING("Hello", idToken->originalStr);
  freeToken(idToken);
}


