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
				dataFlag = getLDWComplexDataFlag(&ldwCodeInfo,operand);
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
				dataFlag = getLDWComplexDataFlag(&ldwCodeInfo,operand);
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
				dataFlag = getLDWComplexDataFlag(&ldwCodeInfo,operand);
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

void test_getMOVDataFlag_given_mov_CC_expect_return_null_dataFlag(void) {
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

void test_getMOVOpcode_given_longmem_byte_expect_return_byte_operand_dataFlag(void) {
	stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      dst = createOperand(LONG_MEM_OPERAND,NA,NA,0x80,0x00,NA);
      src = createOperand(BYTE_OPERAND,NA,NA,0xAA,NA,NA);
			operand = getMOVOpcode(dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(BYTE_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0xAA, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x80, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_getMOVOpcode_given_longmem_longmem_expect_return_longmem_operand_dataFlag(void) {
	stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      dst = createOperand(LONG_MEM_OPERAND,NA,NA,0x80,0x00,NA);
      src = createOperand(LONG_MEM_OPERAND,NA,NA,0xAA,0x11,NA);
			operand = getMOVOpcode(dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(LONG_MEM_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0x11, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x80, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(0x00, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_getMOVOpcode_given_shortmem_shortmem_expect_return_shortmem_operand_dataFlag(void) {
	stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      dst = createOperand(SHORT_MEM_OPERAND,NA,NA,0x80,NA,NA);
      src = createOperand(SHORT_MEM_OPERAND,NA,NA,0xAA,NA,NA);
			operand = getMOVOpcode(dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(SHORT_MEM_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(0xAA, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(0x80, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_getMOVOpcode_given_EXTMEM_shortmem_expect_return_no_operand_dataFlag(void) {
	stm8Operand *dst = NULL;
	stm8Operand *src = NULL;
  stm8Operand *operand = NULL;
	ConversionData dataFlag;
	Try{
      dst = createOperand(EXT_MEM_OPERAND,NA,NA,0x80,0x88,0x33);
      src = createOperand(SHORT_MEM_OPERAND,NA,NA,0xAA,NA,NA);
			operand = getMOVOpcode(dst , src );
      TEST_ASSERT_NOT_NULL(operand);
			TEST_ASSERT_EQUAL_UINT16(NO_OPERAND, operand->type);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extCode);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.code);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ms);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.ls);
			TEST_ASSERT_EQUAL_UINT16(NA, operand->dataSize.extB);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
}

void test_commarCheck_given_commar_expect_pass(void) {
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("  ,  ");
				commarCheck(tokenizer);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_commarCheck_given_not_commar_expect_fail(void) {
		Tokenizer *tokenizer = NULL;
		ConversionData dataFlag;
    Try{
				tokenizer = createTokenizer("   x ");
				commarCheck(tokenizer);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

// When the value in bring in as 1 which mean nvalue = 1 + 2*pos;
// When the value in bring in as 0 which mean nvalue = 2*pos;
void test_hashNValueReturn_given_commar_hash7_condition0_expect_return_0x0F(void) {
		int value;
		Tokenizer *tokenizer = NULL;
    Try{
				tokenizer = createTokenizer(" #7 ");
				value =  hashNValueReturn(tokenizer ,1);
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
				value =  hashNValueReturn(tokenizer ,0);
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
        value =  hashNValueReturn(tokenizer ,1);
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
        value =  hashNValueReturn(tokenizer ,2);
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
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
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

//this movMs2ndOpValue on MachineCodeAllocateOutput used when both operand is LONG_MEM_OPERAND only for mov instruction
// nvalue is used when hashNValueReturn function is used for special instruction eg BJTF ,BJTH ,BCPL ,BCCM
//MachineCodeAllocateOutput check at last which it detect is null or not , if not null exception will be thrown
// it will take value of ExtensionCodeAndCode based on the dataFlag provided and use operand to find its value

void test_MachineCodeAllocateOutput_given_shortmemBB_expect_2(void) {
    stm8Operand *operand = NULL;
    stm8Operand *operand2nd = NULL;
    IntegerToken * token;
		Tokenizer *tokenizer = NULL;
    ConversionData  dataFlag;
    MachineCode* mcode;
    int expectedMcode[]={0x55,0x12,0x34,0xAA,0xBB,END};

    Try{
        tokenizer = createTokenizer(" MOV $AABB, $1234");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = createOperand(LONG_MEM_OPERAND,NA,NA,0xAA,0xBB,NA);
        operand2nd = createOperand(LONG_MEM_OPERAND,NA,NA,0x12,0x34,NA);
        operand = getMOVOpcode(operand , operand2nd);
        token =(IntegerToken*)getToken(tokenizer);
        dataFlag = getMOVDataFlag(&movCodeInfo,operand);
        token =(IntegerToken*)getToken(tokenizer);
        commarCheck(tokenizer);
        token =(IntegerToken*)getToken(tokenizer);
        mcode = machineCodeAllocateOutput(tokenizer,dataFlag ,operand, NA ,operand2nd->dataSize.ms);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
        //freeToken
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

// only usable on JRXX Instruction return value which changed to 2nd compliment for negative value
// it also add the length of machine code with the value together
void test_getJRXX2ndCompLength_given_shortmemBB_expect_2(void) {
    stm8Operand *operand = NULL;
    IntegerToken * token;
		Tokenizer *tokenizer = NULL;
    ConversionData  dataFlag;
    int value;

    Try{
        tokenizer = createTokenizer(" JRc $15");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = createOperand(SHORT_OFF_OPERAND,NA,NA,0x15,NA,NA);
        token =(IntegerToken*)getToken(tokenizer);
        dataFlag = getDataFlag(&jrcCodeInfo,tokenizer);
        token =(IntegerToken*)getToken(tokenizer);
        value = getJRXX2ndCompLength(dataFlag,operand,tokenizer);
        TEST_ASSERT_EQUAL_HEX8(0x18,value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
/*
// only usable on BTJX Instruction return value which changed to 2nd compliment for negative value
// it also add the length of machine code with the value together
void test_getJRXX2ndCompLength_given_shortmemBB_expect_2(void) {
    stm8Operand *operand = NULL;
    IntegerToken * token;
		Tokenizer *tokenizer = NULL;
    ConversionData  dataFlag;
    int value;

    Try{
        tokenizer = createTokenizer(" BJTF $10");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        operand = createOperand(SHORT_OFF_OPERAND,NA,NA,0x15,NA,NA);
        token =(IntegerToken*)getToken(tokenizer);
        dataFlag = getDataFlag(&jrcCodeInfo,tokenizer);
        token =(IntegerToken*)getToken(tokenizer);
        value = getJRXX2ndCompLength(dataFlag,operand,tokenizer);
        TEST_ASSERT_EQUAL_HEX8(0x18,value);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
*/
