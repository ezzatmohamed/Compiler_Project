#include "operations.h"




char *operation(struct ExpInfo x, struct ExpInfo y,char *op)
{
    struct ExpInfo res;
    strcpy(res.type,NULL);
    strcpy(res.val,NULL);
    
    if(strcmp(x.type,y.type) != 0)
    {
        printf("Error : type mismatch ! \n");
        return NULL;
    }

    char result[20];

    if( strcmp("int",x.type))
    {
        int op1 = atoi(x.val);
        int op2 = atoi(y.val);
        return IntOper(op1,op2,op);
    }
    else if ( strcmp("float",x.type) == 0)
    {
        float op1 = atof(x.val);
        float op2 = atof(y.val);
        return FloatOper(op1,op2,op);
    }
    else if ( strcmp("str",x.type) == 0)
    {
        printf("Error: Can't perform this operation on strings.\n");
    }
    return NULL;

}
char *IntOper(int x, int y, char *op)
{
    int result;
    if( strcmp("+",op)  == 0 )
        result = x+y;
    else if( strcmp("-",op) == 0)
        result = x-y;
    else if( strcmp("*",op) == 0)
        result = x*y;

    else if (strcmp("/",op) == 0)
        result = x/y;
    else if( strcmp("%",op) == 0)
        result = x % y;
    else if( strcmp("&",op) == 0)
        result = x & y;
    else if( strcmp("|",op) == 0)
        result = x | y;
    else if( strcmp("not",op) == 0)
        result = !x;
    else
    {
        printf("Error : can't perform this operation on int. \n");
        return NULL;
    }

    char str[20];
    sprintf(str, "%d", result);

    return str;
}

char *FloatOper(float x, float y, char *op)
{
    float result;
    if( strcmp("+",op)  == 0 )
        result = x+y;
    else if( strcmp("-",op) == 0)
        result = x-y;
    else if( strcmp("*",op) == 0)
        result = x*y;

    else if (strcmp("/",op) == 0)
        result = x/y;
    else if( strcmp("not",op) == 0)
        result = !x;
    else
    {
        printf("Error : can't perform this operation on float. \n");
        return NULL;
    }

    char str[20];
    snprintf(str, sizeof str, "%f", result);

    return str;
}

char *boolOperation(struct ExpInfo x, struct ExpInfo y,char *op)
{
    if(strcmp(x.type,y.type) != 0)
    {
        printf("Error : type mismatch ! \n");
        return NULL;
    }
    char result;

    

    char result[20];
}