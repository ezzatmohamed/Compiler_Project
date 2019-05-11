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

           ptr = ptr->next; 
        }

        //fprintf(SymbolFile,"");
    }
}

void insert(struct node *new_node) 
{
    new_node->next = ST[CurrentST].head; 
    ST[CurrentST].head   = new_node; 

} 


bool Declare(char *name,char  *var_type,int yylineno)
{
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

    insert(new_node);
    return true;
}


bool Assign(char *name , char *val,char  *var_type,int yylineno)
{
    search(name);


    if( strcmp("Cint",var_type) == 0)
        strcpy(var_type,"int");
    else if( strcmp("Cfloat",var_type) == 0)
        strcpy(var_type,"float");
    else if( strcmp("Cchar",var_type) == 0)
        strcpy(var_type,"char");
    else if( strcmp("Cstr",var_type) == 0)
        strcpy(var_type,"str");
    
    

    if( current == NULL)    
    {
        fprintf(ErrorFile,"Error at line %d : undeclared variable ! \n",yylineno);
        return false;
    }
    else if( strcmp("Cint",current->value.type)==0 || strcmp("Cfloat",current->value.type)==0 || strcmp("Cstr",current->value.type)==0 || strcmp("Cchar",current->value.type)==0 )
    {
        fprintf(ErrorFile,"Error at line %d : can't change a constant ! \n",yylineno);
        return false;
    
    }
    else if( strcmp(current->value.type,var_type) )
    {
        fprintf(ErrorFile,"Error at line %d : type mismatch ! \n",yylineno);
        return false;
    }
    

    strcpy(current->value.val,val);
    return true;
}
bool ConstAssign(char *name,char *const_type,char *val,char * var_type,int yylineno)
{
    

    char x[7];
    if( strcmp("int",var_type) == 0)
    {
        strcpy(x,"Cint");
    }
    else if( strcmp("float",var_type) == 0)
    {
        strcpy(x,"Cfloat");
    }
    else if( strcmp("str",x) == 0)
        strcpy(x,"Cstr");
    else if( strcmp("char",var_type) == 0)
        strcpy(x,"Cchar");

    if( Declare(  name , x,yylineno) )
    {
        search(name); 
        strcpy(current->value.val,val);
        return true;
    }
    
    return false;
}

bool CheckType(char *x,char *y,int yylineno)
{
    if( strcmp("Cint",x) == 0)
        strcpy(x,"int");
    else if( strcmp("Cfloat",x) == 0)
        strcpy(x,"float");
    else if( strcmp("Cstr",x) == 0)
        strcpy(x,"str");
    
    if( strcmp("Cint",y) == 0)
        strcpy(y,"int");
    else if( strcmp("Cfloat",y) == 0)
        strcpy(y,"float");
    else if( strcmp("Cstr",y) == 0)
        strcpy(y,"str");
    



    if(strcmp(x,y) != 0)
    {
        fprintf(ErrorFile,"Error at line %d : type mismatch ! \n",yylineno);
        return false;
    }
    else if ( strcmp(x,"str") == 0)
    {
        fprintf(ErrorFile,"Error at line %d : Can't perform this operation on strings ! \n",yylineno);
        return false;
    }

    return true;
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