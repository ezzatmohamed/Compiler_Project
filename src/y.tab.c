/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y" /* yacc.c:337  */
  
    #include <stdio.h>
		#include "includes/symbol.c"
		#include "includes/operations.c"
		#include "includes/code.c"

		int yylineno;
		extern char *yytext; 
    int yylex(void);
    void yyerror(char *);
		

#line 83 "y.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 13 "yacc.y" /* yacc.c:352  */

    
		struct ExpInfo {
	  char type[10];
		char val[100];
		char name[50];
		};

#line 125 "y.tab.c" /* yacc.c:352  */

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
#line 23 "yacc.y" /* yacc.c:352  */

	char name[20];

	int iVal;
	float fVal;

	struct ExpInfo info;

#line 264 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

#define YYUNDEFTOK  2
#define YYMAXUTOK   314

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      60,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    64,    67,    69,    71,    74,    74,    74,
      76,    76,    76,    78,    79,    78,    85,    85,    85,    89,
      89,    93,    93,    95,    99,   102,   102,   102,   103,   103,
     106,   107,   108,   109,   110,   113,   117,   117,   120,   121,
     121,   124,   126,   128,   130,   132,   134,   136,   140,   144,
     149,   154,   158,   162,   166,   170,   174,   178,   179,   183,
     184,   185,   186,   187,   201,   213,   214,   217,   218
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SCOPE_OBRACE", "SCOPE_CBRACE",
  "ARGUMENT_OBRACKET", "ARGUMENT_CBRACKET", "SEMICOLON", "COLON", "COMMA",
  "TYPE_INT", "TYPE_FLOAT", "TYPE_CHAR", "TYPE_BOOL", "TYPE_CONSTANT",
  "TYPE_STRING", "IDENTIFIER", "IF", "ELSE", "DO", "WHILE", "FOR", "BREAK",
  "CONTINUE", "REPEAT", "UNTIL", "SWITCH", "CASE", "FALSE", "TRUE",
  "DEFAULT", "PRINT", "RET", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "POWER", "MODULUS", "ASSIGN", "AND", "OR", "NOT", "INCREMENT",
  "DECREMENT", "RELATION_EQUALS", "RELATION_NOTEQUAL",
  "RELATION_LESS_THAN", "RELATION_GREATER_THAN", "RELATION_LESS_EQUAL",
  "RELATION_GREATER_EQUAL", "RELATION_AND", "RELATION_OR", "INTEGER_VALUE",
  "FLOATINPOINT_VALUE", "STRING_VALUE", "CHARACTER", "BOOLEAN_VALUE",
  "IFX", "UMINUS", "'\\n'", "$accept", "program", "statement", "$@1",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "SwitchBody", "CaseStatment", "$@11", "$@12", "$@13", "type",
  "Assignment_Statement", "If_statment", "$@14", "If_else", "$@15",
  "conditions", "exp", "value", "V", "statements", "scope", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      10
};
# endif

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     229,   -52,   -52,   -52,   -52,    65,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,     4,    11,   160,   -52,   -11,   -52,   -10,
      -5,    26,    29,    30,    32,    29,    -5,   -52,   -52,   -52,
     107,    27,     1,    -1,     1,   -52,   183,    20,     1,    -5,
      19,    35,   -52,   -52,   -52,     1,     1,   -52,   -52,   -52,
     -52,   118,   -52,   -52,     1,     8,   224,   -52,   206,    40,
      13,     1,    41,   -52,   109,   242,   -52,     1,     1,     1,
       1,     1,     1,     1,   128,   -52,     1,     1,     1,     1,
       1,     1,     1,   -52,     1,   -52,     9,     1,    44,   -52,
     -28,   -28,   -17,   -17,   -17,   242,   242,   -52,    29,   -52,
     242,   242,   242,   242,   242,   242,    15,    29,   -52,    16,
      -2,   -52,   -52,    33,   -52,   -52,    -5,   -52,    43,   -52,
      48,   -52,    58,    62,    63,    28,    29,   -52,    29,   -52,
      29,   -52,    66,   -52,   -52,    64,   -52,    -5,    29,    67,
     -52,    75,    -2,   -52,   -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    30,    31,    32,    33,     0,    34,    64,    19,    10,
       7,    13,    16,     0,     0,     0,     3,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     1,    65,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     2,    66,     4,     0,     0,    59,    60,    61,
      62,     0,    58,    63,     0,     0,    48,    67,     0,     0,
       0,     0,     0,    21,     0,    56,    35,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     8,     0,     0,     0,    57,
      49,    50,    51,    52,    53,    54,    55,     6,     0,    47,
      46,    45,    41,    44,    42,    43,     0,     0,    14,     0,
       0,    22,    37,    38,    11,     9,     0,    17,     0,    28,
       0,    39,     0,     0,     0,     0,     0,    24,     0,    12,
       0,    18,     0,    29,    40,     0,    25,     0,     0,     0,
      26,     0,     0,    15,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,     3,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -51,   -52,   -52,   -52,    87,   -37,
     -52,   -52,   -52,   -52,   -34,    17,   -52,     0,    57,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    29,    23,   107,    22,   122,    24,   116,    25,
     124,    21,    88,   111,   120,   138,   142,   126,    17,    18,
      35,    98,   112,   128,    55,    56,    52,    53,    30,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      19,    40,    61,    16,    60,    31,    45,    69,    70,    26,
      71,     7,    72,    73,    75,    19,   108,     7,    27,    85,
      33,   114,   117,    72,    73,   118,    41,    86,   119,    32,
      19,    34,    36,    43,    44,    38,    19,    39,    54,    19,
      59,    63,    99,    46,    62,    84,    87,   110,   125,    51,
     106,   121,   127,   109,    47,    48,    49,    50,    19,    76,
      76,    43,    64,    65,    76,   129,    76,    76,   130,   137,
     131,    74,   136,   141,   113,     1,     2,     3,     4,   123,
       6,   132,   143,   115,    90,    91,    92,    93,    94,    95,
      96,   144,    20,    58,   100,   101,   102,   103,   104,   105,
     139,     0,   133,     0,   134,     0,   135,     0,     0,     0,
       0,     0,     0,     0,   140,    89,    19,     1,     2,     3,
       4,     5,     6,     7,     8,    66,     9,    10,    11,     0,
       0,    12,     0,    13,     0,    97,     0,    19,     0,    14,
       0,     0,    67,    68,    69,    70,     0,    71,     0,    72,
      73,    67,    68,    69,    70,     0,    71,     0,    72,    73,
      28,    67,    68,    69,    70,     0,    71,    42,    72,    73,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
      10,    11,     0,     0,    12,     0,    13,    57,     0,     0,
       0,     0,    14,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,    10,    11,     0,     0,    12,     0,    13,
      83,     0,     0,     0,     0,    14,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,    10,    11,     0,     0,
      12,     0,    13,     0,     0,     0,     0,     0,    14,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,    10,
      11,     0,     0,    12,     0,    13,     0,    67,    68,    69,
      70,    14,    71,     0,    72,    73,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    67,    68,    69,    70,     0,
      71,     0,    72,    73
};

static const yytype_int16 yycheck[] =
{
       0,    25,    39,     0,    38,    16,     5,    35,    36,     5,
      38,    16,    40,    41,     6,    15,     7,    16,     7,     6,
      20,     6,     6,    40,    41,    27,    26,    61,    30,    39,
      30,     5,     3,    30,     7,     5,    36,     5,    39,    39,
      20,     6,    76,    42,    25,     5,     5,     3,     5,    32,
      84,    18,     4,    87,    53,    54,    55,    56,    58,    51,
      51,    58,    45,    46,    51,     7,    51,    51,     6,     5,
       7,    54,     6,     6,    98,    10,    11,    12,    13,   116,
      15,    53,     7,   107,    67,    68,    69,    70,    71,    72,
      73,   142,     5,    36,    77,    78,    79,    80,    81,    82,
     137,    -1,   126,    -1,   128,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,     6,   116,    10,    11,    12,
      13,    14,    15,    16,    17,     7,    19,    20,    21,    -1,
      -1,    24,    -1,    26,    -1,     7,    -1,   137,    -1,    32,
      -1,    -1,    33,    34,    35,    36,    -1,    38,    -1,    40,
      41,    33,    34,    35,    36,    -1,    38,    -1,    40,    41,
       0,    33,    34,    35,    36,    -1,    38,    60,    40,    41,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    -1,    -1,    24,    -1,    26,     4,    -1,    -1,
      -1,    -1,    32,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    24,    -1,    26,
       4,    -1,    -1,    -1,    -1,    32,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    -1,    -1,
      24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    -1,    -1,    24,    -1,    26,    -1,    33,    34,    35,
      36,    32,    38,    -1,    40,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    33,    34,    35,    36,    -1,
      38,    -1,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    17,    19,
      20,    21,    24,    26,    32,    62,    63,    79,    80,    88,
      79,    72,    66,    64,    68,    70,     5,     7,     0,    63,
      89,    16,    39,    88,     5,    81,     3,    90,     5,     5,
      90,    88,    60,    63,     7,     5,    42,    53,    54,    55,
      56,    86,    87,    88,    39,    85,    86,     4,    89,    20,
      85,    80,    25,     6,    86,    86,     7,    33,    34,    35,
      36,    38,    40,    41,    86,     6,    51,    45,    46,    47,
      48,    49,    50,     4,     5,     6,    85,     5,    73,     6,
      86,    86,    86,    86,    86,    86,    86,     7,    82,    85,
      86,    86,    86,    86,    86,    86,    85,    65,     7,    85,
       3,    74,    83,    90,     6,    90,    69,     6,    27,    30,
      75,    18,    67,    80,    71,     5,    78,     4,    84,     7,
       6,     7,    53,    90,    90,    90,     6,     5,    76,    80,
      90,     6,    77,     7,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    63,    64,    65,    63,
      66,    67,    63,    68,    69,    63,    70,    71,    63,    72,
      63,    73,    63,    63,    74,    76,    77,    75,    78,    75,
      79,    79,    79,    79,    79,    80,    82,    81,    83,    84,
      83,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    87,    88,    89,    89,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     3,     1,     6,     0,     0,     7,
       0,     0,     9,     0,     0,    14,     0,     0,     9,     0,
       3,     0,     6,     2,     3,     0,     0,     8,     0,     3,
       1,     1,     1,     1,     1,     4,     0,     5,     1,     0,
       4,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 67 "yacc.y" /* yacc.c:1652  */
    {Declare((yyvsp[-1].name),(yyvsp[-2].name),yylineno);    }
#line 1490 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 71 "yacc.y" /* yacc.c:1652  */
    {  if(ConstAssign((yyvsp[-3].info).name,(yyvsp[-4].name),(yyvsp[-1].info).val,(yyvsp[-1].info).type,yylineno)){ AssignCode();   }}
#line 1496 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 74 "yacc.y" /* yacc.c:1652  */
    {NewScope(); LoopBegin();}
#line 1502 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 74 "yacc.y" /* yacc.c:1652  */
    {CheckCondition();}
#line 1508 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 74 "yacc.y" /* yacc.c:1652  */
    {LoopEnd(); EndScope();}
#line 1514 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 76 "yacc.y" /* yacc.c:1652  */
    {NewScope(); LoopBegin();}
#line 1520 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 76 "yacc.y" /* yacc.c:1652  */
    {CheckCondition(); }
#line 1526 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 76 "yacc.y" /* yacc.c:1652  */
    {LoopEnd(); EndScope(); }
#line 1532 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 78 "yacc.y" /* yacc.c:1652  */
    {NewScope(); LoopBegin();}
#line 1538 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 79 "yacc.y" /* yacc.c:1652  */
    {CheckCondition();}
#line 1544 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 81 "yacc.y" /* yacc.c:1652  */
    {LoopEnd(); EndScope();}
#line 1550 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 85 "yacc.y" /* yacc.c:1652  */
    {NewScope();LoopBegin();}
#line 1556 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 85 "yacc.y" /* yacc.c:1652  */
    {RepeatCondition();}
#line 1562 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 85 "yacc.y" /* yacc.c:1652  */
    { LoopEnd(); EndScope(); }
#line 1568 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 89 "yacc.y" /* yacc.c:1652  */
    {NewScope(); IfBegin();}
#line 1574 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 93 "yacc.y" /* yacc.c:1652  */
    {if(strcmp((yyvsp[-1].info).type,"int") != 0 && strcmp((yyvsp[-1].info).type,"Cint")!= 0){fprintf(ErrorFile,"Error at line %d : Switch accpets integers only !\n",yylineno);}cases[++caseTop] = caseEnd; caseEnd++; }
#line 1580 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 95 "yacc.y" /* yacc.c:1652  */
    {return  1;}
#line 1586 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 102 "yacc.y" /* yacc.c:1652  */
    { push((yyvsp[-1].name));CaseBegin();}
#line 1592 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 102 "yacc.y" /* yacc.c:1652  */
    { CaseEnd();}
#line 1598 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 103 "yacc.y" /* yacc.c:1652  */
    {DefaultCase();}
#line 1604 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 103 "yacc.y" /* yacc.c:1652  */
    {SwitchEnd();}
#line 1610 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 106 "yacc.y" /* yacc.c:1652  */
    {strcpy((yyval.name),(yyvsp[0].name));}
#line 1616 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 107 "yacc.y" /* yacc.c:1652  */
    {strcpy((yyval.name),(yyvsp[0].name));}
#line 1622 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 108 "yacc.y" /* yacc.c:1652  */
    {strcpy((yyval.name),(yyvsp[0].name));}
#line 1628 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 109 "yacc.y" /* yacc.c:1652  */
    {strcpy((yyval.name),(yyvsp[0].name));}
#line 1634 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 110 "yacc.y" /* yacc.c:1652  */
    {strcpy((yyval.name),(yyvsp[0].name));}
#line 1640 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 113 "yacc.y" /* yacc.c:1652  */
    { if(Assign((yyvsp[-3].info).name,(yyvsp[-1].info).val,(yyvsp[-1].info).type,yylineno)){ AssignCode(); }}
#line 1646 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 117 "yacc.y" /* yacc.c:1652  */
    { CheckCondition();}
#line 1652 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 120 "yacc.y" /* yacc.c:1652  */
    { IfEnd();  EndScope();  }
#line 1658 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 121 "yacc.y" /* yacc.c:1652  */
    {Else();}
#line 1664 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 121 "yacc.y" /* yacc.c:1652  */
    { IfEnd();  EndScope();  }
#line 1670 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 124 "yacc.y" /* yacc.c:1652  */
    { if(CheckType((yyvsp[-2].info).type,(yyvsp[0].info).type,yylineno)){  push("<");}}
#line 1676 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 126 "yacc.y" /* yacc.c:1652  */
    {if(CheckType((yyvsp[-2].info).type,(yyvsp[0].info).type,yylineno)){push("<=");}}
#line 1682 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 128 "yacc.y" /* yacc.c:1652  */
    {if(CheckType((yyvsp[-2].info).type,(yyvsp[0].info).type,yylineno)){push(">=");}}
#line 1688 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 130 "yacc.y" /* yacc.c:1652  */
    {if(CheckType((yyvsp[-2].info).type,(yyvsp[0].info).type,yylineno)){ push(">");}}
#line 1694 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 132 "yacc.y" /* yacc.c:1652  */
    {if(CheckType((yyvsp[-2].info).type,(yyvsp[0].info).type,yylineno)){ push("!=");}}
#line 1700 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 134 "yacc.y" /* yacc.c:1652  */
    {if(CheckType((yyvsp[-2].info).type,(yyvsp[0].info).type,yylineno)){push("==");}}
#line 1706 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 136 "yacc.y" /* yacc.c:1652  */
    { CheckCondition(); }
#line 1712 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 140 "yacc.y" /* yacc.c:1652  */
    {(yyval.info)=(yyvsp[0].info);}
#line 1718 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 144 "yacc.y" /* yacc.c:1652  */
    { push("ADD"); OpCode();  
														 operation((yyvsp[-2].info).val,(yyvsp[0].info).val,(yyvsp[-2].info).type,(yyvsp[0].info).type,(yyval.info).val,(yyval.info).type,"PLUS",yylineno);
														
														}
#line 1727 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 149 "yacc.y" /* yacc.c:1652  */
    { push("SUB"); OpCode();    
														 !operation((yyvsp[-2].info).val,(yyvsp[0].info).val,(yyvsp[-2].info).type,(yyvsp[0].info).type,(yyval.info).val,(yyval.info).type,"MINUS",yylineno);
															
														}
#line 1736 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 154 "yacc.y" /* yacc.c:1652  */
    { push("MUL"); OpCode();   
														operation((yyvsp[-2].info).val,(yyvsp[0].info).val,(yyvsp[-2].info).type,(yyvsp[0].info).type,(yyval.info).val,(yyval.info).type,"MULTIPLY",yylineno);
														}
#line 1744 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 158 "yacc.y" /* yacc.c:1652  */
    { push("DIV"); OpCode();    
															operation((yyvsp[-2].info).val,(yyvsp[0].info).val,(yyvsp[-2].info).type,(yyvsp[0].info).type,(yyval.info).val,(yyval.info).type,"DIVIDE",yylineno);
														}
#line 1752 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 162 "yacc.y" /* yacc.c:1652  */
    { push("MOD"); OpCode();    
															operation((yyvsp[-2].info).val,(yyvsp[0].info).val,(yyvsp[-2].info).type,(yyvsp[0].info).type,(yyval.info).val,(yyval.info).type,"MODULUS",yylineno);
														}
#line 1760 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 166 "yacc.y" /* yacc.c:1652  */
    { push("AND"); OpCode();    
															operation((yyvsp[-2].info).val,(yyvsp[0].info).val,(yyvsp[-2].info).type,(yyvsp[0].info).type,(yyval.info).val,(yyval.info).type,"AND",yylineno);
														}
#line 1768 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 170 "yacc.y" /* yacc.c:1652  */
    { push("OR") ; OpCode();    
															operation((yyvsp[-2].info).val,(yyvsp[0].info).val,(yyvsp[-2].info).type,(yyvsp[0].info).type,(yyval.info).val,(yyval.info).type,"OR",yylineno);
														}
#line 1776 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 174 "yacc.y" /* yacc.c:1652  */
    { push("NOT"); OpCode();    
															operation((yyvsp[0].info).val,(yyvsp[0].info).val,(yyvsp[0].info).type,(yyvsp[0].info).type,(yyval.info).val,(yyval.info).type,"NOT",yylineno);
														}
#line 1784 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 178 "yacc.y" /* yacc.c:1652  */
    {(yyval.info)=(yyvsp[-1].info);}
#line 1790 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 179 "yacc.y" /* yacc.c:1652  */
    {(yyval.info)=(yyvsp[0].info);}
#line 1796 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 183 "yacc.y" /* yacc.c:1652  */
    { push((yyvsp[0].name)); strcpy((yyval.info).type,"int"); strcpy((yyval.info).val,(yyvsp[0].name));  }
#line 1802 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 184 "yacc.y" /* yacc.c:1652  */
    {	push((yyvsp[0].name)); strcpy((yyval.info).type,"float"); strcpy((yyval.info).val,(yyvsp[0].name)); }
#line 1808 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 185 "yacc.y" /* yacc.c:1652  */
    {	push((yyvsp[0].name)); strcpy((yyval.info).type,"str"); strcpy((yyval.info).val,(yyvsp[0].name)); }
#line 1814 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 186 "yacc.y" /* yacc.c:1652  */
    { push((yyvsp[0].name)); strcpy((yyval.info).type,"char"); strcpy((yyval.info).val,(yyvsp[0].name));}
#line 1820 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 187 "yacc.y" /* yacc.c:1652  */
    { (yyval.info)=(yyvsp[0].info);

																									search((yyvsp[0].info).name);
																									if( current == NULL)
																									{
																										fprintf(ErrorFile,"Error at line %d : undeclared Variable !\n",yylineno);
																									}
																									else if(strcmp(current->value.val,"NULL") == 0)	
																									{
																										fprintf(ErrorFile,"Error at line %d : uninitialized Variable !\n",yylineno);
																									}

																							}
#line 1838 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 201 "yacc.y" /* yacc.c:1652  */
    { 					push((yyvsp[0].name));
																	search((yyvsp[0].name)); 
																	if( current != NULL)
																	{
																		strcpy((yyval.info).name,current->value.name); strcpy((yyval.info).val,current->value.val); strcpy((yyval.info).type,current->value.type);}
																	else 
																	{
																		strcpy((yyval.info).name,(yyvsp[0].name)); strcpy((yyval.info).val,"NULL");
																		
																	}
															}
#line 1854 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1858 "y.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 223 "yacc.y" /* yacc.c:1918  */


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
