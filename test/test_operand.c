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
void test_symbolOperandCheck_given_A_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  A ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_ASSERT_EQUAL_UINT16(A_OPERAND, opType);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_symbolOperandCheck_given_X_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  X");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_ASSERT_EQUAL_UINT16(X_OPERAND, opType);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_symbolOperandCheck_given_Y_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  Y ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_ASSERT_EQUAL_UINT16(Y_OPERAND, opType);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_symbolOperandCheck_given_SP_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  SP ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_ASSERT_EQUAL_UINT16(SP_OPERAND, opType);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_symbolOperandCheck_given_XL_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  XL ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_ASSERT_EQUAL_UINT16(XL_OPERAND, opType);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_symbolOperandCheck_given_YL_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  YL ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_ASSERT_EQUAL_UINT16(YL_OPERAND, opType);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_symbolOperandCheck_given_YH_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  YH ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_ASSERT_EQUAL_UINT16(YH_OPERAND, opType);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_symbolOperandCheck_given_XH_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  Xh ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_ASSERT_EQUAL_UINT16(XH_OPERAND, opType);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_symbolOperandCheck_given_CC_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  cc ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_ASSERT_EQUAL_UINT16(CC_OPERAND, opType);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_symbolOperandCheck_given_z_expect_fail(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  z ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				opType = symbolOperandCheck(token);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_squareBracketFlagCheck_given_shortptrw_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  [$22] ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        pushBackToken(tokenizer,(Token*)token);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        pushBackToken(tokenizer,(Token*)token);
        token = (IntegerToken *)getToken(tokenizer);
        squareBracketFlagCheck(token, operand ,1<<BRACKETED_SHORTPTR_DOT_W_OPERAND);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_squareBracketFlagCheck_given_longptrw_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  [$2222] ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        pushBackToken(tokenizer,(Token*)token);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        pushBackToken(tokenizer,(Token*)token);
        token = (IntegerToken *)getToken(tokenizer);
        squareBracketFlagCheck(token, operand ,1<<BRACKETED_LONGPTR_DOT_W_OPERAND);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_squareBracketFlagCheck_given_longptre_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  [$2222.e] ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        pushBackToken(tokenizer,(Token*)token);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        pushBackToken(tokenizer,(Token*)token);
        token = (IntegerToken *)getToken(tokenizer);
        squareBracketFlagCheck(token, operand ,1<<BRACKETED_LONGPTR_DOT_E_OPERAND);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_squareBracketFlagCheck_given_X_expect_fail(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    Try{
        tokenizer = createTokenizer("  X ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        pushBackToken(tokenizer,(Token*)token);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        pushBackToken(tokenizer,(Token*)token);
        token = (IntegerToken *)getToken(tokenizer);
        squareBracketFlagCheck(token, operand ,ALL_OPERANDS);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_signedIntCheck_given_hash22_expect_22(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    int value;
    Try{
        tokenizer = createTokenizer("  $22 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        value = signedIntCheck(tokenizer);
        TEST_ASSERT_EQUAL_HEX16(0x22, value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_signedIntCheck_given_hash0_expect_0x00(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    int value;
    Try{
        tokenizer = createTokenizer("  $0 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        value = signedIntCheck(tokenizer);
        TEST_ASSERT_EQUAL_HEX16(0x0, value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_signedIntCheck_given_hash7F_expect_0x7F(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    int value;
    Try{
        tokenizer = createTokenizer("  $7F ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        value = signedIntCheck(tokenizer);
        TEST_ASSERT_EQUAL_HEX16(0x7F, value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_signedIntCheck_given_hash80_expect_fail(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    int value;
    Try{
        tokenizer = createTokenizer("  $80 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        value = signedIntCheck(tokenizer);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SIGNEDINT_VALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_signedIntCheck_given_hashneg31_expect_0xCF(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    int value;
    Try{
        tokenizer = createTokenizer("  -$31 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        value = signedIntCheck(tokenizer);
        TEST_ASSERT_EQUAL_HEX16(0xCF, value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_signedIntCheck_given_hashneg0_expect_0x00(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    int value;
    Try{
        tokenizer = createTokenizer("  -$0 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        value = signedIntCheck(tokenizer);
        TEST_ASSERT_EQUAL_HEX16(0x0, value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_signedIntCheck_given_hashneg80_expect_0x80(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    int value;
    Try{
        tokenizer = createTokenizer("  -$80 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        value = signedIntCheck(tokenizer);
        TEST_ASSERT_EQUAL_HEX16(0x80, value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_signedIntCheck_given_hashneg81_expect_fail(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    stm8OperandType opType;
    int value;
    Try{
        tokenizer = createTokenizer("  -$81 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        value = signedIntCheck(tokenizer);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SIGNEDINT_VALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_extendTokenStr_given_AB_expect_tokenstr_AB(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    IntegerToken * initToken;
    IntegerToken * flagToken;
    stm8Operand * operand;
    stm8OperandType opType;
    int value;
    Try{
        tokenizer = createTokenizer("  A B ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        initToken = (IntegerToken *)getToken(tokenizer);
        token = (IntegerToken *)getToken(tokenizer);
        flagToken =extendTokenStr(initToken ,token);
        TEST_ASSERT_EQUAL_STRING("A B", flagToken->str);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_nullCheck_given_empty_expect_error_thrown(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;

    Try{
        tokenizer = createTokenizer("    ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        nullCheck(ERR_INVALID_SYNTAX,token,"NULL detected");
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        nullCheck(ERR_INVALID_SYNTAX,token,"Expected w after .");
        TEST_ASSERT_NOT_NULL(token->str);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandFlagCheck_given_X_expect_pass_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;

    Try{
        tokenizer = createTokenizer(" X ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operandFlagCheck(ALL_OPERANDS,token ,X_OPERAND );
        TEST_ASSERT_NOT_NULL(token->str);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandFlagCheck_given_X_expect_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;

    Try{
        tokenizer = createTokenizer(" X ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operandFlagCheck((1<<Y_OPERAND),token ,X_OPERAND);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
//valueCheck is used to check is this value ls or ms
// ls will return 1 (<256)
// ms will return 2 (>256)
// ext will return 3 (>65535)

void test_valueCheck_given_hash23_expect_return_1(void) {
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_hash2543_expect_return_2(void) {
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_hashFFFFFF_expect_return_3(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$FFFFFF");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        int a = valueCheck(token);
        TEST_ASSERT_EQUAL(3,a);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_negative_hashFFFFFFF_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$FFFFFFF");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        int a = valueCheck(token);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_negative_hash1234_expect_fail(void) {
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
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_NEGATIVE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_0_expect_return_1(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("0");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        int a = valueCheck(token);
        TEST_ASSERT_EQUAL(1,a);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_256_expect_return_2(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("256");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        int a = valueCheck(token);
        TEST_ASSERT_EQUAL(2,a);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_65536_expect_return_3(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("65536");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        int a = valueCheck(token);
        TEST_ASSERT_EQUAL(3,a);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_123456679_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("123456679");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        int a = valueCheck(token);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_negative_hash1234_expect_pass(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("-$1234");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        int a = valueCheck(token);
        TEST_ASSERT_EQUAL(4,a);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_valueCheck_given_z_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("z");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        int a = valueCheck(token);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_createOperand_given_SHORTOFFX90_SHORTOFF_X_OPERAND_with_0x90(void) {
    stm8Operand *operand = NULL;
    Try{
      operand = createOperand(SHORTOFF_X_OPERAND, NA, NA, 0x90, NA,NA);
      TEST_ASSERT_NOT_NULL(operand);
      TEST_ASSERT_EQUAL_UINT16(SHORTOFF_X_OPERAND, operand->type);
      TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
      TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
      TEST_ASSERT_EQUAL_UINT16(0x90, operand->dataSize.ms);
      TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
      TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_createOperand_given_EXTOFFX903133_expect_EXTOFF_X_OPERAND_with_0x903133(void) {
    stm8Operand *operand = NULL;
    Try{
      operand = createOperand(EXTOFF_X_OPERAND, NA, NA, 0x90, 0x31,0x33);
      TEST_ASSERT_NOT_NULL(operand);
      TEST_ASSERT_EQUAL_UINT16(EXTOFF_X_OPERAND, operand->type);
      TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
      TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
      TEST_ASSERT_EQUAL_UINT16(0x90, operand->dataSize.ms);
      TEST_ASSERT_EQUAL_UINT16(0x31, operand->dataSize.ls);
      TEST_ASSERT_EQUAL_UINT16(0x33, operand->dataSize.extB);
    } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_createLsOperand_given_hash12_expect_pass(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$FF");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createLsOperand(SHORT_MEM_OPERAND, token->value,token);
        TEST_ASSERT_EQUAL_UINT16(SHORT_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0xFF, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_createLsOperand_given_hash0_expect_pass(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$0");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createLsOperand(SHORT_MEM_OPERAND, token->value,token);
        TEST_ASSERT_EQUAL_UINT16(SHORT_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x0, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_createLsOperand_given_hash100_expect_exception(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$100");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createMsOperand(SHORT_MEM_OPERAND, token->value,token);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_createMsOperand_given_hashFFFF_expect_pass(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$FFFF");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createMsOperand(LONG_MEM_OPERAND, token->value,token);
        TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0xFF, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0xFF, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_createMsOperand_given_hash0_expect_pass(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$0");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createMsOperand(LONG_MEM_OPERAND, token->value,token);
        TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_createMsOperand_given_hash100000_expect_exception(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$10000");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createMsOperand(LONG_MEM_OPERAND, token->value,token);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_createExtMemOperand_given_hashFFFFFF_expect_pass(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$FFFFFF");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createExtMemOperand(EXT_MEM_OPERAND, token->value,token);
        TEST_ASSERT_EQUAL_UINT16(EXT_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0xFF, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0xFF, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(0xFF, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_createExtMemOperand_given_0_expect_pass(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("0");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createExtMemOperand(EXT_MEM_OPERAND, token->value,token);
        TEST_ASSERT_EQUAL_UINT16(EXT_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_createExtMemOperand_given_hash1FFFFFF_expect_exception(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("$1ffffff");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createExtMemOperand(EXT_MEM_OPERAND, token->value,token);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

//comparingLastOperand

// this operandHandleFirstSymbol supports A ,XL ,YL ,X ,Y ,SP ,YH ,XH ,CC operand
void test_operandHandleFirstSymbol_given_X_expect_X_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" X ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleFirstSymbol(tokenizer ,ALL_OPERANDS);
        TEST_ASSERT_EQUAL_UINT16(X_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleFirstSymbol_given_Y_expect_Y_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" Y ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleFirstSymbol(tokenizer ,ALL_OPERANDS);
        TEST_ASSERT_EQUAL_UINT16(Y_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleFirstSymbol_given_Z_expect_exception(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" Z ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleFirstSymbol(tokenizer ,ALL_OPERANDS);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleHash_given_hashbyte_with_flag_support_expect_byte_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" #$21 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleHash(tokenizer ,(1<<BYTE_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(BYTE_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x21, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleHash_given_hashbyte_without_flag_support_expect_word_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" #$23 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleHash(tokenizer ,(1<<WORD_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(WORD_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x23, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleHash_given_hashword_with_flag_support_expect_word_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" #$2121 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleHash(tokenizer ,(1<<WORD_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(WORD_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x21, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x21, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleHash_given_hash_byte_flag_unsupported_expect_error(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" #$21 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleHash(tokenizer ,ALL_OPERANDS & ~(1<<WORD_OPERAND | 1<< BYTE_OPERAND));
      } Catch(ex) {
          dumpTokenErrorMessage(ex, __LINE__);
          TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleHash_given_hash_word_flag_unsupported_expect_error(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" #$2121 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleHash(tokenizer ,ALL_OPERANDS & ~(1<<WORD_OPERAND));
      } Catch(ex) {
          dumpTokenErrorMessage(ex, __LINE__);
          TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleHash_given_hash_extmem__expect_error(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" #$212111 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleHash(tokenizer ,(1<<WORD_OPERAND));
      } Catch(ex) {
          dumpTokenErrorMessage(ex, __LINE__);
          TEST_ASSERT_EQUAL(ERR_INVALID_HASH_VALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleHash_given_hash_negative_word_expect_error(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" #-$2121 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleHash(tokenizer ,ALL_OPERANDS);
      } Catch(ex) {
          dumpTokenErrorMessage(ex, __LINE__);
          TEST_ASSERT_EQUAL(ERR_INVALID_HASH_VALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
void test_operandHandleValue_given_shortmem_with_flag_support_expect_shortmem_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $21 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,(1<<SHORT_MEM_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(SHORT_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x21, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_shortmem_with_onlyLONGMEM_flag_support_expect_longmem_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $11");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,(1<<LONG_MEM_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x11, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_shortmem_with_onlyEXTMEM_flag_support_expect_EXTmem_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $31");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,(1<<EXT_MEM_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(EXT_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(0x31, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_longmem_with_flag_support_expect_longmem_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $211");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,(1<<LONG_MEM_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x02, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x11, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_longmem_with_onlyEXTMEM_flag_support_expect_EXTmem_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $1122");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,(1<<EXT_MEM_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(EXT_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x11, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(0x22, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_extmem_with_onlyEXTMEM_flag_support_expect_EXTmem_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $FF1122");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,(1<<EXT_MEM_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(EXT_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0xFF, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x11, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(0x22, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_12shortoff_with_flag_support_expect_shortoff_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $12");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,(1<<SHORT_OFF_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(SHORT_OFF_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_neg22_shortoff_with_flag_support_expect_shortoff_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" -$22");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,(1<<SHORT_OFF_OPERAND));
        TEST_ASSERT_EQUAL_UINT16(SHORT_OFF_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0xDE, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_shortmem_without_flag_support_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $22");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,ALL_OPERANDS &&
                                      ~(1<<SHORT_MEM_OPERAND |1<<SHORT_OFF_OPERAND |
                                        1 << LONG_MEM_OPERAND | 1<< EXT_MEM_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_longmem_without_flag_support_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $2213");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,ALL_OPERANDS &&
                                      ~(1 << LONG_MEM_OPERAND | 1<< EXT_MEM_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_extmem_without_flag_support_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" $221314");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,ALL_OPERANDS && ~( 1<< EXT_MEM_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleValue_given_neg_shortmem_without_flag_support_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" -$12");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleValue(tokenizer ,ALL_OPERANDS && ~( 1<< SHORT_OFF_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_hex12_shortptrw_with_flag_support_expect_shortptrw_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$12.w]");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_ASSERT_EQUAL_UINT16(BRACKETED_SHORTPTR_DOT_W_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_hex14_shortptrw_with_flag_support_expect_shortptrw_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$14]");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_ASSERT_EQUAL_UINT16(BRACKETED_SHORTPTR_DOT_W_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x14, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_hex232_longptrw_with_flag_support_expect_longptrw_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$232]");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_ASSERT_EQUAL_UINT16(BRACKETED_LONGPTR_DOT_W_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x02, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x32, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_hex1332_longptre_with_flag_support_expect_longptre_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$1332.e]");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_ASSERT_EQUAL_UINT16(BRACKETED_LONGPTR_DOT_E_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x13, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x32, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_empty_square_brac_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" []");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_missing_we_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$2.]");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_missing_closing_bracket_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$2.w ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_extmem_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$22331.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
void test_operandHandleSquareBracket_given_extmem_dote_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$22331.e] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_extmem_withoutdot_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$22331] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_neg_shortoff_dote_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [-$22.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_NEGATIVE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_operandHandleSquareBracket_given_unsupportedflag_shortoff_dote_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer(" [$22.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = operandHandleSquareBracket(tokenizer ,ALL_OPERANDS && ~(1<<BRACKETED_SHORTPTR_DOT_W_OPERAND |1<<BRACKETED_LONGPTR_DOT_W_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
