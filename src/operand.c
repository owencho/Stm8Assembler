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

int signedIntCheck(Tokenizer *tokenizer){
    int value;
    IntegerToken *token;
    IntegerToken *initToken;
    IntegerToken *flagToken;
    token = (IntegerToken *)getToken(tokenizer);
    initToken = token;
    if(token->str[0]=='-'){
        token = (IntegerToken *)getToken(tokenizer);
        if(token->str[0]!='$' && ispunct(token->str[0])){
          flagToken = extendTokenStr(initToken ,token);
          throwException(ERR_INVALID_SYNTAX,flagToken,"Invalid SYNTAX only expect eg -$AA");
        }
        else if(token->value >= 0 && token->value <= 127){
            if(token->value == 0)
              value =0;
            else
              value = 256-token->value;
        }
        else if(token->value > 127){
          throwException(ERR_INTEGER_TOO_LARGE,token,"The range only can be from -128 => x <= 127");
        }
        else{
          throwException(ERR_INTEGER_TOO_SMALL,token,"The range only can be from -128 => x <= 127");
        }
    }
    else if(token->value <= 127 && token->value >= 0){
      value = token->value;
    }
    else if(token->value > 127){
      throwException(ERR_INTEGER_TOO_LARGE,token,"The range only can be from -128 => x <= 127");
    }
    else{
      throwException(ERR_INTEGER_TOO_SMALL,token,"The range only can be from -128 => x <= 127");
    }
    return value;
}

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

void operandFlagCheck(uint64_t flags, IntegerToken* token ,stm8OperandType type  ){
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
        throwException(ERR_INVALID_SYNTAX,token,"Expected only X ,Y , A and SP");
    else if (condition ==1 )
        throwException(ERR_INVALID_SYNTAX,token,"Expected only X ,Y , and SP");
    else if (condition == 0)
        throwException(ERR_INVALID_SYNTAX,token,"Expected only X and Y ");
    else
        throwException(ERR_INVALID_SYNTAX,token,"Invalid input ");
}

int valueCheck(IntegerToken* token){
    nullCheck(ERR_INTEGER_NULL,token,"The integer number cannot be NULL");
    if(token->str[0]=='$'){
        if(token->str[1]!='-' && !isalnum(token->str[1])){
            throwException(ERR_INVALID_SYNTAX,token,"Expected only numbers ($10)");
        }
        else if(token->value <256 && token->value >= 0 ){
            return 1;
        }
        else if (token->value >=256  && token->value < 65536){
            return 2;
        }
        else if (token->value >= 65536  && token->value <= 16777215){
            return 3;
        }
        else if (token-> value <0){
            throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive eg ($10)");
        }
        else if (token-> value >65536){
            throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must smaller than 65536 eg ($1000)");
        }
  }
  else if((token->str[0]=='-') || isdigit(token->str[0])){
      if(strcmp(token->str,"-")==0){
          return 4;
      }
      else if(token->value <=255 && token->value >=0 ){
          return 1;
      }
      else if (token->value >=256  && token->value < 65536){
          return 2;
      }
      else if (token->value >= 65536  && token->value <= 16777215){
          return 3;
      }
      else if (token-> value <0){
          throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be positive eg ($10)");
      }
      else if (token-> value >65536){
          throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must smaller than 65536 eg ($1000)");
      }
  }
  else{
      throwException(ERR_INVALID_SYNTAX,token,"Expected only numbers ($10)");
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
    if(value <256 && value >= 0){
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
    if(value <65536){
        uint16_t valueLs = value & 0xff;  // low
        uint16_t valueMs = value >> 8;    // high
        operand = createOperand(type,NA,NA,valueMs,valueLs,NA);
    }
    else if (value >= 65536){
        throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must be smaller than 65536 ($1000)");
    }
    else if(value < 0){
        throwException(ERR_INTEGER_NEGATIVE,token,"The integer number must be larger than 0 (non zero)");
    }
    return operand;
}

stm8Operand *createExtMemOperand( stm8OperandType type,
                                  int value,
                                  IntegerToken *token){

    stm8Operand *operand =malloc(sizeof(stm8Operand));
    if(value <=16777215 ){
          uint16_t valueLs = value & 0xff;  // low
          uint16_t valueMs = (value & 0xffff)>> 8;    // high
          uint16_t valueExtMem = value >> 16;  // ext
          operand = createOperand(type,NA,NA,valueExtMem,valueMs,valueLs);
    }
    else if(value > 16777215){
          throwException(ERR_INTEGER_TOO_LARGE,token,"The integer number must be smaller than 65536 ($1000)");
    }
    return operand;
}

stm8Operand *operandHandleFirstSymbol(Tokenizer* tokenizer ,uint64_t flags){
    stm8Operand *operand =malloc(sizeof(stm8Operand));
    IntegerToken* token = (IntegerToken *)getToken(tokenizer);
    IntegerToken *valueToken = token ;
    IntegerToken* flagToken;
    stm8OperandType operandType;
    token = (IntegerToken *)getToken(tokenizer);
      if(strcasecmp(valueToken->str,"A")==0)
          operandType = A_OPERAND;
      else if(strcasecmp(valueToken->str,"XL")==0){
          operandType = XL_OPERAND;
      }
      else if(strcasecmp(valueToken->str,"YL")==0){
          operandType = YL_OPERAND;
      }
      else if(strcasecmp(valueToken->str,"X")==0){
          operandType = X_OPERAND;
      }
      else if(strcasecmp(valueToken->str,"Y")==0){
          operandType = Y_OPERAND;
      }
      else if(strcasecmp(valueToken->str,"SP")==0){
          operandType = SP_OPERAND;
      }
      else if(strcasecmp(valueToken->str,"YH")==0){
          operandType = YH_OPERAND;
      }
      else if(strcasecmp(valueToken->str,"XH")==0){
          operandType = XH_OPERAND;
      }
      else if(strcasecmp(valueToken->str,"CC")==0){
          operandType = CC_OPERAND;
      }
      else{
        throwException(ERR_INVALID_SYNTAX,valueToken,"Invalid Operand");
      }
    if(token->str == NULL){
      flagToken = extendTokenStr(valueToken ,token);
      operandFlagCheck(flags,flagToken,operandType);
      operand = createOperand(operandType,NA,NA,NA,NA,NA);
    }
    else{
      throwException(ERR_INVALID_SYNTAX,token,"Expected nothing after that ");
    }
    return operand;
}

stm8Operand *comparingLastOperand(uint64_t flags,IntegerToken* tokenValue,Tokenizer* tokenizer , int value, int valueCount , int squarecount){
    int operandCounter =0;
    stm8Operand *operand =malloc(sizeof(stm8Operand));
    IntegerToken* token = (IntegerToken *)getToken(tokenizer);
    IntegerToken* flagToken;
    operandCounter = operandCheck(token,1);
    token = (IntegerToken *)getToken(tokenizer);
    nullCheck(ERR_INVALID_SYNTAX,token,"Expected )");
    if(strcmp(token->str,")")==0){
         if(squarecount==1){
             if(operandCounter==1){
                 if(valueCount==1 && isOperandNeeded(flags,SHORTPTR_DOT_W_BRACKETEDX_OPERAND)){
                      flagToken = extendTokenStr(tokenValue ,token);
                      operandFlagCheck(flags,tokenValue,SHORTPTR_DOT_W_BRACKETEDX_OPERAND);
                      operand = createLsOperand(SHORTPTR_DOT_W_BRACKETEDX_OPERAND,value,token);
                 }
                 else if (valueCount==2 || (valueCount ==1 && isOperandNeeded(flags,LONGPTR_DOT_W_BRACKETEDX_OPERAND))){
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
                    throwException(ERR_INVALID_SYNTAX,tokenValue,"Expected only value less than 65536 and larger than 0");
               }
            }
        }
        else if(squarecount==2){
            if(operandCounter==1){
                if (valueCount==2 || (valueCount ==1 && isOperandNeeded(flags,LONGPTR_DOT_E_BRACKETEDX_OPERAND))){
                    flagToken = extendTokenStr(tokenValue ,token);
                    operandFlagCheck(flags,flagToken,LONGPTR_DOT_E_BRACKETEDX_OPERAND);
                    operand = createMsOperand(LONGPTR_DOT_E_BRACKETEDX_OPERAND,value,token);
                }
                else{
                    throwException(ERR_INVALID_SYNTAX,tokenValue,"Expected only value larger than 0");
                }
            }
            else if(operandCounter==2){
                if (valueCount==2 || (valueCount ==1 && isOperandNeeded(flags,LONGPTR_DOT_E_BRACKETEDY_OPERAND))){
                    flagToken = extendTokenStr(tokenValue ,token);
                    operandFlagCheck(flags,flagToken,LONGPTR_DOT_E_BRACKETEDY_OPERAND);
                    operand = createMsOperand(LONGPTR_DOT_E_BRACKETEDY_OPERAND,value,token);
                }
                else{
                    throwException(ERR_INVALID_SYNTAX,tokenValue,"Expected only value larger than 0");
                }
            }
        }
        else if(operandCounter==1){
            if(valueCount==1 && isOperandNeeded(flags,SHORTOFF_X_OPERAND)){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,SHORTOFF_X_OPERAND);
                  if(value == 0)
                      operand = createOperand(BRACKETED_X_OPERAND,NA,NA,NA,NA,NA);
                  else
                      operand = createLsOperand(SHORTOFF_X_OPERAND,value,token);
            }
            else if ((valueCount==2 || valueCount ==1) && isOperandNeeded(flags,LONGOFF_X_OPERAND)){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,LONGOFF_X_OPERAND);
                  if(value == 0)
                      operand = createOperand(BRACKETED_X_OPERAND,NA,NA,NA,NA,NA);
                  else
                      operand = createMsOperand(LONGOFF_X_OPERAND,value,token);
            }
            else if (valueCount==3||((valueCount==1 ||valueCount==2) && isOperandNeeded(flags,EXTOFF_X_OPERAND))){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,EXTOFF_X_OPERAND);
                  operand = createExtMemOperand(EXTOFF_X_OPERAND,value,token);
            }
            else if ((valueCount ==1 && !isOperandNeeded(flags,SHORTOFF_X_OPERAND))&& !isOperandNeeded(flags,LONGOFF_X_OPERAND )){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,SHORTOFF_X_OPERAND);
            }
            else{
                  throwException(ERR_INVALID_SYNTAX,tokenValue,"Expected only value larger than 0");
            }
          }
        else if(operandCounter==2){
            if(valueCount==1 && isOperandNeeded(flags,SHORTOFF_Y_OPERAND)){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,SHORTOFF_Y_OPERAND);
                  if(value == 0)
                      operand = createOperand(BRACKETED_Y_OPERAND,NA,NA,NA,NA,NA);
                  else
                      operand = createLsOperand(SHORTOFF_Y_OPERAND,value,token);
            }
            else if ((valueCount==2 || valueCount ==1) && isOperandNeeded(flags,LONGOFF_Y_OPERAND)){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,LONGOFF_Y_OPERAND);
                  if(value == 0)
                      operand = createOperand(BRACKETED_Y_OPERAND,NA,NA,NA,NA,NA);
                  else
                      operand = createMsOperand(LONGOFF_Y_OPERAND,value,token);
            }
            else if (valueCount==3||((valueCount==1 ||valueCount==2) && isOperandNeeded(flags,EXTOFF_Y_OPERAND))){
                  flagToken = extendTokenStr(tokenValue ,token);
                  operandFlagCheck(flags,flagToken,EXTOFF_Y_OPERAND);
                  operand = createExtMemOperand(EXTOFF_Y_OPERAND,value,token);
            }
            else if ((valueCount ==1 && !isOperandNeeded(flags,SHORTOFF_Y_OPERAND))&& !isOperandNeeded(flags,LONGOFF_Y_OPERAND )){
                flagToken = extendTokenStr(tokenValue ,token);
                operandFlagCheck(flags,flagToken,SHORTOFF_Y_OPERAND);
            }
            else{
                throwException(ERR_INVALID_SYNTAX,tokenValue,"Expected only value larger than 0");
            }
        }
        else if(operandCounter==3){
            if(valueCount==1){
                flagToken = extendTokenStr(tokenValue ,token);
                operandFlagCheck(flags,flagToken,SHORTOFF_SP_OPERAND);
                operand = createLsOperand(SHORTOFF_SP_OPERAND,value,token);
            }
            else{
              throwException(ERR_INVALID_SYNTAX,tokenValue,"Expected only value less than 256 and larger than 0 on SP");
            }
        }
    }
    else{
      throwException(ERR_INVALID_SYNTAX,token,"Expected ')'");
    }
return operand;
}

stm8Operand *operandHandleSquareBracket( Tokenizer *tokenizer ,uint64_t flags){
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
    nullCheck(ERR_INVALID_SYNTAX,token,"Expected [ ");
    if(strcmp(token->str,"[")==0){
        initToken = token;
        token = (IntegerToken *)getToken(tokenizer);
        if(token->str[0]=='$' || isdigit(token->str[0])){
            value = token -> value;
            valueCount = valueCheck(token);
            valueBracToken = token;
        }
        else{
            throwException(ERR_INVALID_SYNTAX,token,"Expected only value eg [$77.w]");
        }
        freeToken(token);
        token = (IntegerToken *)getToken(tokenizer);
        nullCheck(ERR_INVALID_SYNTAX,token,"Expected . after value");
        if(strcmp(token->str,".")==0){
            freeToken(token);
            token = (IntegerToken *)getToken(tokenizer);
            nullCheck(ERR_INVALID_SYNTAX,token,"Expected w after .");
            if(strcasecmp(token->str,"W")==0){
                freeToken(token);
                token = (IntegerToken *)getToken(tokenizer);
                nullCheck(ERR_INVALID_SYNTAX,token,"Expected ] closing squarebracket");
                if(strcmp(token->str,"]")==0){
                    if(valueCount==1 && isOperandNeeded(flags,BRACKETED_SHORTPTR_DOT_W_OPERAND) ){
                        flagToken = extendTokenStr(initToken ,token);
                        operandFlagCheck(flags,flagToken,BRACKETED_SHORTPTR_DOT_W_OPERAND);
                        operand = createLsOperand(BRACKETED_SHORTPTR_DOT_W_OPERAND,value,token);
                    }
                    else if (valueCount==2 || (valueCount ==1 && isOperandNeeded(flags,BRACKETED_LONGPTR_DOT_W_OPERAND))){
                        flagToken = extendTokenStr(initToken,token);
                        operandFlagCheck(flags,flagToken,BRACKETED_LONGPTR_DOT_W_OPERAND);
                        operand = createMsOperand(BRACKETED_LONGPTR_DOT_W_OPERAND,value,token);
                    }
                }
                else{
                    throwException(ERR_INVALID_SYNTAX,token,"Expected ] closing squarebracket");
                }
            }
            else if(strcasecmp(token->str,"e")==0){
                freeToken(token);
                token = (IntegerToken *)getToken(tokenizer);
                nullCheck(ERR_INVALID_SYNTAX,token,"Expected ] closing squarebracket");
                if(strcmp(token->str,"]")==0){
                    if(valueCount==2 || (valueCount ==1 && isOperandNeeded(flags,BRACKETED_LONGPTR_DOT_E_OPERAND))){
                      flagToken = extendTokenStr(initToken ,token);
                      operandFlagCheck(flags,flagToken,BRACKETED_LONGPTR_DOT_E_OPERAND);
                      operand = createMsOperand(BRACKETED_LONGPTR_DOT_E_OPERAND,value,token);
                    }
                    else{
                    throwException(ERR_UNSUPPORTED_OPERAND,token,"Expected longptr and shortptr is not supported");
                    }
                }
                else{
                  throwException(ERR_INVALID_SYNTAX,token,"Expected ] closing squarebracket");
                }
            }
            else{
                throwException(ERR_INVALID_SYNTAX,token,"Expected .w or .e");
            }
        }
        else if(strcmp(token->str,"]")==0){
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
            throwException(ERR_INVALID_SYNTAX,token,"Expected . after value");
        }
    return operand;
    }
    else{
        throwException(ERR_INVALID_SYNTAX,token,"Expected [ ");
    }
}

stm8Operand *operandHandleRoundBracket( Tokenizer *tokenizer , uint64_t flags){
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
    nullCheck(ERR_INVALID_SYNTAX,token,"Expected X , Y or value");
    if(isalpha(token->str[0])){
        operandCount=operandCheck(token,0);
    }
    else if(strcmp(token->str,"[")==0){
        pushBackToken(tokenizer,(Token*)token);
        squareOperand = operandHandleSquareBracket(tokenizer,flags);
        if(squareOperand->type == BRACKETED_LONGPTR_DOT_E_OPERAND)
            squareCount=2;
        else
            squareCount =1;
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
        throwException(ERR_INVALID_SYNTAX,token,"only Expected X , Y and value");
    }
    token = (IntegerToken *)getToken(tokenizer);
    if(token->str==NULL){
        throwException(ERR_INVALID_SYNTAX,token,"Expected , or ) ");
    }
    else if(strcmp(token->str,",")==0){
        if(operandCount == 0){ //if first word is not alphabet
            operand = comparingLastOperand(flags,initToken,tokenizer,value,valueCount,squareCount);
        }
        else{
            throwException(ERR_INVALID_SYNTAX,token,"Expected only X and Y after commar and value before commar eg:(88,X)");
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
        throwException(ERR_INVALID_SYNTAX,token,"Expected , and ) ");

    return operand;
}

stm8Operand *getOperand(Tokenizer *tokenizer , uint64_t flags){
    CEXCEPTION_T ex;
    stm8Operand *operand =NULL;
    IntegerToken *token;
    IntegerToken *initToken;
    int lsCount = 0;
    int msCount = 0;
    uint16_t valueLs ;
    uint16_t valueMs ;
    int valueShortMem;
    int valueCount;

      token =(IntegerToken*)getToken(tokenizer);
      nullCheck(ERR_DSTSRC_NULL,token,"The must include the source eg (X)");
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
          token = (IntegerToken *)getToken(tokenizer);
          int valueCount = valueCheck(token);
          if(valueCount == 1 && isOperandNeeded(flags,BYTE_OPERAND)){
              operandFlagCheck(flags,initToken,BYTE_OPERAND);
              operand = createOperand(BYTE_OPERAND,NA,NA,token->value,NA,NA);
          }
          else if(valueCount == 2 || (valueCount == 1 && isOperandNeeded(flags,WORD_OPERAND))){
              operandFlagCheck(flags,initToken,WORD_OPERAND);
              operand = createMsOperand(WORD_OPERAND,token->value,token);
          }
          else if(valueCount == 3)
              throwException(ERR_INVALID_HASH_VALUE,token,"Expected only value less than 65536");
          else if(valueCount == 4)
              throwException(ERR_INVALID_HASH_VALUE,token,"Expected only positive value");
          else{
              operandFlagCheck(flags,initToken,BYTE_OPERAND);
              operandFlagCheck(flags,initToken,WORD_OPERAND);
          }
      }
      else if(token->str[0]=='-'|| token->str[0]=='$' || isdigit(token->str[0])){
          valueCount = valueCheck(token);
          if(valueCount ==1 && isOperandNeeded(flags,SHORT_MEM_OPERAND)){
              operandFlagCheck(flags,token,SHORT_MEM_OPERAND);
              operand = createLsOperand(SHORT_MEM_OPERAND,token->value,token);
          }
          else if(valueCount ==1 && isOperandNeeded(flags,SHORT_OFF_OPERAND)){
              operandFlagCheck(flags,token,SHORT_OFF_OPERAND);
              pushBackToken(tokenizer, (Token*)token);
              valueShortMem = signedIntCheck(tokenizer);
              operand = createLsOperand(SHORT_OFF_OPERAND,valueShortMem,token);
          }
          else if(valueCount ==2 || (valueCount ==1 && isOperandNeeded(flags,LONG_MEM_OPERAND))){
              operandFlagCheck(flags,token,LONG_MEM_OPERAND);
              operand = createMsOperand(LONG_MEM_OPERAND,token->value,token);
            }
          else if (valueCount==3||((valueCount==1 ||valueCount==2) && isOperandNeeded(flags,EXT_MEM_OPERAND))){
                operandFlagCheck(flags,token,EXT_MEM_OPERAND);
                operand = createExtMemOperand(EXT_MEM_OPERAND,token->value,token);
          }
          else if(valueCount ==4){
              operandFlagCheck(flags,token,SHORT_OFF_OPERAND);
              pushBackToken(tokenizer, (Token*)token);
              valueShortMem = signedIntCheck(tokenizer);
              operand = createLsOperand(SHORT_OFF_OPERAND,valueShortMem,token);
          }
          else{
              operandFlagCheck(flags,token,SHORT_MEM_OPERAND);
              operandFlagCheck(flags,token,LONG_MEM_OPERAND);
          }
          freeToken(token);
      }

      else if(token->str[0]=='('){
          pushBackToken(tokenizer, (Token*)token);
          operand = operandHandleRoundBracket(tokenizer,flags);
      }

      else{
          throwException(ERR_INVALID_SYNTAX,token,"Expected only X , Y , A , SP , ( ,# , $ ");
      }
    return operand;
}
