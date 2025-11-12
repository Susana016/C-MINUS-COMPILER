/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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

void yyerror(const char* s);
ASTNode* root = NULL;

#line 89 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_FLOAT_NUM = 4,                  /* FLOAT_NUM  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_DOUBLE = 7,                     /* DOUBLE  */
  YYSYMBOL_PRINT = 8,                      /* PRINT  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_MAIN = 15,                      /* MAIN  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 17,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 18,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 19,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 20,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 21,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 22,                     /* COMMA  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_IS = 27,                        /* IS  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_global_decl_list = 39,          /* global_decl_list  */
  YYSYMBOL_global_decl = 40,               /* global_decl  */
  YYSYMBOL_function_list = 41,             /* function_list  */
  YYSYMBOL_function_decl = 42,             /* function_decl  */
  YYSYMBOL_param_list = 43,                /* param_list  */
  YYSYMBOL_stmt_list = 44,                 /* stmt_list  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_decl = 46,                      /* decl  */
  YYSYMBOL_assign = 47,                    /* assign  */
  YYSYMBOL_expr = 48,                      /* expr  */
  YYSYMBOL_print_stmt = 49,                /* print_stmt  */
  YYSYMBOL_while_stmt = 50,                /* while_stmt  */
  YYSYMBOL_for_stmt = 51,                  /* for_stmt  */
  YYSYMBOL_if_stmt = 52,                   /* if_stmt  */
  YYSYMBOL_value_list = 53                 /* value_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   684

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    34,     2,     2,
       2,     2,    32,    30,     2,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      28,    36,    29,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    63,    68,    74,    84,    87,    93,    98,
     103,   108,   113,   125,   128,   134,   139,   144,   148,   156,
     160,   164,   168,   172,   182,   185,   191,   192,   193,   194,
     195,   196,   197,   200,   203,   208,   217,   221,   225,   229,
     233,   241,   245,   249,   260,   263,   266,   270,   273,   276,
     279,   282,   285,   288,   291,   294,   297,   300,   304,   307,
     310,   314,   318,   323,   328,   336,   343,   346,   353,   360,
     370,   373,   376,   379,   382,   385,   392,   396
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "FLOAT_NUM",
  "ID", "INT", "DOUBLE", "PRINT", "WHILE", "FOR", "IF", "ELSE", "VOID",
  "RETURN", "MAIN", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "COMMA", "AND", "OR", "NOT", "EQ", "IS", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "';'", "'='", "$accept", "program",
  "global_decl_list", "global_decl", "function_list", "function_decl",
  "param_list", "stmt_list", "stmt", "decl", "assign", "expr",
  "print_stmt", "while_stmt", "for_stmt", "if_stmt", "value_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    62,
      43,    45,    42,    47,    37,    59,    61
};
#endif

#define YYPACT_NINF (-15)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     651,     0,     8,    37,    -2,    33,    39,    53,    38,    -1,
      84,   651,   -15,    32,   -15,   661,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,     3,    65,    65,    -6,    64,    60,    65,
      65,   101,    65,    93,   103,   -15,   -15,    -9,   661,    65,
      65,   -15,   342,   -15,   -15,    32,   661,    57,   -15,   117,
     119,   -15,    92,   177,   288,   355,    82,   123,   129,    65,
     111,   132,   193,   210,    97,   226,    82,   115,    36,    65,
     161,   242,   650,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,   -15,   118,   -10,   102,   -15,   105,
      11,   -15,   133,   138,    27,   125,   368,   134,   116,    91,
      65,   603,    44,   136,   -15,   258,   302,   -15,   -15,   650,
     573,    46,   382,   -15,    46,    46,    59,    59,   121,   121,
     121,   150,   -15,    65,   -15,   -15,    65,    65,   -15,   -15,
     139,   113,    13,   156,   661,   -15,   661,   -15,   394,   661,
     145,   143,   661,   -15,   140,    65,   142,   407,   316,   420,
     661,   171,   172,   176,   180,   477,   490,    65,   503,   615,
     661,   516,    65,   -15,    15,   -15,   146,   -15,   529,   -15,
     -15,   160,   -15,   -15,   433,   173,   661,   -15,   542,   -15,
     330,   183,   -15,    65,   -15,   148,   184,   627,   555,   -15,
     -15,   167,   446,   190,   157,   661,   -15,   -15,   163,   -15,
      65,   568,   -15,   274,   -15,   639,   661,   -15,   581,   -15
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     3,    13,     4,    24,    26,    27,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,    46,     0,     0,
       0,    33,     0,     1,     7,     2,     5,     0,    14,     0,
       0,    25,     0,     0,     0,     0,    23,     0,     8,     0,
       0,     9,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,    35,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,     0,    59,    58,    55,
      56,    54,    76,    64,    52,    53,    47,    48,    49,    50,
      51,     0,    36,     0,    37,    34,     0,     0,    19,    20,
       0,     0,     0,    10,     0,    65,     0,    66,     0,     0,
      70,     0,     0,    62,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    38,     0,    42,     0,    21,
      22,     0,    17,    67,     0,    71,     0,    72,     0,    18,
       0,     0,    39,     0,    15,     0,     0,     0,     0,    16,
      61,     0,     0,    12,     0,     0,    73,    74,     0,    43,
       0,     0,    40,     0,    75,     0,     0,    68,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -15,   -15,   -15,   188,   191,    -8,   147,   -11,   -14,   -15,
     -15,    35,   -15,   -15,   -15,   -15,    69
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    94,    15,    16,    17,
      18,   112,    19,    20,    21,    22,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    51,    35,    36,    37,    48,    35,    36,    37,    68,
     121,    69,    56,    26,    57,    38,    29,    39,    23,    38,
      24,    39,    52,    27,    40,   122,   123,    70,    40,    58,
      59,   126,    51,   153,    41,   181,    25,    48,    47,    35,
      36,    37,    28,    33,    42,     8,   130,   127,   154,   131,
     182,    30,    38,    34,    39,   104,    51,    31,    53,    54,
      55,    40,    85,   141,    62,    63,   131,    65,    35,    36,
      37,    32,    27,    76,    71,    72,    79,    80,    81,    82,
      83,    38,    60,    39,    43,   137,    76,   140,    92,    93,
      40,    81,    82,    83,    96,    61,     1,    49,    50,     4,
       5,     6,     7,   105,   106,     9,    64,   136,   109,   110,
     111,    66,   114,   115,   116,   117,   118,   119,   120,   151,
     152,    67,    86,   155,    87,   156,    95,    88,   158,   -36,
      97,   161,   -37,   100,   103,   138,    56,   124,   128,   168,
     125,    51,    51,   129,    51,   177,   132,    51,    76,   178,
     134,   135,   142,   146,    51,   150,   -38,   159,   147,   160,
     162,   148,   149,   164,    51,   188,     1,    49,    50,     4,
       5,     6,     7,   196,    51,     9,   169,   170,   107,   171,
     -39,   185,   183,   193,   201,   187,   191,    51,   198,   194,
     -40,   207,   174,   200,    51,   208,    89,   180,   202,    44,
      73,    74,    45,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    98,   102,   163,     0,    73,    74,   192,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,    99,
       0,     0,     0,    73,    74,   203,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   101,     0,     0,     0,    73,
      74,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   108,     0,     0,     0,    73,    74,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   143,     0,     0,
       0,    73,    74,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   205,     0,     0,     0,    73,    74,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    90,
       0,    73,    74,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   144,     0,    73,    74,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   166,     0,    73,
      74,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   190,     0,    73,    74,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    73,    74,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    73,    74,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      91,    73,    74,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   133,   145,    73,    74,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    73,    74,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,   157,
      73,    74,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   165,    73,    74,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   167,    73,    74,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   186,    73,
      74,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   199,     1,    49,    50,     4,     5,     6,     7,     0,
       0,     9,     0,     0,   172,     1,    49,    50,     4,     5,
       6,     7,     0,     0,     9,     0,     0,   173,     1,    49,
      50,     4,     5,     6,     7,     0,     0,     9,     0,     0,
     175,     1,    49,    50,     4,     5,     6,     7,     0,     0,
       9,     0,     0,   179,     1,    49,    50,     4,     5,     6,
       7,     0,     0,     9,     0,     0,   184,     1,    49,    50,
       4,     5,     6,     7,     0,     0,     9,     0,     0,   189,
       1,    49,    50,     4,     5,     6,     7,     0,     0,     9,
       0,     0,   197,     1,    49,    50,     4,     5,     6,     7,
       0,     0,     9,     0,     0,   204,     1,    49,    50,     4,
       5,     6,     7,     0,     0,     9,    73,     0,   209,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     1,    49,
      50,     4,     5,     6,     7,     0,     0,     9,     0,   139,
       1,    49,    50,     4,     5,     6,     7,     0,     0,     9,
       0,   176,     1,    49,    50,     4,     5,     6,     7,     0,
       0,     9,     0,   195,     1,    49,    50,     4,     5,     6,
       7,     0,     0,     9,     0,   206,     1,     2,     3,     4,
       5,     6,     7,     0,     8,     9,     1,    49,    50,     4,
       5,     6,     7,     0,     0,     9,    75,    76,    77,    78,
      79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
      11,    15,     3,     4,     5,    13,     3,     4,     5,    18,
      20,    20,    18,     5,    20,    16,    18,    18,    18,    16,
      20,    18,    19,    15,    25,    35,    36,    38,    25,    35,
      36,    20,    46,    20,    35,    20,    36,    45,     6,     3,
       4,     5,     5,     5,     9,    13,    19,    36,    35,    22,
      35,    18,    16,    15,    18,    19,    70,    18,    23,    24,
      25,    25,     5,    19,    29,    30,    22,    32,     3,     4,
       5,    18,    15,    27,    39,    40,    30,    31,    32,    33,
      34,    16,    18,    18,     0,    99,    27,   101,     6,     7,
      25,    32,    33,    34,    59,    35,     5,     6,     7,     8,
       9,    10,    11,    68,    69,    14,     5,    16,    73,    74,
      75,    18,    77,    78,    79,    80,    81,    82,    83,     6,
       7,    18,     5,   134,     5,   136,     3,    35,   139,     0,
      19,   142,     0,    36,    19,   100,    18,    35,     5,   150,
      35,   155,   156,     5,   158,   159,    21,   161,    27,   160,
      16,    35,    16,     3,   168,    16,     0,    12,   123,    16,
      20,   126,   127,    21,   178,   176,     5,     6,     7,     8,
       9,    10,    11,   187,   188,    14,     5,     5,    17,     3,
       0,    21,    36,    35,   195,    12,     3,   201,    21,     5,
       0,   205,   157,    36,   208,   206,    19,   162,    35,    11,
      23,    24,    11,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    19,    66,   145,    -1,    23,    24,   183,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    19,
      -1,    -1,    -1,    23,    24,   200,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    19,    -1,    -1,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    19,    -1,    -1,    -1,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    19,    -1,    -1,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    19,    -1,    -1,    -1,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    21,
      -1,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    21,    -1,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    21,    -1,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    21,    -1,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    -1,    -1,    17,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    -1,    -1,    17,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    -1,    -1,
      17,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    -1,    -1,    17,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    -1,    17,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    -1,    -1,    17,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      -1,    -1,    17,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    -1,    -1,    17,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    23,    -1,    17,    26,
      27,    28,    29,    30,    31,    32,    33,    34,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    -1,    16,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    14,
      -1,    16,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    14,    -1,    16,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    16,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    26,    27,    28,    29,
      30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    11,    13,    14,
      38,    39,    40,    41,    42,    44,    45,    46,    47,    49,
      50,    51,    52,    18,    20,    36,     5,    15,     5,    18,
      18,    18,    18,     5,    15,     3,     4,     5,    16,    18,
      25,    35,    48,     0,    40,    41,    44,     6,    42,     6,
       7,    45,    19,    48,    48,    48,    18,    20,    35,    36,
      18,    35,    48,    48,     5,    48,    18,    18,    18,    20,
      44,    48,    48,    23,    24,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,     5,     5,     5,    35,    19,
      21,    35,     6,     7,    43,     3,    48,    19,    19,    19,
      36,    19,    43,    19,    19,    48,    48,    17,    19,    48,
      48,    48,    48,    53,    48,    48,    48,    48,    48,    48,
      48,    20,    35,    36,    35,    35,    20,    36,     5,     5,
      19,    22,    21,    35,    16,    35,    16,    45,    48,    16,
      45,    19,    16,    19,    21,    22,     3,    48,    48,    48,
      16,     6,     7,    20,    35,    44,    44,    35,    44,    12,
      16,    44,    20,    53,    21,    35,    21,    35,    44,     5,
       5,     3,    17,    17,    48,    17,    16,    45,    44,    17,
      48,    20,    35,    36,    17,    21,    35,    12,    44,    17,
      21,     3,    48,    35,     5,    16,    45,    17,    21,    35,
      36,    44,    35,    48,    17,    19,    16,    45,    44,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    38,    38,    39,    39,    40,    40,
      40,    40,    40,    41,    41,    42,    42,    42,    42,    43,
      43,    43,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    46,    46,    46,    46,
      46,    47,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     2,     3,     3,
       5,     6,     9,     1,     2,     8,     8,     7,     7,     2,
       2,     4,     4,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     3,     2,     5,     4,     3,     3,     5,     6,
       9,     4,     7,    10,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       4,     7,     4,     3,     3,     5,     5,     7,    13,    15,
       5,     7,     7,     9,     9,    11,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* program: global_decl_list function_list  */
#line 58 "parser.y"
                                   {
        /* Program consists of optional global declarations followed by functions */
        (yyval.node) = createProgram((yyvsp[-1].node), (yyvsp[0].node));
        root = (yyval.node);
    }
#line 1345 "parser.tab.c"
    break;

  case 3: /* program: function_list  */
#line 63 "parser.y"
                    {
        /* Program with only functions, no global variables */
        (yyval.node) = createProgram(NULL, (yyvsp[0].node));
        root = (yyval.node);
    }
#line 1355 "parser.tab.c"
    break;

  case 4: /* program: stmt_list  */
#line 68 "parser.y"
                {
        /* Old style: statements only - wrap in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, (yyvsp[0].node));
        (yyval.node) = createProgram(NULL, mainFunc);
        root = (yyval.node);
    }
#line 1366 "parser.tab.c"
    break;

  case 5: /* program: global_decl_list stmt_list  */
#line 74 "parser.y"
                                 {
        /* Old style with globals: wrap statements in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, (yyvsp[0].node));
        (yyval.node) = createProgram((yyvsp[-1].node), mainFunc);
        root = (yyval.node);
    }
#line 1377 "parser.tab.c"
    break;

  case 6: /* global_decl_list: global_decl  */
#line 84 "parser.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1385 "parser.tab.c"
    break;

  case 7: /* global_decl_list: global_decl_list global_decl  */
#line 87 "parser.y"
                                   {
        (yyval.node) = createStmtList((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1393 "parser.tab.c"
    break;

  case 8: /* global_decl: INT ID ';'  */
#line 93 "parser.y"
               {
        /* Global variable: int x; */
        (yyval.node) = createGlobalDecl((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1403 "parser.tab.c"
    break;

  case 9: /* global_decl: DOUBLE ID ';'  */
#line 98 "parser.y"
                    {
        /* Global double: double x; */
        (yyval.node) = createGlobalDeclDouble((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1413 "parser.tab.c"
    break;

  case 10: /* global_decl: INT ID '=' expr ';'  */
#line 103 "parser.y"
                          {
        /* Global with initialization: int x = 10; */
        (yyval.node) = createGlobalDeclInit((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1423 "parser.tab.c"
    break;

  case 11: /* global_decl: INT ID LBRACKET NUM RBRACKET ';'  */
#line 108 "parser.y"
                                       {
        /* Global 1D array: int arr[10]; */
        (yyval.node) = createGlobalArrayDecl((yyvsp[-4].str), (yyvsp[-2].num));
        free((yyvsp[-4].str));
    }
#line 1433 "parser.tab.c"
    break;

  case 12: /* global_decl: INT ID LBRACKET NUM RBRACKET LBRACKET NUM RBRACKET ';'  */
#line 113 "parser.y"
                                                             {
        /* Global 2D array: int matrix[5][5]; */
        (yyval.node) = createGlobalArray2DDecl((yyvsp[-7].str), (yyvsp[-5].num), (yyvsp[-2].num));
        free((yyvsp[-7].str));
    }
#line 1443 "parser.tab.c"
    break;

  case 13: /* function_list: function_decl  */
#line 125 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1451 "parser.tab.c"
    break;

  case 14: /* function_list: function_list function_decl  */
#line 128 "parser.y"
                                  {
        (yyval.node) = createFunctionList((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1459 "parser.tab.c"
    break;

  case 15: /* function_decl: INT ID LPAREN param_list RPAREN LBRACE stmt_list RBRACE  */
#line 134 "parser.y"
                                                            {
        /* int function_name(params) { body } */
        (yyval.node) = createFunction((yyvsp[-6].str), "int", (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-6].str));
    }
#line 1469 "parser.tab.c"
    break;

  case 16: /* function_decl: VOID ID LPAREN param_list RPAREN LBRACE stmt_list RBRACE  */
#line 139 "parser.y"
                                                               {
        /* void function_name(params) { body } */
        (yyval.node) = createFunction((yyvsp[-6].str), "void", (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-6].str));
    }
#line 1479 "parser.tab.c"
    break;

  case 17: /* function_decl: INT MAIN LPAREN RPAREN LBRACE stmt_list RBRACE  */
#line 144 "parser.y"
                                                     {
        /* Special case: int main() { body } */
        (yyval.node) = createFunction("main", "int", NULL, (yyvsp[-1].node));
    }
#line 1488 "parser.tab.c"
    break;

  case 18: /* function_decl: VOID MAIN LPAREN RPAREN LBRACE stmt_list RBRACE  */
#line 148 "parser.y"
                                                      {
        /* void main() { body } */
        (yyval.node) = createFunction("main", "void", NULL, (yyvsp[-1].node));
    }
#line 1497 "parser.tab.c"
    break;

  case 19: /* param_list: INT ID  */
#line 156 "parser.y"
           {
        (yyval.node) = createParameter((yyvsp[0].str), "int", NULL);
        free((yyvsp[0].str));
    }
#line 1506 "parser.tab.c"
    break;

  case 20: /* param_list: DOUBLE ID  */
#line 160 "parser.y"
                {
        (yyval.node) = createParameter((yyvsp[0].str), "double", NULL);
        free((yyvsp[0].str));
    }
#line 1515 "parser.tab.c"
    break;

  case 21: /* param_list: param_list COMMA INT ID  */
#line 164 "parser.y"
                              {
        (yyval.node) = createParameter((yyvsp[0].str), "int", (yyvsp[-3].node));
        free((yyvsp[0].str));
    }
#line 1524 "parser.tab.c"
    break;

  case 22: /* param_list: param_list COMMA DOUBLE ID  */
#line 168 "parser.y"
                                 {
        (yyval.node) = createParameter((yyvsp[0].str), "double", (yyvsp[-3].node));
        free((yyvsp[0].str));
    }
#line 1533 "parser.tab.c"
    break;

  case 23: /* param_list: %empty  */
#line 172 "parser.y"
                  {
        (yyval.node) = NULL;
    }
#line 1541 "parser.tab.c"
    break;

  case 24: /* stmt_list: stmt  */
#line 182 "parser.y"
         {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1549 "parser.tab.c"
    break;

  case 25: /* stmt_list: stmt_list stmt  */
#line 185 "parser.y"
                     {
        (yyval.node) = createStmtList((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1557 "parser.tab.c"
    break;

  case 32: /* stmt: RETURN expr ';'  */
#line 197 "parser.y"
                      {
        (yyval.node) = createReturn((yyvsp[-1].node));
    }
#line 1565 "parser.tab.c"
    break;

  case 33: /* stmt: RETURN ';'  */
#line 200 "parser.y"
                 {
        (yyval.node) = createReturn(NULL);
    }
#line 1573 "parser.tab.c"
    break;

  case 34: /* stmt: ID LPAREN expr RPAREN ';'  */
#line 203 "parser.y"
                                {
        /* Function call with argument */
        (yyval.node) = createCall((yyvsp[-4].str), (yyvsp[-2].node));
        free((yyvsp[-4].str));
    }
#line 1583 "parser.tab.c"
    break;

  case 35: /* stmt: ID LPAREN RPAREN ';'  */
#line 208 "parser.y"
                           {
        /* Function call without arguments */
        (yyval.node) = createCall((yyvsp[-3].str), NULL);
        free((yyvsp[-3].str));
    }
#line 1593 "parser.tab.c"
    break;

  case 36: /* decl: INT ID ';'  */
#line 217 "parser.y"
               {
        (yyval.node) = createDecl((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1602 "parser.tab.c"
    break;

  case 37: /* decl: DOUBLE ID ';'  */
#line 221 "parser.y"
                    {
        (yyval.node) = createDeclDouble((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1611 "parser.tab.c"
    break;

  case 38: /* decl: INT ID '=' expr ';'  */
#line 225 "parser.y"
                          {
        (yyval.node) = createDeclInit((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1620 "parser.tab.c"
    break;

  case 39: /* decl: INT ID LBRACKET NUM RBRACKET ';'  */
#line 229 "parser.y"
                                       {
        (yyval.node) = createArrayDecl((yyvsp[-4].str), (yyvsp[-2].num));
        free((yyvsp[-4].str));
    }
#line 1629 "parser.tab.c"
    break;

  case 40: /* decl: INT ID LBRACKET NUM RBRACKET LBRACKET NUM RBRACKET ';'  */
#line 233 "parser.y"
                                                             {
        (yyval.node) = createArray2DDecl((yyvsp[-7].str), (yyvsp[-5].num), (yyvsp[-2].num));
        free((yyvsp[-7].str));
    }
#line 1638 "parser.tab.c"
    break;

  case 41: /* assign: ID '=' expr ';'  */
#line 241 "parser.y"
                    {
        (yyval.node) = createAssign((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1647 "parser.tab.c"
    break;

  case 42: /* assign: ID LBRACKET expr RBRACKET '=' expr ';'  */
#line 245 "parser.y"
                                             {
        (yyval.node) = createArrayAssign((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-6].str));
    }
#line 1656 "parser.tab.c"
    break;

  case 43: /* assign: ID LBRACKET expr RBRACKET LBRACKET expr RBRACKET '=' expr ';'  */
#line 249 "parser.y"
                                                                    {
        (yyval.node) = createArray2DAssign((yyvsp[-9].str), (yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-9].str));
    }
#line 1665 "parser.tab.c"
    break;

  case 44: /* expr: NUM  */
#line 260 "parser.y"
        {
        (yyval.node) = createNum((yyvsp[0].num));
    }
#line 1673 "parser.tab.c"
    break;

  case 45: /* expr: FLOAT_NUM  */
#line 263 "parser.y"
                {
        (yyval.node) = createFloatNum((yyvsp[0].fnum));
    }
#line 1681 "parser.tab.c"
    break;

  case 46: /* expr: ID  */
#line 266 "parser.y"
         {
        (yyval.node) = createVar((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1690 "parser.tab.c"
    break;

  case 47: /* expr: expr '+' expr  */
#line 270 "parser.y"
                    {
        (yyval.node) = createBinOp('+', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1698 "parser.tab.c"
    break;

  case 48: /* expr: expr '-' expr  */
#line 273 "parser.y"
                    {
        (yyval.node) = createBinOp('-', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1706 "parser.tab.c"
    break;

  case 49: /* expr: expr '*' expr  */
#line 276 "parser.y"
                    {
        (yyval.node) = createBinOp('*', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1714 "parser.tab.c"
    break;

  case 50: /* expr: expr '/' expr  */
#line 279 "parser.y"
                    {
        (yyval.node) = createBinOp('/', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1722 "parser.tab.c"
    break;

  case 51: /* expr: expr '%' expr  */
#line 282 "parser.y"
                    {
        (yyval.node) = createBinOp('%', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1730 "parser.tab.c"
    break;

  case 52: /* expr: expr '<' expr  */
#line 285 "parser.y"
                    {
        (yyval.node) = createBinOp('<', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1738 "parser.tab.c"
    break;

  case 53: /* expr: expr '>' expr  */
#line 288 "parser.y"
                    {
        (yyval.node) = createBinOp('>', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1746 "parser.tab.c"
    break;

  case 54: /* expr: expr EQ expr  */
#line 291 "parser.y"
                   {
        (yyval.node) = createBinOp('=', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1754 "parser.tab.c"
    break;

  case 55: /* expr: expr AND expr  */
#line 294 "parser.y"
                    {
        (yyval.node) = createBinOp('&', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1762 "parser.tab.c"
    break;

  case 56: /* expr: expr OR expr  */
#line 297 "parser.y"
                   {
        (yyval.node) = createBinOp('|', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1770 "parser.tab.c"
    break;

  case 57: /* expr: NOT expr  */
#line 300 "parser.y"
               {
        /* Logical NOT unary operator */
        (yyval.node) = createBinOp('!', (yyvsp[0].node), NULL);
    }
#line 1779 "parser.tab.c"
    break;

  case 58: /* expr: LPAREN expr RPAREN  */
#line 304 "parser.y"
                         {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1787 "parser.tab.c"
    break;

  case 59: /* expr: LBRACE stmt_list RBRACE  */
#line 307 "parser.y"
                              {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1795 "parser.tab.c"
    break;

  case 60: /* expr: ID LBRACKET expr RBRACKET  */
#line 310 "parser.y"
                                {
        (yyval.node) = createArrayAccess((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1804 "parser.tab.c"
    break;

  case 61: /* expr: ID LBRACKET expr RBRACKET LBRACKET expr RBRACKET  */
#line 314 "parser.y"
                                                       {
        (yyval.node) = createArray2DAccess((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-6].str));
    }
#line 1813 "parser.tab.c"
    break;

  case 62: /* expr: ID LPAREN expr RPAREN  */
#line 318 "parser.y"
                            {
        /* Function call with argument as expression */
        (yyval.node) = createCallExpr((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1823 "parser.tab.c"
    break;

  case 63: /* expr: ID LPAREN RPAREN  */
#line 323 "parser.y"
                       {
        /* Function call without arguments as expression */
        (yyval.node) = createCallExpr((yyvsp[-2].str), NULL);
        free((yyvsp[-2].str));
    }
#line 1833 "parser.tab.c"
    break;

  case 64: /* expr: expr IS value_list  */
#line 328 "parser.y"
                         {
        /* Multi-value equality check: expr is val1, val2, val3 */
        (yyval.node) = createMultiValueCheck((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1842 "parser.tab.c"
    break;

  case 65: /* print_stmt: PRINT LPAREN expr RPAREN ';'  */
#line 336 "parser.y"
                                 {
        (yyval.node) = createPrint((yyvsp[-2].node));
    }
#line 1850 "parser.tab.c"
    break;

  case 66: /* while_stmt: WHILE LPAREN expr RPAREN stmt  */
#line 343 "parser.y"
                                  {
        (yyval.node) = createWhile((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1858 "parser.tab.c"
    break;

  case 67: /* while_stmt: WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 346 "parser.y"
                                                       {
        (yyval.node) = createWhile((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1866 "parser.tab.c"
    break;

  case 68: /* for_stmt: FOR LPAREN ID '=' expr ';' expr ';' ID '=' expr RPAREN stmt  */
#line 353 "parser.y"
                                                                {
        ASTNode* init = createAssign((yyvsp[-10].str), (yyvsp[-8].node));
        ASTNode* update = createAssign((yyvsp[-4].str), (yyvsp[-2].node));
        (yyval.node) = createFor(init, (yyvsp[-6].node), update, (yyvsp[0].node));
        free((yyvsp[-10].str));
        free((yyvsp[-4].str));
    }
#line 1878 "parser.tab.c"
    break;

  case 69: /* for_stmt: FOR LPAREN ID '=' expr ';' expr ';' ID '=' expr RPAREN LBRACE stmt_list RBRACE  */
#line 360 "parser.y"
                                                                                     {
        ASTNode* init = createAssign((yyvsp[-12].str), (yyvsp[-10].node));
        ASTNode* update = createAssign((yyvsp[-6].str), (yyvsp[-4].node));
        (yyval.node) = createFor(init, (yyvsp[-8].node), update, (yyvsp[-1].node));
        free((yyvsp[-12].str));
        free((yyvsp[-6].str));
    }
#line 1890 "parser.tab.c"
    break;

  case 70: /* if_stmt: IF LPAREN expr RPAREN stmt  */
#line 370 "parser.y"
                               {
        (yyval.node) = createIf((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1898 "parser.tab.c"
    break;

  case 71: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 373 "parser.y"
                                                    {
        (yyval.node) = createIf((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1906 "parser.tab.c"
    break;

  case 72: /* if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt  */
#line 376 "parser.y"
                                           {
        (yyval.node) = createIfElse((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1914 "parser.tab.c"
    break;

  case 73: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE stmt  */
#line 379 "parser.y"
                                                              {
        (yyval.node) = createIfElse((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[0].node));
    }
#line 1922 "parser.tab.c"
    break;

  case 74: /* if_stmt: IF LPAREN expr RPAREN stmt ELSE LBRACE stmt_list RBRACE  */
#line 382 "parser.y"
                                                              {
        (yyval.node) = createIfElse((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1930 "parser.tab.c"
    break;

  case 75: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE  */
#line 385 "parser.y"
                                                                                 {
        (yyval.node) = createIfElse((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node));
    }
#line 1938 "parser.tab.c"
    break;

  case 76: /* value_list: expr  */
#line 392 "parser.y"
         {
        /* Single value */
        (yyval.node) = createValueList((yyvsp[0].node), NULL);
    }
#line 1947 "parser.tab.c"
    break;

  case 77: /* value_list: expr COMMA value_list  */
#line 396 "parser.y"
                            {
        /* Multiple values */
        (yyval.node) = createValueList((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1956 "parser.tab.c"
    break;


#line 1960 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 402 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}
