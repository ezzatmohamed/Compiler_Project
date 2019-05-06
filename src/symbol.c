#include "symbol.h"



void search(char *x) 
{ 
    int parentST = CurrentST;
    while( parentST != -1)
    {
        current = ST[parentST].head;
        while (current != NULL) 
        { 
            if (strcmp(current->value.name,x)==0) 
            {
                break;
            } 
            current = current->next; 
        }
        parentST = ST[parentST].parent;
    }
    
     
} 
void displaySymboltable()
{
    printf("=========================== Symbol Table %d ========================\n\n",CurrentST);
    struct node *ptr = ST[CurrentST].head;
    while (ptr != NULL) 
    { 
        printf("Name =  %s , Type = %s , Value = %s\n",ptr->value.name,ptr->value.type,ptr->value.val);
        ptr = ptr->next; 
    }
    printf("====================================================================\n\n");
}

void insert(struct node *new_node) 
{
    new_node->next = ST[CurrentST].head; 
    ST[CurrentST].head   = new_node; 

    printf("head : %s   %s   %s \n\n",ST[CurrentST].head->value.name,ST[CurrentST].head->value.type,ST[CurrentST].head->value.val);
    displaySymboltable();
} 


bool Declare(char *name,char  *var_type)
{

    // if no variable is declared with this name.
    // current pointer will be null.
    search(name);

    if( current != NULL )
    {
        printf("Error : Already Declared Variable ! \n");
        return false;
    }
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
    strcpy(new_node->value.name,name);
    strcpy(new_node->value.val,"NULL");
    strcpy(new_node->value.type,var_type); 

    printf("new_node : %s   %s   %s\n\n",name,name,name);
    insert(new_node);
    return true;
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
    else if( strcmp("Cint",var_type)==0 || strcmp("Cfloat",var_type)==0 || strcmp("Cstr",var_type)==0 || strcmp("Cchar",var_type)==0 )
    {
        printf("Error : can't change a constant ! \n");
        return false;
    
    }

    strcpy(current->value.val,val);
    return true;
}
bool ConstAssign(char *name,char *const_type,char *val,char * var_type)
{
    
    if( Declare(  name , strcat("C",const_type)  ) )
    {
        search(name); 
        strcpy(current->value.val,val);
        return true;
    }
    
    
    return false;
}

void NewScope()
{
    ++indexST;
    ST[indexST].parent = CurrentST;

    CurrentST = indexST;
}