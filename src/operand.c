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
int OperandCheck(IntegerToken* token, int condition){
  if(strcasecmp(token->str,"X")==0)
      return 1;
  else if(strcasecmp(token->str,"Y")==0)
      return 2;
  else if (strcasecmp(token->str,"SP")==0 && (condition ==1 || condition ==2))
      return 3;
  else if(strcasecmp(token->str,"A")==0 && condition ==2)
      return 4;
  else if (condition ==1 )
      throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X ,Y , A and SP");
  else if (condition ==1 )
      throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X ,Y , and SP");
  else
      throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X and Y ");
}
int ValueCheck(IntegerToken* token){
  if(token->value <256 && token->value >0 ){
    return 1;
  }
  else if (token->value >256  && token->value < 65536){
    return 2;
  }
  else if (token-> value <0){
    throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive eg ($10)");
  }
  else if (token-> value >65536){
    throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must smaller than 64436 ($1000)");
  }
  else{
    throwException(ERR_INTEGER_NULL,token,"The integer number must have value eg ($10)");
  }
}



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
stm8Operand *operandHandleFirstSymbol(IntegerToken *token, uint32_t flags){
        stm8Operand *operand =malloc(sizeof(stm8Operand));
        if(strcasecmp(token->str,"A")==0){
          if(isOperandNeeded(flags,A_OPERAND)){
            operand = createOperand(A_OPERAND,NA,NA,NA,NA,NA);
          }
          else{
              throwException(ERR_UNSUPPORTED_OPERAND,token,"A operand is not supported");
          }
        }
        else if(strcasecmp(token->str,"X")==0){
            if(isOperandNeeded(flags,X_OPERAND)){
              operand = createOperand(X_OPERAND,NA,NA,NA,NA,NA);
            }
            else{
                throwException(ERR_UNSUPPORTED_OPERAND,token,"X operand is not supported");
            }
        }
        else if(strcasecmp(token->str,"Y")==0){
            if(isOperandNeeded(flags,Y_OPERAND)){
              operand = createOperand(Y_OPERAND,NA,NA,NA,NA,NA);
            }
            else{
                throwException(ERR_UNSUPPORTED_OPERAND,token,"Y operand is not supported");
            }
        }
        else if(strcasecmp(token->str,"SP")==0){
            if(isOperandNeeded(flags,SP_OPERAND)){
              operand = createOperand(SP_OPERAND,NA,NA,NA,NA,NA);
            }
            else{
                throwException(ERR_UNSUPPORTED_OPERAND,token,"SP operand is not supported");
            }
        }
        else{
          throwException(ERR_INVALID_OPERAND,token,"Expected only X , Y , A , SP , ( ,# , $ ");
        }
      }

stm8Operand *comparingLastOperand(IntegerToken* token,Tokenizer* tokenizer , int value, int valueCount , int squarecount){
      int operandCounter =0;
      stm8Operand *operand =malloc(sizeof(stm8Operand));

      operandCounter = OperandCheck(token,1);
          freeToken(token);
          token = (IntegerToken *)getToken(tokenizer);

          if(token->str == NULL){
            throwException(ERR_INVALID_STM8_OPERAND,token,"Expected ')'");
          }
          else if(strcmp(token->str,")")==0){
             if(squarecount>0){
               if(operandCounter==1){
                 if(valueCount==1)
                 operand = createLsOperand(SHORTPTR_DOT_W_BRACKETEDX_OPERAND,value,token);

                 else if (valueCount==2)
                 operand = createMsOperand(LONGPTR_DOT_W_BRACKETEDX_OPERAND,value,token);
               }
                if(operandCounter==2){
                 if(valueCount==1)
                 operand = createLsOperand(SHORTPTR_DOT_W_BRACKETEDY_OPERAND,value,token);

                 else
                  throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only value less than 256 and larger than 0");
               }
            }
              else if(operandCounter==1){
                if(valueCount==1)
                operand = createLsOperand(SHORTOFF_X_OPERAND,value,token);

                else if (valueCount==2)
                operand = createMsOperand(LONGOFF_X_OPERAND,value,token);
              }
              else if(operandCounter==2){
                if(valueCount==1)
                operand = createLsOperand(SHORTOFF_Y_OPERAND,value,token);
                else if (valueCount==2)
                operand = createMsOperand(LONGOFF_Y_OPERAND,value,token);
              }
              else if(operandCounter==3){
                if(valueCount==1)
                operand = createLsOperand(SHORTOFF_SP_OPERAND,value,token);
                else
                throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only value less than 256 and larger than 0 on SP");
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
          int valueCount = 0;
          int value =0;
          IntegerToken *token = (IntegerToken *)getToken(tokenizer);
          if(token->str[0]=='$' || isdigit(token->str[0])){
            value = token -> value;
            valueCount = ValueCheck(token);
          }
          else{
            throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only value eg [$77.w]");
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
                if(valueCount==1)
                operand = createLsOperand(BRACKETED_SHORTPTR_DOT_W_OPERAND,value,token);
                else if (valueCount==2)
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
        int valueCount = 0;
        int operandCount =0;
        int value =0;
        IntegerToken *token = (IntegerToken *)getToken(tokenizer);

        if(isalpha(token->str[0])){
          operandCount=OperandCheck(token,0);
        }
        else if(strcmp(token->str,"[")==0){
          squareOperand = operandHandleSquareBracket(tokenizer);
          squareCount++;
          if(squareOperand->dataSize.ls != 65535){
            valueCount = 2;
            value = (squareOperand->dataSize.ms << 4) || squareOperand->dataSize.ls;
          }
          else {
            valueCount = 1;
            value = squareOperand->dataSize.ms;
          }

        }
        else if(token->str[0]=='$' || isdigit(token->str[0])){
          counterhash++;
          value = token -> value;
            valueCount = ValueCheck(token);
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
          if(operandCount == 0){
            freeToken(token);
            token = (IntegerToken *)getToken(tokenizer);
            operand = comparingLastOperand(token,tokenizer,value,valueCount,squareCount);
          }
          else{
              throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X and Y after commar and value before commar eg:(88,X)");
          }

        }
        else if(strcmp(token->str,")")==0){
          if(operandCount ==1)
          operand = createOperand(BRACKETED_X_OPERAND,NA,NA,NA,NA,NA);
          else if(operandCount ==2 )
          operand = createOperand(BRACKETED_Y_OPERAND,NA,NA,NA,NA,NA);
        }
        else
            throwException(ERR_INVALID_STM8_OPERAND,token,"Expected , and ) ");

        return operand;
      }



      //Main Program
stm8Operand *getOperand(Tokenizer *tokenizer , uint32_t flags){
        CEXCEPTION_T ex;
        stm8Operand *operand =NULL;
        IntegerToken *token;
        int lsCount = 0;
        int msCount = 0;
        uint16_t valueLs ;
        uint16_t valueMs ;

          token =(IntegerToken*)getToken(tokenizer);

          if(isalpha(token->str[0])){
            operand = operandHandleFirstSymbol(token , flags);
            freeToken(token);
          }
          else if(strcmp(token->str,"[")==0){
            operand = operandHandleSquareBracket(tokenizer);
            freeToken(token);
          }

          else if(strcmp(token->str,"#")==0){
            freeToken(token);
            token = (IntegerToken *)getToken(tokenizer);
            int valueCount = ValueCheck(token);
            if(valueCount ==1){
              operand = createOperand(BYTE_OPERAND,NA,NA,token->value,NA,NA);
              freeToken(token);
            }
            else{
              throwException(ERR_INTEGER_HASH_TOO_LARGE,token,"Expected only value lesser than 256 (#12)");
            }
          }

          else if(token->str[0]=='$' || isdigit(token->str[0])){
            int valueCount = ValueCheck(token);
            if(valueCount ==1){
              operand = createLsOperand(SHORT_MEM_OPERAND,token->value,token);
            }
            else if(valueCount ==2){
              operand = createMsOperand(LONG_MEM_OPERAND,token->value,token);
            }
            freeToken(token);
            }

          else if(token->str[0]=='('){
              operand = operandHandleRoundBracket(tokenizer);
              freeToken(token);
          }

          else{
                //need to change
          throwException(ERR_INVALID_OPERAND,token,"Expected only X , Y , A , SP , ( ,# , $ ");
          }

        return operand;
      }
