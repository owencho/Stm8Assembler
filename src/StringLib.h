#ifndef _STRINGLIB_H
#define _STRINGLIB_H


int stringCompare(char *str1 , char *str2);
char *skipWhiteSpaces(char *str);
char *skipNonWhiteSpaces(char *str);
char*skipIfAlphaNumberics(char *str);
int convertStringToInteger(char **strPtr);
int isWordInString(char *str1 , char *str2);
char*skipIfNotAlphaNumberics(char *str);
#endif // _STRINGLIB_H
