#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "symbol.h"
FILE *QuadFile;
//int LineCounter = 1;



int label[100];
int labelTop = -1;
int labelEnd =0;


int cases[100];
int caseTop = -1;
int caseEnd =0;
int caseNum = 0;



char stack[100][20];
int top=-1;
int temp = 0;

void CaseBegin();
void DefaultCase();
void CaseEnd();
void SwitchEnd();

void IfBegin();
void IfEnd();
void Else();



void LoopBegin();
void LoopEnd();
void CheckCondition();
void RepeatCondition();

void push(char* x);
void displaySymboltable();
void AssignCode();
void OpCode();
void displayStack();
