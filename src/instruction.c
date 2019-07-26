#include "instruction.h"
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

InstructionTable instructionTable[]={
  //assembleAOperandAndComplexOperand
  {"adc",&adcCodeInfo},
  {"add",&addCodeInfo},
  {"and",&andCodeInfo},
  {"bcp",&bcpCodeInfo},
  {"cp",&cpCodeInfo},
  {"exg",&exgCodeInfo},
  {"or",&orCodeInfo},
  {"sbc",&sbcCodeInfo},
  {"xor",&xorCodeInfo},
  //assembleASPOperandAndComplexOperand
  {"sub",&subCodeInfo},
  //assembleXYSPOperandAndComplexOperand
  {"addw",&addwCodeInfo},
  //assembleXYOperandAndComplexOperand
  {"cpw",&cpwCodeInfo},
  {"div",&divCodeInfo},
  {"subw",&subwCodeInfo},
  //assembleNoOperand
  {"break",&breakCodeInfo},
  {"ccf",&ccfCodeInfo},
  {"halt",&haltCodeInfo},
  {"iret",&iretCodeInfo},
  {"nop",&nopCodeInfo},
  {"rcf",&rcfCodeInfo},
  {"ret",&retCodeInfo},
  {"retf",&retfCodeInfo},
  {"rim",&rimCodeInfo},
  {"rvf",&rvfCodeInfo},
  {"scf",&scfCodeInfo},
  {"sim",&simCodeInfo},
  {"trap",&trapCodeInfo},
  {"wfe",&wfeCodeInfo},
  {"wfi",&wfiCodeInfo},
  //assembleXOperandAndComplexOperand
  //{"divw",&divwCodeInfo},
  //assembleOneOperand
  {"sllw",&sllwCodeInfo},
  {NULL,NULL}
};


MachineCode *assembleInstruction(Tokenizer *tokenizer){
   IntegerToken *token = NULL;
   CodeInfo *codeInfo = NULL;
   MachineCode* mcode = NULL;
   int i =0;
   int a =0;

    //find codeInfo on instructionTable
    token =(IntegerToken*)getToken(tokenizer);
    pushBackToken(tokenizer,(Token*) token);
    if(TOKEN_IDENTIFIER_TYPE != token-> type)
      return NULL;

    do{
      nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected valid name");
      if(strcasecmp(instructionTable[i].name,token->str)==0){
        codeInfo = instructionTable[i].codeInfo;
        mcode = codeInfo->assembler(codeInfo,tokenizer);
        break;
      }
      i++;
    }while(instructionTable[i].name != NULL);


    return mcode ;
}
