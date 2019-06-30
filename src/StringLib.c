#include "StringLib.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int isWordInString(char *str1, char *str2){
	int counter = 0;
	int j =0;
	for(int i=0; i<strlen(str2); i++) {
		if(toupper(str1[j])==toupper(str2[i])) {
			if(toupper(str1[j+1])==toupper(str2[i+1])||toupper(str2[i+1])==' '||toupper(str2[i+1])=='=' ) {
				counter++;
				j++;
			}
		}
	}

	if((counter) == strlen(str1))
	return 1;
	else
	return 0;
}


int stringCompare(char *str1, char *str2){

	if(str1 == NULL || str2== NULL) {
		if(str1 == str2)
		return 0;
		if(str1==NULL && str2 > 0)
		return -1;
		if(str1 > 0 && str2 == NULL)
		return 1;
	}
	if(strcmp(str1,str2)==0)
	return 0;
	if(strcmp(str1,str2)>=0)
	return 1;
	if(strcmp(str1,str2)<=0)
	return -1;
}


/*char *skipWhiteSpaces(char *str){
	for(int i=0; i< strlen(str); i++) {
		if(isspace(str[i-1])&&isalnum(str[i])) {
			return &str[i];

		}
	}
	return str;
}

char *skipNonWhiteSpaces(char *str){
	for(int i=0; i< strlen(str); i++) {
		if(isspace(str[i])) {
			return &str[i];

		}
	}
	return str;
}
*/

char*skipIfAlphaNumberics(char *str){
	for(int i=0; i< strlen(str); i++) {
		if(!isalnum(str[i])) {
			return &str[i];
		}
	}
	return str;
}

char*skipIfNotAlphaNumberics(char *str){
	for(int i=0; i< strlen(str); i++) {
		if(isalnum(str[i])) {
			return &str[i];
		}
	}
	return str;
}


int convertStringToInteger(char **strPtr){
	int out = strtol(*strPtr, strPtr, 10);
	return out;
}
