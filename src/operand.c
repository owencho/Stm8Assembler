#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include "operand.h"
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

stm8Operand *createLsOperand( stm8OperandType type,
    int value,
    IntegerToken *token){
      stm8Operand *operand =malloc(sizeof(stm8Operand));
      if(value <256 && value >0){
        operand->type = type;
        operand->dataSize.extCode =NA;
        operand->dataSize.code =NA;
        operand->dataSize.ms =value;
        operand->dataSize.ls = NA;
        operand->dataSize.extB =NA;
      }else if (value < 0){
        throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be larger than 0 (non zero)");
      }else {
        throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must be smaller than 255 ($10)");
      }
      return operand;
    }

stm8Operand *createMsOperand( stm8OperandType type,
      int value,
      IntegerToken *token){

        stm8Operand *operand =malloc(sizeof(stm8Operand));
        if(value <65536 && value >256){
          uint16_t valueLs = value & 0xff;  // low
          uint16_t valueMs = value >> 8;    // high
          operand->type = type;
          operand->dataSize.extCode =NA;
          operand->dataSize.code =NA;
          operand->dataSize.ms =valueMs;
          operand->dataSize.ls = valueLs;
          operand->dataSize.extB =NA;
        }else if (value > 65536){
          throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must be smaller than 65536 ($1000)");
        }else if(value < 256){
          throwException(ERR_INTEGER_TOO_SMALL,token,"The integer number must be larger than 0 (non zero)");
        }
        return operand;
      }

stm8Operand *comparingLastOperand(IntegerToken* token,Tokenizer* tokenizer , int value, int lsCount , int msCount , int squarecount){
      int counterX = 0;
      int counterY = 0;
      int counterSP =0;
      stm8Operand *operand =malloc(sizeof(stm8Operand));
          if(strcasecmp(token->str,"X")==0)
              counterX++;
          else if(strcasecmp(token->str,"Y")==0)
              counterY++;
          else if (strcasecmp(token->str,"SP")==0)
              counterSP++;
          else
              throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X ,Y , and SP");


          freeToken(token);
          token = (IntegerToken *)getToken(tokenizer);

          if(token->str == NULL){
            throwException(ERR_INVALID_STM8_OPERAND,token,"Expected ')'");
          }
          else if(strcmp(token->str,")")==0){
             if(squarecount>0 ){
               if(counterX>0){
                 if(lsCount>0)
                 operand = createLsOperand(SHORTPTR_DOT_W_BRACKETEDX_OPERAND,value,token);

                 else if (msCount>0)
                 operand = createMsOperand(LONGPTR_DOT_W_BRACKETEDX_OPERAND,value,token);
               }
                if(counterY>0){
                 if(lsCount>0)
                 operand = createLsOperand(SHORTPTR_DOT_W_BRACKETEDY_OPERAND,value,token);

                 else
                  throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only value less than 256 on [] Y");
               }
            }
              else if(counterX>0){
                if(lsCount>0)
                operand = createLsOperand(SHORTOFF_X_OPERAND,value,token);

                else if (msCount>0)
                operand = createMsOperand(LONGOFF_X_OPERAND,value,token);
              }
              else if(counterY >0 ){
                if(lsCount>0)
                operand = createLsOperand(SHORTOFF_Y_OPERAND,value,token);
                else if (msCount>0)
                operand = createMsOperand(LONGOFF_Y_OPERAND,value,token);
              }

              else if(counterSP >0 ){
                if(lsCount>0)
                operand = createLsOperand(SHORTOFF_SP_OPERAND,value,token);
                else if (msCount >0)
                throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only value less than 256 on SP");
              }
        }
        else{
          throwException(ERR_INVALID_STM8_OPERAND,token,"Expected ')'");
        }
    return operand;
  }

    stm8Operand *operandHandleSquareBracket( Tokenizer *tokenizer){
          stm8Operand *operand =malloc(sizeof(stm8Operand));
          int counterhash =0;
          int commarCount =0;
          int counterX = 0;
          int counterY = 0;
          int lsCount = 0;
          int msCount = 0;
          int value =0;
          IntegerToken *token = (IntegerToken *)getToken(tokenizer);
          if(token->str[0]=='$' || isdigit(token->str[0])){
            value = token -> value;
            if(token->value <256 && token->value >0 ){
              lsCount++;
            }
            else if (token->value >256  && token->value < 65536){
              msCount++;
            }
            else if (token-> value <0){
              throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive ($10)");
            }
            else if (token-> value >65536){
              throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must smaller than 64436 ($1000)");
            }
          }
          else{
            throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only value ($77)");
          }
          freeToken(token);
          token = (IntegerToken *)getToken(tokenizer);
          if(strcmp(token->str,".")==0){
            freeToken(token);
            token = (IntegerToken *)getToken(tokenizer);
            if(strcasecmp(token->str,"W")==0){
              freeToken(token);
              token = (IntegerToken *)getToken(tokenizer);
              if(strcmp(token->str,"]")==0){
                if(lsCount>0)
                operand = createLsOperand(BRACKETED_SHORTPTR_DOT_W_OPERAND,value,token);
                else if (msCount>0)
                operand = createMsOperand(BRACKETED_LONGPTR_DOT_W_OPERAND,value,token);
              }
              else{
                throwException(ERR_INVALID_STM8_OPERAND,token,"Expected ] closing squarebracket");
              }
            }
            else{
                throwException(ERR_INVALID_STM8_OPERAND,token,"Expected w after .");
            }
          }
          else{
            throwException(ERR_INVALID_STM8_OPERAND,token,"Expected . after value");
          }

          return operand;
        }


      stm8Operand *operandHandleRoundBracket( Tokenizer *tokenizer){
        stm8Operand *operand =malloc(sizeof(stm8Operand));
        stm8Operand *squareOperand =malloc(sizeof(stm8Operand));
        int counterhash =0;
        int squareCount =0;
        int counterX = 0;
        int counterY = 0;
        int lsCount = 0;
        int msCount = 0;
        int value =0;
        IntegerToken *token = (IntegerToken *)getToken(tokenizer);
        if(strcasecmp(token->str,"X")==0){
          counterX++;
        }
        else if(strcasecmp(token->str,"Y")==0){
          counterY++;
        }
        else if(strcmp(token->str,"[")==0){
          squareOperand = operandHandleSquareBracket(tokenizer);
          squareCount++;
          if(squareOperand->dataSize.ls != 65535){
            msCount++;
            value = (squareOperand->dataSize.ms << 4) | squareOperand->dataSize.ls;
          }
          else {
          lsCount++;
          value = squareOperand->dataSize.ms;
          }

        }
        else if(token->str[0]=='$' || isdigit(token->str[0])){
          counterhash++;
          value = token -> value;
          if(token->value <256 && token->value >0 ){
            lsCount++;
          }
          else if (token->value >256  && token->value < 65536){
            msCount++;
          }
          else if (token-> value <0){
            throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive ($10)");
          }
          else if (token-> value >65536){
            throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must smaller than 64436 ($1000)");
          }
        }
        else if(strcmp(token->str,"-")==0){
          throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive ($10)");
        }
        else{
          throwException(ERR_INVALID_STM8_OPERAND,token,"only Expected X , Y and value");
        }




        freeToken(token);
        token = (IntegerToken *)getToken(tokenizer);
        if(token->str==NULL){
          throwException(ERR_INVALID_STM8_OPERAND,token,"Expected , and ) ");
        }
        else if(strcmp(token->str,",")==0){
          if(counterX == 0 && counterY== 0){
            freeToken(token);
            token = (IntegerToken *)getToken(tokenizer);
            operand = comparingLastOperand(token,tokenizer,value,lsCount,msCount,squareCount);
          }
          else{
              throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X and Y after commar and value before commar eg:(88,X)");
          }

        } 
        else if(strcmp(token->str,")")==0){
          if(counterX >0)
          operand = createOperand(BRACKETED_X_OPERAND,NA,NA,NA,NA,NA);
          else if(counterY >0 )
          operand = createOperand(BRACKETED_Y_OPERAND,NA,NA,NA,NA,NA);
        }
        else
            throwException(ERR_INVALID_STM8_OPERAND,token,"Expected , and ) ");

        return operand;
      }



      //Main Program
      stm8Operand *getOperand(Tokenizer *tokenizer){
        CEXCEPTION_T ex;
        stm8Operand *operand =NULL;
        IntegerToken *token;
        int lsCount = 0;
        int msCount = 0;
        uint16_t valueLs ;
        uint16_t valueMs ;

          token =(IntegerToken*)getToken(tokenizer);

          if(strcmp(token->str,"A")==0){
            operand = createOperand(A_OPERAND,NA,NA,NA,NA,NA);
            freeToken(token);
          }
          else if(strcmp(token->str,"[")==0){
            operand = operandHandleSquareBracket(tokenizer);
            freeToken(token);
          }

          else if(strcmp(token->str,"#")==0){
            freeToken(token);
            token = (IntegerToken *)getToken(tokenizer);
            if(token-> value <256){
              operand = createOperand(BYTE_OPERAND,NA,NA,token->value,NA,NA);
              freeToken(token);
            }
            else if(token->value >256){
              throwException(ERR_INTEGER_HASH_TOO_LARGE,token,"The integer number must lesser than 255 ($10)");
            }
            else{
              throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive ($10)");
            }
          }

          else if(token->str[0]=='$' || isdigit(token->str[0])){
            if(token->value <256 && token->value >0){
              operand = createLsOperand(SHORT_MEM_OPERAND,token->value,token);
            }
            else if(token->value >256 && token->value < 65536){
              operand = createMsOperand(LONG_MEM_OPERAND,token->value,token);
            }
            else if(token->value <0)
                throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive ($10)");
            else
                throwException(ERR_INTEGER_DOLLAR_TO_LARGE,token,"The integer number must be smaller than 65536 ($10000)");
            freeToken(token);
            }

          else if(token->str[0]=='('){
              operand = operandHandleRoundBracket(tokenizer);
              freeToken(token);
              }

            else{
                //need to change
              throwException(ERR_INTEGER_DOLLAR_TO_LARGE,token,"The integer number must be smaller than 65536 ($10000)");
            }

        return operand;
      }
