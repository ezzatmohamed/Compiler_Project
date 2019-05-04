#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int lno = 0;

char stack[100][20];
int top=-1;
int temp = 0;



void LoopBegin();
void LoopEnd();
void CheckCondition();

void push(char* x);

void AssignCode();
void OpCode();