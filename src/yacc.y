%{  
    #include <stdio.h>
		#include "symbol.h"
    int yylex(void);
    void yyerror(char *);
		int symbols[100];

	typedef struct ExpInfo {
	    char type[10];
			char *val[20];
	} ExpInfo;
}
%}
%union
{
	char name[20];
	struct ExpInfo info;
}

//*****************************Tokens*************************************
%token SCOPE_OBRACE SCOPE_CBRACE ARGUMENT_OBRACKET ARGUMENT_CBRACKET SEMICOLON COLON COMMA 
%token TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_CONSTANT TYPE_STRING
%token IF ELSE DO WHILE FOR BREAK CONTINUE REPEAT UNTIL SWITCH CASE FALSE TRUE DEFAULT PRINT RET 
%token PLUS MINUS MULTIPLY DIVIDE POWER MODULUS ASSIGN AND OR NOT INCREMENT DECREMENT  
%token RELATION_EQUALS RELATION_NOTEQUAL RELATION_LESS_THAN RELATION_GREATER_THAN RELATION_LESS_EQUAL RELATION_GREATER_EQUAL 
%token RELATION_AND RELATION_OR INTEGER_VALUE FLOATINPOINT_VALUE STRING_VALUE CHARACTER IDENTIFIER BOOLEAN_VALUE    

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



%%

program:
        program statements '\n'
				| statement
        ;

statement:	type IDENTIFIER SEMICOLON   																				{  Declare($2,$1);   printf (" Decleration \n"); }

		| IDENTIFIER ASSIGN exp SEMICOLON																						{ Assign($1,$3,$3.type); printf( "Initilization \n");}
		
		| TYPE_CONSTANT type IDENTIFIER ASSIGN exp SEMICOLON 														{printf("Constant Assignment\n");}
		
		
		/*  Loops */
		| WHILE ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET scope  											{printf("While Loop\n");}
		
		| DO scope WHILE ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET SEMICOLON					{printf("Do while\n");}

		| FOR ARGUMENT_OBRACKET  IDENTIFIER ASSIGN exp SEMICOLON 
		  exp SEMICOLON
		  IDENTIFIER ASSIGN exp SEMICOLON ARGUMENT_CBRACKET
		  scope																																		  {printf("For loop\n");}

		//Repeat

		| REPEAT scope UNTIL ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET SEMICOLON			{printf("repeat-until loop\n");}

		//=====================================
		
		| IF ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET scope %prec IFX 								{printf("If statement\n");}

		| IF ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET scope ELSE scope								{printf("If-Elsestatement\n");}

		| SWITCH ARGUMENT_OBRACKET IDENTIFIER ARGUMENT_CBRACKET SwitchBody   		  	{printf("Switch case\n");}

		| PRINT ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET SEMICOLON	                  {printf("Print %d\n",$exp);}
		
		| function	                                            										{printf("Function\n");}

		| IDENTIFIER ARGUMENT_OBRACKET args ARGUMENT_CBRACKET SEMICOLON  {printf("void function call\n");}
		
		| IDENTIFIER ASSIGN IDENTIFIER ARGUMENT_OBRACKET args ARGUMENT_CBRACKET SEMICOLON {printf("function call\n");}
	  
	   
		;


SwitchBody: SCOPE_OBRACE CaseStatment SCOPE_CBRACE
						;

CaseStatment : CASE ARGUMENT_OBRACKET INTEGER_VALUE ARGUMENT_CBRACKET scope CaseStatment
							| DEFAULT scope
							;	

type:	  TYPE_INT 					{$$ = $1;}
			| TYPE_FLOAT  			{$$ = $1;}
			| TYPE_CHAR  				{$$ = $1;}
			| TYPE_BOOL  				{$$ = $1;}
			| TYPE_STRING 			{$$ = $1;}
			;

exp:    exp PLUS exp				{printf("Plus\n");}
		 |  exp MINUS exp				{printf("minus\n");}
		 |  exp MULTIPLY exp		{printf("mult\n");}
		 |  exp DIVIDE exp			{printf("divide\n");}
		 |  exp MODULUS exp			{$$ = $1 % $3;}
		 |  exp AND exp					{$$ = $1 & $3;}
		 |  exp OR exp					{$$ = $1 | $3;}
		 |  NOT exp							{$$ = !$2;}

		 |  exp RELATION_AND exp		{$$ = $1 && $3;}
		 |  exp RELATION_OR exp		{$$ = $1 || $3;}
		 |  exp RELATION_EQUALS exp		{$$ = $1 == $3;}
		 |  exp RELATION_NOTEQUAL exp		{$$ = $1 != $3;}
		 |  exp RELATION_LESS_THAN exp		{$$ = $1 < $3;}
		 |  exp RELATION_GREATER_THAN exp		{$$ = $1 > $3;}
		 |  exp RELATION_LESS_EQUAL exp		{$$ = $1 <= $3;}
		 |  exp RELATION_GREATER_EQUAL exp		{$$ = $1 >= $3;}

		 | ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET 									{$$=$2;}
		 | value									{$$=$1;}
			;


value:      INTEGER_VALUE   									{ $$.type = "int"; sprintf($$.val, "%d", $1); }
					| FLOATINPOINT_VALUE   							{	$$.type = "float"; snprintf($$.val, sizeof $$.val, "%f", $1); }	
					| STRING_VALUE  									  {	$$.type = "str"; strcpy($$.val,$1); }
					| CHARACTER  											  { $$.type = "char"; strcpy($$.val,$1);}
				//	| FALSE														
				//	| TRUE							{		}								
					| IDENTIFIER				{ 	search($1); 
																	if( current != NULL)
																	{$$.val = current->value.val; $$.type = current->value.type;}
																	else 
																		printf("Error undeclared variable ");
															}	  				
					;


FuncRet: RET  exp | RET		;											


function: IDENTIFIER ARGUMENT_OBRACKET args ARGUMENT_CBRACKET SCOPE_OBRACE FuncBody   SCOPE_CBRACE   
	   ;

FuncBody: statements FuncRet  SEMICOLON | FuncRet SEMICOLON ;
statements:  statement
		| statements statement
		;	
		
args: IDENTIFIER more
    |
		;

more:  COMMA IDENTIFIER more 
		| 
		;	   

scope:	SCOPE_OBRACE SCOPE_CBRACE
		| SCOPE_OBRACE statements SCOPE_CBRACE	
		;	

		

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}
