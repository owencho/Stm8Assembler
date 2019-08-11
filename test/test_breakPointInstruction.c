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

void test_assembleInstruction_given_Break_0x8b(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x8b,END};
    Try{
        tokenizer = createTokenizer("  brEak ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex){
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_break_f_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  break f ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_break_1_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  break 1 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, __LINE__);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
