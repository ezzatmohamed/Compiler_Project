#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef enum{INT,FLOAT,CHAR,STRING,BOOL,CONST} Var_Type;





// for variables declaration. we store the variable name as charachters
// and the variable name as characters.
// if it's ( int ,float,... ) we convert it to string before we store it.
typedef struct Var
{
    char* type;
    char* name;
    char* val;


};


// a node for the linked-list
typedef struct node 
{
    struct Var value;   
    struct node *next;    
};

//head and tail pointers for the linked-list
struct node *head = NULL,*tail = NULL,*current=NULL;



void search(char *x);
void push(struct node *new_node) ;
void Declare(char *name,char* var_type);
void Assign(char *name , char *val,char* var_type);
