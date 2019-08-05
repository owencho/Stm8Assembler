#include "mcode.h"
#include "operand.h"
#ifndef AssembleAllInstruction_H
#define AssembleAllInstruction_H


#define NA      -1
#define ALL_OPERANDS -1


ConversionData  getDataFlag(CodeInfo *codeInfo,Tokenizer* tokenizer);
stm8Operand * complexOperandReturn(Tokenizer* tokenizer ,ConversionData  dataFlag);
MachineCode* outputMachineCode(stm8Operand * operand,ExtensionCodeAndCode code, int length);
int machineCodeLengthFinder(stm8Operand * operand,ExtensionCodeAndCode code);
MachineCode* machineCodeAllocateOutput(Tokenizer* tokenizer,ConversionData  dataFlag , stm8Operand *operand, int nvalue);
MachineCode* assembleOneOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleXYOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleXOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleAOperandAndComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleASPComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleXYSPComplexOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleNoOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleTwowithNOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);
MachineCode* assembleJRXXOperand(CodeInfo *codeInfo ,Tokenizer *tokenizer);




#endif // AssembleAllInstruction_H
