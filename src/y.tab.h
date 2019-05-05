/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 16 "yacc.y" /* yacc.c:1921  */

    
		struct ExpInfo {
	  char type[10];
		char val[100];
		char name[50];
		};

#line 57 "y.tab.h" /* yacc.c:1921  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SCOPE_OBRACE = 258,
    SCOPE_CBRACE = 259,
    ARGUMENT_OBRACKET = 260,
    ARGUMENT_CBRACKET = 261,
    SEMICOLON = 262,
    COLON = 263,
    COMMA = 264,
    TYPE_INT = 265,
    TYPE_FLOAT = 266,
    TYPE_CHAR = 267,
    TYPE_BOOL = 268,
    TYPE_CONSTANT = 269,
    TYPE_STRING = 270,
    IDENTIFIER = 271,
    IF = 272,
    ELSE = 273,
    DO = 274,
    WHILE = 275,
    FOR = 276,
    BREAK = 277,
    CONTINUE = 278,
    REPEAT = 279,
    UNTIL = 280,
    SWITCH = 281,
    CASE = 282,
    FALSE = 283,
    TRUE = 284,
    DEFAULT = 285,
    PRINT = 286,
    RET = 287,
    PLUS = 288,
    MINUS = 289,
    MULTIPLY = 290,
    DIVIDE = 291,
    POWER = 292,
    MODULUS = 293,
    ASSIGN = 294,
    AND = 295,
    OR = 296,
    NOT = 297,
    INCREMENT = 298,
    DECREMENT = 299,
    RELATION_EQUALS = 300,
    RELATION_NOTEQUAL = 301,
    RELATION_LESS_THAN = 302,
    RELATION_GREATER_THAN = 303,
    RELATION_LESS_EQUAL = 304,
    RELATION_GREATER_EQUAL = 305,
    RELATION_AND = 306,
    RELATION_OR = 307,
    INTEGER_VALUE = 308,
    FLOATINPOINT_VALUE = 309,
    STRING_VALUE = 310,
    CHARACTER = 311,
    BOOLEAN_VALUE = 312,
    IFX = 313,
    UMINUS = 314
  };
#endif
/* Tokens.  */
#define SCOPE_OBRACE 258
#define SCOPE_CBRACE 259
#define ARGUMENT_OBRACKET 260
#define ARGUMENT_CBRACKET 261
#define SEMICOLON 262
#define COLON 263
#define COMMA 264
#define TYPE_INT 265
#define TYPE_FLOAT 266
#define TYPE_CHAR 267
#define TYPE_BOOL 268
#define TYPE_CONSTANT 269
#define TYPE_STRING 270
#define IDENTIFIER 271
#define IF 272
#define ELSE 273
#define DO 274
#define WHILE 275
#define FOR 276
#define BREAK 277
#define CONTINUE 278
#define REPEAT 279
#define UNTIL 280
#define SWITCH 281
#define CASE 282
#define FALSE 283
#define TRUE 284
#define DEFAULT 285
#define PRINT 286
#define RET 287
#define PLUS 288
#define MINUS 289
#define MULTIPLY 290
#define DIVIDE 291
#define POWER 292
#define MODULUS 293
#define ASSIGN 294
#define AND 295
#define OR 296
#define NOT 297
#define INCREMENT 298
#define DECREMENT 299
#define RELATION_EQUALS 300
#define RELATION_NOTEQUAL 301
#define RELATION_LESS_THAN 302
#define RELATION_GREATER_THAN 303
#define RELATION_LESS_EQUAL 304
#define RELATION_GREATER_EQUAL 305
#define RELATION_AND 306
#define RELATION_OR 307
#define INTEGER_VALUE 308
#define FLOATINPOINT_VALUE 309
#define STRING_VALUE 310
#define CHARACTER 311
#define BOOLEAN_VALUE 312
#define IFX 313
#define UMINUS 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "yacc.y" /* yacc.c:1921  */

	char name[20];

	int iVal;
	float fVal;

	struct ExpInfo info;

#line 196 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
