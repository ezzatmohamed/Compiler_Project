#include "symbol.h"



void search(char *x) 
{ 
    struct node *ptr = head;
    while (current != NULL) 
    { 
        if (ptr->value.name == x) 
        {
            break;
        } 
        ptr = ptr->next; 
    }
     
} 

void push(struct node *new_node) 
{
    new_node->next = head; 
    head    = new_node; 
} 


void Declare(char *name,Var_Type var_type)
{

    // if no variable is declared with this name.
    // current pointer will be null.
    search(name);

    if( current != NULL )
    {
        printf("Error : Already Declared Variable ! \n");
        return;
    }
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
    new_node->value.name  = name;
    new_node->value.val  = "NULL";
    new_node->value.type  = var_type; 

    push(new_node);
}


void Assign(char *name , char *val,Var_Type var_type)
{
    search(name);
    if( current == NULL)
    {
        printf("Error : undeclared variable ! \n");
        return;
    }
    else if( current->value.type != var_type )
    {
        printf("Error : mismatched type ! \n");
        return;
    }

    current->value.val = val;

}