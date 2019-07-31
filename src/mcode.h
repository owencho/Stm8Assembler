#include "unity.h"
#include "Common.h"
#include "Token.h"
#include "Error.h"
#include "Tokenizer.h"
#include "CException.h"
#include "Exception.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#ifndef mcode_H
#define mcode_H

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
  Assembler assembler;
  uint32_t operandExistenceFlags[3];
  ExtensionCodeAndCode *codeTable[5];  //replace with ConversionData
};

struct ConversionData{
  ExtensionCodeAndCode *codeTable;
  uint32_t operandExistenceFlags;
};

struct InstructionTable{
  char* name;
  CodeInfo *codeInfo;
};

#endif // mcode_H
