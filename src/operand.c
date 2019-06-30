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

stm8Operand *getOperand(Tokenizer *tokenizer){
  stm8Operand *value;
  char * strToken = tokenizer-> str;
  strToken = skipWhiteSpaces(strToken);
  int squareBracket = squareBracketCheck(strToken);
  int roundBracket = roundBracketCheck(strToken);
  char* lengthMem = skipIfNotAlphaNumberics(strToken);

  if(isWordInString(strToken," A ")){
    value->type = A_OPERAND;
    return value;
  }
  else{
    if(squareBracket){
      int numlength =0;
      while(lengthMem[numlength] != '.' && lengthMem[numlength +1] != 'w'){
        numlength++;
      }
      if(numlength == 4){
        //getInt square bracket ms ls
        value->type = BRACKETED_LONGPTR_DOT_W_OPERAND;
        value->dataSize.extCode = 92;
        return value;
      }
      if(numlength ==2){
        value->type = BRACKETED_SHORTPTR_DOT_W_OPERAND;
        value->dataSize.ls = convertStringToInteger(&lengthMem);
        value->dataSize.extCode = 72;
        return value;
      }
    }
    else if(roundBracket){
      int numlength =0;
      if(squareBracket){
        int numlength = 0;
        while(lengthMem[numlength] != '.' && lengthMem[numlength +1] != 'w'){
          numlength++;
        }
        if(numlength == 4){

          //getInt round +squareBracket got ms ls
        }
        if(numlength ==2){
          value->dataSize.ls = convertStringToInteger(&lengthMem);
        }
        int i=0;
        int j=0;
        while(lengthMem[j-1]!=','&&lengthMem[j+1]!=')'){
          if(lengthMem[j]=='X' && numlength == 4){
            value->type = LONGPTR_DOT_W_BRACKETEDX_OPERAND;
            value->dataSize.extCode = 72;
            return value;
          }

          if(lengthMem[j]=='X' && numlength == 2){
            value->type = SHORTPTR_DOT_W_BRACKETEDX_OPERAND;
            value->dataSize.extCode = 92;
            return value;
          }

          if(lengthMem[j]=='Y' && numlength == 2){
            value->type =   SHORTPTR_DOT_W_BRACKETEDY_OPERAND;
            value->dataSize.extCode = 91;
            return value;
          }
          j++;
        }
      }
      else{
        if(isdigit(lengthMem[0])){
          int numlength = 0;
          while(lengthMem[numlength] != ','){
            numlength++;
          }
          if(numlength == 4){

            //getInt round +squareBracket got ms ls
          }
          if(numlength ==2){
            value->dataSize.ls = convertStringToInteger(&lengthMem);
          }
          int i=0;
          int j=0;
          while((lengthMem[j-1]!=','&&lengthMem[j+1]!=')') || (lengthMem[j]!='S'&&lengthMem[j+1]!='P')){
            if(numlength == 4){
              if(lengthMem[j]='X'){
                value->type = LONGOFF_X_OPERAND;
                return value;
              }
              if(lengthMem[j]='Y'){
                value->type = LONGOFF_Y_OPERAND;
                value->dataSize.extCode = 90;
                return value;
              }
            }
            if(numlength == 2){
              if(lengthMem[j]='X'){
                value->type = SHORTOFF_X_OPERAND;
                return value;
              }
              if(lengthMem[j]='Y'){
                value->type = SHORTOFF_Y_OPERAND;
                value->dataSize.extCode = 90;
                return value;
              }
              if(lengthMem[j]=='S'&&lengthMem[j+1]=='P')  {
                value->type = SHORTOFF_SP_OPERAND;
                value->dataSize.extCode = 90;
                return value;
              }

            }
            j++;
          }
        }
        else{
          int j=0;
          while(lengthMem[j]!='\0'){
            if(strToken[j]=='(' && strToken[j+2]==')'){
              if(lengthMem[j+1]=='X'){
                value->type = BRACKETED_X_OPERAND;
                return value;
                break;
              }
              if(lengthMem[j+1]=='Y'){
                value->type = BRACKETED_Y_OPERAND;
                return value;
                break;
              }
            }
            j++;
          }
        }

      }
    }
    else{
      int num;
      while(lengthMem[num] != ' '){
        num++;
      }
      if(num== 4){
        //getInt normal got ms ls
      }
      if(num== 2){
        value ->type = BYTE_OPERAND;
        value->dataSize.ls = convertStringToInteger(&lengthMem);
      }
    }
  }
}








int squareBracketCheck(char * str){
  int i=0;
  int count =0;
  while (str[i] != '\0'){
    if (str[i] == ']')
    count=count-3;
    if (str[i] == '[')
    count=count +2;
    if (count == 0)
    {
      return 0;
    }
    i++;
  }
  if (count == -1)
  return 1;
}


int roundBracketCheck(char * str){
  int i=0;
  int count =0;
  while (str[i] != '\0'){
    if (str[i] == ')')
    count=count-3;
    if (str[i] == '(')
    count=count +2;
    if (count == 0)
    {
      return 0;
    }
    i++;
  }
  if (count == -1)
  return 1;
}
