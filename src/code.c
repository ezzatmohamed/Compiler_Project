#include "code.h"


void CaseBegin()
{
    /*
    LoopBegin();
    fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-1],stack[top]) ;      
    fprintf(QuadFile,"JNZ T%d,L%d \n",temp,);
    
    
    temp++; 
*/
}
void IfBegin()
{
    label[++labelTop] = labelEnd; 
    labelEnd++;  
}

void IfEnd()
{
    fprintf(QuadFile,"end%d: \n",label[labelTop]);
    labelTop--;
}
void Else()
{

    fprintf(QuadFile,"JMP end%d\n",labelEnd);

    fprintf(QuadFile,"end%d: \n",label[labelTop]);
    label[labelTop] = labelEnd;

    labelEnd++;
}

void LoopBegin()
{

    label[++labelTop] = labelEnd;

    labelEnd++;
    fprintf(QuadFile,"L%d: \n",label[labelTop]);
}

void LoopEnd()
{
    fprintf(QuadFile,"JMP L%d \n",label[labelTop]);
    fprintf(QuadFile,"end%d: \n",label[labelTop]);
    labelTop--;
}
bool CheckType(char *x,char *y)
{
    if( strcmp("Cint",x) == 0)
        strcpy(x,"int");
    else if( strcmp("Cfloat",x) == 0)
        strcpy(x,"float");
    else if( strcmp("Cstr",x) == 0)
        strcpy(x,"str");
    
    if( strcmp("Cint",y) == 0)
        strcpy(y,"int");
    else if( strcmp("Cfloat",y) == 0)
        strcpy(y,"float");
    else if( strcmp("Cstr",y) == 0)
        strcpy(y,"str");
    



    if(strcmp(x,y) != 0)
    {
        fprintf(QuadFile,"Error : type mismatch ! \n");
        return false;
    }

    return true;
}
void CheckCondition()
{
    
    if( strcmp(stack[top],">") == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JNegZ  T%d,end%d \n",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],">=") == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JNeg T%d,end%d \n",temp,label[labelTop]);
    
    }
    else if( strcmp(stack[top],"<") == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JPosZ T%d,end%d \n",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"<=") == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JPos T%d,end%d \n",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"!=") == 0)
    {   
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JZ T%d,end%d \n",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"==") == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JNZ T%d,end%d \n",temp,label[labelTop]);
    }
    else 
    {
        fprintf(QuadFile,"JZ %s,end%d \n",stack[top],label[labelTop]);
        top++;
    }
    top-=3;
    temp++; 
}

void RepeatCondition()
{
    if( strcmp(stack[top],">")  == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JPos  T%s,end%d \n",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],">=") == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JPosZ T%d,end%d \n",temp,label[labelTop]);
    
    }
    else if( strcmp(stack[top],"<") == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JNeg T%d,end%d \n",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"<=") == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JNegZ T%d,end%d \n",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"!=") == 0)
    {   
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JNZ T%d,end%d \n",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"==") == 0)
    {
        fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        fprintf(QuadFile,"JZ T%d,end%d \n",temp,label[labelTop]);
    }
    else 
    {
        fprintf(QuadFile,"JNZ %s,end%d \n",stack[top],label[labelTop]);
        top++;
    }
    top-=2;
    temp++; 
}


void push(char* x)
{
    strcpy(stack[++top],x);
    displayStack();
}

void OpCode()
{
    
    fprintf(QuadFile,"%s T%d,%s,%s \n",stack[top],temp,stack[top-2],stack[top-1]);
    top-=2;

    sprintf(stack[top], "T%d", temp);
    
    temp++;
}


void displayStack()
{
    printf(" =========================== Stack ========================\n\n");
    for( int i =0 ; i <= top; i++)
    {
        printf("stack[%d] = %s \n",i,stack[i]);
    }
    printf(" =================================================================\n\n");
}

void AssignCode()
{
    fprintf(QuadFile,"MOV %s,%s \n",stack[top-1],stack[top]);
    top-=2; 
}
