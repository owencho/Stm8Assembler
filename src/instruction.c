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
    //arithmeticOperationsInstruction
    {"neg",&negCodeInfo},
    {"adc",&adcCodeInfo},
    {"add",&addCodeInfo},
    {"sub",&subCodeInfo},
    {"mul",&mulCodeInfo},
    {"sbc",&sbcCodeInfo},
    {"addw",&addwCodeInfo},
    {"div",&divCodeInfo},
    {"subw",&subwCodeInfo},
    {"negw",&negwCodeInfo},
    //breakPointInstruction
    {"break",&breakCodeInfo},
    //conditionCodeFlagModificationInstruction
    {"sim",&simCodeInfo},
    {"rim",&rimCodeInfo},
    {"scf",&scfCodeInfo},
    {"rcf",&rcfCodeInfo},
    {"rvf",&rvfCodeInfo},
    {"ccf",&ccfCodeInfo},
    //interruptManagementInstruction
    {"trap",&trapCodeInfo},
    {"wfi",&wfiCodeInfo},
    {"halt",&haltCodeInfo},
    {"iret",&iretCodeInfo},
    //bitOperationInstruction
    {"bcpl",&bcplCodeInfo},
    {"bccm",&bccmCodeInfo},
    {"bset",&bsetCodeInfo},
    {"bres",&bresCodeInfo},
    //shiftRotatesInstruction
    {"sll",&sllCodeInfo},
    {"sla",&slaCodeInfo},
    {"srl",&srlCodeInfo},
    {"sra",&sraCodeInfo},
    {"rlc",&rlcCodeInfo},
    {"rrc",&rrcCodeInfo},
    {"swap",&swapCodeInfo},
    {"sllw",&sllwCodeInfo},
    {"slaw",&slawCodeInfo},
    {"srlw",&srlwCodeInfo},
    {"sraw",&srawCodeInfo},
    {"rlcw",&rlcwCodeInfo},
    {"rrcw",&rrcwCodeInfo},
    {"swapw",&swapwCodeInfo},
    {"rlwa",&rlwaCodeInfo},
    {"rrwa",&rrwaCodeInfo},
    //stackInstruction
    {"push",&pushCodeInfo},
    {"pop",&popCodeInfo},
    {"pushw",&pushwCodeInfo},
    {"popw",&popwCodeInfo},
    //incrementDecrementInstruction
    {"inc",&incCodeInfo},
    {"dec",&decCodeInfo},
    {"incw",&incwCodeInfo},
    {"decw",&decwCodeInfo},
    //compareAndTestsInstruction
    {"cp",&cpCodeInfo},
    {"tnz",&tnzCodeInfo},
    {"bcp",&bcpCodeInfo},
    {"cpw",&cpwCodeInfo},
    {"tnzw",&tnzwCodeInfo},
    //logicalOperationsInstruction
    {"and",&andCodeInfo},
    {"or",&orCodeInfo},
    {"xor",&xorCodeInfo},
    {"cpl",&cplCodeInfo},
    {"cplw",&cplwCodeInfo},
    //conditionalBranchExecutionInstruction
    {"jrc",&jrcCodeInfo},
    {"jreq",&jreqCodeInfo},
    {"jrf",&jrfCodeInfo},
    {"jrh",&jrhCodeInfo},
    {"jrih",&jrihCodeInfo},
    {"jril",&jrilCodeInfo},
    {"jrm",&jrmCodeInfo},
    {"jrmi",&jrmiCodeInfo},
    {"jrnc",&jrncCodeInfo},
    {"jrne",&jrneCodeInfo},
    {"jrnh",&jrnhCodeInfo},
    {"jrnm",&jrnmCodeInfo},
    {"jrnv",&jrnvCodeInfo},
    {"jrpl",&jrplCodeInfo},
    {"jrsge",&jrsgeCodeInfo},
    {"jrsgt",&jrsgtCodeInfo},
    {"jrsle",&jrsleCodeInfo},
    {"jrslt",&jrsltCodeInfo},
    {"jrt",&jrtCodeInfo},
    {"jruge",&jrugeCodeInfo},
    {"jrugt",&jrugtCodeInfo},
    {"jrule",&jrulecodeInfo},
    {"jrult",&jrultCodeInfo},
    {"jrv",&jrvCodeInfo},
    {"wfe",&wfeCodeInfo},
    //loadTransferInstruction
  /*  {"ld",&ldCodeInfo},
    {"ldf",&ldfCodeInfo},
    {"clr",&clrCodeInfo},
    {"mov",&movCodeInfo},
    {"exg",&exgCodeInfo},
    {"ldw",&ldwCodeInfo},
    {"clr",&clrwCodeInfo},
    {"exgw",&exgwCodeInfo},
    /////////////////////////////////////



    //


    /*


    {"nop",&nopCodeInfo},
    {"ret",&retCodeInfo},
    {"retf",&retfCodeInfo},
    //////////////////////////////////////

    {"call",&callCodeInfo},

    */

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
    if(instructionTable[i].name == NULL){
        throwException(ERR_INVALID_STM8_INSTRUCTION,token,"Invalid instruction name!");
    }

    return mcode ;
}
