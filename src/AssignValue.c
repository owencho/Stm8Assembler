#include "AssignValue.h"
#include "StringLib.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void assignValue(NameValueMap map[], char *str){
  int i =0;
  char* ptr;
  int new = 0;
  str = skipWhiteSpaces(str);

  while(map[i].name != NULL) {
    int wordExist = isWordInString(map[i].name,str);
    if(wordExist) {
      ptr = equalValueFind(map[i].name,str);
      if(isEqualSign(ptr)) {
        ptr = skipIfNotAlphaNumberics(ptr);
        int new = convertStringToInteger(&ptr);
        *map[i].value = new;

      }
    }
    i++;
  }
}



int isEqualSign(char *ptr){
  for (int i = 0; i<strlen(ptr); i++) {
    if(ptr[i] == '=') {
      return 1;
    }
  }
  return 0;
}

char* equalValueFind(char* insert,char *ptr){
  while(insert != NULL) {
    int wordInString =isWordInString(insert,ptr);
    if (wordInString) {
      if(isspace(ptr[0]) && ptr[1]==',')
      ptr = skipIfNotAlphaNumberics(ptr);
      else if (isalnum(ptr[0]))
      ptr = skipNonWhiteSpaces(ptr);
      else
      ptr = skipWhiteSpaces(ptr);
    }
    else
    return ptr;

  }
}
