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

void setUp(void){}
void tearDown(void){}
//NEGW test /////////////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_neg_A_OPERAND_expect_0x40(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x40,END};

    Try{
        tokenizer = createTokenizer("  NEG A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_neg_shortmem12_OPERAND_expect_0x3012(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x30,0x12,END};

    Try{
        tokenizer = createTokenizer("  NEG $12 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_longmemff11_OPERAND_expect_0x7250FF11(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x50,0xFF,0x11,END};

    Try{
        tokenizer = createTokenizer("  NEG $FF11 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_bracX_OPERAND_expect_0x70(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x70,END};

    Try{
        tokenizer = createTokenizer("  NeG (   X ) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_shortoffX_OPERAND_expect_0x60BB(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x60,0xBB,END};

    Try{
        tokenizer = createTokenizer("  NEG($BB,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_longoffX_OPERAND_expect_0x72401A3B(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x40,0x1A,0x3B,END};

    Try{
        tokenizer = createTokenizer("  NEG ($1A3B,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_bracY_OPERAND_expect_0x9070(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x70,END};

    Try{
        tokenizer = createTokenizer("  Neg ( Y ) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_shortoffY_OPERAND_expect_0x906077(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x60,0x77,END};

    Try{
        tokenizer = createTokenizer("  NEG($77,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_longoffY_OPERAND_expect_0x9040C172(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x40,0xC1,0x72,END};

    Try{
        tokenizer = createTokenizer("  NEG ($C172,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_shortoffSP_OPERAND_expect_0x0055(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x00,0x55,END};

    Try{
        tokenizer = createTokenizer("  NEG($55,SP) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_shortptrdotW_OPERAND_expect_0x9230F4(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0x30,0xF4,END};

    Try{
        tokenizer = createTokenizer("  NEG [$F4] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_longptrdotW_OPERAND_expect_0x7230F1E2(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x30,0xF1,0xE2,END};

    Try{
        tokenizer = createTokenizer("  NEG [$F1E2.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_shortptrwX_OPERAND_expect_0x926065(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0x60,0x65,END};

    Try{
        tokenizer = createTokenizer("   NEG([$65],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_longptrwX_OPERAND_expect_0x7260EEAA(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x60,0xEE,0xAA,END};

    Try{
        tokenizer = createTokenizer("  NEG([$EEAA.w],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_neg_shortptrwY_OPERAND_expect_0x916005(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x91,0x60,0x05,END};

    Try{
        tokenizer = createTokenizer("   NEG([$5],Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
//ADC testing ////////////////////////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_adc_hash33_expect_0xa933(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xa9,0x33,END};
    Try{
        tokenizer = createTokenizer("  AdC a, #$33 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_NOT_NULL(mcode);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_adc_bracketX_expect_0xf9(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xf9,END};
    Try{
        tokenizer = createTokenizer("  AdC a, (x) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_NOT_NULL(mcode);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_adc_SHORTOFF_X_OPERAND_expect_0xe9c1(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xe9,0xc1,END};
    Try{
        tokenizer = createTokenizer("  AdC a, ($c1,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_adc_LONGOFF_X_OPERAND_expect_0xd9c1aa(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xd9,0xc1,0xaa,END};
    Try{
        tokenizer = createTokenizer("  AdC a, ($c1aa,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_adc_bracketY_expect_0x90f9(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xf9,END};
    Try{
        tokenizer = createTokenizer("  AdC a, (y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_NOT_NULL(mcode);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_adc_SHORTOFF_Y_OPERAND_expect_0x90e9d7(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xe9,0xd7,END};
    Try{
        tokenizer = createTokenizer("  AdC a, ($d7,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_adc_LONGOFF_Y_OPERAND_expect_0x90d9a2c3(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xd9,0xa2,0xc3,END};
    Try{
        tokenizer = createTokenizer("  AdC a, ($a2c3,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}


void test_assembleInstruction_given_adc_z_BracketedY_without_commar_expect_exception_thrown(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  AdC a (Y)  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
}

void test_assembleInstruction_given_adc_z_expect_exception_thrown(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  AdC a ,  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
    }
}

void test_assembleInstruction_given_adc_with_extra_operand_expect_exception_thrown(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  AdC a ,(X) z  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
}

//ADD testing ////////////////////////////////////////////////////////////////////////////////////////////

void test_assembleInstruction_given_add_bracketed_X_OPERAND_expect_0xfb(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xfb,END};

    Try{
        tokenizer = createTokenizer("  ADd a, (X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_NOT_NULL(mcode);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_add_LONGOFF7749_Y_OPERAND_expect_0x90db7749(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xdb,0x77,0x49,END};

    Try{
        tokenizer = createTokenizer("  ADd a, ($7749,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_NOT_NULL(mcode);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
//SUB testing///////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_sub_SP_BYTe_OPERAND_hash99_expect_0x5299(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x52,0x99,END};

    Try{
        tokenizer = createTokenizer("  sub SP,#$99 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sub_SHORTOFF_X_OPERAND_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  sub SP,($5,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
//SBC testing///////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_sbc_a_BRACKETED_SHORTPTR_DOT_W_OPERAND_hash5_expect_0xe205(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xe2,0x05,END};

    Try{
        tokenizer = createTokenizer("  sBc A,($5,X)");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}
//MUL testing///////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_mul_x_a_OPERAND_expect_0x42(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x42,END};

    Try{
        tokenizer = createTokenizer("  MUL X,A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_mul_y_a_OPERAND_expect_0x9042(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x42,END};

    Try{
        tokenizer = createTokenizer("  MUL Y,A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

//DIV & DIVW testing///////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_div_x_A_OPERAND_expect_0x62(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x62,END};

    Try{
        tokenizer = createTokenizer("  dIv X, A  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_div_x_y_OPERAND_expect_0x65(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x65,END};

    Try{
        tokenizer = createTokenizer("  dIv X, Y ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_div_Y_A_OPERAND_expect_0x9062(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x62,END};

    Try{
        tokenizer = createTokenizer("  dIv Y, A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
        } Catch(ex) {
            dumpTokenErrorMessage(ex, 1);
            TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
        }
        freeTokenizer(tokenizer);
    }

    void test_assembleInstruction_given_div_A_Y_OPERAND_expect_fail(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;

        Try{
            tokenizer = createTokenizer("  dIv A, Y ");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

            mcode = assembleInstruction(tokenizer);
            TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
        } Catch(ex) {
            dumpTokenErrorMessage(ex, 416);
            TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
        }
        freeTokenizer(tokenizer);
    }

    void test_assembleInstruction_given_div_A_BYTE_OPERAND_expect_fail(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;

        Try{
            tokenizer = createTokenizer("  dIv Y, #55 ");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

            mcode = assembleInstruction(tokenizer);
            TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
        } Catch(ex) {
            dumpTokenErrorMessage(ex, 416);
            TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
        }
        freeTokenizer(tokenizer);
    }
    //NEGW testing///////////////////////////////////////////////////////////////////////////
    void test_assembleInstruction_given_negw_x_OPERAND_expect_0x50(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;
        int expectedMcode[]={0x50,END};

        Try{
            tokenizer = createTokenizer("  NeGw X ");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
            mcode = assembleInstruction(tokenizer);
            TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
        }Catch(ex) {
            dumpTokenErrorMessage(ex, 1);
            TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
        }
        freeTokenizer(tokenizer);
    }

    void test_assembleInstruction_given_negw_y_OPERAND_expect_0x9050(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;
        int expectedMcode[]={0x90,0x50,END};

        Try{
            tokenizer = createTokenizer("  Negw Y ");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
            mcode = assembleInstruction(tokenizer);
            TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
        }Catch(ex) {
            dumpTokenErrorMessage(ex, 1);
            TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
        }
        freeTokenizer(tokenizer);
    }
    //ADDW testing///////////////////////////////////////////////////////////////////////////
    void test_assembleInstruction_given_addw_x_hashword_OPERAND_expect_0x1c1554(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;
        int expectedMcode[]={0x1c,0x15,0x54,END};

        Try{
            tokenizer = createTokenizer("  ADdw X, #$1554 ");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
            mcode = assembleInstruction(tokenizer);
            TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
        }Catch(ex) {
            dumpTokenErrorMessage(ex, 1);
            TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
        }
        freeTokenizer(tokenizer);
    }

    void test_assembleInstruction_given_addw_x_word_OPERAND_expect_exception(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;

        Try{
            tokenizer = createTokenizer("  ADdw SP,#$1554 ");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
            mcode = assembleInstruction(tokenizer);
            TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
        }Catch(ex) {
            dumpTokenErrorMessage(ex, 416);
            TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
        }
        freeTokenizer(tokenizer);
    }

    void test_assembleInstruction_given_addw_A_word_OPERAND_expect_exception(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;

        Try{
            tokenizer = createTokenizer("  ADdw A,#$1321 ");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
            mcode = assembleInstruction(tokenizer);
            TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
        } Catch(ex) {
            dumpTokenErrorMessage(ex, 416);
            TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
        }
        freeTokenizer(tokenizer);
    }
    //SUBW testing///////////////////////////////////////////////////////////////////////////
    void test_assembleInstruction_given_subw_x_word_OPERAND_expect_0x1d1024(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;
        int expectedMcode[]={0x1d,0x10,0x24,END};

        Try{
            tokenizer = createTokenizer("  suBw X, #$1024");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
            mcode = assembleInstruction(tokenizer);
            TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
        } Catch(ex) {
            dumpTokenErrorMessage(ex, 1);
            TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
        }
        freeTokenizer(tokenizer);
    }

    void test_assembleInstruction_given_subw_Y_longmem_OPERAND_expect_0x72a21114(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;
        int expectedMcode[]={0x72,0xB2,0x11,0x14,END};

        Try{
            tokenizer = createTokenizer("  suBw Y, $1114");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
            mcode = assembleInstruction(tokenizer);
            TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
        } Catch(ex) {
            dumpTokenErrorMessage(ex, 1);
            TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
        }
        freeTokenizer(tokenizer);
    }

    void test_assembleInstruction_given_subw_Z_BYTE_OPERAND_expect_fail(void) {
        MachineCode *mcode =NULL ;
        Tokenizer *tokenizer = NULL;

        Try{
            tokenizer = createTokenizer("  subw Z, #55 ");
            configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

            mcode = assembleInstruction(tokenizer);
            TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
        } Catch(ex) {
            dumpTokenErrorMessage(ex, 416);
            TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
        }
        freeTokenizer(tokenizer);
    }
