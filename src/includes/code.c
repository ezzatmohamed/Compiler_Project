#include "code.h"


void CaseBegin()
{

    NewScope();

    fprintf(QuadFile,"Case%d: \n",caseNum);
    caseNum++;

    fprintf(QuadFile,"CMP T%d,%s,%s \n",temp,stack[top-1],stack[top]);     
    fprintf(QuadFile,"JNZ T%d,Case%d \n",temp,caseNum);
    
    
    temp++; 

}
void DefaultCase()
{
    NewScope();
    fprintf(QuadFile,"Case%d: \n",caseNum);
    caseNum++;
}
void CaseEnd()
{
    fprintf(QuadFile,"JMP SwitchEnd%d \n",cases[caseTop]);

    EndScope();
}
void SwitchEnd()
{
    fprintf(QuadFile,"SwitchEnd%d: \n",cases[caseTop]);
    caseTop--;

    EndScope();
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
        top+=2;
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