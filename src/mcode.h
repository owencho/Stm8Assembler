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
  uint32_t firstFlags;
  Assembler assembler;
  ConversionData * conDataTable ;
};

struct ConversionData{
  char* name;
  ExtensionCodeAndCode *codeTable;
  uint32_t secondFlags;
  uint32_t thirdFlags;
};

struct InstructionTable{
  char* name;
  CodeInfo *codeInfo;
};

#endif // mcode_H
