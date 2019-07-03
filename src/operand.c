#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include "operand.h"
#include "AssignValue.h"
#include "StringLib.h"
#include "unity.h"
#include "Common.h"
#include "Token.h"
#include "Error.h"
#include "Tokenizer.h"
#include "CException.h"
#include "Exception.h"
//SubProgram
stm8Operand *createOperand( stm8OperandType type,
  uint16_t extCode,
  uint16_t code,
  uint16_t ms,
  uint16_t ls,
  uint16_t extB){
    stm8Operand *operand =malloc(sizeof(stm8Operand));
    operand->type = type;
    operand->dataSize.extCode =extCode;
    operand->dataSize.code =code;
    operand->dataSize.ms =ms ;
    operand->dataSize.ls = ls;
    operand->dataSize.extB =extB;

    return operand;
  }



  //Main Program
  stm8Operand *getOperand(Tokenizer *tokenizer){
    CEXCEPTION_T ex;
    stm8Operand *operand =NULL;
    IntegerToken *token;
    int counterX = 0;
    int counterY = 0;
    int counterSP =0;
    int counterhash =0;
    int commarCount =0;
    int lsCount = 0;
    int msCount = 0;
    uint16_t valueLs ;
    uint16_t valueMs ;


    Try {
      token =(IntegerToken*)getToken(tokenizer);

      if(strcmp(token->str,"A")==0){
        operand = createOperand(A_OPERAND,NA,NA,NA,NA,NA);
        freeToken(token);
      }

      else if(strcmp(token->str,"#")==0){
        freeToken(token);
        token = (IntegerToken *)getToken(tokenizer);
        if(token-> value <256){
          operand = createOperand(BYTE_OPERAND,NA,NA,token->value,NA,NA);
          freeToken(token);
        }
        else{
          throwException(ERR_INTEGER_HASH_TOO_LARGE,token,"The integer number must be smaller than 255 ($10)");
        }
      }


      else if(token->str[0]=='$'){

        if(token-> value <256){
          operand = createOperand(SHORT_MEM_OPERAND,NA,NA,token->value,NA,NA);
        }

        else if (token-> value < 65536){
          valueLs = token->value & 0xff;  // low
          valueMs = token->value >> 8;    // high
          operand = createOperand(LONG_MEM_OPERAND,NA,NA,valueMs,valueLs,NA);

        }

        else{
          throwException(ERR_INTEGER_DOLLAR_TO_LARGE,token,"The integer number must be smaller than 65536 ($10000)");
        }
        freeToken(token);
      }

      else if(strcmp(token->str,"(")==0){
        freeToken(token);
        token = (IntegerToken *)getToken(tokenizer);


        if(strcmp(token->str,"X")==0)
        counterX++;
        if(strcmp(token->str,"Y")==0)
        counterY++;
        if(token->str[0]=='$'){
          counterhash++;
          if(token->value <256){
            valueLs = token->value;
            lsCount++;
          }
          else if (token->value < 65536){
            valueLs = token->value & 0xff;  // low
            valueMs = token->value >> 8;    // high
            msCount++;
          }
          else{
            throwException(ERR_INTEGER_DOLLAR_TO_LARGE,token,"The integer number must be smaller than 65536 ($10000)");
          }
          freeToken(token);
          token = (IntegerToken *)getToken(tokenizer);
          if(token->str[0]==','){
            commarCount++;
            freeToken(token);
            token = (IntegerToken *)getToken(tokenizer);
            if(strcmp(token->str,"X")==0)
            counterX++;
            else if(strcmp(token->str,"Y")==0)
            counterY++;
            else{
              //throwException
            }
          }

        }

        freeToken(token);
        token = (IntegerToken *)getToken(tokenizer);
        if(strcmp(token->str,")")==0){
          if(commarCount==1){

            if(counterX>0){
              if(lsCount>0)
                operand = createOperand(SHORTOFF_X_OPERAND,NA,NA,valueLs,NA,NA);

              else if (msCount>0)
                operand = createOperand(LONGOFF_X_OPERAND,NA,NA,valueMs,valueLs,NA);

              else
                //throwException
            }

            else if(counterY >0 ){
              if(lsCount>0)
                operand = createOperand(SHORTOFF_Y_OPERAND,NA,NA,valueLs,NA,NA);

              else if (msCount>0)
                operand = createOperand(LONGOFF_Y_OPERAND,NA,NA,valueMs,valueLs,NA);

              else
                //throwException

            }
            else if(counterSP >0 ){
              if(lsCount>0)
                operand = createOperand(SHORTOFF_SP_OPERAND,NA,NA,valueLs,NA,NA);
              else
              //throwException
            }
          }
            else{
              if(counterX>0)
                operand = createOperand(BRACKETED_X_OPERAND,NA,NA,NA,NA,NA);
              else if(counterY >0 )
                operand = createOperand(BRACKETED_Y_OPERAND,NA,NA,NA,NA,NA);
              else{
                //throwException
              }
            }
          }

      }Catch(ex) {
        dumpTokenErrorMessage(ex, 1);
        freeToken(ex->data);

      }
    return operand;
  }
