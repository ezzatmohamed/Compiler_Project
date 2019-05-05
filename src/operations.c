#include "operations.h"




bool operation(char*x,char*y,char*xType,char*yType,char* val,char*type,char *op)
{
    printf("Operator : %s ,%s ,%s ,%s , %s ,%s , %s\n",x,y,xType,yType,val,type,op);
    if(strcmp(xType,yType) != 0)
    {
        printf("Error : type mismatch ! \n");
        return false;
    }

    char result[20];

    if( strcmp("int",xType)==0)
    {

        printf("Operator : %s ,%s ,%s ,%s , %s ,%s , %s\n",x,y,xType,yType,val,type,op);
        int op1 = atoi(x);
        int op2 = atoi(y);

        printf("Operator : %s ,%s ,%s ,%s , %s ,%s , %s    ,%d , %d\n",x,y,xType,yType,val,type,op,op1,op2);
        int result;
        if(IntOper(op1,op2,&result,op))
        {

            strcpy(type,"int");
            sprintf(val, "%d", result);

            return true;
        }
        printf("Error: none int .\n");
        return false;
    }
    else if ( strcmp("float",xType) == 0)
    {
        float op1 = atof(x);
        float op2 = atof(y);
        float result;
        if(FloatOper(op1,op2,&result,op))
        {
            strcpy(type,"float");
            snprintf(val, sizeof val, "%f", result);
            return true;
        }
        return false;
    }
    else if ( strcmp("str",xType) == 0)
    {
        printf("Error: Can't perform this operation on strings.\n");
    }
    printf("Error: none.\n");
    return false;

}
bool IntOper(int x, int y,int *result, char *op)
{

    if( strcmp("PLUS",op)  == 0 )
        *result = x+y;
    else if( strcmp("MINUS",op) == 0)
        *result = x-y;
    else if( strcmp("MULTIPLY",op) == 0)
        *result = x*y;

    else if (strcmp("DIVIDE",op) == 0)
        *result = x/y;
    else if( strcmp("MODULUS",op) == 0)
        *result = x % y;
    else if( strcmp("AND",op) == 0)
        *result = x & y;
    else if( strcmp("OR",op) == 0)
        *result = x | y;
    else if( strcmp("NOT",op) == 0)
        *result = !x;
    else
    {
        printf("Error : can't perform this operation on int. \n");
        return false;
    }

    return true;
}

bool FloatOper(float x, float y,float *result, char *op)
{
    
    if( strcmp("PLUS",op)  == 0 )
        (*result) = x+y;
    else if( strcmp("MINUS",op) == 0)
        *result = x-y;
    else if( strcmp("MULTIPLY",op) == 0)
        *result = x*y;
    else if (strcmp("DIVIDE",op) == 0)
        *result = x/y;
    else if( strcmp("NOT",op) == 0)
        *result = !x;
    else
    {
        printf("Error : can't perform this operation on float. \n");
        return false ;
    }
    
    return true;
}
/*
struct ExpInfo boolOperation(struct ExpInfo x, struct ExpInfo y,char *op)
{
    struct ExpInfo res;
    strcpy(res.type,"NULL");
    strcpy(res.val,"NULL");
    
    
    char result;
    
    if(strcmp(x.type,y.type) != 0)
    {
        printf("Error : type mismatch ! \n");
        return res;
    }
    
    else if( strcmp(op,"==") == 0 )
    {
        sprintf(res.val, "%d", !strcmp(x.val,y.val));
    }
    else if( strcmp(op,"!=") == 0 )
    {
        sprintf(res.val, "%d", strcmp(x.val,y.val));
    }
    else
    {
        if()
        {}
        else if(){}
        else if(){}
    }
    
    if( strcmp(op,"and") == 0)
    {
        
    }
    else if( strcmp(op,"or") == 0 )
    {

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
    
    strcpy(res.val,"int");
    return res;

}*/