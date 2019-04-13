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

%{  
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}
%%

program:
        program statement '\n'
        | statement
        ;

statement:	type IDENTIFIER SEMICOLON   																				{printf (" Decleration \n");}
		
		| IDENTIFIER ASSIGN exp SEMICOLON																						{printf( "Initilization \n");}
		
		| TYPE_CONSTANT type IDENTIFIER ASSIGN exp SEMICOLON 														{printf("Constant Assignment\n");}
		
		
		/*  Loops */
		| WHILE ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET scope  											{printf("While Loop\n");}
		
		| DO scope WHILE ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET SEMICOLON					{printf("Do while\n");}

		| FOR ARGUMENT_OBRACKET TYPE_INT IDENTIFIER ASSIGN exp SEMICOLON 
		  exp SEMICOLON
		  IDENTIFIER ASSIGN exp ARGUMENT_CBRACKET
		  scope																																		  {printf("For loop\n");}

		//Repeat

		| REPEAT scope UNTIL ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET SEMICOLON			{printf("repeat-until loop\n");}

		//=====================================
		
		| IF ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET scope %prec IFX 								{printf("If statement\n");}

		| IF ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET scope ELSE scope								{printf("If-Elsestatement\n");}

		| SWITCH ARGUMENT_OBRACKET IDENTIFIER ARGUMENT_CBRACKET SwitchBody   		  	{printf("Switch case\n");}

		| PRINT ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET SEMICOLON	                  {printf("Print %d\n",$exp);}
		
		| function	                                            										{printf("Function\n");}

		;


SwitchBody: SCOPE_OBRACE CaseStatment SCOPE_CBRACE
						;

CaseStatment : CASE ARGUMENT_OBRACKET INTEGER_VALUE ARGUMENT_CBRACKET scope CaseStatment
							| DEFAULT scope
							;	

type:	  TYPE_INT 							{$$=$1;}
			| TYPE_FLOAT  							{$$=$1;}
			| TYPE_CHAR  							{$$=$1;}
			| TYPE_BOOL  							{$$=$1;}
			| TYPE_STRING 							{$$=$1;}
			;

exp:    exp PLUS exp		{$$ = $1 + $3;}
		 |  exp MINUS exp		{$$ = $1 - $3;}
		 |  exp MULTIPLY exp		{$$ = $1 * $3;}
		 |  exp DIVIDE exp		{$$ = $1 / $3;}
		 |  exp MODULUS exp		{$$ = $1 % $3;}
		 |  exp AND exp		{$$ = $1 & $3;}
		 |  exp OR exp		{$$ = $1 | $3;}
		 |  NOT exp								{$$ = !$2;}

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


value:      INTEGER_VALUE   									{$$=$1;}
					| FLOATINPOINT_VALUE   							{$$=$1;}
					| STRING_VALUE  										{$$=$1;}
					| CHARACTER  												{$$=$1;}
					| BOOLEAN_VALUE     								{$$=$1;}
					| IDENTIFIER					  						{$$=$1;}
					;


FuncRet: RET  exp | RET		;											


function: IDENTIFIER ARGUMENT_OBRACKET args ARGUMENT_CBRACKET SCOPE_OBRACE statements FuncRet  SEMICOLON   SCOPE_CBRACE   {printf("function\n");}
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

		

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}