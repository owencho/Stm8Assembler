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

void test_assembleInstruction_given_sll_shortptr_OPERAND_expect_0x923865(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x92,0x38,0x65,END};

    Try{
        tokenizer = createTokenizer("  sll [$65] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sll_shortoffX_OPERAND_expect_0x6867(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x68,0x67,END};

    Try{
        tokenizer = createTokenizer("  sll ($67,x) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_srl_longptr_OPERAND_expect_0x72346544(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x34,0x65,0x44,END};

    Try{
        tokenizer = createTokenizer("  srl [$6544.w] ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_srl_bracY_OPERAND_expect_0x9074(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x74,END};

    Try{
        tokenizer = createTokenizer("  srl (y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sra_shortptrwY_OPERAND_expect_0x916766(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x91,0x67,0x66,END};

    Try{
        tokenizer = createTokenizer("  SRA ([$66],Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sra_longmem_OPERAND_expect_0x72573211(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x57,0x32,0x11,END};

    Try{
        tokenizer = createTokenizer("  SRA $3211 ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_rlc_A_OPERAND_expect_0x49(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x49,END};

    Try{
        tokenizer = createTokenizer("   RLC A ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_rlc_shortoffSP_OPERAND_expect_0x0914(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x09,0x14,END};

    Try{
        tokenizer = createTokenizer("  RLC ($14,SP) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_rrc_longoffY_OPERAND_expect_0x90461341(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x46,0x13,0x41,END};

    Try{
        tokenizer = createTokenizer("   RRC ($1341,Y) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_rrc_shortmem_OPERAND_expect_0x36AA(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x36,0xAA,END};

    Try{
        tokenizer = createTokenizer(" RRC $AA ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_swap_shortoffY_OPERAND_expect_0x906EBB(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x90,0x6E,0xBB,END};

    Try{
        tokenizer = createTokenizer(" SWAP ($BB,Y)");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_swap_longptrwX_OPERAND_expect_0x726E5057(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x72,0x6E,0x50,0x57,END};

    Try{
        tokenizer = createTokenizer("   SWAP ([$5057.w],X) ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
    }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);
}


void test_assembleInstruction_given_sllw_x_OPERAND_expect_0x58(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x58,END};

	Try{
		tokenizer = createTokenizer("  sllw x ");
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

void test_assembleInstruction_given_sllw_y_OPERAND_expect_0x9058(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x58,END};

	Try{
		tokenizer = createTokenizer("  sllw y ");
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


void test_assembleInstruction_given_slaw_x_OPERAND_expect_0x58(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x58,END};

	Try{
		tokenizer = createTokenizer("  slaw x ");
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

void test_assembleInstruction_given_slaw_y_OPERAND_expect_0x9058(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x58,END};

	Try{
		tokenizer = createTokenizer("  slaw y ");
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

void test_assembleInstruction_given_srlw_x_OPERAND_expect_0x54(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x54,END};

	Try{
		tokenizer = createTokenizer("  srlw x ");
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

void test_assembleInstruction_given_srlw_y_OPERAND_expect_0x9054(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x54,END};

	Try{
		tokenizer = createTokenizer("  srlw y ");
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

void test_assembleInstruction_given_sraw_x_OPERAND_expect_0x57(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x57,END};

	Try{
		tokenizer = createTokenizer("  sraw x ");
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

void test_assembleInstruction_given_sraw_y_OPERAND_expect_0x9057(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x57,END};

	Try{
		tokenizer = createTokenizer("  srAw y ");
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

void test_assembleInstruction_given_rlcw_x_OPERAND_expect_0x59(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x59,END};

	Try{
		tokenizer = createTokenizer("  rlcw x ");
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

void test_assembleInstruction_given_rlcw_y_OPERAND_expect_0x9059(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x59,END};

	Try{
		tokenizer = createTokenizer("  rLcW y ");
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

void test_assembleInstruction_given_rrcw_x_OPERAND_expect_0x56(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x56,END};

	Try{
		tokenizer = createTokenizer("  rrcw x ");
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

void test_assembleInstruction_given_rrcw_y_OPERAND_expect_0x9056(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x56,END};

	Try{
		tokenizer = createTokenizer("  rRcW y ");
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

void test_assembleInstruction_given_swapw_x_OPERAND_expect_0x5E(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x5E,END};

	Try{
		tokenizer = createTokenizer("  SwApw x ");
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

void test_assembleInstruction_given_swap_y_OPERAND_expect_0x905E(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x5E,END};

	Try{
		tokenizer = createTokenizer("  SwApw y ");
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

void test_assembleInstruction_given_rlwa_x_OPERAND_expect_0x02(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x02,END};

	Try{
		tokenizer = createTokenizer("  rlwa x ");
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

void test_assembleInstruction_given_rlwa_y_OPERAND_expect_0x9002(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x02,END};

	Try{
		tokenizer = createTokenizer("  rlwa y ");
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

void test_assembleInstruction_given_rrwa_x_OPERAND_expect_0x01(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x01,END};

	Try{
		tokenizer = createTokenizer("  rrwa x ");
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

void test_assembleInstruction_given_rrwa_y_OPERAND_expect_0x9001(void) {
	MachineCode *mcode =NULL ;
	Tokenizer *tokenizer = NULL;
	int expectedMcode[]={0x90,0x01,END};

	Try{
		tokenizer = createTokenizer("  rrwa y ");
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
////////////////////////////////////////////////////////////////////////////////////
void test_assembleInstruction_given_sllw_y_commar_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  sllw y , ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  sllw ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_XL_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  sllw XL ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_Z_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  sllw Z ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_sllw_X1_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  slaw X 1 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_slaw_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  slaw ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_DSTSRC_NULL, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_slaw_dollarsign10_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  slaw $10 ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_slaw_Q_expect_fail(void) {
  MachineCode *mcode =NULL ;
  Tokenizer *tokenizer = NULL;

  Try{
    tokenizer = createTokenizer("  slaw Q ");
    configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

    mcode = assembleInstruction(tokenizer);
    TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
  } Catch(ex) {
    dumpTokenErrorMessage(ex, 416);
    TEST_ASSERT_EQUAL(ERR_INVALID_STM8_OPERAND, ex->errorCode);
  }
	  freeTokenizer(tokenizer);
}
