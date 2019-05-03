#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ExpInfo {
	    char type[10];
		char *val[20];
};

// atof() chars to float
// atoi() chars to int

// float to string :  snprintf(str, sizeof str, "%f", myFloat);
// int to string   :  sprintf(str, "%d", i);

char *operation(struct ExpInfo x, struct ExpInfo y,char *op);
char *IntOper(int x, int y, char *op);
char *FloatOper(float x, float y, char *op);

char *boolOperation();


