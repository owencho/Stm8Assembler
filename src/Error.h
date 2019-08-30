#ifndef Error_H
#define Error_H

// Error code
#define ERR_SYSTEM_ERROR                  10
#define ERR_INVALID_INSTRUCTION           20
#define ERR_INVALID_OPERAND               21
#define ERR_INVALID_INTEGER               41   // throw when $ is negative value
#define ERR_INVALID_FLOAT                 42
#define ERR_INVALID_OPERATOR              50
#define ERR_EXPECTING_INTEGER             51
#define ERR_EXPECTING_OPERATOR            52
#define ERR_INVALID_INPUT                 53
#define ERR_INTEGER_DOLLAR_TO_LARGE       60   // when it larger than certain value
#define ERR_INVALID_HASH_VALUE            61   // when hash value is invalid
#define ERR_INVALID_SIGNEDINT_VALUE       62   // for SHORT_OFF_OPERAND which exceed (-128 to 127) range
#define ERR_INVALID_MOV_OPERAND           63   // for MOV instruction when combination of two Operand is invalid
#define ERR_INTEGER_NEGATIVE              70   // negative value error
#define ERR_INTEGER_TOO_LARGE             71   // value larger than certain number
#define ERR_INTEGER_TOO_SMALL             72   // value smaller than certain number
#define ERR_INVALID_STM8_OPERAND          73
#define ERR_UNSUPPORTED_OPERAND           74   // when flag doesnt support this operand
#define ERR_INTEGER_NULL                  75   // when checking value is NULL
#define ERR_INVALID_SYNTAX                76   // for invalid syntax
#define ERR_DSTSRC_NULL                   77   // throw when detect a null dst src operand
#define ERR_INVALID_STM8_INSTRUCTION      78   // invalid instruction name
#define ERR_OPERAND_NULL                  79   // throw when detect a null operand (rarely use)
#define ERR_INVALID_NVALUE                80   // when nvalue on #n exceed (0 to 7) range
#define ERR_DATATABLE_NULL                81   // error when function cant find the data table
#define ERR_CODE_NULL                     82
#define ERR_MCODE_NULL                    83   // error throw by machineCodeAllocateOutput when NULL mcode generated


#endif // Error_H
