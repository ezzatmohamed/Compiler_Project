%{  
    #include <stdio.h>
		#include "symbol.c"
		#include "operations.c"
		#include "code.c"


    int yylex(void);
    void yyerror(char *);
		

		char Ttype[10];
		char Tval[20];

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
%%

program:
        program statements '\n'
				| statement
        ;

statement:	type IDENTIFIER SEMICOLON   																		{   printf("new_dec : %s   %s \n\n",$2,$1); if(!Declare($2,$1)){return 1;};   printf (" Decleration \n"); }

		| Assignment_Statement
		
		| TYPE_CONSTANT type V ASSIGN exp SEMICOLON 										{  if(!ConstAssign($3.name,$2,$5.val,$5.type)){return 1;}; AssignCode();   printf("Constant Assignment\n");}
		
		/*  Loops */
		| WHILE {LoopBegin();} ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET 	{CheckCondition();} scope {LoopEnd();} 	{printf("While Loop\n");}
		
		| DO 		{LoopBegin();} scope WHILE ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET {CheckCondition();} SEMICOLON					{printf("Do while\n");}

		| FOR 	{LoopBegin();} ARGUMENT_OBRACKET  Assignment_Statement
		  conditions SEMICOLON {CheckCondition();}
		  Assignment_Statement ARGUMENT_CBRACKET
		  scope	ARGUMENT_OBRACKET		Assignment_Statement ARGUMENT_CBRACKET SEMICOLON					{LoopEnd();}																										  {printf("For loop\n");}

		//Repeat

		| REPEAT {LoopBegin();} scope UNTIL ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET {RepeatCondition();} SEMICOLON			{printf("repeat-until loop\n");}

		//=====================================
		
		| IF {IfBegin();} If_statment   


//		| IF { IfBegin(); } ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET {CheckCondition();} scope %prec IFX { IfEnd(); printf("If statement\n"); }

//		| IF { IfBegin(); } ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET {CheckCondition();} scope {Else();} ELSE scope	 {IfEnd(); printf("If-Elsestatement\n");}

//		| SWITCH ARGUMENT_OBRACKET V ARGUMENT_CBRACKET SwitchBody   		  	{printf("Switch case\n");}

		//| PRINT ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET SEMICOLON	                  {printf("Print %d\n",$exp);}
		
		;


//SwitchBody: SCOPE_OBRACE CaseStatment SCOPE_CBRACE
//					;

//CaseStatment : CASE ARGUMENT_OBRACKET INTEGER_VALUE ARGUMENT_CBRACKET {push($3);CaseBegin();} scope CaseStatment
//							| DEFAULT {CaseBegin();}  scope {SwitchEnd();}
//							;	

type:	  TYPE_INT 					{strcpy($$,$1);}
			| TYPE_FLOAT  			{strcpy($$,$1);}
			| TYPE_CHAR  				{strcpy($$,$1);}
			| TYPE_BOOL  				{strcpy($$,$1);}
			| TYPE_STRING 			{strcpy($$,$1);}
			;

Assignment_Statement:		V ASSIGN exp SEMICOLON			{ if(!Assign($1.name,$3.val,$3.type)){return 1;} AssignCode();   printf( "Initilization \n");}



If_statment : ARGUMENT_OBRACKET conditions ARGUMENT_CBRACKET { CheckCondition();} If_else
						;
						
If_else : scope %prec IFX 								 { IfEnd(); printf("If statement\n"); }
						|	scope ELSE {Else();} scope	 {IfEnd(); printf("If-Elsestatement\n");}
						;
conditions:
	 		conditions  RELATION_LESS_THAN exp{ if(!CheckType($1.type,$3.type)){return 1;} push("<");}

    | conditions  RELATION_LESS_EQUAL exp {if(!CheckType($1.type,$3.type)){return 1;}push("<=");}

    | conditions  RELATION_GREATER_EQUAL exp  {if(!CheckType($1.type,$3.type)){return 1;} push(">=");}

    | conditions  RELATION_GREATER_THAN exp  {if(!CheckType($1.type,$3.type)){return 1;} push(">");}

    | conditions  RELATION_NOTEQUAL exp {if(!CheckType($1.type,$3.type)){return 1;} push("!=");}

    | conditions  RELATION_EQUALS exp  {if(!CheckType($1.type,$3.type)){return 1;} push("==");} 

    | exp  													{$$=$1;}
   
    ;
														//(char*x,char*y,char*xType,char*yType,char* val,char*type,char *op)
exp:    exp PLUS exp				{ push("ADD"); OpCode();  
															if( !operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"PLUS") )
															{
																return 1;
															}
															printf("Plus\n");
														}

		 |  exp MINUS exp				{ push("SUB"); OpCode();    
															if( !operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"MINUS") )
															{
																return 1;
															}
															;printf("minus\n");
														}

		 |  exp MULTIPLY exp		{ push("MUL"); OpCode();   
															if( !operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"MULTIPLY") )
															{
																return 1;
															}
															printf("mult\n");
														}

		 |  exp DIVIDE exp			{ push("DIV"); OpCode();    
															if( !operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"DIVIDE") )
															{
																return 1;
															}
															printf("divide\n");
														}

		 |  exp MODULUS exp			{ push("MOD"); OpCode();    
															if( !operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"MODULUS") )
															{
																return 1;
															}
															printf("modulus\n");
														}

		 |  exp AND exp					{ push("AND"); OpCode();    
															if( !operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"AND") )
															{
																return 1;
															}
															printf("bitwise and\n");
														}

		 |  exp OR exp					{ push("OR") ; OpCode();    
															if( !operation($1.val,$3.val,$1.type,$3.type,$$.val,$$.type,"OR") )
															{
																return 1;
															}
															printf("bitwise or\n");
														}

		 |  NOT exp							{ push("NOT"); OpCode();    
															if( !operation($2.val,$2.val,$2.type,$2.type,$$.val,$$.type,"NOT") )
															{
																return 1;
															}
															printf("bitwise not\n");
														}
														
		 | 	ARGUMENT_OBRACKET exp ARGUMENT_CBRACKET 			{$$=$2;}
		 | 	value																				{$$=$1;}
			;


value:      INTEGER_VALUE   									{ push($1); strcpy($$.type,"int"); strcpy($$.val,$1);  }
					| FLOATINPOINT_VALUE   							{	push($1); strcpy($$.type,"float"); strcpy($$.val,$1); }	
					| STRING_VALUE  									  {	push($1); strcpy($$.type,"str"); strcpy($$.val,$1); }
					| CHARACTER  											  { push($1); strcpy($$.type,"char"); strcpy($$.val,$1);}						
					| V																	{ $$=$1;}
					;
V:  IDENTIFIER				{ 					push($1);
																	search($1); 
																	if( current != NULL)
																	{strcpy($$.name,current->value.name); strcpy($$.val,current->value.val); strcpy($$.type,current->value.type);}
																	else 
																	{
																		printf("Error undeclared variable ");
																		return 1;
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
    fprintf(stderr, "%s\n", s);
}

int main(void) {
		ST[CurrentST].head = NULL;
		ST[CurrentST].parent = -1;
    yyparse();
    return 0;
}
