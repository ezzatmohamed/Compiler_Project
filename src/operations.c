#include "operations.h"




struct ExpInfo operation(struct ExpInfo x, struct ExpInfo y,char *op)
{
    
    struct ExpInfo res;
    strcpy(res.type,"NULL");
    strcpy(res.val,"NULL");
    if(strcmp(x.type,y.type) != 0)
    {
        printf("Error : type mismatch ! \n");
        return res;
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


    
    return res;

}
struct ExpInfo  IntOper(int x, int y, char *op)
{
    struct ExpInfo res;
    strcpy(res.type,"NULL");
    strcpy(res.val,"NULL");


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
        return res;
    }

    sprintf(res.val, "%d", result);

    strcpy(res.type,"int");
    return res;
}

struct ExpInfo FloatOper(float x, float y, char *op)
{
    struct ExpInfo res;
    strcpy(res.type,"NULL");
    strcpy(res.val,"NULL");

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
        return res;
    }

    
    snprintf(res.val, sizeof res.val, "%f", result);
    strcpy(res.type,"float");

    return res;
}

struct ExpInfo boolOperation(struct ExpInfo x, struct ExpInfo y,char *op)
{
    struct ExpInfo res;
    strcpy(res.type,"NULL");
    strcpy(res.val,"NULL");

    if(strcmp(x.type,y.type) != 0)
    {
        printf("Error : type mismatch ! \n");
        return res;
    }
    char result;

    if( strcmp(op,"and") == 0)
    {

    }
    else if( strcmp(op,"or") == 0 )
    {

    }
    else if( strcmp(op,"==") == 0 )
    {
        sprintf(res.val, "%d", !strcmp(x.val,y.val));
    }
    else if( strcmp(op,"!=") == 0 )
    {
        sprintf(res.val, "%d", strcmp(x.val,y.val));
    }
    else if( strcmp(op,"<") == 0)
    {

    }
    else if( strcmp(op,">") == 0 )
    {

    }
    else if( strcmp(op,"<=") == 0 )
    {

    }
    else if( strcmp(op,">=") == 0 )
    {

    }
    
    return res;



}