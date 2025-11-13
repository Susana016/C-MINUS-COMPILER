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
  YYSYMBOL_SWITCH = 28,                    /* SWITCH  */
  YYSYMBOL_CASE = 29,                      /* CASE  */
  YYSYMBOL_DEFAULT = 30,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_COLON = 32,                     /* COLON  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '%'  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_global_decl_list = 44,          /* global_decl_list  */
  YYSYMBOL_global_decl = 45,               /* global_decl  */
  YYSYMBOL_function_list = 46,             /* function_list  */
  YYSYMBOL_function_decl = 47,             /* function_decl  */
  YYSYMBOL_param_list = 48,                /* param_list  */
  YYSYMBOL_stmt_list = 49,                 /* stmt_list  */
  YYSYMBOL_stmt = 50,                      /* stmt  */
  YYSYMBOL_decl = 51,                      /* decl  */
  YYSYMBOL_assign = 52,                    /* assign  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_print_stmt = 54,                /* print_stmt  */
  YYSYMBOL_while_stmt = 55,                /* while_stmt  */
  YYSYMBOL_for_stmt = 56,                  /* for_stmt  */
  YYSYMBOL_if_stmt = 57,                   /* if_stmt  */
  YYSYMBOL_switch_stmt = 58,               /* switch_stmt  */
  YYSYMBOL_case_list = 59,                 /* case_list  */
  YYSYMBOL_case_stmt = 60,                 /* case_stmt  */
  YYSYMBOL_value_list = 61                 /* value_list  */
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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   868

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  229

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    66,    71,    77,    87,    90,    96,   101,
     106,   111,   116,   128,   131,   137,   142,   147,   151,   159,
     163,   167,   171,   175,   185,   188,   194,   195,   196,   197,
     198,   199,   200,   201,   204,   207,   210,   215,   224,   228,
     232,   236,   240,   248,   252,   256,   267,   270,   273,   277,
     280,   283,   286,   289,   292,   295,   298,   301,   304,   307,
     311,   314,   317,   321,   325,   330,   335,   343,   350,   353,
     360,   367,   377,   380,   383,   386,   389,   392,   399,   405,
     408,   415,   418,   421,   424,   431,   435
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
  "RBRACKET", "COMMA", "AND", "OR", "NOT", "EQ", "IS", "SWITCH", "CASE",
  "DEFAULT", "BREAK", "COLON", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "';'", "'='", "$accept", "program", "global_decl_list",
  "global_decl", "function_list", "function_decl", "param_list",
  "stmt_list", "stmt", "decl", "assign", "expr", "print_stmt",
  "while_stmt", "for_stmt", "if_stmt", "switch_stmt", "case_list",
  "case_stmt", "value_list", YY_NULLPTR
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    60,    62,    43,    45,    42,    47,    37,
      59,    61
};
#endif

#define YYPACT_NINF (-19)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -19,   -19,   -19,   219,   225,   -11,   163,   -13,    13,   -19,
     -19,    -8,   -19,   -19,   -19,   -19,   -19,    64,   -19,    96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,   100,    17,    18,    19,
      20,   118,    21,    22,    23,    24,    25,   174,   175,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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
static const yytype_int8 yystos[] =
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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
#line 61 "parser.y"
                                   {
        /* Program consists of optional global declarations followed by functions */
        (yyval.node) = createProgram((yyvsp[-1].node), (yyvsp[0].node));
        root = (yyval.node);
    }
#line 1401 "parser.tab.c"
    break;

  case 3: /* program: function_list  */
#line 66 "parser.y"
                    {
        /* Program with only functions, no global variables */
        (yyval.node) = createProgram(NULL, (yyvsp[0].node));
        root = (yyval.node);
    }
#line 1411 "parser.tab.c"
    break;

  case 4: /* program: stmt_list  */
#line 71 "parser.y"
                {
        /* Old style: statements only - wrap in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, (yyvsp[0].node));
        (yyval.node) = createProgram(NULL, mainFunc);
        root = (yyval.node);
    }
#line 1422 "parser.tab.c"
    break;

  case 5: /* program: global_decl_list stmt_list  */
#line 77 "parser.y"
                                 {
        /* Old style with globals: wrap statements in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, (yyvsp[0].node));
        (yyval.node) = createProgram((yyvsp[-1].node), mainFunc);
        root = (yyval.node);
    }
#line 1433 "parser.tab.c"
    break;

  case 6: /* global_decl_list: global_decl  */
#line 87 "parser.y"
                {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1441 "parser.tab.c"
    break;

  case 7: /* global_decl_list: global_decl_list global_decl  */
#line 90 "parser.y"
                                   {
        (yyval.node) = createStmtList((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1449 "parser.tab.c"
    break;

  case 8: /* global_decl: INT ID ';'  */
#line 96 "parser.y"
               {
        /* Global variable: int x; */
        (yyval.node) = createGlobalDecl((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1459 "parser.tab.c"
    break;

  case 9: /* global_decl: DOUBLE ID ';'  */
#line 101 "parser.y"
                    {
        /* Global double: double x; */
        (yyval.node) = createGlobalDeclDouble((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1469 "parser.tab.c"
    break;

  case 10: /* global_decl: INT ID '=' expr ';'  */
#line 106 "parser.y"
                          {
        /* Global with initialization: int x = 10; */
        (yyval.node) = createGlobalDeclInit((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1479 "parser.tab.c"
    break;

  case 11: /* global_decl: INT ID LBRACKET NUM RBRACKET ';'  */
#line 111 "parser.y"
                                       {
        /* Global 1D array: int arr[10]; */
        (yyval.node) = createGlobalArrayDecl((yyvsp[-4].str), (yyvsp[-2].num));
        free((yyvsp[-4].str));
    }
#line 1489 "parser.tab.c"
    break;

  case 12: /* global_decl: INT ID LBRACKET NUM RBRACKET LBRACKET NUM RBRACKET ';'  */
#line 116 "parser.y"
                                                             {
        /* Global 2D array: int matrix[5][5]; */
        (yyval.node) = createGlobalArray2DDecl((yyvsp[-7].str), (yyvsp[-5].num), (yyvsp[-2].num));
        free((yyvsp[-7].str));
    }
#line 1499 "parser.tab.c"
    break;

  case 13: /* function_list: function_decl  */
#line 128 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1507 "parser.tab.c"
    break;

  case 14: /* function_list: function_list function_decl  */
#line 131 "parser.y"
                                  {
        (yyval.node) = createFunctionList((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1515 "parser.tab.c"
    break;

  case 15: /* function_decl: INT ID LPAREN param_list RPAREN LBRACE stmt_list RBRACE  */
#line 137 "parser.y"
                                                            {
        /* int function_name(params) { body } */
        (yyval.node) = createFunction((yyvsp[-6].str), "int", (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-6].str));
    }
#line 1525 "parser.tab.c"
    break;

  case 16: /* function_decl: VOID ID LPAREN param_list RPAREN LBRACE stmt_list RBRACE  */
#line 142 "parser.y"
                                                               {
        /* void function_name(params) { body } */
        (yyval.node) = createFunction((yyvsp[-6].str), "void", (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-6].str));
    }
#line 1535 "parser.tab.c"
    break;

  case 17: /* function_decl: INT MAIN LPAREN RPAREN LBRACE stmt_list RBRACE  */
#line 147 "parser.y"
                                                     {
        /* Special case: int main() { body } */
        (yyval.node) = createFunction("main", "int", NULL, (yyvsp[-1].node));
    }
#line 1544 "parser.tab.c"
    break;

  case 18: /* function_decl: VOID MAIN LPAREN RPAREN LBRACE stmt_list RBRACE  */
#line 151 "parser.y"
                                                      {
        /* void main() { body } */
        (yyval.node) = createFunction("main", "void", NULL, (yyvsp[-1].node));
    }
#line 1553 "parser.tab.c"
    break;

  case 19: /* param_list: INT ID  */
#line 159 "parser.y"
           {
        (yyval.node) = createParameter((yyvsp[0].str), "int", NULL);
        free((yyvsp[0].str));
    }
#line 1562 "parser.tab.c"
    break;

  case 20: /* param_list: DOUBLE ID  */
#line 163 "parser.y"
                {
        (yyval.node) = createParameter((yyvsp[0].str), "double", NULL);
        free((yyvsp[0].str));
    }
#line 1571 "parser.tab.c"
    break;

  case 21: /* param_list: param_list COMMA INT ID  */
#line 167 "parser.y"
                              {
        (yyval.node) = createParameter((yyvsp[0].str), "int", (yyvsp[-3].node));
        free((yyvsp[0].str));
    }
#line 1580 "parser.tab.c"
    break;

  case 22: /* param_list: param_list COMMA DOUBLE ID  */
#line 171 "parser.y"
                                 {
        (yyval.node) = createParameter((yyvsp[0].str), "double", (yyvsp[-3].node));
        free((yyvsp[0].str));
    }
#line 1589 "parser.tab.c"
    break;

  case 23: /* param_list: %empty  */
#line 175 "parser.y"
                  {
        (yyval.node) = NULL;
    }
#line 1597 "parser.tab.c"
    break;

  case 24: /* stmt_list: stmt  */
#line 185 "parser.y"
         {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1605 "parser.tab.c"
    break;

  case 25: /* stmt_list: stmt_list stmt  */
#line 188 "parser.y"
                     {
        (yyval.node) = createStmtList((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1613 "parser.tab.c"
    break;

  case 33: /* stmt: BREAK ';'  */
#line 201 "parser.y"
                {
        (yyval.node) = createBreak();
    }
#line 1621 "parser.tab.c"
    break;

  case 34: /* stmt: RETURN expr ';'  */
#line 204 "parser.y"
                      {
        (yyval.node) = createReturn((yyvsp[-1].node));
    }
#line 1629 "parser.tab.c"
    break;

  case 35: /* stmt: RETURN ';'  */
#line 207 "parser.y"
                 {
        (yyval.node) = createReturn(NULL);
    }
#line 1637 "parser.tab.c"
    break;

  case 36: /* stmt: ID LPAREN expr RPAREN ';'  */
#line 210 "parser.y"
                                {
        /* Function call with argument */
        (yyval.node) = createCall((yyvsp[-4].str), (yyvsp[-2].node));
        free((yyvsp[-4].str));
    }
#line 1647 "parser.tab.c"
    break;

  case 37: /* stmt: ID LPAREN RPAREN ';'  */
#line 215 "parser.y"
                           {
        /* Function call without arguments */
        (yyval.node) = createCall((yyvsp[-3].str), NULL);
        free((yyvsp[-3].str));
    }
#line 1657 "parser.tab.c"
    break;

  case 38: /* decl: INT ID ';'  */
#line 224 "parser.y"
               {
        (yyval.node) = createDecl((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1666 "parser.tab.c"
    break;

  case 39: /* decl: DOUBLE ID ';'  */
#line 228 "parser.y"
                    {
        (yyval.node) = createDeclDouble((yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1675 "parser.tab.c"
    break;

  case 40: /* decl: INT ID '=' expr ';'  */
#line 232 "parser.y"
                          {
        (yyval.node) = createDeclInit((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1684 "parser.tab.c"
    break;

  case 41: /* decl: INT ID LBRACKET NUM RBRACKET ';'  */
#line 236 "parser.y"
                                       {
        (yyval.node) = createArrayDecl((yyvsp[-4].str), (yyvsp[-2].num));
        free((yyvsp[-4].str));
    }
#line 1693 "parser.tab.c"
    break;

  case 42: /* decl: INT ID LBRACKET NUM RBRACKET LBRACKET NUM RBRACKET ';'  */
#line 240 "parser.y"
                                                             {
        (yyval.node) = createArray2DDecl((yyvsp[-7].str), (yyvsp[-5].num), (yyvsp[-2].num));
        free((yyvsp[-7].str));
    }
#line 1702 "parser.tab.c"
    break;

  case 43: /* assign: ID '=' expr ';'  */
#line 248 "parser.y"
                    {
        (yyval.node) = createAssign((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1711 "parser.tab.c"
    break;

  case 44: /* assign: ID LBRACKET expr RBRACKET '=' expr ';'  */
#line 252 "parser.y"
                                             {
        (yyval.node) = createArrayAssign((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-6].str));
    }
#line 1720 "parser.tab.c"
    break;

  case 45: /* assign: ID LBRACKET expr RBRACKET LBRACKET expr RBRACKET '=' expr ';'  */
#line 256 "parser.y"
                                                                    {
        (yyval.node) = createArray2DAssign((yyvsp[-9].str), (yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-9].str));
    }
#line 1729 "parser.tab.c"
    break;

  case 46: /* expr: NUM  */
#line 267 "parser.y"
        {
        (yyval.node) = createNum((yyvsp[0].num));
    }
#line 1737 "parser.tab.c"
    break;

  case 47: /* expr: FLOAT_NUM  */
#line 270 "parser.y"
                {
        (yyval.node) = createFloatNum((yyvsp[0].fnum));
    }
#line 1745 "parser.tab.c"
    break;

  case 48: /* expr: ID  */
#line 273 "parser.y"
         {
        (yyval.node) = createVar((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1754 "parser.tab.c"
    break;

  case 49: /* expr: expr '+' expr  */
#line 277 "parser.y"
                    {
        (yyval.node) = createBinOp('+', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1762 "parser.tab.c"
    break;

  case 50: /* expr: expr '-' expr  */
#line 280 "parser.y"
                    {
        (yyval.node) = createBinOp('-', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1770 "parser.tab.c"
    break;

  case 51: /* expr: expr '*' expr  */
#line 283 "parser.y"
                    {
        (yyval.node) = createBinOp('*', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1778 "parser.tab.c"
    break;

  case 52: /* expr: expr '/' expr  */
#line 286 "parser.y"
                    {
        (yyval.node) = createBinOp('/', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1786 "parser.tab.c"
    break;

  case 53: /* expr: expr '%' expr  */
#line 289 "parser.y"
                    {
        (yyval.node) = createBinOp('%', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1794 "parser.tab.c"
    break;

  case 54: /* expr: expr '<' expr  */
#line 292 "parser.y"
                    {
        (yyval.node) = createBinOp('<', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1802 "parser.tab.c"
    break;

  case 55: /* expr: expr '>' expr  */
#line 295 "parser.y"
                    {
        (yyval.node) = createBinOp('>', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1810 "parser.tab.c"
    break;

  case 56: /* expr: expr EQ expr  */
#line 298 "parser.y"
                   {
        (yyval.node) = createBinOp('=', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1818 "parser.tab.c"
    break;

  case 57: /* expr: expr AND expr  */
#line 301 "parser.y"
                    {
        (yyval.node) = createBinOp('&', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1826 "parser.tab.c"
    break;

  case 58: /* expr: expr OR expr  */
#line 304 "parser.y"
                   {
        (yyval.node) = createBinOp('|', (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1834 "parser.tab.c"
    break;

  case 59: /* expr: NOT expr  */
#line 307 "parser.y"
               {
        /* Logical NOT unary operator */
        (yyval.node) = createBinOp('!', (yyvsp[0].node), NULL);
    }
#line 1843 "parser.tab.c"
    break;

  case 60: /* expr: LPAREN expr RPAREN  */
#line 311 "parser.y"
                         {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1851 "parser.tab.c"
    break;

  case 61: /* expr: LBRACE stmt_list RBRACE  */
#line 314 "parser.y"
                              {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1859 "parser.tab.c"
    break;

  case 62: /* expr: ID LBRACKET expr RBRACKET  */
#line 317 "parser.y"
                                {
        (yyval.node) = createArrayAccess((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1868 "parser.tab.c"
    break;

  case 63: /* expr: ID LBRACKET expr RBRACKET LBRACKET expr RBRACKET  */
#line 321 "parser.y"
                                                       {
        (yyval.node) = createArray2DAccess((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-6].str));
    }
#line 1877 "parser.tab.c"
    break;

  case 64: /* expr: ID LPAREN expr RPAREN  */
#line 325 "parser.y"
                            {
        /* Function call with argument as expression */
        (yyval.node) = createCallExpr((yyvsp[-3].str), (yyvsp[-1].node));
        free((yyvsp[-3].str));
    }
#line 1887 "parser.tab.c"
    break;

  case 65: /* expr: ID LPAREN RPAREN  */
#line 330 "parser.y"
                       {
        /* Function call without arguments as expression */
        (yyval.node) = createCallExpr((yyvsp[-2].str), NULL);
        free((yyvsp[-2].str));
    }
#line 1897 "parser.tab.c"
    break;

  case 66: /* expr: expr IS value_list  */
#line 335 "parser.y"
                         {
        /* Multi-value equality check: expr is val1, val2, val3 */
        (yyval.node) = createMultiValueCheck((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1906 "parser.tab.c"
    break;

  case 67: /* print_stmt: PRINT LPAREN expr RPAREN ';'  */
#line 343 "parser.y"
                                 {
        (yyval.node) = createPrint((yyvsp[-2].node));
    }
#line 1914 "parser.tab.c"
    break;

  case 68: /* while_stmt: WHILE LPAREN expr RPAREN stmt  */
#line 350 "parser.y"
                                  {
        (yyval.node) = createWhile((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1922 "parser.tab.c"
    break;

  case 69: /* while_stmt: WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 353 "parser.y"
                                                       {
        (yyval.node) = createWhile((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1930 "parser.tab.c"
    break;

  case 70: /* for_stmt: FOR LPAREN ID '=' expr ';' expr ';' ID '=' expr RPAREN stmt  */
#line 360 "parser.y"
                                                                {
        ASTNode* init = createAssign((yyvsp[-10].str), (yyvsp[-8].node));
        ASTNode* update = createAssign((yyvsp[-4].str), (yyvsp[-2].node));
        (yyval.node) = createFor(init, (yyvsp[-6].node), update, (yyvsp[0].node));
        free((yyvsp[-10].str));
        free((yyvsp[-4].str));
    }
#line 1942 "parser.tab.c"
    break;

  case 71: /* for_stmt: FOR LPAREN ID '=' expr ';' expr ';' ID '=' expr RPAREN LBRACE stmt_list RBRACE  */
#line 367 "parser.y"
                                                                                     {
        ASTNode* init = createAssign((yyvsp[-12].str), (yyvsp[-10].node));
        ASTNode* update = createAssign((yyvsp[-6].str), (yyvsp[-4].node));
        (yyval.node) = createFor(init, (yyvsp[-8].node), update, (yyvsp[-1].node));
        free((yyvsp[-12].str));
        free((yyvsp[-6].str));
    }
#line 1954 "parser.tab.c"
    break;

  case 72: /* if_stmt: IF LPAREN expr RPAREN stmt  */
#line 377 "parser.y"
                               {
        (yyval.node) = createIf((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1962 "parser.tab.c"
    break;

  case 73: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE  */
#line 380 "parser.y"
                                                    {
        (yyval.node) = createIf((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1970 "parser.tab.c"
    break;

  case 74: /* if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt  */
#line 383 "parser.y"
                                           {
        (yyval.node) = createIfElse((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1978 "parser.tab.c"
    break;

  case 75: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE stmt  */
#line 386 "parser.y"
                                                              {
        (yyval.node) = createIfElse((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[0].node));
    }
#line 1986 "parser.tab.c"
    break;

  case 76: /* if_stmt: IF LPAREN expr RPAREN stmt ELSE LBRACE stmt_list RBRACE  */
#line 389 "parser.y"
                                                              {
        (yyval.node) = createIfElse((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1994 "parser.tab.c"
    break;

  case 77: /* if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE  */
#line 392 "parser.y"
                                                                                 {
        (yyval.node) = createIfElse((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node));
    }
#line 2002 "parser.tab.c"
    break;

  case 78: /* switch_stmt: SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE  */
#line 399 "parser.y"
                                                      {
        (yyval.node) = createSwitch((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 2010 "parser.tab.c"
    break;

  case 79: /* case_list: case_stmt  */
#line 405 "parser.y"
              {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2018 "parser.tab.c"
    break;

  case 80: /* case_list: case_stmt case_list  */
#line 408 "parser.y"
                          {
        (yyvsp[-1].node)->data.casestmt.next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2027 "parser.tab.c"
    break;

  case 81: /* case_stmt: CASE NUM COLON stmt_list  */
#line 415 "parser.y"
                             {
        (yyval.node) = createCase((yyvsp[-2].num), (yyvsp[0].node), NULL);
    }
#line 2035 "parser.tab.c"
    break;

  case 82: /* case_stmt: CASE NUM COLON  */
#line 418 "parser.y"
                     {
        (yyval.node) = createCase((yyvsp[-1].num), NULL, NULL);
    }
#line 2043 "parser.tab.c"
    break;

  case 83: /* case_stmt: DEFAULT COLON stmt_list  */
#line 421 "parser.y"
                              {
        (yyval.node) = createDefault((yyvsp[0].node));
    }
#line 2051 "parser.tab.c"
    break;

  case 84: /* case_stmt: DEFAULT COLON  */
#line 424 "parser.y"
                    {
        (yyval.node) = createDefault(NULL);
    }
#line 2059 "parser.tab.c"
    break;

  case 85: /* value_list: expr  */
#line 431 "parser.y"
         {
        /* Single value */
        (yyval.node) = createValueList((yyvsp[0].node), NULL);
    }
#line 2068 "parser.tab.c"
    break;

  case 86: /* value_list: expr COMMA value_list  */
#line 435 "parser.y"
                            {
        /* Multiple values */
        (yyval.node) = createValueList((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2077 "parser.tab.c"
    break;


#line 2081 "parser.tab.c"

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

#line 441 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}
