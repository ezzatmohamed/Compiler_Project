#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef enum{INT,FLOAT,CHAR,STRING,BOOL,CONST} Var_Type;





// for variables declaration. we store the variable name as charachters
// and the variable name as characters.
// if it's ( int ,float,... ) we convert it to string before we store it.
struct Var
{
    char type[10];
    char name[50];
    char val[100];
};


// a node for the linked-list
struct node 
{
    struct Var value;   
    struct node *next;    
    int scope;
};

struct SymbolTable
{
    struct node *head;
    int parent;
};

int indexST=0;
int CurrentST = 0;
struct SymbolTable ST[100];

//head and tail pointers for the linked-list
struct node *head = NULL,*tail = NULL,*current=NULL;



void search(char *x);
void insert(struct node *new_node) ;
bool Declare(char *name,char  *var_type);
bool Assign(char *name , char *val,char* var_type);
