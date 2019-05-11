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
                if( CurrentST != parentST)
                {
                    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
                
                    strcpy(new_node->value.name,current->value.name);
                    strcpy(new_node->value.val,current->value.val);
                    strcpy(new_node->value.type,current->value.type); 
                    insert(new_node);   
                    current = new_node;
                }
                return;
            } 
            current = current->next; 
        }
        parentST = ST[parentST].parent;
    }
    
     
} 
void displaySymboltable()
{
    for( int i = 0; i <= indexST; i++)
    {
        struct node *ptr = ST[i].head;
        while (ptr != NULL) 
        { 
            fprintf(SymbolFile,"%s %s %d ",ptr->value.name,ptr->value.type,i);

           // printf("%d , %d %s %s %s dd1 \n",indexST,i,ptr->value.name,ptr->value.type,ptr->value.val);
            ptr = ptr->next; 
        }

        //fprintf(SymbolFile,"");
    }
}

void insert(struct node *new_node) 
{
    new_node->next = ST[CurrentST].head; 
    ST[CurrentST].head   = new_node; 

  //  printf("head : %s   %s   %s \n\n",ST[CurrentST].head->value.name,ST[CurrentST].head->value.type,ST[CurrentST].head->value.val);
  // displaySymboltable();
} 


bool Declare(char *name,char  *var_type,int yylineno)
{

    // if no variable is declared with this name.
    // current pointer will be null.
    search(name);

    if( current != NULL )
    {
        fprintf(ErrorFile,"Error at line %d : Already Declared Variable ! \n",yylineno);
        return false;
    }
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
    strcpy(new_node->value.name,name);
    strcpy(new_node->value.val,"NULL");
    strcpy(new_node->value.type,var_type); 

  //  printf("new_node : %s   %s   %s\n\n",name,name,name);
    insert(new_node);
    return true;
}


bool Assign(char *name , char *val,char  *var_type,int yylineno)
{
    printf("Search : %s\n",name);
    search(name);
    if( current == NULL)    
    {
        fprintf(ErrorFile,"Error at line %d : undeclared variable ! \n",yylineno);
        return false;
    }
    else if( strcmp(current->value.type,var_type) )
    {
        fprintf(ErrorFile,"Error at line %d : type mismatch ! \n",yylineno);
        return false;
    }
    else if( strcmp("Cint",var_type)==0 || strcmp("Cfloat",var_type)==0 || strcmp("Cstr",var_type)==0 || strcmp("Cchar",var_type)==0 )
    {
        fprintf(ErrorFile,"Error at line %d : can't change a constant ! \n",yylineno);
        return false;
    
    }

    strcpy(current->value.val,val);
    return true;
}
bool ConstAssign(char *name,char *const_type,char *val,char * var_type,int yylineno)
{
    
    if( Declare(  name , strcat("C",const_type),yylineno) )
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

void EndScope()
{
    CurrentST = ST[indexST].parent;
}