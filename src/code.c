#include "code.h"

void LoopBegin()
{
    printf("\tL%d: \n",lno++);
}

void LoopEnd()
{
    printf("\tL%d: \n",--lno);
    printf("\tend%d: \n",lno);
}

void CheckCondition()
{
    printf("%s = not %s",temp,stack[top]);
    printf("if T%s jmp end%s",temp,lno-1);
    temp++; 
}


void push(char* x)
{
    strcpy(stack[++top],x);
}

void OpCode()
{
    printf("T%s = %s %s %s",temp,stack[top-2],stack[top],stack[top-1]);
    top-=2;

    sprintf(stack[top], "%d", temp);
    
    temp++;
}

void AssignCode()
{
    printf("%s = T%s",stack[top],stack[top-1]);
    top--; 
}
