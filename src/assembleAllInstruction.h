#include "mcode.h"
#include "operand.h"
#ifndef AssembleAllInstruction_H
#define AssembleAllInstruction_H


#define NA      -1
#define ALL_OPERANDS -1


ConversionData  getDataFlag(CodeInfo *codeInfo,Tokenizer* tokenizer);
ConversionData getLDWDataFlag(CodeInfo *codeInfo,stm8Operand * operand);
ConversionData getMOVDataFlag(CodeInfo *codeInfo,stm8Operand * operand);
stm8Operand * complexOperandReturn(Tokenizer* tokenizer ,uint64_t flags);
int hashNValueReturn(Tokenizer* tokenizer ,uint64_t flags , int cmpType);
MachineCode* outputMachineCode(stm8Operand * operand,ExtensionCodeAndCode code, int length);
int machineCodeLengthFinder(stm8Operand * operand,ExtensionCodeAndCode code);
int getValue2ndCompLength(ConversionData dataFlag,stm8Operand * operand,Tokenizer * tokenizer);
MachineCode* machineCodeAllocateOutput(Tokenizer* tokenizer,ConversionData  dataFlag , stm8Operand *operand, int nvalue);
MachineCode* mcodeMOVLONGOutput(Tokenizer* tokenizer,ConversionData  dataFlag , stm8Operand *operand , uint16_t ms);

MachineCode* assembleXYOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleXOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleAOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleASPComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleXYSPComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);

MachineCode* assembleJRXXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleBTJXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleLDOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleLDFOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleLDWOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleMOVperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleLDFLDOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleSymbolComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleNoOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleTwowithNOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleOneOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);


#endif // AssembleAllInstruction_H
