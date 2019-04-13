//*****************************Tokens*************************************
%token SCOPE_OBRACE SCOPE_CBRACE ARGUMENT_OBRACKET ARGUMENT_CBRACKET SEMICOLON COLON COMMA 
%token TYPE_INT TYPE_FLOAT TYPE_CHAR TYPE_BOOL TYPE_CONSTANT TYPE_STRING
%token IF ELSE DO WHILE FOR BREAK CONTINUE SWITCH CASE FALSE TRUE DEFAULT PRINT RET 
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

%{  
	#include <stdio.h>   
	int yyerror(char *);
	int yylex(void);
	int yylineno;
	FILE * f1;
	FILE * yyin;

%}
%%

program:
        program statement '\n'
        | /* NULL */
        ;

statement:	type IDENTIFIER SEMICOLON   {printf (" Decleration \n");}
		
		| IDENTIFIER ASSIGN exp SEMICOLON	{printf( "Initilization \n");}
		
		| TYPE_CONSTANT IDENTIFIER ASSIGN exp SEMICOLON {printf("Constant Assignment\n");}
		
		| WHILE ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET scope  {printf("While Loop\n");}
		
		| DO scope WHILE ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET SEMICOLON	{printf("Do while\n");}
		
		| FOR ARGUMENT_OBRACKET INT IDENTIFIER ASSIGN exp SEMICOLON 
		  IDENTIFIER BoolOp exp SEMICOLON
		  IDENTIFIER ASSIGN exp ARGUMENT_CBRACKET
		  scope											  {printf("For loop\n");}

		
		| IF ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET scope %prec IFX {printf("If statement\n");}

		| IF ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET scope ELSE scope	{printf("If-Elsestatement\n");}

		| SWITCH ARGUMENT_OBRACKET IDENTIFIER ARGUMENT_CBRACKET SwitchBody      {printf("Switch case\n");}

		| PRINT exp 	SEMICOLON	                        {printf("Print\n");}
		
		| function	                                            	

		| scope											{printf("New braces scope\n");} //Not sure

		;


SwitchBody: SCOPE_OBRACE CaseStatment SCOPE_CBRACE
						;

CaseStatment : CASE ARGUMENT_OBRACKET value ARGUMENT_CBRACKET scope CaseStatment
							| DEFAULT scope

type:	  TYPE_INT 
			| TYPE_FLOAT 
			| TYPE_CHAR 
			| TYPE_BOOL 
			| TYPE_STRING



exp:   exp ArithmeticOp exp
		 | exp BoolOp exp
		 | (exp) 
		 | IDENTIFIER
		 | value

ArithExp : ArithExp ArithmeticOp ArithExp 
					



ArithmeticOp:  	  PLUS
								| MINUS
								| MULTIPLY
								| DIVIDE
								| POWER 
								| MODULUS
								| AND 
				 				| OR 
				 				| NOT
								;

BoolOp:    
				   RELATION_AND 
				 | RELATION_OR 
				 | RELATION_EQUALS
				 | RELATION_NOTEQUAL
				 | RELATION_LESS_THAN 
				 | RELATION_GREATER_THAN
				 | RELATION_LESS_EQUAL
				 | RELATION_GREATER_EQUAL
				 ;
				 


value:      INTEGER_VALUE 
					| FLOATINPOINT_VALUE 
					| STRING_VALUE
					| CHARACTER
					| BOOLEAN_VALUE   
					



function: IDENTIFIER ARGUMENT_OBRACKET args ARGUMENT_CBRACKET SCOPE_OBRACE statements RET  exp  SEMICOLON   SCOPE_CBRACE   {printf("function\n");}
	   ;
	   
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

		

//increment: IDENTIFIER  INCREMENT              { $$ = $1+1; }
	//	 | IDENTIFIER DECREMENT                { $$ = $1-1; }
		 //;		

%%