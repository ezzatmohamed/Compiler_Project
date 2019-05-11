%{  
    #include <stdio.h>
		#include "symbol.c"
		#include "operations.c"
		#include "code.c"

		int yylineno;
		extern char *yytext; 
    int yylex(void);
    void yyerror(char *);
		
%}
%code requires {
    
		struct ExpInfo {
	  char type[10];
		char val[100];
		char name[50];
		};
}

%union
{
	char name[20];

	int iVal;
	float fVal;

	struct ExpInfo info;
}
%expect 26
//*****************************Tokens*************************************
%token  SCOPE_OBRACE SCOPE_CBRACE ARGUMENT_OBRACKET ARGUMENT_CBRACKET SEMICOLON COLON COMMA 
%token<name> TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_CONSTANT TYPE_STRING IDENTIFIER
%token IF ELSE DO WHILE FOR BREAK CONTINUE REPEAT UNTIL SWITCH CASE FALSE TRUE DEFAULT PRINT RET 
%token<name> PLUS MINUS MULTIPLY DIVIDE POWER MODULUS ASSIGN AND OR NOT INCREMENT DECREMENT  
%token RELATION_EQUALS RELATION_NOTEQUAL RELATION_LESS_THAN RELATION_GREATER_THAN RELATION_LESS_EQUAL RELATION_GREATER_EQUAL 
%token RELATION_AND RELATION_OR 
%token<name> INTEGER_VALUE FLOATINPOINT_VALUE STRING_VALUE CHARACTER  BOOLEAN_VALUE    



//**************************Precedences************************************
%left ASSIGN
%left RELATION_GREATER_THAN RELATION_LESS_THAN RELATION_GREATER_EQUAL RELATION_LESS_EQUAL RELATION_EQUALS RELATION_NOTEQUAL RELATION_AND RELATION_OR NOT
%left PLUS MINUS 
%left DIVIDE MULTIPLY MODULUS
%left POWER

//IF-ELSE Ambiguity
%nonassoc IFX
%nonassoc ELSE

//Unary minus ambiguity
%nonassoc UMINUS

%type<info> exp value V conditions
%type<name> type 
%start program
%%

program:
        program statements '\n'
				| statement
        ;

statement:	type IDENTIFIER SEMICOLON   																		{Declare($2,$1,yylineno);    }

		| Assignment_Statement
		
		| TYPE_CONSTANT type IDENTIFIER ASSIGN exp SEMICOLON 										{  if(ConstAssign($3,$2,$5.val,$5.type,yylineno)){ AssignCode();   printf("Constant Assignment\n");}}
		
		/*  Loops */
		| WHILE {NewScope(); LoopBegin();} ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET 	{CheckCondition();} scope {LoopEnd(); EndScope();}
		
		| DO 		{NewScope(); LoopBegin();} scope WHILE ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET {CheckCondition(); } SEMICOLON					{LoopEnd(); EndScope(); printf("Do while\n");}

		| FOR 	{NewScope(); LoopBegin();} ARGUMENT_OBRACKET  Assignment_Statement
		  conditions SEMICOLON {CheckCondition();}
		  Assignment_Statement ARGUMENT_CBRACKET
		  scope	ARGUMENT_OBRACKET		Assignment_Statement ARGUMENT_CBRACKET SEMICOLON					{LoopEnd(); EndScope();}																										  {printf("For loop\n");}

		//Repeat

		| REPEAT {NewScope();LoopBegin();} scope UNTIL ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET {RepeatCondition();} SEMICOLON			{ LoopEnd(); EndScope(); printf("repeat-until loop\n");}

		//=====================================
		
		| IF {NewScope(); IfBegin();} If_statment   



		| SWITCH ARGUMENT_OBRACKET V ARGUMENT_CBRACKET   {if(strcmp($3.type,"int") != 0 && strcmp($3.type,"Cint")!= 0){fprintf(ErrorFile,"Error at line %d : Switch accpets integers only !\n",yylineno);}cases[++caseTop] = caseEnd; caseEnd++; printf("Switch case\n");} SwitchBody   		
	
		| RET SEMICOLON {return  1;}
		;


SwitchBody: SCOPE_OBRACE CaseStatment SCOPE_CBRACE 
					;

CaseStatment : CASE ARGUMENT_OBRACKET INTEGER_VALUE ARGUMENT_CBRACKET { push($3);CaseBegin();} scope { CaseEnd();} CaseStatment
							| DEFAULT {DefaultCase();}  scope {SwitchEnd();}
							;	

type:	  TYPE_INT 					{strcpy($$,$1);}
			| TYPE_FLOAT  			{strcpy($$,$1);}
			| TYPE_CHAR  				{strcpy($$,$1);}
			| TYPE_BOOL  				{strcpy($$,$1);}
			| TYPE_STRING 			{strcpy($$,$1);}
			;

Assignment_Statement:		V ASSIGN exp SEMICOLON			{ if(Assign($1.name,$3.val,$3.type,yylineno)){ AssignCode();   printf( "Initilization \n");}}



If_statment : ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET { CheckCondition();} If_else
						;
						
If_else : scope %prec IFX 								 { IfEnd();  EndScope();  }
						|	scope ELSE {Else();} scope	 { IfEnd();  EndScope();  }
						;
conditions:
	 		exp  RELATION_LESS_THAN exp{ if(CheckType($1.type,$3.type,yylineno)){  push("<");}}

    | exp  RELATION_LESS_EQUAL exp {if(CheckType($1.type,$3.type,yylineno)){push("<=");}}

    | exp  RELATION_GREATER_EQUAL exp  {if(CheckType($1.type,$3.type,yylineno)){push(">=");}}

    | exp  RELATION_GREATER_THAN exp  {if(CheckType($1.type,$3.type,yylineno)){ push(">");}}

    | exp  RELATION_NOTEQUAL exp {if(CheckType($1.type,$3.type,yylineno)){ push("!=");}}

    | exp  RELATION_EQUALS exp  	{if(CheckType($1.type,$3.type,yylineno)){push("==");}}

		| conditions RELATION_AND  conditions { CheckCondition(); }

		//| conditions RELATION_OR   conditions		{ ORcondition(); }

    | exp  													{$$=$1;}
   
    ;
														//(char*x,char*y,char*xType,char*yType,char* val,char*type,char *op)
exp:    exp PLUS exp				{ push("ADD"); OpCode();  
														 operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"PLUS",yylineno);
														
															printf("Plus\n");
														}

		 |  exp MINUS exp				{ push("SUB"); OpCode();    
														 !operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"MINUS",yylineno);
															
														}

		 |  exp MULTIPLY exp		{ push("MUL"); OpCode();   
														operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"MULTIPLY",yylineno);
														}

		 |  exp DIVIDE exp			{ push("DIV"); OpCode();    
															operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"DIVIDE",yylineno);
														}

		 |  exp MODULUS exp			{ push("MOD"); OpCode();    
															operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"MODULUS",yylineno);
														}

		 |  exp AND exp					{ push("AND"); OpCode();    
															operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"AND",yylineno);
														}

		 |  exp OR exp					{ push("OR") ; OpCode();    
															operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"OR",yylineno);
														}

		 |  NOT exp							{ push("NOT"); OpCode();    
															operation($2.val,$2.val,$2.type,$2.type,$$.val,$$.type,"NOT",yylineno);
														}
														
		 | 	ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET 			{$$=$2;}
		 | 	value																				{$$=$1;}
			;


value:      INTEGER_VALUE   									{ push($1); strcpy($$.type,"int"); strcpy($$.val,$1);  }
					| FLOATINPOINT_VALUE   							{	push($1); strcpy($$.type,"float"); strcpy($$.val,$1); }	
					| STRING_VALUE  									  {	push($1); strcpy($$.type,"str"); strcpy($$.val,$1); }
					| CHARACTER  											  { push($1); strcpy($$.type,"char"); strcpy($$.val,$1);}						
					| V																	{ $$=$1;

																									search($1.name);
																									if( current == NULL)
																									{
																										fprintf(ErrorFile,"Error at line %d : undeclared Variable !\n",yylineno);
																									}
																									else if(strcmp(current->value.val,"NULL") == 0)	
																									{
																										fprintf(ErrorFile,"Error at line %d : uninitialized Variable !\n",yylineno);
																									}

																							}
					;
V:  IDENTIFIER				{ 					push($1);
																	search($1); 
																	if( current != NULL)
																	{strcpy($$.name,current->value.name); strcpy($$.val,current->value.val); strcpy($$.type,current->value.type);}
																	else 
																	{
																		printf("Error undeclared variable ");
																		
																	}
															}	  

statements:  statement
		| statements statement
		;	
		
scope:	SCOPE_OBRACE SCOPE_CBRACE
		| SCOPE_OBRACE statements SCOPE_CBRACE	
		;	

		

%%

void yyerror(char *s) {
    fprintf(ErrorFile,"%s at line %d : %s \n",s,yylineno,yytext);
}

int main(void) 
{


		ST[CurrentST].head = NULL;
		ST[CurrentST].parent = -1;
		QuadFile = fopen ("/root/Desktop/CCE/Semester-2/Compilers/Compilers_Project/GUI/Results/quad.txt","w");
		
		SymbolFile = fopen ("/root/Desktop/CCE/Semester-2/Compilers/Compilers_Project/GUI/Results/symbol.txt","w");
		ErrorFile = fopen ("/root/Desktop/CCE/Semester-2/Compilers/Compilers_Project/GUI/Results/errors.txt","w");

		extern FILE *yyin;		
		yyin = fopen ("/root/Desktop/CCE/Semester-2/Compilers/Compilers_Project/GUI/uploads/program.txt","r");

		
	  yyparse();
		displaySymboltable();
		fclose (QuadFile);
		fclose (SymbolFile);
		fclose (ErrorFile);
		fclose (yyin);


		return 0;
}
