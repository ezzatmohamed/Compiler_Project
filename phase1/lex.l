%{
    #include "y.tab.h"
    #include <stdlib.h>
    void yyerror(char *);
%}

%%
\{                      return SCOPE_OBRACE;
\}                      return SCOPE_CBRACE;
\(						return ARGUMENT_OBRACKET;
\)						return ARGUMENT_CBRACKET;
;                      	return SEMICOLON;
:						return COLON;
,                       return COMMA;

int						return TYPE_INT;
float					return TYPE_FLOAT;
char				   	return TYPE_CHAR;
bool					return TYPE_BOOL;
const					return TYPE_CONSTANT;
str 					return TYPE_STRING;   	

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

print        			return PRINT;
return                	return RET;

\+ 						return PLUS;
\- 						return MINUS;
\* 					   	return MULTIPLY;
\/ 			            return DIVIDE;
\^                      return POWER;
\%						return MODULUS;
\= 						return ASSIGN;

\&						return AND;
\|						return OR;
\!						return NOT;

\=\= 		    		return RELATION_EQUALS;
\!\=					return RELATION_NOTEQUAL;
\<						return RELATION_LESS_THAN;
\>						return RELATION_GREATER_THAN;
\<\=   					return RELATION_LESS_EQUAL;
\>\=					return RELATION_GREATER_EQUAL;
\&\&					return RELATION_AND;
\|\|					return RELATION_OR;





[0-9]+                  {yylval = atoi(yytext); return INTEGER_VALUE;}
[0-9]+\.[0-9]+          {yylval = atof(yytext); return FLOATINPOINT_VALUE;}
\"[\x23-\x7E =\?!\*()<>+/^%~|&@#;{}.]*\"     	return STRING_VALUE;
\'[\x23-\x7E =\?!\*()<>+/^%~|&@#;{}.]?\'        return CHARACTER;
[_a-zA-Z][_a-zA-Z0-9]*   						return IDENTIFIER; 	
[\t  ]+                							;
[\n]					{yylineno=yylineno+1;}
\(false\|true\)            { return BOOLEAN_VALUE;}




%% 
 int yywrap(void)
{ return 1; } 