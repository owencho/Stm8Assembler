#include <stdlib.h>
#include <errno.h>
#include "unity.h"
#include "SimpleArithmetic.h"
#include "Common.h"
#include "Token.h"
#include "Error.h"
#include "mock_Tokenizer.h"
#include "CException.h"
#include "Exception.h"

void setUp(void) {}

void tearDown(void) {}

void test_getToken_with_mock_given_23_plus_47() {
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

void test_operateOn2Numbers_with_getToken_mock_given_987_multiply_161_expect_158907() {
  CEXCEPTION_T e;
  Token *token, *value1Token, *value2Token, *plusToken;
  OperatorToken *opToken;
  IntegerToken *intToken;
  Tokenizer dummyTokenizer, *tokenizer = (Tokenizer *)&dummyTokenizer;
  int result;
  char *line = " 987 * 161 ";     // This line is for readability only

  // Fake values
  value1Token = createIntegerToken(987, "987");
  value2Token = createIntegerToken(161, "161");
  plusToken = createOperatorToken("*", "*");
  // Mock with the fake values
  initTokenizer_ExpectAndReturn(line, tokenizer);
  getToken_ExpectAndReturn(tokenizer, value1Token);
  getToken_ExpectAndReturn(tokenizer, plusToken);
  getToken_ExpectAndReturn(tokenizer, value2Token);
  // Run test
  Try {
    tokenizer = initTokenizer(line);
    result = operateOn2Numbers(tokenizer);
    printf("987 * 161 = %d\n", result);
    TEST_ASSERT_EQUAL(158907, result);
  } Catch(e) {
    // Catch and display exception if it has been thrown
    printf("Err: %s", e->msg);
    TEST_FAIL_MESSAGE("System Error: Don't expect any exception to be thrown!");
  }
}

void test_operateOn2Numbers_with_getToken_mock_given_48_subtract_920_expect_minus872() {
  CEXCEPTION_T e;
  Token *token, *value1Token, *value2Token, *plusToken;
  OperatorToken *opToken;
  IntegerToken *intToken;
  Tokenizer dummyTokenizer, *tokenizer = (Tokenizer *)&dummyTokenizer;
  int result;
  char *line = " 48 - 920 ";     // This line is for readability only

  // Fake values
  value1Token = createIntegerToken(48, "48");
  value2Token = createIntegerToken(920, "920");
  plusToken = createOperatorToken("-", "-");
  // Mock with the fake values
  initTokenizer_ExpectAndReturn(line, tokenizer);
  getToken_ExpectAndReturn(tokenizer, value1Token);
  getToken_ExpectAndReturn(tokenizer, plusToken);
  getToken_ExpectAndReturn(tokenizer, value2Token);
  // Run test
  Try {
    tokenizer = initTokenizer(line);
    result = operateOn2Numbers(tokenizer);
    printf("48 - 920 = %d\n", result);
    TEST_ASSERT_EQUAL(-872, result);
  } Catch(e) {
    // Catch and display exception if it has been thrown
    printf("Err: %s", e->msg);
    TEST_FAIL_MESSAGE("System Error: Don't expect any exception to be thrown!");
  }
}
