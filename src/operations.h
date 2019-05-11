#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// atof() chars to float
// atoi() chars to int

// float to string :  snprintf(str, sizeof str, "%f", myFloat);
// int to string   :  sprintf(str, "%d", i);

bool  operation(char*x,char*y,char*xType,char*yType,char* val,char*type,char *op,int yylineno);
bool  IntOper(int x, int y,int *result, char *op,int yylineno);
bool  FloatOper(float x, float y,float *result, char *op,int yylineno);

//struct ExpInfo boolOperation(struct ExpInfo x, struct ExpInfo y,char *op);


