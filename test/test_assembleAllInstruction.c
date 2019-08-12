#include "assembleAllInstruction.h"
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

void setUp(void)
{
}

void tearDown(void)
{
}

void test_getDataFlag_given_bccmCodeINfo_comp_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
		ConversionData dataFlag;
    Try{
        tokenizer = createTokenizer("  bccm $12 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				freeToken(token);
				dataFlag = getDataFlag(&bccmCodeInfo,tokenizer);
				TEST_ASSERT_EQUAL_STRING("COMP", dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getDataFlag_given_adc_A_expect_pass(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
		ConversionData dataFlag;
    Try{
        tokenizer = createTokenizer("  adc A, #$12 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				freeToken(token);
				dataFlag = getDataFlag(&adcCodeInfo,tokenizer);
				TEST_ASSERT_EQUAL_STRING("A", dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getDataFlag_given_adc_Z_expect_null_dataFlag(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
		ConversionData dataFlag;
    Try{
        tokenizer = createTokenizer("  adc Z, #$12 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				freeToken(token);
				dataFlag = getDataFlag(&adcCodeInfo,tokenizer);
				TEST_ASSERT_EQUAL_STRING(NULL, dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getLDWDataFlag_given_X_expect_return_COMPX_dataFlag(void) {
		stm8Operand *operand = NULL;
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("  X ");
				operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getLDWDataFlag(&ldwCodeInfo,operand);
				TEST_ASSERT_EQUAL_STRING("COMPX", dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getLDWDataFlag_given_Y_expect_return_COMPY_dataFlag(void) {
		stm8Operand *operand = NULL;
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("  Y ");
				operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getLDWDataFlag(&ldwCodeInfo,operand);
				TEST_ASSERT_EQUAL_STRING("COMPY", dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getLDWDataFlag_given_CC_expect_return_null_dataFlag(void) {
		stm8Operand *operand = NULL;
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("  CC ");
				operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getLDWDataFlag(&ldwCodeInfo,operand);
				TEST_ASSERT_EQUAL_STRING(NULL, dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVDataFlag_given_shortmem_expect_return_SHORT_dataFlag(void) {
		stm8Operand *operand = NULL;
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("  $12 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getMOVDataFlag(&movCodeInfo,operand);
				TEST_ASSERT_EQUAL_STRING("SHORT", dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVDataFlag_given_longmem_expect_return_LONG_dataFlag(void) {
		stm8Operand *operand = NULL;
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("  $1222 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getMOVDataFlag(&movCodeInfo,operand);
				TEST_ASSERT_EQUAL_STRING("LONG", dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVDataFlag_given_CC_expect_return_null_dataFlag(void) {
		stm8Operand *operand = NULL;
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("  CC ");
				operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getMOVDataFlag(&movCodeInfo,operand);
				TEST_ASSERT_EQUAL_STRING(NULL, dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_shortmem_shortmem_expect_return_shortmem_operand_dataFlag(void) {
	stm8Operand *operand = NULL;
	stm8Operand *operand2 = NULL;
	Tokenizer *tokenizer = NULL;
	Tokenizer *tokenizer2 = NULL;
	ConversionData dataFlag;
	Try{
			tokenizer = createTokenizer("  $12 ");
			configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
			operand = getOperand(tokenizer,ALL_OPERANDS);
			tokenizer2 = createTokenizer("  $31 ");
			configureTokenizer(tokenizer2,TOKENIZER_DOLLAR_SIGN_HEX);
			operand2 = getOperand(tokenizer2,ALL_OPERANDS);
			operand = getMOVOpcode(operand , operand2 );
			TEST_ASSERT_EQUAL_UINT16(SHORT_MEM_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0x31, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
/*
void test_getMOVDataFlag_given_longmem_expect_return_LONG_dataFlag(void) {
		stm8Operand *operand = NULL;
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("  $1222 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getMOVOpcode(&movCodeInfo,operand);
				TEST_ASSERT_EQUAL_STRING("LONG", dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVDataFlag_given_CC_expect_return_null_dataFlag(void) {
		stm8Operand *operand = NULL;
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("  CC ");
				operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getMOVDataFlag(&movCodeInfo,operand);
				TEST_ASSERT_EQUAL_STRING(NULL, dataFlag.name) ;
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
*/
