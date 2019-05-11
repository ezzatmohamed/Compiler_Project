#include "operations.h"

bool operation(char*x,char*y,char*xType,char*yType,char* val,char*type,char *op,int yylineno)
{
    printf("Operator : %s ,%s ,%s ,%s , %s ,%s , %s\n",x,y,xType,yType,val,type,op);
    
    if( strcmp("Cint",xType) == 0)
        strcpy(xType,"int");
    else if( strcmp("Cfloat",xType) == 0)
        strcpy(xType,"float");
    
    if( strcmp("Cint",yType) == 0)
        strcpy(yType,"int");
    else if( strcmp("Cfloat",yType) == 0)
        strcpy(yType,"float");


    if(strcmp(xType,yType) != 0)
    {
        fprintf(ErrorFile,"Error at line %d : type mismatch ! \n",yylineno);
        return false;
    }

    char result[100];

    if( strcmp("int",xType)==0  )
    {

        printf("Operator : %s ,%s ,%s ,%s , %s ,%s , %s\n",x,y,xType,yType,val,type,op);
        int op1 = atoi(x);
        int op2 = atoi(y);

        printf("Operator : %s ,%s ,%s ,%s , %s ,%s , %s    ,%d , %d\n",x,y,xType,yType,val,type,op,op1,op2);
        int result;
        if(IntOper(op1,op2,&result,op,yylineno))
        {

            strcpy(type,"int");
            sprintf(val, "%d", result);

            return true;
        }
        fprintf(ErrorFile,"Error at line %d : none int .\n",yylineno);
        return false;
    }
    else if ( strcmp("float",xType) == 0)
    {
        float op1 = atof(x);
        float op2 = atof(y);
        float result;
        if(FloatOper(op1,op2,&result,op,yylineno))
        {
            strcpy(type,"float");
            snprintf(val, sizeof val, "%f", result);
            return true;
        }
        return false;
    }
    fprintf(ErrorFile,"Error at line %d : Can't perform this operation. \n",yylineno);
    return false;

}
bool IntOper(int x, int y,int *result, char *op,int yylineno)
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
        fprintf(ErrorFile,"Error at line %d : can't perform this operation on int. \n",yylineno);
        return false;
    }

    return true;
}

bool FloatOper(float x, float y,float *result, char *op,int yylineno)
{
    
    if( strcmp("PLUS",op)  == 0 )
        (*result) = x+y;
    else if( strcmp("MINUS",op) == 0)
        *result = x-y;
    else if( strcmp("MULTIPLY",op) == 0)
        *result = x*y;
    else if (strcmp("DIVIDE",op) == 0)
        *result = x/y;
    else
    {
        fprintf(ErrorFile,"Error at line %d : can't perform this operation on float. \n",yylineno);
        return false ;
    }
    
    return true;
}