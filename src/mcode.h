#ifndef mcode_H
#define mcode_H

typedef struct InstructionTable InstructionTable;
typedef struct MachineCode MachineCode;
typedef struct CodeInfo CodeInfo;
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
  ExtensionCodeAndCode *codeTable;
};

struct InstructionTable{
  char* name;
  CodeInfo *codeInfo;
};

#endif // mcode_H
