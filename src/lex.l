%{
    #include "y.tab.h"
    #include <stdlib.h>
    void yyerror(char *s);
    int line = 1;
%}

%%
\{                      return SCOPE_OBRACE;
\}                      return SCOPE_CBRACE;
\(						return ARGUMENT_OBRACKET;
\)						return ARGUMENT_CBRACKET;
;                      	return SEMICOLON;
:						return COLON;
,                       return COMMA;


int						{strcpy(yylval.name,strdup(yytext)); return TYPE_INT;}
float					{strcpy(yylval.name,strdup(yytext)); return TYPE_FLOAT; }
char				   	{strcpy(yylval.name,strdup(yytext)); return TYPE_CHAR;}
bool					{strcpy(yylval.name,strdup(yytext)); return TYPE_BOOL;}
const					{strcpy(yylval.name,strdup(yytext)); return TYPE_CONSTANT;}
str 					{strcpy(yylval.name,strdup(yytext)); return TYPE_STRING;   }	

if			  			return IF;
else 					return ELSE;


do						return DO;
while 					return WHILE;
for 					return FOR;
break               	return BREAK;
continue				return CONTINUE;
repeat                  return REPEAT;
until                   return UNTIL;


switch                	return SWITCH;
case                  	return CASE;
default               	return DEFAULT;

false					return FALSE;
true					return TRUE;

echo        			return PRINT;
return                	return RET;

\+ 						{strcpy(yylval.name,strdup(yytext)); return PLUS;}
\- 						{strcpy(yylval.name,strdup(yytext)); return MINUS;}
\* 					   	{strcpy(yylval.name,strdup(yytext)); return MULTIPLY;}
\/ 			            {strcpy(yylval.name,strdup(yytext)); return DIVIDE;}
\%						{strcpy(yylval.name,strdup(yytext)); return MODULUS;}
\= 						{strcpy(yylval.name,strdup(yytext)); return ASSIGN;}

\&						{strcpy(yylval.name,strdup(yytext)); return AND;}
\|						{strcpy(yylval.name,strdup(yytext)); return OR;}
not						{strcpy(yylval.name,strdup(yytext)); return NOT;}

\=\= 		    		return RELATION_EQUALS;
\!\=					return RELATION_NOTEQUAL;
\<						return RELATION_LESS_THAN;
\>						return RELATION_GREATER_THAN;
\<\=   					return RELATION_LESS_EQUAL;
\>\=					return RELATION_GREATER_EQUAL;
and					return RELATION_AND;
or					return RELATION_OR;





-?[0-9]+                                          {strcpy(yylval.name,yytext); return INTEGER_VALUE;}
-?[0-9]+\.[0-9]+                                  {strcpy(yylval.name,yytext); return FLOATINPOINT_VALUE;}
\"[\x23-\x7E =\?!\*()<>+/^%~|&@#;{}.]*\"     	{strcpy(yylval.name,yytext);  return STRING_VALUE;}
\'[\x23-\x7E =\?!\*()<>+/^%~|&@#;{}.]?\'        {strcpy(yylval.name,yytext);  return CHARACTER;}
[a-zA-Z][_a-zA-Z0-9]*   						{strcpy(yylval.name,yytext); return IDENTIFIER;} 	
[\t  ]+                							;
[\n]					                        {yylineno=yylineno+1;}

.                                               { return yytext[0];}


%% 
 int yywrap(void)
{ return 1; } 
