#ifndef AssembleAllInstruction_H
#define AssembleAllInstruction_H
#include "Mcode.h"
#include "Operand.h"


#define NA      -1
#define ALL_OPERANDS -1

//Sub-module
void notNullCheck(Tokenizer* tokenizer);
ConversionData getDataFlag(CodeInfo *codeInfo,Tokenizer * tokenizer,stm8Operand* operand);
void commarCheck(Tokenizer* tokenizer);
int bitOperationCheck(IntegerToken * token);
int hashNValueReturn(Tokenizer* tokenizer , int cmpType);
MachineCode* outputMachineCode(stm8Operand * operand,ExtensionCodeAndCode code, int length);
int machineCodeLengthFinder(stm8Operand * operand,ExtensionCodeAndCode code);
MachineCode* machineCodeAllocateOutput(Tokenizer* tokenizer,ConversionData  dataFlag ,
                                       stm8Operand *operand, int nvalue , int movMs2ndOpValue);
int get2ndCompValue(ConversionData dataFlag,stm8Operand * operand,Tokenizer * tokenizer);
int addition2ndCompValueWithLength(stm8Operand * operand,int length,IntegerToken *token);
stm8Operand * getMOVOperand(Tokenizer* tokenizer,stm8Operand * dst ,stm8Operand * src );
//AssembleHandler
MachineCode* assembleLDWOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleBTJXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleLDLDFOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleOneOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleNoOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleTwoComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleSymbolComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);



#endif // AssembleAllInstruction_H
