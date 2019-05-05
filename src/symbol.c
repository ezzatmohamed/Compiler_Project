#include "symbol.h"



void search(char *x) 
{ 
    current  = head;
    while (current != NULL) 
    { 
        if (strcmp(current->value.name,x)==0) 
        {
            break;
        } 
        current = current->next; 
    }
     
} 
void displaySymboltable()
{
    printf(" =========================== Symbol Table ========================\n\n");
    struct node *ptr = head;
    while (ptr != NULL) 
    { 
        printf("Name =  %s , Type = %s , Value = %s\n",ptr->value.name,ptr->value.type,ptr->value.val);
        ptr = ptr->next; 
    }
    printf(" =================================================================\n\n");
}

void insert(struct node *new_node) 
{
    new_node->next = head; 
    head    = new_node; 

    printf("head : %s   %s   %s \n\n",head->value.name,head->value.type,head->value.val);
   displaySymboltable();
} 


void Declare(char *name,char  *var_type)
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
  
    strcpy(new_node->value.name,name);
    strcpy(new_node->value.val,"NULL");
    strcpy(new_node->value.type,var_type); 

    printf("new_node : %s   %s   %s\n\n",name,name,name);
    insert(new_node);
}


bool Assign(char *name , char *val,char  *var_type)
{
    printf("Search : %s\n",name);
    search(name);
    if( current == NULL)
    {
        printf("Error : undeclared variable ! \n");
        return false;
    }
    else if( strcmp(current->value.type,var_type) )
    {
        printf("Error : type mismatch ! \n");
        return false;
    }

    strcpy(current->value.val,val);
    return true;
}