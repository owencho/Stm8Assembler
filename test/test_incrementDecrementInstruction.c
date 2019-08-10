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

void test_assembleInstruction_given_inc_A_OPERAND_expect_0x4C(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x4C,END};

		Try{
				tokenizer = createTokenizer("  inc A ");
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

void test_assembleInstruction_given_inc_shortmem_OPERAND_expect_0x3C0C(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x3C,0x0C,END};

		Try{
				tokenizer = createTokenizer("  inc 12 ");
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

void test_assembleInstruction_given_inc_longmem_OPERAND_expect_0x725C4416(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x72,0x5C,0x44,0x16,END};

		Try{
				tokenizer = createTokenizer("  inc $4416 ");
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

void test_assembleInstruction_given_inc_bracX_OPERAND_expect_0x7C(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x7C,END};

		Try{
				tokenizer = createTokenizer("  inc (X) ");
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

void test_assembleInstruction_given_inc_shortoffX_OPERAND_expect_0x6C80(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x6C,0x80,END};

		Try{
				tokenizer = createTokenizer("  inc (128,X) ");
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

void test_assembleInstruction_given_inc_longoffX_OPERAND_expect_0x724C8864(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x72,0x4c,0x88,0x64,END};

		Try{
				tokenizer = createTokenizer("  inc (34916,X) ");
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

void test_assembleInstruction_given_inc_bracY_OPERAND_expect_0x907C(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x90,0x7C,END};

		Try{
				tokenizer = createTokenizer("  inc (Y) ");
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

void test_assembleInstruction_given_inc_shortoffY_OPERAND_expect_0x906C80(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x90,0x6C,0x55,END};

		Try{
				tokenizer = createTokenizer("  inc ($55,Y) ");
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

void test_assembleInstruction_given_inc_longoffY_OPERAND_expect_0x904C3321(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x90,0x4c,0x33,0x21,END};

		Try{
				tokenizer = createTokenizer("  inc ($3321,Y) ");
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

void test_assembleInstruction_given_inc_shortoffSP_OPERAND_expect_0x0C31(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x0c,0x31,END};

		Try{
				tokenizer = createTokenizer("  inc ($31,SP) ");
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

void test_assembleInstruction_given_inc_shortptrw_OPERAND_expect_0x923C12(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x92,0x3C,0x12 ,END};
		Try{
				tokenizer = createTokenizer("  INC [$12] ");
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

void test_assembleInstruction_given_inc_longptrw_OPERAND_expect_0x723C1512(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x72,0x3C,0x15,0x12 ,END};
		Try{
				tokenizer = createTokenizer("  INC [$1512] ");
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

void test_assembleInstruction_given_inc_shortptrwX_OPERAND_expect_0x926C41(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x92,0x6C,0x41 ,END};
		Try{
				tokenizer = createTokenizer("  inc([$41],X) ");
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

void test_assembleInstruction_given_inc_longptrwX_OPERAND_expect_0x726C4431(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x72,0x6C,0x44,0x31,END};
		Try{
				tokenizer = createTokenizer("  iNC ([$4431],X) ");
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

void test_assembleInstruction_given_inc_shortptrwY_OPERAND_expect_0x916C20(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x91,0x6C,0x20 ,END};
		Try{
				tokenizer = createTokenizer("  inc([$20],Y) ");
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



void test_assembleInstruction_given_dec_A_OPERAND_expect_0x4A(void) {
			MachineCode *mcode =NULL ;
			Tokenizer *tokenizer = NULL;
			int expectedMcode[]={0x4A,END};

		Try{
				tokenizer = createTokenizer("  dec A ");
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

void test_assembleInstruction_given_dec_shortmem_OPERAND_expect_0x3AFD(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x3A,0xFD,END};

		Try{
				tokenizer = createTokenizer("  dec $FD ");
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

void test_assembleInstruction_given_dec_longmem_OPERAND_expect_0x725A9033(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x72,0x5A,0x90,0x33 ,END};

		Try{
				tokenizer = createTokenizer("  DEC $9033 ");
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

void test_assembleInstruction_given_dec_bracX_OPERAND_expect_0x7A(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x7A,END};

		Try{
				tokenizer = createTokenizer("  dec (X) ");
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

void test_assembleInstruction_given_dec_shortoffX_OPERAND_expect_0x6A10(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x6A,0x10,END};

		Try{
				tokenizer = createTokenizer("  dec ($10,X) ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
		  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_dec_longoffX_OPERAND_expect_0x724A6488(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x72,0x4A,0x64,0x88,END};

		Try{
				tokenizer = createTokenizer("  dec ($6488,X) ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_dec_bracY_OPERAND_expect_0x907A(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x90,0x7A,END};

		Try{
				tokenizer = createTokenizer("  dec (Y) ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_dec_shortoffY_OPERAND_expect_0x906A56(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x90,0x6A,0x56,END};

		Try{
				tokenizer = createTokenizer("  DEC($56,Y) ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}


void test_assembleInstruction_given_dec_longoffY_OPERAND_expect_0x904a3321(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x90,0x4a,0x33,0x21,END};

		Try{
				tokenizer = createTokenizer("  dec ($3321,Y) ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_dec_shortoffSP_OPERAND_expect_0x0a31(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x0a,0x31,END};

		Try{
				tokenizer = createTokenizer("  dec ($31,SP) ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
		} Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
		}
		freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_dec_shortptrw_OPERAND_expect_0x923a12(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x92,0x3a,0x12 ,END};
		Try{
				tokenizer = createTokenizer("  dec [$12] ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_dec_longptrw_OPERAND_expect_0x723a1512(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x72,0x3a,0x15,0x12 ,END};
		Try{
				tokenizer = createTokenizer("  dec [$1512] ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_dec_shortptrwX_OPERAND_expect_0x926a41(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x92,0x6a,0x41 ,END};
		Try{
				tokenizer = createTokenizer("  dec([$41],X) ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_dec_longptrwX_OPERAND_expect_0x726A7749(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x72,0x6A,0x44,0x31 ,END};
		Try{
				tokenizer = createTokenizer("  DEC([$4431],X) ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_dec_shortptrwY_OPERAND_expect_0x916A20(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x91,0x6A,0x20 ,END};
		Try{
				tokenizer = createTokenizer("  dec([$20],Y) ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}
void test_assembleInstruction_given_dec_X_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" dec X  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}



void test_assembleInstruction_given_incw_x_OPERAND_expect_0x5C(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x5C,END};

		Try{
				tokenizer = createTokenizer("  incw x ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_incw_y_OPERAND_expect_0x905C(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x90,0x5C,END};

		Try{
				tokenizer = createTokenizer("  incw y ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_incw_f_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" incw f  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);

        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_decw_x_OPERAND_expect_0x5A(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x5A,END};

		Try{
				tokenizer = createTokenizer("  decw x ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_decw_y_OPERAND_expect_0x905A(void) {
		MachineCode *mcode =NULL ;
		Tokenizer *tokenizer = NULL;
		int expectedMcode[]={0x90,0x5A,END};

		Try{
				tokenizer = createTokenizer("  decw y ");
				configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
				mcode = assembleInstruction(tokenizer);
				TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);
	  } Catch(ex) {
		    dumpTokenErrorMessage(ex, 1);
		    TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
	  }
	  freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_decw_A_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" decw A  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_UNSUPPORTED_OPERAND, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}

void test_assembleInstruction_given_decw_x_commar_expect_fail(void) {
    MachineCode *mcode =NULL ;
    Tokenizer *tokenizer = NULL;

    Try{
        tokenizer = createTokenizer(" decw x,  ");
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown.");
    } Catch(ex) {
        dumpTokenErrorMessage(ex, 416);
        TEST_ASSERT_EQUAL(ERR_INVALID_SYNTAX, ex->errorCode);
    }
    freeTokenizer(tokenizer);
}
