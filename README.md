# Stm8Assembler

## 1.0 About This Project
This is STM8Assembler project which it convert STM8 assembly code into STM8 machine code. \
This function will generate the machine code according to the instruction and operand of the assembly code. \
The main function for this STM8Assmbler is **assembleInstruction** function. \
The tokenizer that used inside this STM8 Assembler to retrieve the instruction and operand token are based on the TokenizerSkeleton [2]. \
The format of the machine code is based on [1] which is STM8 datasheet PM0044.pdf file that has all the STM8 instruction details. 

## 1.1 Objective
- To read the STM 8 assembly code and generate / return output with STM 8 machine code .
![assemtoMcode](https://user-images.githubusercontent.com/51066670/63931584-295f8680-ca88-11e9-9a48-3b0fdc9e163b.PNG)

# 2.0 Getting Started
## 2.1 Requirement
The following software need to be installed on your PC,
1. Ceedling 
2. MSYS2
3. Ruby
4. Git
5. Cosmic STM8 Software Development tools 
6. MINGW32/64


## 2.2 How to clone the file from GitHUB
Stm8Assembler can be cloned by issuing the command below with GitBash.
```
git clone https://github.com/owencho/Stm8Assembler
```
Or you can download through STM8Assembler GitHub webpage. 

![cloneImage](https://user-images.githubusercontent.com/51066670/63933047-126e6380-ca8b-11e9-9d25-7a93737b99c6.PNG)


## 2.3 Updating the STM8Assembler
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
## 2.4 Configuring Project.yml 
**If you are first time running this project, please follow the instruction below to configure Project.yml file before running it.**
1. ensure executable output `:executable: .exe` are remain as .exe ,so that it is easier to run the debugger by using IDE eg :CodeLite 
2. You need to choose the library type depends on your gcc version for the tokenizer for test_linker, \
   remove the hash to choose the library and remember to add hash to other library version if not used.
![lib](https://user-images.githubusercontent.com/51066670/63945479-f5935980-caa5-11e9-84e7-ddd99cc4fbc3.PNG)
- -Llib/x86 is for user who are using x86 or 32bit PC
- -Llib/x64_7_3_0 is for user who are using 64 bit PC with 7.3.0 gcc version installed
- -Llib/x64_6_3_0 is for user who are using 64 bit PC with 6.3.0 gcc version installed
- -Llib/x64_5_3_0 is for user who are using 64 bit PC with 5.3.0 gcc version installed
- -Llib/x64_TDM_5_1_0 is for user who are using 64 bit PC \
**Please use -Llib/x64_TDM_5_1_0 version if you running on 64 bit PC and other version are not working**
## 2.5 Important note
Before you implement this **assembleInstruction** function , tokenizer must be created with createTokenizer so that this function only able to tokenize the input string with STM8 assembly code .
Configure the Tokenizer to detect dollar sign as hex value are also required to ensure this assembler works properly.

The example code below shows how to create tokenizer and configure hex value for the tokenizer .
```
tokenizer = createTokenizer("  your input string here "); //create Tokenizer by passing in string with assembly code
configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX);  // configure tokenizer to recognize dollar sign as hex value
mcode = assembleInstruction(tokenizer);                   // run assembleInstruction to generate machine code
```

# 3.0 STM8 Instruction set
![STM8InsSet](https://user-images.githubusercontent.com/51066670/63931590-2a90b380-ca88-11e9-9759-9aa32695b000.PNG)

Note: Each different instruction group have different source file, header file and test file in this repository. \
      This is a modified STM8 instruction set as the instruction table in the PM0044.pdf datasheet did not include interrupt instruction inside any of them.

# 4.0 Implementing the function
You can implement the function by using the example code below
  ```
MachineCode *mcode =NULL ;                     //declare machine code and tokenizer variable
Tokenizer *tokenizer = NULL;

tokenizer = createTokenizer("  JRNC $44 ");              //create Tokenizer by passing in string with assembly code
configureTokenizer(tokenizer,TOKENIZER_DOLLAR_SIGN_HEX); // configure tokenizer to recognize dollar sign as hex value
mcode = assembleInstruction(tokenizer);                  // run assembleInstruction to generate machine code
```
The struct for Machine code can be found [here](https://github.com/owencho/Stm8Assembler/blob/master/src/Mcode.h) \
The struct and function for Tokenizer can be found [here](https://github.com/owencho/Stm8Assembler/blob/master/src/Tokenizer.h)

Remember to free the tokenizer and machine code with sample code below after the tokenizer and machine code does not used anymore.
```
freeTokenizer(tokenizer);             
freeMachineCode(mcode);
```    
# 5.0 Testing
## 5.1 Testing the function
You can test STM8Assembler by issuing command below on GitBash.
```
ceedling test:all 
```
note: Please ensure the file [Project.yml](https://github.com/owencho/Stm8Assembler/blob/master/project.yml) has been configured properly before running the test.If not, please refer back to [Configuring Project.yml](https://github.com/owencho/Stm8Assembler/blob/master/README.md#24-configuring-projectyml)


## 5.2 Adding extra test
You add extra test by following the example code below,
Here's a simple example code for testing\
For adding pass test,
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
note: TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode) are custom test assert function which does not located at unity.h

For adding fail test, 
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
        TEST_ASSERT_EQUAL(ERR_INVALID_OPERAND, ex->errorCode); 
        // compare generated errorCode with expected errorCode
    }
    freeTokenizer(tokenizer);  //remember to free Tokenizer and MachineCode after testing
    freeMachineCode(mcode);
}
```
If you experienced some failed test message generated by ceedling \
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
It may caused by typo or bringing in wrong instruction and operand combination / syntax .You can refer to the line number for troubleshooting.

_For more examples, please refer [here](https://github.com/owencho/Stm8Assembler/tree/master/test)_ \
_For all error code , please refer [here](https://github.com/owencho/Stm8Assembler/blob/master/src/Error.h)_ 

# 6.0 Results
When ceedling run the test , it passed all test in all test file excluding customAssert test file that is disabled by default. \
![passedall](https://user-images.githubusercontent.com/51066670/63948601-86b8ff00-caab-11e9-8212-eea5374261f6.PNG)

Ceedling will also will generate message throw by exception on the specific test that is expected to fail. 

For example error message generated on the Increment Decrement instruction group test file, \
![errMsg](https://user-images.githubusercontent.com/51066670/63949159-8705ca00-caac-11e9-92f8-ddd88784777b.PNG)


# 7.0 Source file:
- For Source Code details [click here](https://github.com/owencho/Stm8Assembler/tree/master/src)
- For Test Code details [click here](https://github.com/owencho/Stm8Assembler/tree/master/test)
- The Source code for assembleInstruction [click here](https://github.com/owencho/Stm8Assembler/blob/master/src/Instruction.c)

# 8.0 Note
1. For instruction that is **relative jump or relative call function**
  - It **DOES NOT support word jump** eg `JRNE loop` , the word jump label are not supported \
    and it **ONLY support value jump** eg `JRNE $21` \
![wordvaluejump](https://user-images.githubusercontent.com/51066670/63931591-2a90b380-ca88-11e9-8488-6179c65ec7df.PNG)    
  - The output machine code value for the address part will be value of `destination hex value + machine code length` \
    instead of value with `Program Counter + destination hex value`.
    
  - The address value are **8 bit signed integer** which it only supports value from -128 to 127 (- $80 to $7F) which it will generate error message if exceeded the value range\
    ![signedInt](https://user-images.githubusercontent.com/51066670/63987285-3329ce00-cb0a-11e9-86e7-b5a4165bfbff.PNG)

2. There is an extra instruction named **interrupt instruction** which does not belong to any instruction group are now placed under 
**Interrupt Management** instruction group.

3. There is an CustomAssert test file which test the `TEST_ASSERT_EQUAL_MACHINECODE(expectedMcode,mcode)` function.
This function compares the difference between the expected machine code and the generated machine code which returned by the **assembleInstruction** function. \
This CustomAssert test file is disabled by default during the test and it required to manually remove the x from this file name `test\xtest_CustomAssert.c` to conduct the test.
This function will generate error message if detected difference between expected and generated machine code as shown below,
![CustomAssert](https://user-images.githubusercontent.com/51066670/63946620-f75e1c80-caa7-11e9-986b-99bdf7d184a0.PNG)

4. For the instruction at **Bit Operation and Conditional Bit Test Branch** instruction group  which required #pos value .
   #pos value only supports from 0 to 7 and it will throw exception and generate error message as below if value exceeded that range. \
   ![hasherror](https://user-images.githubusercontent.com/51066670/63933109-2f0a9b80-ca8b-11e9-885e-0e2f01366502.PNG)
 
5. For LDW instruction , if the first operand of the code is a complex operand and second operand is a symbol operand .If first operand and second operand is unsupported operand combination for this LDW instruction, it will generate an exception which will highlight both of the operand and generate *Operand is not supported!* message. \
![LDWunsupported](https://user-images.githubusercontent.com/51066670/63933375-b2c48800-ca8b-11e9-9962-5d3f4a8dda70.PNG)

6. If your operand is bracketed X or Y short ptr operand and the value is 0 hex value such as `($0,X)` or `($0,Y)`,
   it will **follow same machine code as bracketed X or Y operand** is `(X) ` or `(Y)` in respective instruction that supports bracketed X or Y short ptr operand and bracketed X or Y operand .
   ```
   ($0,X) = (X) 
   ($0,Y) = (Y)
   
   ```
7. If this instruction does not support short addressing mode operand but it support longer addressing mode operand , this function will return a longer addressing mode operand instead of throw exception telling users operand is not supported. 
This function will allow smaller value to be accepted on larger value type. \
You can refer to the test [here](https://github.com/owencho/Stm8Assembler/blob/master/test/test_UnconditionalJumpCallInstruction.c#L495).\
For example JPF instruction that only supports extmem and longptr.e operand. 
   ```
    JPF $1 ---> 0xAC000001
    short mem on JPF will generate machine code above 

    JPF $FFFF ---> 0xAC00FFFF
    long mem on JPF will generate machine code above
   ```





















## Appendix
1. https://www.st.com/content/ccc/resource/technical/document/programming_manual/43/24/13/9a/89/df/45/ed/CD00161709.pdf/files/CD00161709.pdf/jcr:content/translations/en.CD00161709.pdf
2. https://github.com/chaosAD/TokenizerSkeleton
