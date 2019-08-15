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
void test_notNullCheck_given_a_expect_thrown(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  ConversionData dataFlag;
  Try{
      tokenizer = createTokenizer("  a ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      notNullCheck(tokenizer);
      TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
  } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_notNullCheck_given_NULL_expect_no_exception_thrown(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  ConversionData dataFlag;
  Try{
      tokenizer = createTokenizer("   ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      notNullCheck(tokenizer);
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
    stm8Operand * operand;
    Try{
        tokenizer = createTokenizer("  ADC A,#$55 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				freeToken(token);
        operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getDataFlag(&adcCodeInfo,tokenizer,operand);
        TEST_ASSERT_EQUAL_UINT16(A_OPERAND, dataFlag.type);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
// it throw exception due to adc doesnt support X operand which in the flag
// which this function couldnt locate the flag for X_OPERAND
void test_getDataFlag_given_adc_X_expect_null_dataFlag_throw_error(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
		ConversionData dataFlag;
    stm8Operand * operand;
    Try{
        tokenizer = createTokenizer("  ADC X,#$55 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				freeToken(token);
        operand = getOperand(tokenizer,ALL_OPERANDS);
				dataFlag = getDataFlag(&adcCodeInfo,tokenizer,operand);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_DATATABLE_NULL, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_commarCheck_given_1_expect_thrown(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  ConversionData dataFlag;
  Try{
      tokenizer = createTokenizer("  1 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      commarCheck(tokenizer);
      TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
  } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
  }
  freeTokenizer(tokenizer);
}

void test_commarCheck_given_NULL_expect_no_exception_thrown(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  ConversionData dataFlag;
  Try{
      tokenizer = createTokenizer("  , ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      commarCheck(tokenizer);
  } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
  freeTokenizer(tokenizer);
}
//bitOperationCheck is used to detect is the instruction is BCCM ,BCPL
// BSET,BRES,BTJT,BTJF to return the selection of nvalue which is 1+2*n
// or 2*n only
void test_bitOperationCheck_given_BCCM_expect_return2(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  int value;
  Try{
      tokenizer = createTokenizer("  BCCM ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      value = bitOperationCheck(token);
      TEST_ASSERT_EQUAL_INT(2,value);
  } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
  freeTokenizer(tokenizer);
}
void test_bitOperationCheck_given_BRES_expect_return2(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  int value;
  Try{
      tokenizer = createTokenizer("  BRES ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      value = bitOperationCheck(token);
      TEST_ASSERT_EQUAL_INT(2,value);
  } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
  freeTokenizer(tokenizer);
}
void test_bitOperationCheck_given_BTJF_expect_return2(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  int value;
  Try{
      tokenizer = createTokenizer("  Btjf ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      value = bitOperationCheck(token);
      TEST_ASSERT_EQUAL_INT(2,value);
  } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
  freeTokenizer(tokenizer);
}

void test_bitOperationCheck_given_BCPL_expect_return1(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  int value;
  Try{
      tokenizer = createTokenizer("  BCPL ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      value = bitOperationCheck(token);
      TEST_ASSERT_EQUAL_INT(1,value);
  } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
  freeTokenizer(tokenizer);
}
void test_bitOperationCheck_given_BSET_expect_return1(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  int value;
  Try{
      tokenizer = createTokenizer("  BSET ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      value = bitOperationCheck(token);
      TEST_ASSERT_EQUAL_INT(1,value);
  } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
  freeTokenizer(tokenizer);
}
void test_bitOperationCheck_given_BTJT_expect_return1(void){
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  int value;
  Try{
      tokenizer = createTokenizer("  Btjt ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      value = bitOperationCheck(token);
      TEST_ASSERT_EQUAL_INT(1,value);
  } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
  }
  freeTokenizer(tokenizer);
}
// get2ndCompValue will return the value which is 2nd compliment and added with
// the length of opcode which is only limited to SHORT_OFF_OPERAND
// other operand negative value will be thrown
void test_get2ndCompValue_given_jrc_neg12_expect_return_F0(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
		ConversionData dataFlag;
    stm8Operand * operand;
    int value;
    Try{
        tokenizer = createTokenizer("   JRC -$12 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				freeToken(token);
        operand = getOperand(tokenizer,(1<<SHORT_OFF_OPERAND));
				dataFlag = getDataFlag(&jrcCodeInfo,tokenizer,operand);
        value = get2ndCompValue(dataFlag,operand,tokenizer);
        TEST_ASSERT_EQUAL_HEX8(0xF0,value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_get2ndCompValue_given_jrc_hex13_expect_hex15(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
		ConversionData dataFlag;
    stm8Operand * operand;
    int value;
    Try{
        tokenizer = createTokenizer("   JRC $13");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				freeToken(token);
        operand = getOperand(tokenizer,(1<<SHORT_OFF_OPERAND));
				dataFlag = getDataFlag(&jrcCodeInfo,tokenizer,operand);
        value = get2ndCompValue(dataFlag,operand,tokenizer);
        TEST_ASSERT_EQUAL_HEX8(0x15,value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_get2ndCompValue_given_jrc_hex0_expect_hex02(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
		ConversionData dataFlag;
    stm8Operand * operand;
    int value;
    Try{
        tokenizer = createTokenizer("   JRC $0 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
				freeToken(token);
        operand = getOperand(tokenizer,(1<<SHORT_OFF_OPERAND));
				dataFlag = getDataFlag(&jrcCodeInfo,tokenizer,operand);
        value = get2ndCompValue(dataFlag,operand,tokenizer);
        TEST_ASSERT_EQUAL_HEX8(0x02,value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_addition2ndCompValueWithLength_given_hex20_expect_hex25(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    int value;
    Try{
        tokenizer = createTokenizer("   $20 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,(1<<SHORT_OFF_OPERAND));
        token = (IntegerToken *)getToken(tokenizer);
        value = addition2ndCompValueWithLength(operand,5,token);
        TEST_ASSERT_EQUAL_HEX8(0x25,value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_addition2ndCompValueWithLength_given_neghex31_expect_hexD1(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    int value;
    Try{
        tokenizer = createTokenizer("   -$31 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = getOperand(tokenizer,(1<<SHORT_OFF_OPERAND));
        token = (IntegerToken *)getToken(tokenizer);
        value = addition2ndCompValueWithLength(operand,2,token);
        TEST_ASSERT_EQUAL_HEX8(0xD1,value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_addition2ndCompValueWithLength_given_NA_expect_exception(void) {
    Tokenizer *tokenizer = NULL;
		IntegerToken * token;
    stm8Operand * operand;
    int value;
    Try{
        tokenizer = createTokenizer("   -$31 ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        operand = createOperand(BYTE_OPERAND,NA,NA,NA,NA,NA);
        token = (IntegerToken *)getToken(tokenizer);
        value = addition2ndCompValueWithLength(operand,2,token);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INTEGER_NULL, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_shortmem_byte_expect_return_byte_operand(void) {
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      tokenizer = createTokenizer("   mov $12,#$12 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      dst = getOperand(tokenizer,(1<<SHORT_MEM_OPERAND | 1<LONG_MEM_OPERAND));
      commarCheck(tokenizer);
      src = getOperand(tokenizer,( 1<<BYTE_OPERAND));
			operand = getMOVOperand(tokenizer,dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(BYTE_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_shortmem_longmem_expect_return_longmem_operand(void) {
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      tokenizer = createTokenizer("   mov $12,$1200 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      dst = getOperand(tokenizer,1<<SHORT_MEM_OPERAND);
      commarCheck(tokenizer);
      src = getOperand(tokenizer,1<<LONG_MEM_OPERAND);
      operand = getMOVOperand(tokenizer,dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_shortmem_X_expect_return_exception(void) {
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      tokenizer = createTokenizer("   mov $12,X ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      dst = getOperand(tokenizer,1<<SHORT_MEM_OPERAND);
      commarCheck(tokenizer);
      src = getOperand(tokenizer,ALL_OPERANDS);
      operand = getMOVOperand(tokenizer,dst , src );
      TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_ASSERT_EQUAL(ERR_INVALID_MOV_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_longmem_byte_expect_return_byte_operand(void) {
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      tokenizer = createTokenizer("   mov $1200,#$12 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      dst = getOperand(tokenizer,1<<LONG_MEM_OPERAND);
      commarCheck(tokenizer);
      src = getOperand(tokenizer,1<<BYTE_OPERAND);
      operand = getMOVOperand(tokenizer,dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(BYTE_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_longmem_shortmem_expect_return_longmem_operand(void) {
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      tokenizer = createTokenizer("   mov $1200,$22 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      dst = getOperand(tokenizer,1<<LONG_MEM_OPERAND);
      commarCheck(tokenizer);
      src = getOperand(tokenizer,1<<SHORT_MEM_OPERAND);
      operand = getMOVOperand(tokenizer,dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0x22, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_longmem_longmem_expect_return_longmem_operand(void) {
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      tokenizer = createTokenizer("   mov $2200,$3123 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      dst = getOperand(tokenizer,1<<LONG_MEM_OPERAND);
      commarCheck(tokenizer);
      src = getOperand(tokenizer,1<<LONG_MEM_OPERAND);
      operand = getMOVOperand(tokenizer,dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0x23, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x22, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_longmem_Y_expect_exception(void) {
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      tokenizer = createTokenizer("   mov $2200,Y ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      dst = getOperand(tokenizer,1<<LONG_MEM_OPERAND);
      commarCheck(tokenizer);
      src = getOperand(tokenizer,1<<Y_OPERAND);
      operand = getMOVOperand(tokenizer,dst , src );
      TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_ASSERT_EQUAL(ERR_INVALID_MOV_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_Y_longmem_expect_exception(void) {
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      tokenizer = createTokenizer("   mov Y,$2200 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      dst = getOperand(tokenizer,1<<Y_OPERAND);
      commarCheck(tokenizer);
      src = getOperand(tokenizer,1<<LONG_MEM_OPERAND);
      operand = getMOVOperand(tokenizer,dst , src );
      TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
      dumpTokenErrorMessage(ex, __LINE__);
      TEST_ASSERT_EQUAL(ERR_INVALID_MOV_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_getMOVOpcode_given_shortmem_shortmem_expect_return_shortmem_operand(void) {
  Tokenizer *tokenizer = NULL;
  IntegerToken * token;
  stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      tokenizer = createTokenizer("   mov $12,$12 ");
      configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
      token = (IntegerToken *)getToken(tokenizer);
      dst = getOperand(tokenizer,(1<<SHORT_MEM_OPERAND | 1<LONG_MEM_OPERAND));
      commarCheck(tokenizer);
      src = getOperand(tokenizer,(1<<SHORT_MEM_OPERAND | 1<LONG_MEM_OPERAND | 1<<BYTE_OPERAND));
      operand = getMOVOperand(tokenizer,dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(SHORT_MEM_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x12, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

// When the value in bring in as 2 which mean nvalue = 1 + 2*pos;
// When the value in bring in as 1 which mean nvalue = 2*pos;
void test_hashNValueReturn_given_commar_hash7_condition0_expect_return_0x0F(void) {
		int value;
		Tokenizer *tokenizer = NULL;
    Try{
				tokenizer = createTokenizer(" #7 ");
				value =  hashNValueReturn(tokenizer ,2);
        TEST_ASSERT_EQUAL_HEX16(0x0F,value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_hashNValueReturn_given_commar_hash2_condition1_expect_return_0x04(void) {
		int value;
		Tokenizer *tokenizer = NULL;
    Try{
				tokenizer = createTokenizer(" #2 ");
				value =  hashNValueReturn(tokenizer ,1);
        TEST_ASSERT_EQUAL_HEX16(0x04,value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_hashNValueReturn_given_commar_hash8_condition1_expect_fail_nlargerthan7(void) {
		Tokenizer *tokenizer = NULL;
		int value;
    Try{
				tokenizer = createTokenizer("  #8 ");
        value =  hashNValueReturn(tokenizer ,2);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_NVALUE, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_hashNValueReturn_given_commar_hash8_condition2_expect_fail_invalid_cmptype(void) {
		Tokenizer *tokenizer = NULL;
		int value;
    Try{
				tokenizer = createTokenizer("  #2 ");
        value =  hashNValueReturn(tokenizer ,3);
        TEST_FAIL_MESSAGE("Expecting error exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_INPUT, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_outputMachineCode_given_shortmemAA_expect_0x27AA(void) {
		stm8Operand *operand = NULL;
    MachineCode* mcode;
    int a ;
    int expectedMcode[]={0x27,0xAA,END};
    ExtensionCodeAndCode code ={NA,0x27};

    Try{
        operand = createOperand(SHORT_MEM_OPERAND,NA,NA,0xAA,NA,NA);
        a = machineCodeLengthFinder(operand,code);
				mcode =  outputMachineCode(operand ,code,a);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_outputMachineCode_given_longmemAABB_expect_0x3327AABB(void) {
		stm8Operand *operand = NULL;
    MachineCode* mcode;
    int a ;
    int expectedMcode[]={0x33,0x27,0xAA,0xBB,END};
    ExtensionCodeAndCode code ={0x33,0x27};

    Try{
        operand = createOperand(LONG_MEM_OPERAND,NA,NA,0xAA,0xBB,NA);
        a = machineCodeLengthFinder(operand,code);
				mcode =  outputMachineCode(operand ,code,a);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_outputMachineCode_given_longmemAABB_invalid_length_input_expect_NULL(void) {
		stm8Operand *operand = NULL;
    MachineCode* mcode;
    int expectedMcode[]={0x33,0x27,0xAA,0xBB,END};
    ExtensionCodeAndCode code ={0x33,0x27};

    Try{
        operand = createOperand(LONG_MEM_OPERAND,NA,NA,0xAA,0xBB,NA);
				mcode =  outputMachineCode(operand ,code,1);

    } Catch(ex) {
        TEST_ASSERT_NULL(mcode);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_machineCodeLengthFinder_given_longmemAABB_expect_4(void) {
		stm8Operand *operand = NULL;
    int a ;
    ExtensionCodeAndCode code ={0x33,0x27};

    Try{
        operand = createOperand(LONG_MEM_OPERAND,NA,NA,0xAA,0xBB,NA);
        a = machineCodeLengthFinder(operand,code);
        TEST_ASSERT_EQUAL_UINT16(4, a);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_machineCodeLengthFinder_given_shortmemBB_expect_2(void) {
		stm8Operand *operand = NULL;
    int a ;
    ExtensionCodeAndCode code ={NA,0x27};

    Try{
        operand = createOperand(SHORT_MEM_OPERAND,NA,NA,NA,0xBB,NA);
        a = machineCodeLengthFinder(operand,code);
        TEST_ASSERT_EQUAL_UINT16(2, a);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}
/*
//this movMs2ndOpValue on MachineCodeAllocateOutput used when both operand is LONG_MEM_OPERAND only for mov instruction
// nvalue is used when hashNValueReturn function is used for special instruction eg BJTF ,BJTH ,BCPL ,BCCM
//MachineCodeAllocateOutput check at last which it detect is null or not , if not null exception will be thrown
// it will take value of ExtensionCodeAndCode based on the dataFlag provided and use operand to find its value
void test_MachineCodeAllocateOutput_given_shortmemBB_expect_2(void) {
    stm8Operand *dst = NULL;
    stm8Operand *src = NULL;
    stm8Operand *operand = NULL;
    IntegerToken * token;
		Tokenizer *tokenizer = NULL;
    ConversionData  dataFlag;
    MachineCode* mcode;
    int expectedMcode[]={0x55,0x12,0x34,0xAA,0xBB,END};

    Try{
        tokenizer = createTokenizer("   mov $AABB,$1234 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        token = (IntegerToken *)getToken(tokenizer);
        dst = getOperand(tokenizer,1<<LONG_MEM_OPERAND);
        token = (IntegerToken *)getToken(tokenizer);
        pushBackToken(tokenizer , (*token)token);
        dataFlag =getDataFlag(&movCodeInfo,tokenizer,dst);
        commarCheck(tokenizer);
        src = getOperand(tokenizer,1<<LONG_MEM_OPERAND);
        operand = getMOVOperand(tokenizer,dst , src );
        mcode = machineCodeAllocateOutput(tokenizer,dataFlag ,operand, NA ,src->dataSize.ms);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
*/
