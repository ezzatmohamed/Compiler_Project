#include "code.h"


void IfBegin()
{
    label[++labelTop] = labelEnd; 
    labelEnd++;  
}

void IfEnd()
{

    printf("\tend%d: \n",label[labelTop]);
    labelTop--;
}
void Else()
{

    printf("\tJMP end%s\n",labelEnd);
   

    printf("\tend%d: \n",label[labelTop]);
    label[labelTop] = labelEnd;

    labelEnd++;
}

void LoopBegin()
{

    label[++labelTop] = labelEnd;
    labelEnd++;
    printf("\tL%d: \n",label[labelTop]);
}

void LoopEnd()
{
    printf("\tJMP L%d \n",label[labelTop]);
    printf("\tend%d: \n",label[labelTop]);
    labelTop--;
}

void CheckCondition()
{
    
    if( strcmp(stack[top],">") )
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JNegZ  T%s,end%s ",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],">="))
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JNeg T%s,end%s ",temp,label[labelTop]);
    
    }
    else if( strcmp(stack[top],"<"))
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JPosZ T%s,end%s ",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"<="))
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JPos T%s,end%s ",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"!="))
    {   
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JZ T%s,end%s ",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"=="))
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JNZ T%s,end%s ",temp,label[labelTop]);
    }
    else 
    {
        printf("JZ %s,end%s \n",stack[top],label[labelTop]);
        top++;
    }
    top-=2;
    temp++; 
}

void RepeatCondition()
{
    if( strcmp(stack[top],">") )
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JPos  T%s,end%s ",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],">="))
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JPosZ T%s,end%s ",temp,label[labelTop]);
    
    }
    else if( strcmp(stack[top],"<"))
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JNeg T%s,end%s ",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"<="))
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JNegZ T%s,end%s ",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"!="))
    {   
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JNZ T%s,end%s ",temp,label[labelTop]);
    }
    else if( strcmp(stack[top],"=="))
    {
        printf("CMP T%s,%s,%s \n",temp,stack[top-2],stack[top-1])  ;      
        printf("JZ T%s,end%s ",temp,label[labelTop]);
    }
    else 
    {
        printf("JNZ %s,end%s \n",stack[top],label[labelTop]);
        top++;
    }
    top-=2;
    temp++; 
}


void push(char* x)
{
    strcpy(stack[++top],x);
}

void OpCode()
{
    
    printf("%s T%s,%s,%s \n",stack[top],temp,stack[top-2],stack[top-1]);
    top-=2;

    sprintf(stack[top], "T%d", temp);
    
    temp++;
}

void AssignCode()
{
    printf("MOV %s,%s \n",stack[top-1],stack[top]);
    top--; 
}
