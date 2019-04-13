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
    IF = 271,
    ELSE = 272,
    DO = 273,
    WHILE = 274,
    FOR = 275,
    BREAK = 276,
    CONTINUE = 277,
    REPEAT = 278,
    UNTIL = 279,
    SWITCH = 280,
    CASE = 281,
    FALSE = 282,
    TRUE = 283,
    DEFAULT = 284,
    PRINT = 285,
    RET = 286,
    PLUS = 287,
    MINUS = 288,
    MULTIPLY = 289,
    DIVIDE = 290,
    POWER = 291,
    MODULUS = 292,
    ASSIGN = 293,
    AND = 294,
    OR = 295,
    NOT = 296,
    INCREMENT = 297,
    DECREMENT = 298,
    RELATION_EQUALS = 299,
    RELATION_NOTEQUAL = 300,
    RELATION_LESS_THAN = 301,
    RELATION_GREATER_THAN = 302,
    RELATION_LESS_EQUAL = 303,
    RELATION_GREATER_EQUAL = 304,
    RELATION_AND = 305,
    RELATION_OR = 306,
    INTEGER_VALUE = 307,
    FLOATINPOINT_VALUE = 308,
    STRING_VALUE = 309,
    CHARACTER = 310,
    IDENTIFIER = 311,
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
#define IF 271
#define ELSE 272
#define DO 273
#define WHILE 274
#define FOR 275
#define BREAK 276
#define CONTINUE 277
#define REPEAT 278
#define UNTIL 279
#define SWITCH 280
#define CASE 281
#define FALSE 282
#define TRUE 283
#define DEFAULT 284
#define PRINT 285
#define RET 286
#define PLUS 287
#define MINUS 288
#define MULTIPLY 289
#define DIVIDE 290
#define POWER 291
#define MODULUS 292
#define ASSIGN 293
#define AND 294
#define OR 295
#define NOT 296
#define INCREMENT 297
#define DECREMENT 298
#define RELATION_EQUALS 299
#define RELATION_NOTEQUAL 300
#define RELATION_LESS_THAN 301
#define RELATION_GREATER_THAN 302
#define RELATION_LESS_EQUAL 303
#define RELATION_GREATER_EQUAL 304
#define RELATION_AND 305
#define RELATION_OR 306
#define INTEGER_VALUE 307
#define FLOATINPOINT_VALUE 308
#define STRING_VALUE 309
#define CHARACTER 310
#define IDENTIFIER 311
#define BOOLEAN_VALUE 312
#define IFX 313
#define UMINUS 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
