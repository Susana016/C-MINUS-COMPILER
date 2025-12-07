/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     VOID = 262,
     DOUBLE = 263,
     OUTPUT = 264,
     INPUT = 265,
     LPAREN = 266,
     RPAREN = 267,
     LBRACE = 268,
     RBRACE = 269,
     SEMICOLON = 270,
     LBRACKET = 271,
     RBRACKET = 272,
     COMMA = 273,
     MAIN = 274,
     RETURN = 275,
     PRINT = 276,
     WHILE = 277,
     FOR = 278,
     IF = 279,
     ELSE = 280,
     AND = 281,
     OR = 282,
     NOT = 283,
     EQ = 284,
     LE = 285,
     GE = 286,
     NEQ = 287,
     IS = 288,
     SWITCH = 289,
     CASE = 290,
     DEFAULT = 291,
     BREAK = 292,
     COLON = 293,
     LOWER_THAN_ELSE = 294,
     UMINUS = 295
   };
#endif
/* Tokens.  */
#define NUM 258
#define FLOAT_NUM 259
#define ID 260
#define INT 261
#define VOID 262
#define DOUBLE 263
#define OUTPUT 264
#define INPUT 265
#define LPAREN 266
#define RPAREN 267
#define LBRACE 268
#define RBRACE 269
#define SEMICOLON 270
#define LBRACKET 271
#define RBRACKET 272
#define COMMA 273
#define MAIN 274
#define RETURN 275
#define PRINT 276
#define WHILE 277
#define FOR 278
#define IF 279
#define ELSE 280
#define AND 281
#define OR 282
#define NOT 283
#define EQ 284
#define LE 285
#define GE 286
#define NEQ 287
#define IS 288
#define SWITCH 289
#define CASE 290
#define DEFAULT 291
#define BREAK 292
#define COLON 293
#define LOWER_THAN_ELSE 294
#define UMINUS 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "parser.y"
{
    int num;
    double fnum;
    char* str;
    struct ASTNode* node;
}
/* Line 1529 of yacc.c.  */
#line 136 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

