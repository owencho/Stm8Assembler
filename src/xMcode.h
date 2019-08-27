#ifndef Mcode_H
#define Mcode_H
#include "Common.h"
#include "Tokenizer.h"
#include "Operand.h"

typedef struct InstructionTable InstructionTable;
typedef struct MachineCode MachineCode;
typedef struct CodeInfo CodeInfo;
typedef struct ConversionData ConversionData;
typedef struct ExtensionCodeAndCode ExtensionCodeAndCode;
typedef  MachineCode*(*Assembler)(CodeInfo *CodeInfo , Tokenizer *tokenizer);

struct MachineCode{
    uint8_t length;
    uint8_t code[0];
};

struct ExtensionCodeAndCode{
    uint16_t extCode;
    uint16_t code;
};

struct CodeInfo{
    char* name;
    uint32_t firstFlags;
    Assembler assembler;
    ConversionData * conDataTable ;
};

struct ConversionData{
    stm8OperandType type;
    ExtensionCodeAndCode *codeTable;
    uint32_t secondFlags;
    uint32_t thirdFlags;
};

struct InstructionTable{
    char* name;
    CodeInfo *codeInfo;
};

#endif // Mcode_H
