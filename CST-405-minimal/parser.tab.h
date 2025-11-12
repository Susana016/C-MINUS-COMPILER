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
     NOT = 280
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "parser.y"
{
    int num;
    double fnum;
    char* str;
    struct ASTNode* node;
}
/* Line 1529 of yacc.c.  */
#line 106 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

