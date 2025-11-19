/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     FLOAT_NUM = 259,
     ID = 260,
     INT = 261,
     DOUBLE = 262,
     PRINT = 263,
     WHILE = 264,
     FOR = 265,
     IF = 266,
     ELSE = 267,
     VOID = 268,
     RETURN = 269,
     MAIN = 270,
     LBRACE = 271,
     RBRACE = 272,
     LPAREN = 273,
     RPAREN = 274,
     LBRACKET = 275,
     RBRACKET = 276,
     COMMA = 277,
     AND = 278,
     OR = 279,
     NOT = 280,
     EQ = 281,
     IS = 282,
     SWITCH = 283,
     CASE = 284,
     DEFAULT = 285,
     BREAK = 286,
     COLON = 287
   };
#endif
/* Tokens.  */
#define NUM 258
#define FLOAT_NUM 259
#define ID 260
#define INT 261
#define DOUBLE 262
#define PRINT 263
#define WHILE 264
#define FOR 265
#define IF 266
#define ELSE 267
#define VOID 268
#define RETURN 269
#define MAIN 270
#define LBRACE 271
#define RBRACE 272
#define LPAREN 273
#define RPAREN 274
#define LBRACKET 275
#define RBRACKET 276
#define COMMA 277
#define AND 278
#define OR 279
#define NOT 280
#define EQ 281
#define IS 282
#define SWITCH 283
#define CASE 284
#define DEFAULT 285
#define BREAK 286
#define COLON 287




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

/* SYNTAX ANALYZER (PARSER)
 * Enhanced with proper global and function scope support
 * This version allows global declarations and function definitions
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;  /* Line number from scanner */

void yyerror(const char* s);
ASTNode* root = NULL;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "parser.y"
{
    int num;
    double fnum;
    char* str;
    struct ASTNode* node;
}
/* Line 193 of yacc.c.  */
#line 186 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 199 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   868

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  229

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    39,     2,     2,
       2,     2,    37,    35,     2,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      33,    41,    34,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    13,    15,    18,    22,
      26,    32,    39,    49,    51,    54,    63,    72,    80,    88,
      91,    94,    99,   104,   105,   107,   110,   112,   114,   116,
     118,   120,   122,   124,   127,   131,   134,   140,   145,   149,
     153,   159,   166,   176,   181,   189,   200,   202,   204,   206,
     210,   214,   218,   222,   226,   230,   234,   238,   242,   246,
     249,   253,   257,   262,   270,   275,   279,   283,   289,   295,
     303,   317,   333,   339,   347,   355,   365,   375,   387,   395,
     397,   400,   405,   409,   413,   416,   418
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    46,    -1,    46,    -1,    49,    -1,
      44,    49,    -1,    45,    -1,    44,    45,    -1,     6,     5,
      40,    -1,     7,     5,    40,    -1,     6,     5,    41,    53,
      40,    -1,     6,     5,    20,     3,    21,    40,    -1,     6,
       5,    20,     3,    21,    20,     3,    21,    40,    -1,    47,
      -1,    46,    47,    -1,     6,     5,    18,    48,    19,    16,
      49,    17,    -1,    13,     5,    18,    48,    19,    16,    49,
      17,    -1,     6,    15,    18,    19,    16,    49,    17,    -1,
      13,    15,    18,    19,    16,    49,    17,    -1,     6,     5,
      -1,     7,     5,    -1,    48,    22,     6,     5,    -1,    48,
      22,     7,     5,    -1,    -1,    50,    -1,    49,    50,    -1,
      51,    -1,    52,    -1,    54,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    31,    40,    -1,    14,    53,    40,
      -1,    14,    40,    -1,     5,    18,    53,    19,    40,    -1,
       5,    18,    19,    40,    -1,     6,     5,    40,    -1,     7,
       5,    40,    -1,     6,     5,    41,    53,    40,    -1,     6,
       5,    20,     3,    21,    40,    -1,     6,     5,    20,     3,
      21,    20,     3,    21,    40,    -1,     5,    41,    53,    40,
      -1,     5,    20,    53,    21,    41,    53,    40,    -1,     5,
      20,    53,    21,    20,    53,    21,    41,    53,    40,    -1,
       3,    -1,     4,    -1,     5,    -1,    53,    35,    53,    -1,
      53,    36,    53,    -1,    53,    37,    53,    -1,    53,    38,
      53,    -1,    53,    39,    53,    -1,    53,    33,    53,    -1,
      53,    34,    53,    -1,    53,    26,    53,    -1,    53,    23,
      53,    -1,    53,    24,    53,    -1,    25,    53,    -1,    18,
      53,    19,    -1,    16,    49,    17,    -1,     5,    20,    53,
      21,    -1,     5,    20,    53,    21,    20,    53,    21,    -1,
       5,    18,    53,    19,    -1,     5,    18,    19,    -1,    53,
      27,    61,    -1,     8,    18,    53,    19,    40,    -1,     9,
      18,    53,    19,    50,    -1,     9,    18,    53,    19,    16,
      49,    17,    -1,    10,    18,     5,    41,    53,    40,    53,
      40,     5,    41,    53,    19,    50,    -1,    10,    18,     5,
      41,    53,    40,    53,    40,     5,    41,    53,    19,    16,
      49,    17,    -1,    11,    18,    53,    19,    50,    -1,    11,
      18,    53,    19,    16,    49,    17,    -1,    11,    18,    53,
      19,    50,    12,    50,    -1,    11,    18,    53,    19,    16,
      49,    17,    12,    50,    -1,    11,    18,    53,    19,    50,
      12,    16,    49,    17,    -1,    11,    18,    53,    19,    16,
      49,    17,    12,    16,    49,    17,    -1,    28,    18,    53,
      19,    16,    59,    17,    -1,    60,    -1,    60,    59,    -1,
      29,     3,    32,    49,    -1,    29,     3,    32,    -1,    30,
      32,    49,    -1,    30,    32,    -1,    53,    -1,    53,    22,
      61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    67,    72,    78,    88,    91,    97,   102,
     107,   112,   117,   129,   132,   138,   143,   148,   152,   160,
     164,   168,   172,   176,   186,   189,   195,   196,   197,   198,
     199,   200,   201,   202,   205,   208,   211,   216,   225,   229,
     233,   237,   241,   249,   253,   257,   268,   271,   274,   278,
     281,   284,   287,   290,   293,   296,   299,   302,   305,   308,
     312,   315,   318,   322,   326,   331,   336,   344,   351,   354,
     361,   368,   378,   381,   384,   387,   390,   393,   400,   406,
     409,   416,   419,   422,   425,   432,   436
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "FLOAT_NUM", "ID", "INT",
  "DOUBLE", "PRINT", "WHILE", "FOR", "IF", "ELSE", "VOID", "RETURN",
  "MAIN", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "COMMA", "AND", "OR", "NOT", "EQ", "IS", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "COLON", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'",
  "'='", "$accept", "program", "global_decl_list", "global_decl",
  "function_list", "function_decl", "param_list", "stmt_list", "stmt",
  "decl", "assign", "expr", "print_stmt", "while_stmt", "for_stmt",
  "if_stmt", "switch_stmt", "case_list", "case_stmt", "value_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    60,    62,    43,    45,    42,    47,    37,
      59,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    44,    44,    45,    45,
      45,    45,    45,    46,    46,    47,    47,    47,    47,    48,
      48,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      51,    51,    51,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    58,    59,
      59,    60,    60,    60,    60,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     2,     3,     3,
       5,     6,     9,     1,     2,     8,     8,     7,     7,     2,
       2,     4,     4,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     5,     4,     3,     3,
       5,     6,     9,     4,     7,    10,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     4,     7,     4,     3,     3,     5,     5,     7,
      13,    15,     5,     7,     7,     9,     9,    11,     7,     1,
       2,     4,     3,     3,     2,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     3,    13,     4,    24,    26,
      27,    28,    29,    30,    31,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,    35,     0,     0,    33,     1,     7,
       2,     5,     0,    14,     0,     0,    25,     0,     0,     0,
       0,    23,     0,     8,     0,     0,     9,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,    37,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,    61,    60,    57,    58,    56,    85,    66,
      54,    55,    49,    50,    51,    52,    53,     0,     0,    38,
       0,    39,    36,     0,     0,    19,    20,     0,     0,     0,
      10,     0,    67,     0,    68,     0,     0,    72,     0,     0,
      64,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,     0,     0,    79,     0,    40,     0,    44,
       0,    21,    22,     0,    17,    69,     0,    73,     0,    74,
       0,    18,     0,     0,    84,    78,    80,     0,    41,     0,
      15,     0,     0,     0,     0,    16,    63,    82,    83,     0,
       0,    12,     0,     0,    75,    76,    81,     0,    45,     0,
       0,    42,     0,    77,     0,     0,    70,     0,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,   100,    17,    18,    19,
      20,   118,    21,    22,    23,    24,    25,   174,   175,   119
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -19
static const yytype_int16 yypact[] =
{
      76,   -15,     2,    10,    41,    43,    49,    55,    35,    28,
      84,    15,   105,    76,   -19,     0,   -19,   159,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,    44,   410,   410,    -4,
      88,    68,   410,   410,   110,   410,    98,   103,   -19,   -19,
      25,   159,   410,   410,   -19,   653,   410,   -19,   -19,   -19,
       0,   159,    37,   -19,   122,   124,   -19,    91,   413,   579,
     671,     4,   129,   134,   410,   116,   144,   434,   455,   106,
     476,     4,   130,   406,   410,    86,   497,   829,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   -19,
     518,   133,   -18,   112,   -19,   113,   -12,   -19,   145,   149,
     -10,   135,   689,   142,   119,   132,   410,   199,    32,   155,
     -19,   539,   598,   -19,   -19,   829,   815,    74,   708,   -19,
      74,    74,   147,   147,   151,   151,   151,   156,   158,   -19,
     410,   -19,   -19,   410,   410,   -19,   -19,   167,    51,     1,
     188,   159,   -19,   159,   -19,   725,   159,   177,   176,   159,
     -19,   175,   410,    94,   178,   743,   617,   761,   159,   191,
     192,   195,   201,   236,   249,   410,   264,   277,   159,   292,
     410,   -19,   211,   170,   202,    94,    79,   -19,   179,   -19,
     305,   -19,   -19,   197,   -19,   -19,   779,   210,   159,   -19,
     320,   -19,   636,   193,   159,   -19,   -19,   220,   -19,   410,
     -19,   184,   221,   333,   348,   -19,   -19,   159,   159,   207,
     797,   231,   194,   159,   -19,   -19,   159,   196,   -19,   410,
     361,   -19,   560,   -19,   377,   159,   -19,   389,   -19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -19,   -19,   -19,   219,   225,   -11,   163,   -13,    13,   -19,
     -19,    -8,   -19,   -19,   -19,   -19,   -19,    64,   -19,    96
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -43
static const yytype_int16 yytable[] =
{
      51,    45,   128,    26,    53,    27,    52,    29,   133,   137,
      98,    99,   138,     8,    61,    31,    62,    30,    58,    59,
      60,   161,   129,   130,    67,    68,    28,    70,    75,   134,
      56,    38,    39,    40,    76,    77,    63,    64,    90,    53,
      36,   162,    91,    73,    41,    74,    42,    38,    39,    40,
      37,   148,    30,    43,   138,    47,   102,   159,   160,    32,
      41,    33,    42,    57,    56,   111,   112,    34,    44,    43,
     115,   116,   117,    35,   120,   121,   122,   123,   124,   125,
     126,     1,     2,     3,     4,     5,     6,     7,    56,     8,
       9,     1,    54,    55,     4,     5,     6,     7,   145,   197,
       9,    81,    46,   113,    10,    48,    65,    11,    66,    84,
      85,    86,    87,    88,    10,    69,    71,    11,   144,   198,
     147,    72,   155,   172,   173,   156,   157,    92,   163,    93,
     164,    94,   101,   166,   -38,   103,   169,     1,    54,    55,
       4,     5,     6,     7,   -39,   180,     9,   106,   143,   109,
     135,    61,   131,   132,   136,   190,   139,   186,   141,   142,
      10,   154,   192,    11,     1,    54,    55,     4,     5,     6,
       7,   149,   153,     9,    81,   204,    56,    56,    81,    56,
     189,   208,    56,   158,    86,    87,    88,    10,   -40,   167,
      11,   210,   168,    56,   216,   170,   181,   182,   183,   176,
     220,   -41,   194,    56,     1,    54,    55,     4,     5,     6,
       7,   222,   227,     9,   193,   146,   214,    56,   201,   195,
     199,    56,   203,   209,   211,   207,   212,    10,   217,    56,
      11,   -42,    49,    56,   108,   219,   221,   226,    50,   196,
      56,     1,    54,    55,     4,     5,     6,     7,   171,     0,
       9,     0,     0,   184,     1,    54,    55,     4,     5,     6,
       7,     0,     0,     9,    10,     0,   185,    11,     0,     1,
      54,    55,     4,     5,     6,     7,     0,    10,     9,     0,
      11,   187,     1,    54,    55,     4,     5,     6,     7,     0,
       0,     9,    10,   188,     0,    11,     0,     1,    54,    55,
       4,     5,     6,     7,     0,    10,     9,     0,    11,   191,
       1,    54,    55,     4,     5,     6,     7,     0,     0,     9,
      10,     0,   200,    11,     0,     1,    54,    55,     4,     5,
       6,     7,     0,    10,     9,     0,    11,   205,     1,    54,
      55,     4,     5,     6,     7,     0,     0,     9,    10,   213,
       0,    11,     0,     1,    54,    55,     4,     5,     6,     7,
       0,    10,     9,     0,    11,   215,     1,    54,    55,     4,
       5,     6,     7,     0,     0,     9,    10,     0,   223,    11,
       0,     0,     1,    54,    55,     4,     5,     6,     7,    10,
       0,     9,    11,   225,     1,    54,    55,     4,     5,     6,
       7,     0,     0,     9,     0,    10,   228,     0,    11,    38,
      39,    40,     0,    38,    39,    40,     0,    10,     0,     0,
      11,     0,    41,     0,    42,   110,    41,     0,    42,     0,
       0,    43,    95,     0,     0,    43,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,   104,     0,     0,     0,    78,    79,     0,
      80,    81,     0,     0,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,   105,     0,     0,     0,    78,    79,
       0,    80,    81,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,   107,     0,     0,     0,    78,
      79,     0,    80,    81,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,   114,     0,     0,     0,
      78,    79,     0,    80,    81,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,   127,     0,     0,
       0,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,   150,     0,
       0,     0,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,   224,
       0,     0,     0,    78,    79,     0,    80,    81,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      96,     0,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,   151,
       0,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,   178,     0,
      78,    79,     0,    80,    81,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,   206,     0,    78,
      79,     0,    80,    81,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    78,    79,     0,    80,    81,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    97,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,   140,
     152,    78,    79,     0,    80,    81,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    78,    79,
       0,    80,    81,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,   165,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,   177,    78,    79,     0,    80,    81,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,   179,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,   202,
      78,    79,     0,    80,    81,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,   218,    78,     0,
       0,    80,    81,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    80,    81,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      13,     9,    20,    18,    15,    20,     6,     5,    20,    19,
       6,     7,    22,    13,    18,     5,    20,    15,    26,    27,
      28,    20,    40,    41,    32,    33,    41,    35,    41,    41,
      17,     3,     4,     5,    42,    43,    40,    41,    46,    50,
       5,    40,     5,    18,    16,    20,    18,     3,     4,     5,
      15,    19,    15,    25,    22,    40,    64,     6,     7,    18,
      16,    18,    18,    19,    51,    73,    74,    18,    40,    25,
      78,    79,    80,    18,    82,    83,    84,    85,    86,    87,
      88,     5,     6,     7,     8,     9,    10,    11,    75,    13,
      14,     5,     6,     7,     8,     9,    10,    11,   106,    20,
      14,    27,    18,    17,    28,     0,    18,    31,    40,    35,
      36,    37,    38,    39,    28,     5,    18,    31,   105,    40,
     107,    18,   130,    29,    30,   133,   134,     5,   141,     5,
     143,    40,     3,   146,     0,    19,   149,     5,     6,     7,
       8,     9,    10,    11,     0,   158,    14,    41,    16,    19,
       5,    18,    40,    40,     5,   168,    21,   165,    16,    40,
      28,     3,   170,    31,     5,     6,     7,     8,     9,    10,
      11,    16,    16,    14,    27,   188,   163,   164,    27,   166,
     167,   194,   169,    16,    37,    38,    39,    28,     0,    12,
      31,   199,    16,   180,   207,    20,     5,     5,     3,    21,
     213,     0,    32,   190,     5,     6,     7,     8,     9,    10,
      11,   219,   225,    14,     3,    16,   203,   204,    21,    17,
      41,   208,    12,     3,    40,    32,     5,    28,    21,   216,
      31,     0,    13,   220,    71,    41,    40,   224,    13,   175,
     227,     5,     6,     7,     8,     9,    10,    11,   152,    -1,
      14,    -1,    -1,    17,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    28,    -1,    17,    31,    -1,     5,
       6,     7,     8,     9,    10,    11,    -1,    28,    14,    -1,
      31,    17,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    28,    16,    -1,    31,    -1,     5,     6,     7,
       8,     9,    10,    11,    -1,    28,    14,    -1,    31,    17,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      28,    -1,    17,    31,    -1,     5,     6,     7,     8,     9,
      10,    11,    -1,    28,    14,    -1,    31,    17,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    28,    16,
      -1,    31,    -1,     5,     6,     7,     8,     9,    10,    11,
      -1,    28,    14,    -1,    31,    17,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    28,    -1,    17,    31,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    28,
      -1,    14,    31,    16,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    28,    17,    -1,    31,     3,
       4,     5,    -1,     3,     4,     5,    -1,    28,    -1,    -1,
      31,    -1,    16,    -1,    18,    19,    16,    -1,    18,    -1,
      -1,    25,    19,    -1,    -1,    25,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    19,    -1,    -1,    -1,    23,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    19,    -1,    -1,    -1,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    19,    -1,    -1,    -1,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    19,    -1,    -1,    -1,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    19,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    19,    -1,
      -1,    -1,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    19,
      -1,    -1,    -1,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      21,    -1,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    21,
      -1,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    21,    -1,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    21,    -1,    23,
      24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    39,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    23,    24,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    23,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      23,    24,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    23,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    11,    13,    14,
      28,    31,    43,    44,    45,    46,    47,    49,    50,    51,
      52,    54,    55,    56,    57,    58,    18,    20,    41,     5,
      15,     5,    18,    18,    18,    18,     5,    15,     3,     4,
       5,    16,    18,    25,    40,    53,    18,    40,     0,    45,
      46,    49,     6,    47,     6,     7,    50,    19,    53,    53,
      53,    18,    20,    40,    41,    18,    40,    53,    53,     5,
      53,    18,    18,    18,    20,    49,    53,    53,    23,    24,
      26,    27,    33,    34,    35,    36,    37,    38,    39,    40,
      53,     5,     5,     5,    40,    19,    21,    40,     6,     7,
      48,     3,    53,    19,    19,    19,    41,    19,    48,    19,
      19,    53,    53,    17,    19,    53,    53,    53,    53,    61,
      53,    53,    53,    53,    53,    53,    53,    19,    20,    40,
      41,    40,    40,    20,    41,     5,     5,    19,    22,    21,
      40,    16,    40,    16,    50,    53,    16,    50,    19,    16,
      19,    21,    22,    16,     3,    53,    53,    53,    16,     6,
       7,    20,    40,    49,    49,    40,    49,    12,    16,    49,
      20,    61,    29,    30,    59,    60,    21,    40,    21,    40,
      49,     5,     5,     3,    17,    17,    53,    17,    16,    50,
      49,    17,    53,     3,    32,    17,    59,    20,    40,    41,
      17,    21,    40,    12,    49,    17,    21,    32,    49,     3,
      53,    40,     5,    16,    50,    17,    49,    21,    40,    41,
      49,    40,    53,    17,    19,    16,    50,    49,    17
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 62 "parser.y"
    {
        /* Program consists of optional global declarations followed by functions */
        (yyval.node) = createProgram((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
        root = (yyval.node);
    ;}
    break;

  case 3:
#line 67 "parser.y"
    {
        /* Program with only functions, no global variables */
        (yyval.node) = createProgram(NULL, (yyvsp[(1) - (1)].node));
        root = (yyval.node);
    ;}
    break;

  case 4:
#line 72 "parser.y"
    {
        /* Old style: statements only - wrap in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, (yyvsp[(1) - (1)].node));
        (yyval.node) = createProgram(NULL, mainFunc);
        root = (yyval.node);
    ;}
    break;

  case 5:
#line 78 "parser.y"
    {
        /* Old style with globals: wrap statements in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, (yyvsp[(2) - (2)].node));
        (yyval.node) = createProgram((yyvsp[(1) - (2)].node), mainFunc);
        root = (yyval.node);
    ;}
    break;

  case 6:
#line 88 "parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 7:
#line 91 "parser.y"
    {
        (yyval.node) = createStmtList((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 8:
#line 97 "parser.y"
    {
        /* Global variable: int x; */
        (yyval.node) = createGlobalDecl((yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 9:
#line 102 "parser.y"
    {
        /* Global double: double x; */
        (yyval.node) = createGlobalDeclDouble((yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 10:
#line 107 "parser.y"
    {
        /* Global with initialization: int x = 10; */
        (yyval.node) = createGlobalDeclInit((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].node));
        free((yyvsp[(2) - (5)].str));
    ;}
    break;

  case 11:
#line 112 "parser.y"
    {
        /* Global 1D array: int arr[10]; */
        (yyval.node) = createGlobalArrayDecl((yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].num));
        free((yyvsp[(2) - (6)].str));
    ;}
    break;

  case 12:
#line 117 "parser.y"
    {
        /* Global 2D array: int matrix[5][5]; */
        (yyval.node) = createGlobalArray2DDecl((yyvsp[(2) - (9)].str), (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].num));
        free((yyvsp[(2) - (9)].str));
    ;}
    break;

  case 13:
#line 129 "parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 14:
#line 132 "parser.y"
    {
        (yyval.node) = createFunctionList((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 15:
#line 138 "parser.y"
    {
        /* int function_name(params) { body } */
        (yyval.node) = createFunction((yyvsp[(2) - (8)].str), "int", (yyvsp[(4) - (8)].node), (yyvsp[(7) - (8)].node));
        free((yyvsp[(2) - (8)].str));
    ;}
    break;

  case 16:
#line 143 "parser.y"
    {
        /* void function_name(params) { body } */
        (yyval.node) = createFunction((yyvsp[(2) - (8)].str), "void", (yyvsp[(4) - (8)].node), (yyvsp[(7) - (8)].node));
        free((yyvsp[(2) - (8)].str));
    ;}
    break;

  case 17:
#line 148 "parser.y"
    {
        /* Special case: int main() { body } */
        (yyval.node) = createFunction("main", "int", NULL, (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 18:
#line 152 "parser.y"
    {
        /* void main() { body } */
        (yyval.node) = createFunction("main", "void", NULL, (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 19:
#line 160 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(2) - (2)].str), "int", NULL);
        free((yyvsp[(2) - (2)].str));
    ;}
    break;

  case 20:
#line 164 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(2) - (2)].str), "double", NULL);
        free((yyvsp[(2) - (2)].str));
    ;}
    break;

  case 21:
#line 168 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(4) - (4)].str), "int", (yyvsp[(1) - (4)].node));
        free((yyvsp[(4) - (4)].str));
    ;}
    break;

  case 22:
#line 172 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(4) - (4)].str), "double", (yyvsp[(1) - (4)].node));
        free((yyvsp[(4) - (4)].str));
    ;}
    break;

  case 23:
#line 176 "parser.y"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 24:
#line 186 "parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 25:
#line 189 "parser.y"
    {
        (yyval.node) = createStmtList((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 33:
#line 202 "parser.y"
    {
        (yyval.node) = createBreak();
    ;}
    break;

  case 34:
#line 205 "parser.y"
    {
        (yyval.node) = createReturn((yyvsp[(2) - (3)].node));
    ;}
    break;

  case 35:
#line 208 "parser.y"
    {
        (yyval.node) = createReturn(NULL);
    ;}
    break;

  case 36:
#line 211 "parser.y"
    {
        /* Function call with argument */
        (yyval.node) = createCall((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].node));
        free((yyvsp[(1) - (5)].str));
    ;}
    break;

  case 37:
#line 216 "parser.y"
    {
        /* Function call without arguments */
        (yyval.node) = createCall((yyvsp[(1) - (4)].str), NULL);
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 38:
#line 225 "parser.y"
    {
        (yyval.node) = createDecl((yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 39:
#line 229 "parser.y"
    {
        (yyval.node) = createDeclDouble((yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 40:
#line 233 "parser.y"
    {
        (yyval.node) = createDeclInit((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].node));
        free((yyvsp[(2) - (5)].str));
    ;}
    break;

  case 41:
#line 237 "parser.y"
    {
        (yyval.node) = createArrayDecl((yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].num));
        free((yyvsp[(2) - (6)].str));
    ;}
    break;

  case 42:
#line 241 "parser.y"
    {
        (yyval.node) = createArray2DDecl((yyvsp[(2) - (9)].str), (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].num));
        free((yyvsp[(2) - (9)].str));
    ;}
    break;

  case 43:
#line 249 "parser.y"
    {
        (yyval.node) = createAssign((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].node));
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 44:
#line 253 "parser.y"
    {
        (yyval.node) = createArrayAssign((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
        free((yyvsp[(1) - (7)].str));
    ;}
    break;

  case 45:
#line 257 "parser.y"
    {
        (yyval.node) = createArray2DAssign((yyvsp[(1) - (10)].str), (yyvsp[(3) - (10)].node), (yyvsp[(6) - (10)].node), (yyvsp[(9) - (10)].node));
        free((yyvsp[(1) - (10)].str));
    ;}
    break;

  case 46:
#line 268 "parser.y"
    {
        (yyval.node) = createNum((yyvsp[(1) - (1)].num));
    ;}
    break;

  case 47:
#line 271 "parser.y"
    {
        (yyval.node) = createFloatNum((yyvsp[(1) - (1)].fnum));
    ;}
    break;

  case 48:
#line 274 "parser.y"
    {
        (yyval.node) = createVar((yyvsp[(1) - (1)].str));
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 49:
#line 278 "parser.y"
    {
        (yyval.node) = createBinOp('+', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 50:
#line 281 "parser.y"
    {
        (yyval.node) = createBinOp('-', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 51:
#line 284 "parser.y"
    {
        (yyval.node) = createBinOp('*', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 52:
#line 287 "parser.y"
    {
        (yyval.node) = createBinOp('/', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 53:
#line 290 "parser.y"
    {
        (yyval.node) = createBinOp('%', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 54:
#line 293 "parser.y"
    {
        (yyval.node) = createBinOp('<', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 55:
#line 296 "parser.y"
    {
        (yyval.node) = createBinOp('>', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 56:
#line 299 "parser.y"
    {
        (yyval.node) = createBinOp('=', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 57:
#line 302 "parser.y"
    {
        (yyval.node) = createBinOp('&', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 58:
#line 305 "parser.y"
    {
        (yyval.node) = createBinOp('|', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 59:
#line 308 "parser.y"
    {
        /* Logical NOT unary operator */
        (yyval.node) = createBinOp('!', (yyvsp[(2) - (2)].node), NULL);
    ;}
    break;

  case 60:
#line 312 "parser.y"
    {
        (yyval.node) = (yyvsp[(2) - (3)].node);
    ;}
    break;

  case 61:
#line 315 "parser.y"
    {
        (yyval.node) = (yyvsp[(2) - (3)].node);
    ;}
    break;

  case 62:
#line 318 "parser.y"
    {
        (yyval.node) = createArrayAccess((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].node));
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 63:
#line 322 "parser.y"
    {
        (yyval.node) = createArray2DAccess((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
        free((yyvsp[(1) - (7)].str));
    ;}
    break;

  case 64:
#line 326 "parser.y"
    {
        /* Function call with argument as expression */
        (yyval.node) = createCallExpr((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].node));
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 65:
#line 331 "parser.y"
    {
        /* Function call without arguments as expression */
        (yyval.node) = createCallExpr((yyvsp[(1) - (3)].str), NULL);
        free((yyvsp[(1) - (3)].str));
    ;}
    break;

  case 66:
#line 336 "parser.y"
    {
        /* Multi-value equality check: expr is val1, val2, val3 */
        (yyval.node) = createMultiValueCheck((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 67:
#line 344 "parser.y"
    {
        (yyval.node) = createPrint((yyvsp[(3) - (5)].node));
    ;}
    break;

  case 68:
#line 351 "parser.y"
    {
        (yyval.node) = createWhile((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
    ;}
    break;

  case 69:
#line 354 "parser.y"
    {
        (yyval.node) = createWhile((yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 70:
#line 361 "parser.y"
    {
        ASTNode* init = createAssign((yyvsp[(3) - (13)].str), (yyvsp[(5) - (13)].node));
        ASTNode* update = createAssign((yyvsp[(9) - (13)].str), (yyvsp[(11) - (13)].node));
        (yyval.node) = createFor(init, (yyvsp[(7) - (13)].node), update, (yyvsp[(13) - (13)].node));
        free((yyvsp[(3) - (13)].str));
        free((yyvsp[(9) - (13)].str));
    ;}
    break;

  case 71:
#line 368 "parser.y"
    {
        ASTNode* init = createAssign((yyvsp[(3) - (15)].str), (yyvsp[(5) - (15)].node));
        ASTNode* update = createAssign((yyvsp[(9) - (15)].str), (yyvsp[(11) - (15)].node));
        (yyval.node) = createFor(init, (yyvsp[(7) - (15)].node), update, (yyvsp[(14) - (15)].node));
        free((yyvsp[(3) - (15)].str));
        free((yyvsp[(9) - (15)].str));
    ;}
    break;

  case 72:
#line 378 "parser.y"
    {
        (yyval.node) = createIf((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
    ;}
    break;

  case 73:
#line 381 "parser.y"
    {
        (yyval.node) = createIf((yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 74:
#line 384 "parser.y"
    {
        (yyval.node) = createIfElse((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
    ;}
    break;

  case 75:
#line 387 "parser.y"
    {
        (yyval.node) = createIfElse((yyvsp[(3) - (9)].node), (yyvsp[(6) - (9)].node), (yyvsp[(9) - (9)].node));
    ;}
    break;

  case 76:
#line 390 "parser.y"
    {
        (yyval.node) = createIfElse((yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(8) - (9)].node));
    ;}
    break;

  case 77:
#line 393 "parser.y"
    {
        (yyval.node) = createIfElse((yyvsp[(3) - (11)].node), (yyvsp[(6) - (11)].node), (yyvsp[(10) - (11)].node));
    ;}
    break;

  case 78:
#line 400 "parser.y"
    {
        (yyval.node) = createSwitch((yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 79:
#line 406 "parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 80:
#line 409 "parser.y"
    {
        (yyvsp[(1) - (2)].node)->data.casestmt.next = (yyvsp[(2) - (2)].node);
        (yyval.node) = (yyvsp[(1) - (2)].node);
    ;}
    break;

  case 81:
#line 416 "parser.y"
    {
        (yyval.node) = createCase((yyvsp[(2) - (4)].num), (yyvsp[(4) - (4)].node), NULL);
    ;}
    break;

  case 82:
#line 419 "parser.y"
    {
        (yyval.node) = createCase((yyvsp[(2) - (3)].num), NULL, NULL);
    ;}
    break;

  case 83:
#line 422 "parser.y"
    {
        (yyval.node) = createDefault((yyvsp[(3) - (3)].node));
    ;}
    break;

  case 84:
#line 425 "parser.y"
    {
        (yyval.node) = createDefault(NULL);
    ;}
    break;

  case 85:
#line 432 "parser.y"
    {
        /* Single value */
        (yyval.node) = createValueList((yyvsp[(1) - (1)].node), NULL);
    ;}
    break;

  case 86:
#line 436 "parser.y"
    {
        /* Multiple values */
        (yyval.node) = createValueList((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2314 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 442 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, s);
}
