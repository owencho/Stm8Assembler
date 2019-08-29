# Stm8Assembler

## About This Project
This is STM8Assembler project which it perform assembler function that convert STM8 assembly code into STM8 machine code.
This function will generate the machine code according to the instruction and operand of the assembly code.
The main function for this STM8Assmbler is **assembleInstruction** function.
This function which return the machine mode when user pass in the assembly language code into the function.
The tokenizer that used inside this STM8 Assembler to retrieve the instruction and operand token is based on the TokenizerSkeleton [2].
The format of the machine code is based on [1] which is STM8 datasheet PM0044.pdf file that has all the instruction details. 

## Objective
- To read the STM 8 assembly language code and generate output with STM 8 machine code 
![assemtoMcode](https://user-images.githubusercontent.com/51066670/63931584-295f8680-ca88-11e9-9a48-3b0fdc9e163b.PNG)

## Getting Started
Before you implement this **assembleInstruction** function , tokenizer must be initialize with createTokenizer so that this function only able to tokenize the input string with STM8 assembly code .
Configure the Tokenizer to detect $31 as hex value are also required to ensure this assembler works properly.

The example code below shows how to initialize and configure hex value the tokenizer .
```
tokenizer = createTokenizer("  JRNC $31 ");                //create Tokenizer by passing in string with assembly code
configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);   // configure tokenizer to recognize dollar sign as hex value
mcode = assembleInstruction(tokenizer);                    // run assembleInstruction to generate machine code
```

## Requirement
The following software need to be installed on your PC
1. Ceedling 
2. MSYS32/64
3. Ruby
4. Git
5. Cosmic STM8 Software Development tools 


## How to clone the file from GitHUB
Stm8Assembler can be cloned by issuing the command below with GitBash.
```
git clone https://github.com/owencho/Stm8Assembler
```
Or you can download through STM8Assembler GitHub webpage 

![cloneImage](https://user-images.githubusercontent.com/51066670/63933047-126e6380-ca8b-11e9-9d25-7a93737b99c6.PNG)


## Updating the STM8Assembler
If **STM8Assembler** has updates , the repository can be updated by issuing the command below with GitBash.
```
cd Stm8Assembler  // if you are not inside the project folder
git fetch         // to fetch the STM8Assembler update from the source 
git pull          // to pull the update from the source
```
Remember to **clobber and rebuild the project** by using the command below after update.
```
ceedling clobber          // clobber / clean all generated file
ceedling                  // Build the STM8Assembler project
```

## STM8 Instruction set
![STM8InsSet](https://user-images.githubusercontent.com/51066670/63931590-2a90b380-ca88-11e9-9759-9aa32695b000.PNG)

Note: Each different instruction group have different source file, header file and test file in this repository.


## Testing the function
You can test STM8Assembler by issuing command below on GitBash.
```
ceedling test:all 
```
## Usage
By running the test, you can understand how this Stm8Assembler works \
Here's a simple example code \
For adding extra pass test,
```
void test_assembleInstruction_given_neg_shortmem24_OPERAND_expect_0x3024(void) {
    MachineCode *mcode =NULL ;                     //declare machine code and tokenizer variable
    Tokenizer *tokenizer = NULL;
    int expectedMcode[]={0x30,0x12,END};           // declare expected Machine Code to be compared

    Try{
        tokenizer = createTokenizer("  NEG $24 ");   
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode);  //compare expected machine code 
                                                             //and machine code from the function
    }Catch(ex) {
        dumpErrorMessage(ex);
        TEST_FAIL_MESSAGE("Do not expect any exception to be thrown");
    }
    freeTokenizer(tokenizer);               //remember to free Tokenizer and MachineCode after testing
    freeMachineCode(mcode);
}
```
For fail test, 
```
void test_assembleInstruction_given_subw_Z_BYTE_OPERAND_expect_fail(void) {
    MachineCode *mcode =NULL ;                     //declare machine code and tokenizer variable
    Tokenizer *tokenizer = NULL;                   // no need to declare expected
                                                   //Machine Code as it expected to fail              

    Try{
        tokenizer = createTokenizer("  subw Z, #55 ");    //Z is invalid Operand 
        configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);
        mcode = assembleInstruction(tokenizer);
        TEST_FAIL_MESSAGE("Expecting exeception to be thrown."); //throw fail message if the function 
                                                                 //does not throw exception
    } Catch(ex) {
        dumpErrorMessage(ex);                                  //throw to ceedling for fail message 
        TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode); // compare errorCode with expected 
    }
    freeTokenizer(tokenizer);  //remember to free Tokenizer and MachineCode after testing
    freeMachineCode(mcode);
}
```
If you experienced some failed test generated by ceedling \
For example,
```
-------------------
FAILED TEST SUMMARY
-------------------
[test_ArithmeticOperationsInstruction.c]
  Test: test_assembleInstruction_given_neg_shortmem24_OPERAND_expect_0x3024
  At line (71): "Do not expect any exception to be thrown"
```
which the exception thrown by the function but this test does not expect the function to throw it.
It may caused by typo or bringing in wrong instruction and operand combination.You can refer to the line number for troubleshooting.

_For more examples, please refer [here](https://github.com/owencho/Stm8Assembler/tree/master/test)_ \
_For all error code , please refer [here](https://github.com/owencho/Stm8Assembler/blob/master/src/Error.h)_ 


## Source file:
 -------------
- For all Source Code information [click here](https://github.com/owencho/Stm8Assembler/tree/master/src)
- The Source code for assembleInstruction [click here](https://github.com/owencho/Stm8Assembler/blob/master/src/Instruction.c)

## Note
1. For instruction that is **relative jump or relative call function**
  - It **DOES NOT support word jump** eg `JRNE loop` , the word jump label are not supported \
    and it **ONLY support value jump** eg `JRNE $15` \
![wordvaluejump](https://user-images.githubusercontent.com/51066670/63931591-2a90b380-ca88-11e9-8488-6179c65ec7df.PNG)    
  - The output machine code value for the address part will be value of `destination hex value + machine code length` \
    instead of value with `Program Counter + destination hex value`.
    
  - The address value are **8 bit signed integer** which it only supports value from -128 to 127 (- $80 to $7F) which it will generate error message if exceeded the value range\
    ![signedInt](https://user-images.githubusercontent.com/51066670/63933555-0cc54d80-ca8c-11e9-9242-fa8e2e6791fe.PNG)

2. There is an extra instruction named **interrupt instruction** which does not belong to any instruction group are now placed under 
**Interrupt Management** instruction group.

3. There is an CustomAssert test file which test the `TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode)` function.
This function compares the difference between the expected machine code and the generated machine code which returned by the **assembleInstruction** function. \
This CustomAssert test file is disabled by default during the test and it required to manually remove the x from this file name `test\xtest_CustomAssert.c` to conduct the test.

4. For the instruction at **Bit Operation and Conditional Bit Test Branch** instruction group  which required #pos value .
   #pos value only supports from 0 to 7 and it will throw exception and generate error message as below if value exceeded that range. \
   ![hasherror](https://user-images.githubusercontent.com/51066670/63933109-2f0a9b80-ca8b-11e9-885e-0e2f01366502.PNG)
 
5. For LDW instruction , if the first operand of the code is a complex operand and second operand is a symbol operand which first operand and second operand is unsupported operand combination for this LDW instruction.This function will generate an exception which will highlight both of the operand and generate *Operand is unsupported!* message. \
![LDWunsupported](https://user-images.githubusercontent.com/51066670/63933375-b2c48800-ca8b-11e9-9962-5d3f4a8dda70.PNG)

   
    






















## Appendix
1. https://www.st.com/content/ccc/resource/technical/document/programming_manual/43/24/13/9a/89/df/45/ed/CD00161709.pdf/files/CD00161709.pdf/jcr:content/translations/en.CD00161709.pdf
2. https://github.com/chaosAD/TokenizerSkeleton
