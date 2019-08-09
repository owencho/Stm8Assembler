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

void test_assembleInstruction_given_ld_A_hash77_expect_0xA677(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xA6,0x77,END};

    Try{
        tokenizer = createTokenizer("  LD A,#$77 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_shortmem_expect_0xB637(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xB6,0x37,END};

    Try{
        tokenizer = createTokenizer("  LD A,$37 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_longmem_expect_0xC62121(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xC6,0x21,0x21,END};

    Try{
        tokenizer = createTokenizer("  LD A,$2121 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_BracX_expect_0xF6(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xF6,END};

    Try{
        tokenizer = createTokenizer("  lD A, (X )");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_A_shortptrBracX_expect_0xE669(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xE6,0x69,END};

    Try{
        tokenizer = createTokenizer("  lD A, ($69,X )");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_A_longptrBracX_expect_0xD68A31(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xD6,0x8A,0x31,END};

    Try{
        tokenizer = createTokenizer("  lD A, ($8A31,X )");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_BracY_expect_0x90F6(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xF6,END};

    Try{
        tokenizer = createTokenizer("  lD A, (Y )");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_A_shortptrBracY_expect_0x90E655(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xE6,0x55,END};

    Try{
        tokenizer = createTokenizer("  lD A, ($55,Y )");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_A_longptrBracY_expect_0xD6A13D(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xD6,0xA1,0x3D,END};

    Try{
        tokenizer = createTokenizer("  lD A, ($A13D,Y )");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_longptrBracY_expect_0x7BD3(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x7B,0xD3,END};

    Try{
        tokenizer = createTokenizer("  lD A, ($D3,SP )");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_shortptr_w_expect_0x92C601(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xC6,0x01,END};

    Try{
        tokenizer = createTokenizer("  LD A,[$1.w]");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_shortptr_w_expect_0x72C63A4B(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0xC6,0x3A,0x4B,END};

    Try{
        tokenizer = createTokenizer("  LD A,[$3A4B.w]");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_A_shortptrX_expect_0x92D6AC(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xD6,0xAC,END};

    Try{
        tokenizer = createTokenizer("  LD A,([$AC.w],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_longptrX_expect_0x72D67700(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0xD6,0x77,0x00,END};

    Try{
        tokenizer = createTokenizer("  LD A,([$7700.w],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_shortptrY_expect_0x91D60F(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x91,0xD6,0x0F,END};

    Try{
        tokenizer = createTokenizer("  LD A,([$F.w],Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_XL_expect_0x9F(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x9F,END};

    Try{
        tokenizer = createTokenizer("  LD A,XL ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_XL_expect_0x909F(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x9F,END};

    Try{
        tokenizer = createTokenizer("  LD A,YL ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_XH_expect_0x9E(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x9E,END};

    Try{
        tokenizer = createTokenizer("  LD A,XH ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_A_YH_expect_0x909E(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x9E,END};

    Try{
        tokenizer = createTokenizer("  LD A,YH ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_hash77_A_expect_error(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    Try{
        tokenizer = createTokenizer("  LD #$77, A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_shortmem_A_expect_0xB721(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xB7,0x21,END};

    Try{
        tokenizer = createTokenizer("  LD $21,A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_longmem_A_expect_0xC73014(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xC7,0x30,0x14,END};

    Try{
        tokenizer = createTokenizer("  LD $3014,A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_BracX_A_expect_0xF7(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xF7,END};

    Try{
        tokenizer = createTokenizer("  LD (X),A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_shortptrBracX_A_expect_0xE731(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xE7,0x31,END};

    Try{
        tokenizer = createTokenizer(" LD ($31,X),A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_longptrBracX_A_expect_0xD7F1E2(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xD7,0xF1,0xE2,END};

    Try{
        tokenizer = createTokenizer(" LD ($F1E2,X),A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_BracY_A_expect_0x90F7(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xF7,END};

    Try{
        tokenizer = createTokenizer(" LD (Y),A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_A_shortoffBracY_expect_0x90E708(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xE7,0x08,END};

    Try{
        tokenizer = createTokenizer("  LD ($8,Y),A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_A_longoffBracY_expect_0xD7003213(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xD7,0x32,0x13,END};

    Try{
        tokenizer = createTokenizer(" LD ($3213,Y),A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_shortoff_SP_A_expect_0x6B15(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x6B,0x15,END};

    Try{
        tokenizer = createTokenizer("  LD ($15,SP),A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_shortptr_w_A_expect_0x92C725(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xC7,0x25,END};

    Try{
        tokenizer = createTokenizer(" LD [$25.w],A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_longptr_w_A_expect_0x72C63A4B(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0xC7,0x3A,0x4B,END};

    Try{
        tokenizer = createTokenizer("  LD [$3A4B.w],A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_ld_shortptrX_A_expect_0x92D7AC(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xD7,0xAC,END};

    Try{
        tokenizer = createTokenizer(" LD ([$AC.w],X),A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_longptrX_A_expect_0x72D68754(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0xD7,0x87,0x54,END};

    Try{
        tokenizer = createTokenizer("  LD ([$8754.w],X),A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_shortptrY_A_expect_0x91D78C(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x91,0xD7,0x8C,END};

    Try{
        tokenizer = createTokenizer("  LD ([$8C.w],Y),A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_XL_A_expect_0x97(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x97,END};

    Try{
        tokenizer = createTokenizer("  LD XL,A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_YL_A_expect_0x9097(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x97,END};

    Try{
        tokenizer = createTokenizer("  LD YL,A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_XH_A_expect_0x95(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x95,END};

    Try{
        tokenizer = createTokenizer("  LD XH,A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_YH_A_expect_0x9095(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x95,END};

    Try{
        tokenizer = createTokenizer("  LD YH,A");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_z_XL_OPERAND_expect_exception(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  LD Z,XL ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ld_y_XL_OPERAND_expect_exception(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  LD Y,XL ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_extmem_expect_0xBC345612(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xBC,0x34,0x56,0x12,END};

    Try{
        tokenizer = createTokenizer("  LDF A,$345612 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_extmem_expect_0xBC000012(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xBC,0x00,0x00,0x12,END};

    Try{
        tokenizer = createTokenizer("  LDF A,$12 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_EXTOFF_X_OPERAND_expect_0xAF678967(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xAF,0x67,0x89,0x67,END};

    Try{
        tokenizer = createTokenizer("  LDF A,($678967,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_EXTOFF_X_OPERAND_expect_0xAF008967(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xAF,0x00,0x89,0x67,END};

    Try{
        tokenizer = createTokenizer("  LDF A,($8967,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_EXTOFF_Y_OPERAND_expect_0x90145793(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xaf,0x14,0x57,0x93,END};

    Try{
        tokenizer = createTokenizer("  LDF A,($145793,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_longptre_X_OPERAND_expect_0x90af2256(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xaf,0x22,0x56,END};

    Try{
        tokenizer = createTokenizer("  LDF A,([$2256.e],x) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_longptre_Y_OPERAND_expect_0x91af3586(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x91,0xaf,0x35,0x86,END};

    Try{
        tokenizer = createTokenizer("  LDF A,([$3586.e],y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_longptre_expect_0x92BC5023(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xBC,0x50,0x23,END};

    Try{
        tokenizer = createTokenizer("  LDF A,[$5023.e] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_extmem_A_expect_0xBD95436A(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xBD,0x95,0x43,0x6A,END};

    Try{
        tokenizer = createTokenizer("  LDF $95436A,A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_EXTOFF_X_OPERAND_A_expect_0xA7ABCDEF(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xA7,0xAB,0xCD,0xEF,END};

    Try{
        tokenizer = createTokenizer("  LDF ($ABCDEF,X),A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_EXTOFF_Y_OPERAND_expect_0x90A7FFFFFF(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xa7,0xFF,0xFF,0xFF,END};

    Try{
        tokenizer = createTokenizer("  LDF ($FFFFFF,Y),A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_longptre_X_A_OPERAND_expect_0x92a73678(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xa7,0x36,0x78,END};

    Try{
        tokenizer = createTokenizer("  LDF ([$3678.e],x),A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_A_longptre_Y_OPERAND_expect_0x91a74576(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x91,0xa7,0x45,0x76,END};

    Try{
        tokenizer = createTokenizer("  LDF ([$4576.e],y),A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
  	freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldf_longptre_A_expect_0x92BD0011(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xBD,0x00,0x11,END};

    Try{
        tokenizer = createTokenizer("  LDF [$11.e],A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_word_expect_0xAE0055(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xAE,0x00,0x55,END};

    Try{
        tokenizer = createTokenizer("  LDW X,#$55 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_word_expect_0xBE12(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xBE,0x12,END};

    Try{
        tokenizer = createTokenizer("  LDW X,$12 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_shortmem_expect_0xCE1254(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xCE,0x12,0x54,END};

    Try{
        tokenizer = createTokenizer("  LDW X,$1254 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_shortmem_with_extra_symbol_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  LDW X,$1254 ? ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("expect exception to be thrown");
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_shortoffX_expect_0xEE51(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xEE,0x51,END};

    Try{
        tokenizer = createTokenizer("  LDW X,($51,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_longoffX_expect_0xDE5122(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xDE,0x51,0x22,END};

    Try{
        tokenizer = createTokenizer("  LDW X,($5122,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_shortoffSP_expect_0x1E11(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x1E,0x11,END};

    Try{
        tokenizer = createTokenizer("  LDW X,($11,SP) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_shortptrw_expect_0x92CE12(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xCE,0x12,END};

    Try{
        tokenizer = createTokenizer("  LDW X,[$12.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_longptrw_expect_0x72CE3721(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0xCE,0x37,0x21,END};

    Try{
        tokenizer = createTokenizer("  LDW X,[$3721.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_shortptrw_BracX_expect_0x92DEDD(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xDE,0xDD,END};

    Try{
        tokenizer = createTokenizer("  LDW X,([$DD.w], x  ) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_longptrw_BracX_expect_0x72DE8864(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0xDE,0x88,0x64,END};

    Try{
        tokenizer = createTokenizer("  LDW X,([$8864.w], x  ) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_Y_expect_0x93(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x93,END};

    Try{
        tokenizer = createTokenizer("  LDW X,Y ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_Y_expect_0x96(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x96,END};

    Try{
        tokenizer = createTokenizer("  LDW X,SP ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_Y_word_expect_0x90AE0055(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xAE,0x00,0xFF,END};

    Try{
        tokenizer = createTokenizer("  LDW Y,#$FF ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_word_expect_0x90BE11(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xBE,0x01,END};

    Try{
        tokenizer = createTokenizer("  LDW Y,$01 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_Y_shortmem_expect_0x90CE0339(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xCE,0x03,0x39,END};

    Try{
        tokenizer = createTokenizer("  LDW Y,$339 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}
/*
void test_assembleInstruction_given_ldw_X_shortoffX_expect_0xEE51(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xEE,0x51,END};

    Try{
        tokenizer = createTokenizer("  LDW X,($51,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_longoffX_expect_0xDE5122(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0xDE,0x51,0x22,END};

    Try{
        tokenizer = createTokenizer("  LDW X,($5122,X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_shortoffSP_expect_0x1E11(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x1E,0x11,END};

    Try{
        tokenizer = createTokenizer("  LDW X,($11,SP) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_shortptrw_expect_0x92CE12(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xCE,0x12,END};

    Try{
        tokenizer = createTokenizer("  LDW X,[$12.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_longptrw_expect_0x72CE3721(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0xCE,0x37,0x21,END};

    Try{
        tokenizer = createTokenizer("  LDW X,[$3721.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_shortptrw_BracX_expect_0x92DEDD(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0xDE,0xDD,END};

    Try{
        tokenizer = createTokenizer("  LDW X,([$DD.w], x  ) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_ldw_X_longptrw_BracX_expect_0x72DE8864(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0xDE,0x88,0x64,END};

    Try{
        tokenizer = createTokenizer("  LDW X,([$8864.w], x  ) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}


*/
void test_assembleInstruction_given_ldw_shortOffSP_X_expect_0x1F50(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x1F,0x50,END};

    Try{
        tokenizer = createTokenizer(" LDW ($50,SP),X ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
   freeTokenizer(tokenizer);
}




void test_assembleInstruction_given_ldw_y_word_A_expect_0x90AE55BB(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0xAE,0x55,0xBB,END};

    Try{
        tokenizer = createTokenizer("  LDW Y,#$55BB ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}



void test_assembleInstruction_given_ldw_shortptrSP_CC_OPERAND_expect_exception(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  LDW ($50,SP),CC ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
	  freeTokenizer(tokenizer);
}










void test_assembleInstruction_given_mov_longmem_byte_expect_0x35AA8000(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x35,0xAA,0x80,0x00,END};

    Try{
        tokenizer = createTokenizer(" MOV $8000, #$AA ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_mov_longmem_longmem_expect_0x3510008000(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x55,0x10,0x00,0x80,0x00,END};

    Try{
        tokenizer = createTokenizer("MOV $8000,$1000");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_mov_shortmem_shortmem_expect_0x451080(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x45,0x10,0x80,END};

    Try{
        tokenizer = createTokenizer("MOV $80,$10");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex){
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}



void test_assembleInstruction_given_exg_XL_OPERAND_expect_0x41(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x41,END};

    Try{
        tokenizer = createTokenizer("eXg A,XL");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_exg_YL_OPERAND_expect_0x61(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x61,END};

    Try{
        tokenizer = createTokenizer("eXg A,YL");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_exg_LONG_MEM_OPERAND_1234_expect_0x311234(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x31,0x12,0x34,END};

    Try{
        tokenizer = createTokenizer("exg A, $1234");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_exg_z_XL_OPERAND_expect_exception(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer("  eXg Z,XL ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
	  freeTokenizer(tokenizer);
}
