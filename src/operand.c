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

IntegerToken* extendTokenStr(IntegerToken *tokenToExtend , IntegerToken *tokenToCover ){
  if(tokenToExtend->str != NULL){
      free(tokenToExtend->str);
  }
  IntegerToken *token = tokenToExtend;
   token-> str = malloc(tokenToCover->startColumn - tokenToExtend->startColumn +1 +1);
   strncpy (token->str ,tokenToExtend->originalStr + tokenToExtend->startColumn ,(tokenToCover->startColumn - tokenToExtend->startColumn +1));
   token->length = tokenToCover->startColumn - tokenToExtend->startColumn +1;
   return token;
}
void nullCheck(int errorCode, IntegerToken* token , char *message){
    if(token->str == NULL)
      throwException(errorCode,token,message);
}

void operandFlagCheck(uint32_t flags, IntegerToken* token ,stm8OperandType type  ){
    if(!isOperandNeeded(flags,type))
      throwException(ERR_UNSUPPORTED_OPERAND,token,"Operand is not supported");
}



int operandCheck(IntegerToken* token, int condition){
    nullCheck(ERR_INTEGER_NULL,token,"The integer number cannot be NULL");
    if(strcasecmp(token->str,"X")==0)
        return 1;
    else if(strcasecmp(token->str,"Y")==0)
        return 2;
    else if (strcasecmp(token->str,"SP")==0 && (condition ==1 || condition ==2))
        return 3;
    else if(strcasecmp(token->str,"A")==0 && condition ==2)
        return 4;
    else if (condition == 2)
        throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X ,Y , A and SP");
    else if (condition ==1 )
        throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X ,Y , and SP");
    else if (condition == 0)
        throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X and Y ");
    else
        throwException(ERR_INVALID_STM8_OPERAND,token,"Invalid input ");
}


int valueCheck(IntegerToken* token){
    nullCheck(ERR_INTEGER_NULL,token,"The integer number cannot be NULL");
    if((token->str[0]=='$' || token->str[0]=='-') || isdigit(token->str[0])){
      if(strcmp(token->str,"-")==0){
        throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive eg ($10)");
      }
      else if(token->str[1]!='-' && !isalnum(token->str[1]) ){
        throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only numbers ($10)");
      }
      else if(token->value <256 && token->value >0 ){
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
    }
    else{
      throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only numbers ($10)");
    }

}



stm8Operand *createOperand( stm8OperandType type,
    uint16_t extCode,
    uint16_t code,
    uint16_t ms,
    uint16_t ls,
    uint16_t extB){
      stm8Operand *operand =malloc(sizeof(stm8Operand));
        operand->dataSize.extCode = extCode;
      operand->type = type;
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
        operand = createOperand(type,NA,NA,value,NA,NA);
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
          operand = createOperand(type,NA,NA,valueMs,valueLs,NA);
        }else if (value > 65536){
          throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must be smaller than 65536 ($1000)");
        }else if(value < 256){
          throwException(ERR_INTEGER_TOO_SMALL,token,"The integer number must be larger than 0 (non zero)");
        }
        return operand;
      }

stm8Operand *operandHandleFirstSymbol(Tokenizer* tokenizer ,uint32_t flags){
        stm8Operand *operand =malloc(sizeof(stm8Operand));
        IntegerToken* token = (IntegerToken *)getToken(tokenizer);
        IntegerToken *valueToken = token ;
        IntegerToken* flagToken;
        token = (IntegerToken *)getToken(tokenizer);
        if(token->str == NULL){
          if(strcasecmp(valueToken->str,"A")==0){
              flagToken = extendTokenStr(valueToken ,token);
              operandFlagCheck(flags,flagToken,A_OPERAND);
              operand = createOperand(A_OPERAND,NA,NA,NA,NA,NA);
          }
          else if(strcasecmp(valueToken->str,"X")==0){
            flagToken = extendTokenStr(valueToken ,token);
            operandFlagCheck(flags,flagToken,X_OPERAND);
            operand = createOperand(X_OPERAND,NA,NA,NA,NA,NA);
          }
          else if(strcasecmp(valueToken->str,"Y")==0){
            flagToken = extendTokenStr(valueToken ,token);
            operandFlagCheck(flags,flagToken,Y_OPERAND);
            operand = createOperand(Y_OPERAND,NA,NA,NA,NA,NA);
          }
          else if(strcasecmp(valueToken->str,"SP")==0){
            flagToken = extendTokenStr(valueToken ,token);
            operandFlagCheck(flags,flagToken,SP_OPERAND);
            operand = createOperand(SP_OPERAND,NA,NA,NA,NA,NA);
          }
          else{
            throwException(ERR_INVALID_OPERAND,valueToken,"Expected only X , Y , A , SP , ( ,# , $ ");
          }
        }
        else{
          throwException(ERR_INVALID_OPERAND,token,"Expected nothing after that ");
        }

        return operand;
      }

stm8Operand *comparingLastOperand(uint32_t flags,IntegerToken* tokenValue,Tokenizer* tokenizer , int value, int valueCount , int squarecount){
      int operandCounter =0;
      stm8Operand *operand =malloc(sizeof(stm8Operand));
      IntegerToken* token = (IntegerToken *)getToken(tokenizer);
      IntegerToken* flagToken;
      operandCounter = operandCheck(token,1);
      token = (IntegerToken *)getToken(tokenizer);


        nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected )");
        if(strcmp(token->str,")")==0){
             if(squarecount>0){
               if(operandCounter==1){
                 if(valueCount==1){
                    flagToken = extendTokenStr(tokenValue ,token);
                    operandFlagCheck(flags,tokenValue,SHORTPTR_DOT_W_BRACKETEDX_OPERAND);
                    operand = createLsOperand(SHORTPTR_DOT_W_BRACKETEDX_OPERAND,value,token);
                 }
                 else if (valueCount==2){
                   flagToken = extendTokenStr(tokenValue ,token);
                   operandFlagCheck(flags,flagToken,LONGPTR_DOT_W_BRACKETEDX_OPERAND);
                   operand = createMsOperand(LONGPTR_DOT_W_BRACKETEDX_OPERAND,value,token);
                 }
               }
               else if(operandCounter==2){
                 if(valueCount==1){
                   flagToken = extendTokenStr(tokenValue ,token);
                   operandFlagCheck(flags,flagToken,SHORTPTR_DOT_W_BRACKETEDY_OPERAND);
                    operand = createLsOperand(SHORTPTR_DOT_W_BRACKETEDY_OPERAND,value,token);
                 }

                 else{
                   throwException(ERR_INVALID_STM8_OPERAND,tokenValue,"Expected only value less than 256 and larger than 0");
                 }
               }

            }
            else if(operandCounter==1){
                if(valueCount==1){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,SHORTOFF_X_OPERAND);
                  operand = createLsOperand(SHORTOFF_X_OPERAND,value,token);
                }
                else if (valueCount==2){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,LONGOFF_X_OPERAND);
                  operand = createMsOperand(LONGOFF_X_OPERAND,value,token);
                }
              }
              else if(operandCounter==2){
                if(valueCount==1){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,SHORTOFF_Y_OPERAND);
                  operand = createLsOperand(SHORTOFF_Y_OPERAND,value,token);
                }
                else if (valueCount==2){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,LONGOFF_Y_OPERAND);
                  operand = createMsOperand(LONGOFF_Y_OPERAND,value,token);
                }
              }
              else if(operandCounter==3){
                if(valueCount==1){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,SHORTOFF_SP_OPERAND);
                  operand = createLsOperand(SHORTOFF_SP_OPERAND,value,token);
                }
                else{
                  throwException(ERR_INVALID_STM8_OPERAND,tokenValue,"Expected only value less than 256 and larger than 0 on SP");
                }
              }
        }
        else{
          throwException(ERR_INVALID_STM8_OPERAND,token,"Expected ')'");
        }
    return operand;
  }

stm8Operand *operandHandleSquareBracket( Tokenizer *tokenizer ,uint32_t flags){
          stm8Operand *operand =malloc(sizeof(stm8Operand));
          int counterhash =0;
          int commarCount =0;
          int counterX = 0;
          int counterY = 0;
          int valueCount = 0;
          int value =0;
          IntegerToken *flagToken;
          IntegerToken *valueBracToken;
          IntegerToken *initToken;
          IntegerToken *token = (IntegerToken *)getToken(tokenizer);

          nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected [ ");
          if(strcmp(token->str,"[")==0){
              initToken = token;
              token = (IntegerToken *)getToken(tokenizer);
              if(token->str[0]=='$' || isdigit(token->str[0])){
                value = token -> value;
                valueCount = valueCheck(token);
                valueBracToken = token;
              }
              else{
                throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only value eg [$77.w]");
              }
              //freeToken(token);
              token = (IntegerToken *)getToken(tokenizer);
              nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected . after value");
              if(strcmp(token->str,".")==0){
                freeToken(token);
                token = (IntegerToken *)getToken(tokenizer);
                nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected w after .");
                if(strcasecmp(token->str,"W")==0){
                  freeToken(token);
                  token = (IntegerToken *)getToken(tokenizer);
                  nullCheck(ERR_INVALID_STM8_OPERAND,token,"Expected ] closing squarebracket");
                  if(strcmp(token->str,"]")==0){
                    if(valueCount==1){
                      flagToken = extendTokenStr(initToken ,token);
                      operandFlagCheck(flags,flagToken,BRACKETED_SHORTPTR_DOT_W_OPERAND);
                      operand = createLsOperand(BRACKETED_SHORTPTR_DOT_W_OPERAND,value,token);
                    }

                    else if (valueCount==2){
                      flagToken = extendTokenStr(initToken,token);
                      operandFlagCheck(flags,flagToken,BRACKETED_LONGPTR_DOT_W_OPERAND);
                      operand = createMsOperand(BRACKETED_LONGPTR_DOT_W_OPERAND,value,token);
                    }

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

        }


stm8Operand *operandHandleRoundBracket( Tokenizer *tokenizer , uint32_t flags){
        stm8Operand *operand =malloc(sizeof(stm8Operand));
        stm8Operand *squareOperand =malloc(sizeof(stm8Operand));
        int counterhash =0;
        int squareCount =0;
        int valueCount = 0;
        int operandCount =0;
        IntegerToken *tokenValue;
        IntegerToken *flagToken;
        unsigned int value =0;

        IntegerToken* token = (IntegerToken *)getToken(tokenizer);
        IntegerToken *initToken = token ;

        token = (IntegerToken *)getToken(tokenizer);
        tokenValue = token;

        if(isalpha(token->str[0])){
          operandCount=operandCheck(token,0);
        }
        else if(strcmp(token->str,"[")==0){
          pushBackToken(tokenizer,(Token*)token);
          squareOperand = operandHandleSquareBracket(tokenizer,flags);
          squareCount++;
          if(squareOperand->dataSize.ls != 65535){
            valueCount = 2;
            value = (squareOperand->dataSize.ms << 8) | squareOperand->dataSize.ls;
          }
          else {
            valueCount = 1;
            value = squareOperand->dataSize.ms;
          }

        }
        else if(token->str[0]=='$' || isdigit(token->str[0])){
          counterhash++;
          value = token -> value;
          valueCount = valueCheck(token);
          tokenValue = token;
        }
        else if(strcmp(token->str,"-")==0){
          throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive ($10)");
        }
        else{
          throwException(ERR_INVALID_STM8_OPERAND,token,"only Expected X , Y and value");
        }


        token = (IntegerToken *)getToken(tokenizer);
        if(token->str==NULL){
          throwException(ERR_INVALID_STM8_OPERAND,token,"Expected , or ) ");
        }
        else if(strcmp(token->str,",")==0){
          if(operandCount == 0){
            operand = comparingLastOperand(flags,initToken,tokenizer,value,valueCount,squareCount);
          }
          else{
              throwException(ERR_INVALID_STM8_OPERAND,token,"Expected only X and Y after commar and value before commar eg:(88,X)");
          }

        }
        else if(strcmp(token->str,")")==0){
          if(operandCount ==1){
            flagToken = extendTokenStr(initToken ,token);
            operandFlagCheck(flags,flagToken,BRACKETED_X_OPERAND);
            operand = createOperand(BRACKETED_X_OPERAND,NA,NA,NA,NA,NA);
          }

          else if(operandCount ==2 ){
            flagToken = extendTokenStr(initToken ,token);
            operandFlagCheck(flags,flagToken,BRACKETED_Y_OPERAND);
            operand = createOperand(BRACKETED_Y_OPERAND,NA,NA,NA,NA,NA);
          }

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
        IntegerToken *initToken;
        int lsCount = 0;
        int msCount = 0;
        uint16_t valueLs ;
        uint16_t valueMs ;

          token =(IntegerToken*)getToken(tokenizer);
          nullCheck(ERR_SRC_NULL,token,"The must include the source eg (X)");
          initToken = token;
          if(isalpha(token->str[0])){
            pushBackToken(tokenizer, (Token*)token);
            operand = operandHandleFirstSymbol(tokenizer, flags);
          }
          else if(strcmp(token->str,"[")==0){
            pushBackToken(tokenizer, (Token*)token);
            operand = operandHandleSquareBracket(tokenizer,flags);
          }
          else if(strcmp(token->str,"#")==0){
                freeToken(token);
                token = (IntegerToken *)getToken(tokenizer);
                int valueCount = valueCheck(token);
                if(valueCount == 1){
                  operandFlagCheck(flags,initToken,BYTE_OPERAND);
                  operand = createOperand(BYTE_OPERAND,NA,NA,token->value,NA,NA);
                }
                else if(valueCount == 2){
                  operandFlagCheck(flags,initToken,WORD_OPERAND);
                  operand = createMsOperand(WORD_OPERAND,token->value,token);
                }
                else{
                  throwException(ERR_INTEGER_HASH_TOO_LARGE,token,"Expected only value lesser than 256 (#12)");
                }
          }

          else if(token->str[0]=='$' || isdigit(token->str[0])){
            int valueCount = valueCheck(token);

            if(valueCount ==1){
                  operandFlagCheck(flags,token,SHORT_MEM_OPERAND);
                  operand = createLsOperand(SHORT_MEM_OPERAND,token->value,token);
            }
            else if(valueCount ==2){
                  operandFlagCheck(flags,token,LONG_MEM_OPERAND);
                  operand = createMsOperand(LONG_MEM_OPERAND,token->value,token);
              }
            freeToken(token);
            }

          else if(token->str[0]=='('){
              pushBackToken(tokenizer, (Token*)token);
              operand = operandHandleRoundBracket(tokenizer,flags);
          }

          else{
                //need to change
          throwException(ERR_INVALID_OPERAND,token,"Expected only X , Y , A , SP , ( ,# , $ ");
          }

        return operand;
      }
