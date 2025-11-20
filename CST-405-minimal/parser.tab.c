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
     LE = 282,
     GE = 283,
     IS = 284,
     SWITCH = 285,
     CASE = 286,
     DEFAULT = 287,
     BREAK = 288,
     COLON = 289,
     UMINUS = 290,
     NEQ = 291
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
#define LE 282
#define GE 283
#define IS 284
#define SWITCH 285
#define CASE 286
#define DEFAULT 287
#define BREAK 288
#define COLON 289
#define UMINUS 290
#define NEQ 291




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
#line 194 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 207 "parser.tab.c"

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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   995

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  245

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    43,     2,     2,
       2,     2,    41,    39,     2,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      36,    45,    37,     2,     2,     2,     2,     2,     2,     2,
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
      35,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    13,    15,    18,    22,
      26,    32,    39,    49,    51,    54,    63,    72,    80,    88,
      91,    94,    99,   104,   109,   114,   121,   128,   129,   131,
     134,   136,   138,   140,   142,   144,   146,   148,   151,   155,
     158,   164,   169,   173,   177,   183,   190,   200,   205,   213,
     224,   226,   228,   230,   234,   238,   242,   246,   250,   254,
     258,   262,   266,   270,   274,   278,   282,   285,   289,   293,
     298,   306,   311,   315,   319,   322,   328,   334,   342,   356,
     372,   378,   386,   394,   404,   414,   426,   434,   436,   439,
     444,   448,   452,   455,   457
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    50,    -1,    50,    -1,    53,    -1,
      48,    53,    -1,    49,    -1,    48,    49,    -1,     6,     5,
      44,    -1,     7,     5,    44,    -1,     6,     5,    45,    57,
      44,    -1,     6,     5,    20,     3,    21,    44,    -1,     6,
       5,    20,     3,    21,    20,     3,    21,    44,    -1,    51,
      -1,    50,    51,    -1,     6,     5,    18,    52,    19,    16,
      53,    17,    -1,    13,     5,    18,    52,    19,    16,    53,
      17,    -1,     6,    15,    18,    19,    16,    53,    17,    -1,
      13,    15,    18,    19,    16,    53,    17,    -1,     6,     5,
      -1,     7,     5,    -1,    52,    22,     6,     5,    -1,    52,
      22,     7,     5,    -1,     6,     5,    20,    21,    -1,     7,
       5,    20,    21,    -1,    52,    22,     6,     5,    20,    21,
      -1,    52,    22,     7,     5,    20,    21,    -1,    -1,    54,
      -1,    53,    54,    -1,    55,    -1,    56,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    33,    44,
      -1,    14,    57,    44,    -1,    14,    44,    -1,     5,    18,
      57,    19,    44,    -1,     5,    18,    19,    44,    -1,     6,
       5,    44,    -1,     7,     5,    44,    -1,     6,     5,    45,
      57,    44,    -1,     6,     5,    20,     3,    21,    44,    -1,
       6,     5,    20,     3,    21,    20,     3,    21,    44,    -1,
       5,    45,    57,    44,    -1,     5,    20,    57,    21,    45,
      57,    44,    -1,     5,    20,    57,    21,    20,    57,    21,
      45,    57,    44,    -1,     3,    -1,     4,    -1,     5,    -1,
      57,    39,    57,    -1,    57,    40,    57,    -1,    57,    41,
      57,    -1,    57,    42,    57,    -1,    57,    43,    57,    -1,
      57,    36,    57,    -1,    57,    37,    57,    -1,    57,    26,
      57,    -1,    57,    27,    57,    -1,    57,    28,    57,    -1,
      57,    38,    57,    -1,    57,    23,    57,    -1,    57,    24,
      57,    -1,    25,    57,    -1,    18,    57,    19,    -1,    16,
      53,    17,    -1,     5,    20,    57,    21,    -1,     5,    20,
      57,    21,    20,    57,    21,    -1,     5,    18,    57,    19,
      -1,     5,    18,    19,    -1,    57,    29,    65,    -1,    40,
      57,    -1,     8,    18,    57,    19,    44,    -1,     9,    18,
      57,    19,    54,    -1,     9,    18,    57,    19,    16,    53,
      17,    -1,    10,    18,     5,    45,    57,    44,    57,    44,
       5,    45,    57,    19,    54,    -1,    10,    18,     5,    45,
      57,    44,    57,    44,     5,    45,    57,    19,    16,    53,
      17,    -1,    11,    18,    57,    19,    54,    -1,    11,    18,
      57,    19,    16,    53,    17,    -1,    11,    18,    57,    19,
      54,    12,    54,    -1,    11,    18,    57,    19,    16,    53,
      17,    12,    54,    -1,    11,    18,    57,    19,    54,    12,
      16,    53,    17,    -1,    11,    18,    57,    19,    16,    53,
      17,    12,    16,    53,    17,    -1,    30,    18,    57,    19,
      16,    63,    17,    -1,    64,    -1,    64,    63,    -1,    31,
       3,    34,    53,    -1,    31,     3,    34,    -1,    32,    34,
      53,    -1,    32,    34,    -1,    57,    -1,    57,    22,    65,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    70,    75,    81,    91,    94,   100,   105,
     110,   115,   120,   132,   135,   141,   146,   151,   155,   163,
     167,   171,   175,   179,   183,   187,   191,   195,   205,   208,
     214,   215,   216,   217,   218,   219,   220,   221,   224,   227,
     230,   235,   244,   248,   252,   256,   260,   268,   272,   276,
     287,   290,   293,   297,   300,   303,   306,   309,   312,   315,
     318,   321,   324,   327,   330,   333,   336,   340,   343,   346,
     350,   354,   359,   364,   368,   376,   383,   386,   393,   400,
     410,   413,   416,   419,   422,   425,   432,   438,   441,   448,
     451,   454,   457,   464,   468
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
  "COMMA", "AND", "OR", "NOT", "EQ", "LE", "GE", "IS", "SWITCH", "CASE",
  "DEFAULT", "BREAK", "COLON", "UMINUS", "'<'", "'>'", "NEQ", "'+'", "'-'",
  "'*'", "'/'", "'%'", "';'", "'='", "$accept", "program",
  "global_decl_list", "global_decl", "function_list", "function_decl",
  "param_list", "stmt_list", "stmt", "decl", "assign", "expr",
  "print_stmt", "while_stmt", "for_stmt", "if_stmt", "switch_stmt",
  "case_list", "case_stmt", "value_list", 0
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
     285,   286,   287,   288,   289,   290,    60,    62,   291,    43,
      45,    42,    47,    37,    59,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    50,    50,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    63,    63,    64,
      64,    64,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     2,     3,     3,
       5,     6,     9,     1,     2,     8,     8,     7,     7,     2,
       2,     4,     4,     4,     4,     6,     6,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     2,
       5,     4,     3,     3,     5,     6,     9,     4,     7,    10,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     4,
       7,     4,     3,     3,     2,     5,     5,     7,    13,    15,
       5,     7,     7,     9,     9,    11,     7,     1,     2,     4,
       3,     3,     2,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     3,    13,     4,    28,    30,
      31,    32,    33,    34,    35,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,     0,     0,     0,     0,    39,     0,     0,    37,     1,
       7,     2,     5,     0,    14,     0,     0,    29,     0,     0,
       0,     0,    27,     0,     8,     0,     0,     9,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,    66,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,    41,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,     0,     0,    68,    67,
      64,    65,    60,    61,    62,    93,    73,    58,    59,    63,
      53,    54,    55,    56,    57,     0,     0,    42,     0,    43,
      40,     0,     0,    19,    20,     0,     0,     0,    10,     0,
      75,     0,    76,     0,     0,    80,     0,     0,    71,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,     0,    87,     0,    44,     0,    48,
      23,    24,     0,    21,    22,     0,    17,    77,     0,    81,
       0,    82,     0,    18,     0,     0,    92,    86,    88,     0,
      45,     0,    15,     0,     0,     0,     0,     0,     0,    16,
      70,    90,    91,     0,     0,    25,    26,    12,     0,     0,
      83,    84,    89,     0,    49,     0,     0,    46,     0,    85,
       0,     0,    78,     0,    79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,   105,    17,    18,    19,
      20,   125,    21,    22,    23,    24,    25,   184,   185,   126
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
     140,    -4,     0,     2,    25,    30,    53,    59,     7,     5,
      79,   -42,    60,   140,   -43,    46,   -43,   450,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,    28,    91,    91,    -7,
      83,    62,    91,    91,   103,    91,    97,    99,   -43,   -43,
      36,   450,    91,    91,    91,   -43,   736,    91,   -43,   -43,
     -43,    46,   450,    50,   -43,   105,   113,   -43,    75,   448,
     646,   758,    63,   117,   121,    91,   104,   125,   473,   498,
      82,   523,    63,   109,    86,    91,   232,   548,   952,   952,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,   -43,   573,   111,     6,    88,   -43,
      93,    -3,   -43,   130,   134,   -16,   119,   780,   126,   108,
     191,    91,   261,    39,   127,   -43,   598,   669,   -43,   -43,
     952,   934,   135,   135,   135,   803,   -43,   135,   135,   135,
      71,    71,   128,   128,   128,   142,   153,   -43,    91,   -43,
     -43,    91,    91,   139,   141,   144,    92,    42,   162,   450,
     -43,   450,   -43,   824,   450,   151,   150,   450,   -43,   148,
      91,    61,   158,   846,   692,   868,   159,   160,   450,   164,
     166,   179,   183,   273,   290,    91,   304,   319,   450,   333,
      91,   -43,   181,   156,   175,    61,    43,   -43,   149,   -43,
     -43,   -43,   348,   186,   189,   174,   -43,   -43,   890,   198,
     450,   -43,   362,   -43,   715,   177,   450,   -43,   -43,   209,
     -43,    91,   -43,   192,   194,   173,   213,   377,   391,   -43,
     -43,   450,   450,   199,   912,   -43,   -43,   219,   178,   450,
     -43,   -43,   450,   182,   -43,    91,   406,   -43,   623,   -43,
     421,   450,   -43,   435,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   -43,   212,   218,   -11,   161,   -13,    12,   -43,
     -43,    -8,   -43,   -43,   -43,   -43,   -43,    37,   -43,    72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      52,    46,    48,   145,    54,    29,   146,    31,    38,    39,
      40,    62,    36,    63,    26,    30,    27,   141,    59,    60,
      61,    41,    37,    42,    68,    69,   136,    71,    76,    57,
      43,    38,    39,    40,    77,    78,    79,    64,    65,    95,
      54,    28,   142,    32,    41,    44,    42,    58,    33,    45,
     137,   138,    53,    43,    74,    96,    75,   107,   156,     8,
      49,   146,   171,   209,    57,    30,   116,   117,    44,   103,
     104,    34,   120,   121,   122,   123,   124,    35,   127,   128,
     129,   130,   131,   132,   133,   134,   172,   210,    57,    38,
      39,    40,   182,   183,    38,    39,    40,    47,   169,   170,
      85,    66,    41,   153,    42,   115,    67,    41,    70,    42,
      97,    43,    91,    92,    93,    72,    43,    73,    98,    99,
     106,   -42,   152,   108,   155,   -43,    44,   111,   114,    62,
     163,    44,   139,   164,   165,   143,   173,   140,   174,   144,
     147,   176,   149,   157,   179,     1,     2,     3,     4,     5,
       6,     7,   150,     8,     9,   192,   162,    85,   161,   166,
     168,   167,   -44,   177,    85,   202,   178,   198,   180,   193,
      10,   194,   204,    11,    89,    90,    91,    92,    93,   186,
     190,   191,   195,   -45,   205,    57,    57,   218,    57,   201,
     206,    57,   207,   222,   211,   215,     1,    55,    56,     4,
       5,     6,     7,   224,    57,     9,   213,   151,   232,   214,
     217,   221,   223,   225,    57,   226,   236,   227,   228,   -46,
     233,    10,   208,   235,    11,    50,   237,   238,   243,   230,
      57,    51,   181,   113,    57,     0,     0,     1,    55,    56,
       4,     5,     6,     7,    57,     0,     9,     0,    57,   118,
       0,     0,   242,     0,     0,    57,     0,     0,     0,     0,
       0,     0,    10,     0,     0,    11,     1,    55,    56,     4,
       5,     6,     7,     0,     0,     9,     0,   154,     1,    55,
      56,     4,     5,     6,     7,     0,     0,     9,     0,     0,
     196,    10,     0,     0,    11,     1,    55,    56,     4,     5,
       6,     7,     0,    10,     9,     0,    11,   197,     0,     1,
      55,    56,     4,     5,     6,     7,     0,     0,     9,     0,
      10,   199,     0,    11,     1,    55,    56,     4,     5,     6,
       7,     0,     0,     9,    10,   200,     0,    11,     1,    55,
      56,     4,     5,     6,     7,     0,     0,     9,     0,    10,
     203,     0,    11,     1,    55,    56,     4,     5,     6,     7,
       0,     0,     9,    10,     0,   212,    11,     1,    55,    56,
       4,     5,     6,     7,     0,     0,     9,     0,    10,   219,
       0,    11,     1,    55,    56,     4,     5,     6,     7,     0,
       0,     9,    10,   229,     0,    11,     1,    55,    56,     4,
       5,     6,     7,     0,     0,     9,     0,    10,   231,     0,
      11,     1,    55,    56,     4,     5,     6,     7,     0,     0,
       9,    10,     0,   239,    11,     0,     1,    55,    56,     4,
       5,     6,     7,     0,     0,     9,    10,   241,     0,    11,
       1,    55,    56,     4,     5,     6,     7,     0,     0,     9,
       0,    10,   244,     0,    11,     1,    55,    56,     4,     5,
       6,     7,     0,     0,     9,    10,     0,   100,    11,     0,
       0,    80,    81,     0,    82,    83,    84,    85,     0,     0,
      10,     0,     0,    11,    86,    87,    88,    89,    90,    91,
      92,    93,   109,     0,     0,     0,    80,    81,     0,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,   110,     0,     0,
       0,    80,    81,     0,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,   112,     0,     0,     0,    80,    81,     0,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,   119,     0,     0,
       0,    80,    81,     0,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,   135,     0,     0,     0,    80,    81,     0,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,   158,     0,     0,
       0,    80,    81,     0,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,   240,     0,     0,     0,    80,    81,     0,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,   101,     0,    80,
      81,     0,    82,    83,    84,    85,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
     159,     0,    80,    81,     0,    82,    83,    84,    85,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,   188,     0,    80,    81,     0,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93,   220,     0,    80,    81,
       0,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    80,
      81,     0,    82,    83,    84,    85,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    80,    81,     0,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,   102,    80,    81,     0,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,   148,   160,    80,    81,     0,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    80,    81,     0,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,   175,    80,
      81,     0,    82,    83,    84,    85,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
     187,    80,    81,     0,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,   189,    80,    81,     0,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,   216,    80,    81,     0,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93,   234,    80,     0,     0,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93
};

static const yytype_int16 yycheck[] =
{
      13,     9,    44,    19,    15,     5,    22,     5,     3,     4,
       5,    18,     5,    20,    18,    15,    20,    20,    26,    27,
      28,    16,    15,    18,    32,    33,    20,    35,    41,    17,
      25,     3,     4,     5,    42,    43,    44,    44,    45,    47,
      51,    45,    45,    18,    16,    40,    18,    19,    18,    44,
      44,    45,     6,    25,    18,     5,    20,    65,    19,    13,
       0,    22,    20,    20,    52,    15,    74,    75,    40,     6,
       7,    18,    80,    81,    82,    83,    84,    18,    86,    87,
      88,    89,    90,    91,    92,    93,    44,    44,    76,     3,
       4,     5,    31,    32,     3,     4,     5,    18,     6,     7,
      29,    18,    16,   111,    18,    19,    44,    16,     5,    18,
       5,    25,    41,    42,    43,    18,    25,    18,     5,    44,
       3,     0,   110,    19,   112,     0,    40,    45,    19,    18,
     138,    40,    44,   141,   142,     5,   149,    44,   151,     5,
      21,   154,    16,    16,   157,     5,     6,     7,     8,     9,
      10,    11,    44,    13,    14,   168,     3,    29,    16,    20,
      16,    20,     0,    12,    29,   178,    16,   175,    20,     5,
      30,     5,   180,    33,    39,    40,    41,    42,    43,    21,
      21,    21,     3,     0,     3,   173,   174,   200,   176,   177,
      34,   179,    17,   206,    45,    21,     5,     6,     7,     8,
       9,    10,    11,   211,   192,    14,    20,    16,   221,    20,
      12,    34,     3,    21,   202,    21,   229,    44,     5,     0,
      21,    30,   185,    45,    33,    13,    44,   235,   241,   217,
     218,    13,   160,    72,   222,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,   232,    -1,    14,    -1,   236,    17,
      -1,    -1,   240,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    -1,    16,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    -1,    -1,
      17,    30,    -1,    -1,    33,     5,     6,     7,     8,     9,
      10,    11,    -1,    30,    14,    -1,    33,    17,    -1,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    -1,
      30,    17,    -1,    33,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    30,    16,    -1,    33,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    -1,    30,
      17,    -1,    33,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    30,    -1,    17,    33,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    -1,    30,    17,
      -1,    33,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    30,    16,    -1,    33,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    -1,    30,    17,    -1,
      33,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    30,    -1,    17,    33,    -1,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    30,    16,    -1,    33,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      -1,    30,    17,    -1,    33,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    30,    -1,    19,    33,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    -1,    -1,
      30,    -1,    -1,    33,    36,    37,    38,    39,    40,    41,
      42,    43,    19,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    19,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    19,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    19,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    19,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    19,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    19,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    21,    -1,    23,
      24,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      21,    -1,    23,    24,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    21,    -1,    23,    24,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    21,    -1,    23,    24,
      -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    23,
      24,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    23,    24,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    23,    24,    -1,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    22,    23,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    23,    24,    -1,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    23,
      24,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    23,    24,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    23,    24,    -1,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    23,    24,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    23,    -1,    -1,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    11,    13,    14,
      30,    33,    47,    48,    49,    50,    51,    53,    54,    55,
      56,    58,    59,    60,    61,    62,    18,    20,    45,     5,
      15,     5,    18,    18,    18,    18,     5,    15,     3,     4,
       5,    16,    18,    25,    40,    44,    57,    18,    44,     0,
      49,    50,    53,     6,    51,     6,     7,    54,    19,    57,
      57,    57,    18,    20,    44,    45,    18,    44,    57,    57,
       5,    57,    18,    18,    18,    20,    53,    57,    57,    57,
      23,    24,    26,    27,    28,    29,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    57,     5,     5,     5,    44,
      19,    21,    44,     6,     7,    52,     3,    57,    19,    19,
      19,    45,    19,    52,    19,    19,    57,    57,    17,    19,
      57,    57,    57,    57,    57,    57,    65,    57,    57,    57,
      57,    57,    57,    57,    57,    19,    20,    44,    45,    44,
      44,    20,    45,     5,     5,    19,    22,    21,    44,    16,
      44,    16,    54,    57,    16,    54,    19,    16,    19,    21,
      22,    16,     3,    57,    57,    57,    20,    20,    16,     6,
       7,    20,    44,    53,    53,    44,    53,    12,    16,    53,
      20,    65,    31,    32,    63,    64,    21,    44,    21,    44,
      21,    21,    53,     5,     5,     3,    17,    17,    57,    17,
      16,    54,    53,    17,    57,     3,    34,    17,    63,    20,
      44,    45,    17,    20,    20,    21,    44,    12,    53,    17,
      21,    34,    53,     3,    57,    21,    21,    44,     5,    16,
      54,    17,    53,    21,    44,    45,    53,    44,    57,    17,
      19,    16,    54,    53,    17
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
#line 65 "parser.y"
    {
        /* Program consists of optional global declarations followed by functions */
        (yyval.node) = createProgram((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
        root = (yyval.node);
    ;}
    break;

  case 3:
#line 70 "parser.y"
    {
        /* Program with only functions, no global variables */
        (yyval.node) = createProgram(NULL, (yyvsp[(1) - (1)].node));
        root = (yyval.node);
    ;}
    break;

  case 4:
#line 75 "parser.y"
    {
        /* Old style: statements only - wrap in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, (yyvsp[(1) - (1)].node));
        (yyval.node) = createProgram(NULL, mainFunc);
        root = (yyval.node);
    ;}
    break;

  case 5:
#line 81 "parser.y"
    {
        /* Old style with globals: wrap statements in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, (yyvsp[(2) - (2)].node));
        (yyval.node) = createProgram((yyvsp[(1) - (2)].node), mainFunc);
        root = (yyval.node);
    ;}
    break;

  case 6:
#line 91 "parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 7:
#line 94 "parser.y"
    {
        (yyval.node) = createStmtList((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 8:
#line 100 "parser.y"
    {
        /* Global variable: int x; */
        (yyval.node) = createGlobalDecl((yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 9:
#line 105 "parser.y"
    {
        /* Global double: double x; */
        (yyval.node) = createGlobalDeclDouble((yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 10:
#line 110 "parser.y"
    {
        /* Global with initialization: int x = 10; */
        (yyval.node) = createGlobalDeclInit((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].node));
        free((yyvsp[(2) - (5)].str));
    ;}
    break;

  case 11:
#line 115 "parser.y"
    {
        /* Global 1D array: int arr[10]; */
        (yyval.node) = createGlobalArrayDecl((yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].num));
        free((yyvsp[(2) - (6)].str));
    ;}
    break;

  case 12:
#line 120 "parser.y"
    {
        /* Global 2D array: int matrix[5][5]; */
        (yyval.node) = createGlobalArray2DDecl((yyvsp[(2) - (9)].str), (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].num));
        free((yyvsp[(2) - (9)].str));
    ;}
    break;

  case 13:
#line 132 "parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 14:
#line 135 "parser.y"
    {
        (yyval.node) = createFunctionList((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 15:
#line 141 "parser.y"
    {
        /* int function_name(params) { body } */
        (yyval.node) = createFunction((yyvsp[(2) - (8)].str), "int", (yyvsp[(4) - (8)].node), (yyvsp[(7) - (8)].node));
        free((yyvsp[(2) - (8)].str));
    ;}
    break;

  case 16:
#line 146 "parser.y"
    {
        /* void function_name(params) { body } */
        (yyval.node) = createFunction((yyvsp[(2) - (8)].str), "void", (yyvsp[(4) - (8)].node), (yyvsp[(7) - (8)].node));
        free((yyvsp[(2) - (8)].str));
    ;}
    break;

  case 17:
#line 151 "parser.y"
    {
        /* Special case: int main() { body } */
        (yyval.node) = createFunction("main", "int", NULL, (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 18:
#line 155 "parser.y"
    {
        /* void main() { body } */
        (yyval.node) = createFunction("main", "void", NULL, (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 19:
#line 163 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(2) - (2)].str), "int", NULL);
        free((yyvsp[(2) - (2)].str));
    ;}
    break;

  case 20:
#line 167 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(2) - (2)].str), "double", NULL);
        free((yyvsp[(2) - (2)].str));
    ;}
    break;

  case 21:
#line 171 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(4) - (4)].str), "int", (yyvsp[(1) - (4)].node));
        free((yyvsp[(4) - (4)].str));
    ;}
    break;

  case 22:
#line 175 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(4) - (4)].str), "double", (yyvsp[(1) - (4)].node));
        free((yyvsp[(4) - (4)].str));
    ;}
    break;

  case 23:
#line 179 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(2) - (4)].str), "int[]", NULL);
        free((yyvsp[(2) - (4)].str));
    ;}
    break;

  case 24:
#line 183 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(2) - (4)].str), "double[]", NULL);
        free((yyvsp[(2) - (4)].str));
    ;}
    break;

  case 25:
#line 187 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(4) - (6)].str), "int", (yyvsp[(1) - (6)].node));
        free((yyvsp[(4) - (6)].str));
    ;}
    break;

  case 26:
#line 191 "parser.y"
    {
        (yyval.node) = createParameter((yyvsp[(4) - (6)].str), "double", (yyvsp[(1) - (6)].node));
        free((yyvsp[(4) - (6)].str));
    ;}
    break;

  case 27:
#line 195 "parser.y"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 28:
#line 205 "parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 29:
#line 208 "parser.y"
    {
        (yyval.node) = createStmtList((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 37:
#line 221 "parser.y"
    {
        (yyval.node) = createBreak();
    ;}
    break;

  case 38:
#line 224 "parser.y"
    {
        (yyval.node) = createReturn((yyvsp[(2) - (3)].node));
    ;}
    break;

  case 39:
#line 227 "parser.y"
    {
        (yyval.node) = createReturn(NULL);
    ;}
    break;

  case 40:
#line 230 "parser.y"
    {
        /* Function call with argument */
        (yyval.node) = createCall((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].node));
        free((yyvsp[(1) - (5)].str));
    ;}
    break;

  case 41:
#line 235 "parser.y"
    {
        /* Function call without arguments */
        (yyval.node) = createCall((yyvsp[(1) - (4)].str), NULL);
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 42:
#line 244 "parser.y"
    {
        (yyval.node) = createDecl((yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 43:
#line 248 "parser.y"
    {
        (yyval.node) = createDeclDouble((yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 44:
#line 252 "parser.y"
    {
        (yyval.node) = createDeclInit((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].node));
        free((yyvsp[(2) - (5)].str));
    ;}
    break;

  case 45:
#line 256 "parser.y"
    {
        (yyval.node) = createArrayDecl((yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].num));
        free((yyvsp[(2) - (6)].str));
    ;}
    break;

  case 46:
#line 260 "parser.y"
    {
        (yyval.node) = createArray2DDecl((yyvsp[(2) - (9)].str), (yyvsp[(4) - (9)].num), (yyvsp[(7) - (9)].num));
        free((yyvsp[(2) - (9)].str));
    ;}
    break;

  case 47:
#line 268 "parser.y"
    {
        (yyval.node) = createAssign((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].node));
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 48:
#line 272 "parser.y"
    {
        (yyval.node) = createArrayAssign((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
        free((yyvsp[(1) - (7)].str));
    ;}
    break;

  case 49:
#line 276 "parser.y"
    {
        (yyval.node) = createArray2DAssign((yyvsp[(1) - (10)].str), (yyvsp[(3) - (10)].node), (yyvsp[(6) - (10)].node), (yyvsp[(9) - (10)].node));
        free((yyvsp[(1) - (10)].str));
    ;}
    break;

  case 50:
#line 287 "parser.y"
    {
        (yyval.node) = createNum((yyvsp[(1) - (1)].num));
    ;}
    break;

  case 51:
#line 290 "parser.y"
    {
        (yyval.node) = createFloatNum((yyvsp[(1) - (1)].fnum));
    ;}
    break;

  case 52:
#line 293 "parser.y"
    {
        (yyval.node) = createVar((yyvsp[(1) - (1)].str));
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 53:
#line 297 "parser.y"
    {
        (yyval.node) = createBinOp('+', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 54:
#line 300 "parser.y"
    {
        (yyval.node) = createBinOp('-', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 55:
#line 303 "parser.y"
    {
        (yyval.node) = createBinOp('*', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 56:
#line 306 "parser.y"
    {
        (yyval.node) = createBinOp('/', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 57:
#line 309 "parser.y"
    {
        (yyval.node) = createBinOp('%', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 58:
#line 312 "parser.y"
    {
        (yyval.node) = createBinOp('<', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 59:
#line 315 "parser.y"
    {
        (yyval.node) = createBinOp('>', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 60:
#line 318 "parser.y"
    {
        (yyval.node) = createBinOp('=', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 61:
#line 321 "parser.y"
    {
        (yyval.node) = createBinOp(LE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 62:
#line 324 "parser.y"
    {
        (yyval.node) = createBinOp(GE, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 63:
#line 327 "parser.y"
    {
        (yyval.node) = createBinOp(NEQ, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 64:
#line 330 "parser.y"
    {
        (yyval.node) = createBinOp('&', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 65:
#line 333 "parser.y"
    {
        (yyval.node) = createBinOp('|', (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 66:
#line 336 "parser.y"
    {
        /* Logical NOT unary operator */
        (yyval.node) = createBinOp('!', (yyvsp[(2) - (2)].node), NULL);
    ;}
    break;

  case 67:
#line 340 "parser.y"
    {
        (yyval.node) = (yyvsp[(2) - (3)].node);
    ;}
    break;

  case 68:
#line 343 "parser.y"
    {
        (yyval.node) = (yyvsp[(2) - (3)].node);
    ;}
    break;

  case 69:
#line 346 "parser.y"
    {
        (yyval.node) = createArrayAccess((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].node));
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 70:
#line 350 "parser.y"
    {
        (yyval.node) = createArray2DAccess((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
        free((yyvsp[(1) - (7)].str));
    ;}
    break;

  case 71:
#line 354 "parser.y"
    {
        /* Function call with argument as expression */
        (yyval.node) = createCallExpr((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].node));
        free((yyvsp[(1) - (4)].str));
    ;}
    break;

  case 72:
#line 359 "parser.y"
    {
        /* Function call without arguments as expression */
        (yyval.node) = createCallExpr((yyvsp[(1) - (3)].str), NULL);
        free((yyvsp[(1) - (3)].str));
    ;}
    break;

  case 73:
#line 364 "parser.y"
    {
        /* Multi-value equality check: expr is val1, val2, val3 */
        (yyval.node) = createMultiValueCheck((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 74:
#line 368 "parser.y"
    { 
        /* Desugar -Expr into 0 - Expr */
        (yyval.node) = createBinOp('-', createNum(0), (yyvsp[(2) - (2)].node)); 
    ;}
    break;

  case 75:
#line 376 "parser.y"
    {
        (yyval.node) = createPrint((yyvsp[(3) - (5)].node));
    ;}
    break;

  case 76:
#line 383 "parser.y"
    {
        (yyval.node) = createWhile((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
    ;}
    break;

  case 77:
#line 386 "parser.y"
    {
        (yyval.node) = createWhile((yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 78:
#line 393 "parser.y"
    {
        ASTNode* init = createAssign((yyvsp[(3) - (13)].str), (yyvsp[(5) - (13)].node));
        ASTNode* update = createAssign((yyvsp[(9) - (13)].str), (yyvsp[(11) - (13)].node));
        (yyval.node) = createFor(init, (yyvsp[(7) - (13)].node), update, (yyvsp[(13) - (13)].node));
        free((yyvsp[(3) - (13)].str));
        free((yyvsp[(9) - (13)].str));
    ;}
    break;

  case 79:
#line 400 "parser.y"
    {
        ASTNode* init = createAssign((yyvsp[(3) - (15)].str), (yyvsp[(5) - (15)].node));
        ASTNode* update = createAssign((yyvsp[(9) - (15)].str), (yyvsp[(11) - (15)].node));
        (yyval.node) = createFor(init, (yyvsp[(7) - (15)].node), update, (yyvsp[(14) - (15)].node));
        free((yyvsp[(3) - (15)].str));
        free((yyvsp[(9) - (15)].str));
    ;}
    break;

  case 80:
#line 410 "parser.y"
    {
        (yyval.node) = createIf((yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
    ;}
    break;

  case 81:
#line 413 "parser.y"
    {
        (yyval.node) = createIf((yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 82:
#line 416 "parser.y"
    {
        (yyval.node) = createIfElse((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
    ;}
    break;

  case 83:
#line 419 "parser.y"
    {
        (yyval.node) = createIfElse((yyvsp[(3) - (9)].node), (yyvsp[(6) - (9)].node), (yyvsp[(9) - (9)].node));
    ;}
    break;

  case 84:
#line 422 "parser.y"
    {
        (yyval.node) = createIfElse((yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(8) - (9)].node));
    ;}
    break;

  case 85:
#line 425 "parser.y"
    {
        (yyval.node) = createIfElse((yyvsp[(3) - (11)].node), (yyvsp[(6) - (11)].node), (yyvsp[(10) - (11)].node));
    ;}
    break;

  case 86:
#line 432 "parser.y"
    {
        (yyval.node) = createSwitch((yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
    ;}
    break;

  case 87:
#line 438 "parser.y"
    {
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 88:
#line 441 "parser.y"
    {
        (yyvsp[(1) - (2)].node)->data.casestmt.next = (yyvsp[(2) - (2)].node);
        (yyval.node) = (yyvsp[(1) - (2)].node);
    ;}
    break;

  case 89:
#line 448 "parser.y"
    {
        (yyval.node) = createCase((yyvsp[(2) - (4)].num), (yyvsp[(4) - (4)].node), NULL);
    ;}
    break;

  case 90:
#line 451 "parser.y"
    {
        (yyval.node) = createCase((yyvsp[(2) - (3)].num), NULL, NULL);
    ;}
    break;

  case 91:
#line 454 "parser.y"
    {
        (yyval.node) = createDefault((yyvsp[(3) - (3)].node));
    ;}
    break;

  case 92:
#line 457 "parser.y"
    {
        (yyval.node) = createDefault(NULL);
    ;}
    break;

  case 93:
#line 464 "parser.y"
    {
        /* Single value */
        (yyval.node) = createValueList((yyvsp[(1) - (1)].node), NULL);
    ;}
    break;

  case 94:
#line 468 "parser.y"
    {
        /* Multiple values */
        (yyval.node) = createValueList((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2425 "parser.tab.c"
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


#line 474 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, s);
}
