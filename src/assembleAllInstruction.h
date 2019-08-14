#include "mcode.h"
#include "operand.h"
#ifndef AssembleAllInstruction_H
#define AssembleAllInstruction_H


#define NA      -1
#define ALL_OPERANDS -1

//Sub-module
ConversionData getDataFlag(CodeInfo *codeInfo,Tokenizer * tokenizer,stm8Operand* operand);
ConversionData getLDWComplexDataFlag(CodeInfo *codeInfo,stm8Operand * operand);
ConversionData getMOVDataFlag(CodeInfo *codeInfo,stm8Operand * operand);
stm8Operand * getMOVOpcode(stm8Operand * dst ,stm8Operand * src );
void commarCheck(Tokenizer* tokenizer);
int hashNValueReturn(Tokenizer* tokenizer , int cmpType);
MachineCode* outputMachineCode(stm8Operand * operand,ExtensionCodeAndCode code, int length);
int machineCodeLengthFinder(stm8Operand * operand,ExtensionCodeAndCode code);
MachineCode* machineCodeAllocateOutput(Tokenizer* tokenizer,ConversionData  dataFlag , stm8Operand *operand, int nvalue, int movMs2ndOpValue);
int getJRXX2ndCompLength(ConversionData dataFlag,stm8Operand * operand,Tokenizer * tokenizer);
int getBTJX2ndCompLength(stm8Operand * operand,IntegerToken * token);
//AssembleHandler
MachineCode* assembleJRXXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleBTJXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleLDWOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleMOVperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleLDFLDOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleTwowithNOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleOneOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleSymbolComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleNoOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);



#endif // AssembleAllInstruction_H
