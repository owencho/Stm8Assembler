#include <stdlib.h>
#include <errno.h>
#include "unity.h"
#include "Common.h"
#include "Token.h"
#include "Error.h"
#include "mock_Tokenizer.h"
#include "CException.h"
#include "Exception.h"

void setUp(void) {}

void tearDown(void) {}

void test_getToken_given_23_plus_47() {
  Token *token, *value1Token, *value2Token, *plusToken;
  OperatorToken *opToken;
  IntegerToken *intToken;
  Tokenizer dummyTokenizer, *tokenizer = (Tokenizer *)&dummyTokenizer;
  char *line = " 23 + 47 ";

  value1Token = createIntegerToken(23, "23");
  value2Token = createIntegerToken(47, "47");
  plusToken = createOperatorToken("+", "+");

  initTokenizer_ExpectAndReturn(line, tokenizer);
  getToken_ExpectAndReturn(tokenizer, value1Token);
  getToken_ExpectAndReturn(tokenizer, plusToken);
  getToken_ExpectAndReturn(tokenizer, value2Token);

  tokenizer = initTokenizer(line);
  intToken = (IntegerToken *)getToken(tokenizer);

  TEST_ASSERT_NOT_NULL(intToken);
  TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, intToken->type);
  TEST_ASSERT_EQUAL(23, intToken->value);
  freeToken(intToken);

  opToken = (OperatorToken *)getToken(tokenizer);
  TEST_ASSERT_NOT_NULL(opToken);
  TEST_ASSERT_EQUAL(TOKEN_OPERATOR_TYPE, opToken->type);
  TEST_ASSERT_EQUAL_STRING("+", opToken->str);
  freeToken(opToken);

  intToken = (IntegerToken *)getToken(tokenizer);
  TEST_ASSERT_NOT_NULL(intToken);
  TEST_ASSERT_EQUAL(TOKEN_INTEGER_TYPE, intToken->type);
  TEST_ASSERT_EQUAL(47, intToken->value);
  freeToken(intToken);
}
