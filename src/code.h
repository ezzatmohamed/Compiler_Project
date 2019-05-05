#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int label[100];
int labelTop = -1;
int labelEnd =0;


char stack[100][20];
int top=-1;
int temp = 0;

void IfBegin();
void IfEnd();
void Else();



void LoopBegin();
void LoopEnd();
void CheckCondition();
void RepeatCondition();

void push(char* x);

void AssignCode();
void OpCode();
void displayStack();