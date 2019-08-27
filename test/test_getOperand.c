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
#include "Operand.h"
CEXCEPTION_T ex;

void setUp(void) {}

void tearDown(void) {}

/*
* This is getOperand test file which test
* getOperand function
* this getOperand take the token and check the operand
* it returns stm8Type eg A_OPERAND and
* extCode, code, ms, ls ,extB
**/


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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_CC_expect_CC_register_type_is_returned(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  CC  ");
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(CC_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_hash7_expect_BYTE_OPERAND_register_type_is_with_ms_equals_7(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  #7  ");
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(BYTE_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(7, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_hash_negative_43_expect_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;
    IntegerToken *token ;
    int a;

    Try{
        tokenizer = createTokenizer("#-43");
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting ERR_INVALID_HASH_VALUE exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_HASH_VALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_dollarsign_3a3b3c_expect_EXT_MEM_OPERAND_register_type_is_with_ms_equals_3a_ls_equals_3b_extB_equals_3c(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  $3a3b3c  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(EXT_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x3a, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x3b, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(0x3c, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_XL_expect_XL_OPERAND_register_type(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  XL  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(XL_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_XL_expect_YL_OPERAND_register_type(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  YL  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(YL_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_XH_expect_XH_OPERAND_register_type(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  XH  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(XH_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_XH_expect_YH_OPERAND_register_type(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  YH  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(YH_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_Z_expect_error(void) {
    CEXCEPTION_T ex;
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  Z  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting ERR_INTEGER_NEGATIVE exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}


void test_getOperand_given_hash_1000_expect_error(void) {
    CEXCEPTION_T ex;
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  #$1234  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(WORD_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x34, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
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
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_hash_negative_1234_expect_error(void) {
    CEXCEPTION_T ex;
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  #-1234  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting ERR_INVALID_HASH_VALUE exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_HASH_VALUE, ex->errorCode);
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
    }Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_dollarsign_neg3a_expect_shortoff_OPERAND_register_type_is_with_ms_equals_C6(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  -$3a  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(SHORT_OFF_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0xC6, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    }Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_negative_hash_1264_expect_error(void) {
    CEXCEPTION_T ex;
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  -#1264  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting ERR_UNSUPPORTED_OPERAND exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_dollarsign_3c_expect_shortoff_OPERAND_register_type_is_with_ms_equals_C6(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  $3c  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,(1 << SHORT_OFF_OPERAND ));
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(SHORT_OFF_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x3c, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    }Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_dollarsign_3a_expect_longmem_OPERAND_register_type_when_shortmem_not_available_is_with_ms_equals_00_ls_equals_3a(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  $3a  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORT_MEM_OPERAND | 1 << SHORT_OFF_OPERAND ));
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_HEX16(0x3a, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    }Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_negative_3_expect_error(void) {
    CEXCEPTION_T ex;
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  $-3  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
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
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracX1234_expect_error(void) {
    CEXCEPTION_T ex;
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("   (X1234)  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracX_171_without_closing_bracket_expect_error(void) {
    CEXCEPTION_T ex;
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("   (171,X  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_INTEGER, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_2a3b4e_X_expect_EXTOFF_X_OPERAND_register_type_is_with_ms_equals_2a_ls_equal_3b_eb_equal_4e(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ($2a3b4e,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(EXTOFF_X_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x2a, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x3b, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(0x4e, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
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
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
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
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
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
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_99678d_y_expect_extoffY_OPERAND_register_type_is_with_ms_equals_99_ls_equal_67_eB_equal_8d(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ($99678d,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(EXTOFF_Y_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x99, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x67, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(0x8d, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_negative_256_sp_expect_error(void) {
    CEXCEPTION_T ex;
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  ($-256,SP) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_85_expect_shortptrw_OPERAND_register_type_is_with_ms_equals_77(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  [$85] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(BRACKETED_SHORTPTR_DOT_W_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x85, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_556d_expect_longptrw_OPERAND_register_type_is_with_ms_equals_55_ls_equal_6d(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  [$556d] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(BRACKETED_LONGPTR_DOT_W_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x55, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x6d, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}


void test_getOperand_given_negative_256_w_expect_error(void) {
    CEXCEPTION_T ex;
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  [$-256.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INTEGER_NEGATIVE, ex->errorCode);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_43_and_X_expect_shortptrwX_OPERAND_register_type_is_with_ms_equals_43(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$43],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(SHORTPTR_DOT_W_BRACKETEDX_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x43, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_7856_and_X_expectLONGPTR_DOT_W_BRACKETEDX_OPERAND_register_type_is_with_ms_equals_78_ls_equal_56(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$7856],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(LONGPTR_DOT_W_BRACKETEDX_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x78, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x56, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
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
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_58_dot_w_and_Y_expect_shortptrwY_OPERAND_register_type_is_with_ms_equals_58(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$58],Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(SHORTPTR_DOT_W_BRACKETEDY_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x58, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_58_dot_e_expected_BRACKETED_LONGPTR_DOT_E_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  [$58.e] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(BRACKETED_LONGPTR_DOT_E_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x58, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_5766_dot_e_expected_BRACKETED_LONGPTR_DOT_E_OPERAND(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  [$5766.e] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(BRACKETED_LONGPTR_DOT_E_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x57, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x66, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_12_dot_e_and_X_expect_LONGPTR_DOT_E_BRACKETEDX_OPERAND_register_type_is_with_ms_equals_00_ls_equal_12(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$12.e],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(LONGPTR_DOT_E_BRACKETEDX_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_3456_dote_and_X_expect_LONGPTR_DOT_E_BRACKETEDX_OPERAND_register_type_is_with_ms_equals_34_ls_equal_56(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$3456.e],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(LONGPTR_DOT_E_BRACKETEDX_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x34, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x56, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_4977_dot_e_and_Y_expect_LONGPTR_DOT_E_BRACKETEDY_OPERAND_register_type_is_with_ms_equals_09_ls_equal_77(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$977.e],Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(LONGPTR_DOT_E_BRACKETEDY_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x09, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x77, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_bracketed_dollarsign_34_and_Y_expect_LONGPTR_DOT_E_BRACKETEDY_OPERAND_register_type_is_with_ms_equals_00_ls_equal_34(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$34.e],Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_ASSERT_NOT_NULL(operand);
        TEST_ASSERT_EQUAL_UINT16(LONGPTR_DOT_E_BRACKETEDY_OPERAND, operand->type);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
        TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
        TEST_ASSERT_EQUAL_UINT16(0x34, operand->dataSize.ls);
        TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_7766_longptr_dot_w_bracY_expect_it_to_fail_on_value(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer(" ([$7766.w],Y)  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INTEGER_TOO_LARGE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_734_Square_BracX_without_closing_bracket_expect_to_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  [$734.w  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_7564_Square_BracX_without_closing_bracket_expect_to_fail(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  [$7564.e  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_A_expect_A_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  A  ");
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<A_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_SP_expect_SP_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  SP  ");
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1 << SP_OPERAND ));
        TEST_FAIL_MESSAGE("Expecting ERR_INVALID_UNSUPPORTED_OPERAND exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_X_expect_X_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  X  ");
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<X_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_Y_expect_Y_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  Y  ");
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<Y_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_CC_expect_CC_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  CC  ");
        operand = getOperand(tokenizer,(ALL_OPERANDS & ~(1<<CC_OPERAND)));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_Byte_expect_Byte_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  #$12  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BYTE_OPERAND | 1<<WORD_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_SHORT_MEM_expect_SHORT_MEM_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  $13  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORT_MEM_OPERAND | 1<< LONG_MEM_OPERAND | 1 <<EXT_MEM_OPERAND |1 << SHORT_OFF_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_LONG_MEM_expect_LONG_MEM_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  $1344  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<LONG_MEM_OPERAND | 1 <<EXT_MEM_OPERAND ));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_BracketX_expect_BracketX_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  (X)  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BRACKETED_X_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_SHORTOFF_X_expect_SHORTOFF_X_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ($10,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~((1<<SHORTOFF_X_OPERAND| 1<<LONGOFF_X_OPERAND) | 1<< EXTOFF_X_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_LONGOFF_X_expect_LONGOFF_X_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ($1120,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,(ALL_OPERANDS & ~(1<<LONGOFF_X_OPERAND | 1<< EXTOFF_X_OPERAND)));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_BracketY_expect_BracketY_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  (Y)  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BRACKETED_Y_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_SHORTOFF_Y_expect_SHORTOFF_Y_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ($21,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORTOFF_Y_OPERAND | 1<< LONGOFF_Y_OPERAND | 1<< EXTOFF_Y_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_LONGOFF_Y_expect_LONGOFF_Y_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ($7749,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<LONGOFF_Y_OPERAND | 1<< EXTOFF_Y_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_SHORTOFF_SP_expect_SHORTOFF_SP_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ($44,SP) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORTOFF_SP_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_SHORTOFF_DOT_W_expect_SHORTOFF_DOT_W_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  [$23.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BRACKETED_SHORTPTR_DOT_W_OPERAND | 1<<BRACKETED_LONGPTR_DOT_W_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_LONGOFF_DOT_W_expect_LONGOFF_DOT_W_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  [$764.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BRACKETED_LONGPTR_DOT_W_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_SHORTPTR_DOT_W_BRACKETEDX_expect_SHORTPTR_DOT_W_BRACKETEDX_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$87.w],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORTPTR_DOT_W_BRACKETEDX_OPERAND | 1<< LONGPTR_DOT_W_BRACKETEDX_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_LONGPTR_DOT_W_BRACKETEDX_expect_LONGPTR_DOT_W_BRACKETEDX_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$8677.w],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<LONGPTR_DOT_W_BRACKETEDX_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_SHORTPTR_DOT_W_BRACKETEDY_expect_SHORTPTR_DOT_W_BRACKETEDY_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$66.w],Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<SHORTPTR_DOT_W_BRACKETEDY_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_LONGPTR_DOT_E_BRACKETEDX_OPERAND_expect_LONGPTR_DOT_E_BRACKETEDX_OPERAND_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$66.e],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<LONGPTR_DOT_E_BRACKETEDX_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_BRACKETED_LONGPTR_DOT_E_OPERAND_expect_BRACKETED_LONGPTR_DOT_E_OPERAND_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$5678.e]) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<BRACKETED_LONGPTR_DOT_E_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getOperand_given_LONGPTR_DOT_E_BRACKETEDY_OPERAND_expect_LONGPTR_DOT_E_BRACKETEDY_OPERAND_to_fail_on_flags(void) {
    stm8Operand *operand = NULL;
    Tokenizer *tokenizer = NULL;

    Try {
        tokenizer = createTokenizer("  ([$345.e],Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,ALL_OPERANDS & ~(1<<LONGPTR_DOT_E_BRACKETEDY_OPERAND));
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpErrorMessage(ex);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
