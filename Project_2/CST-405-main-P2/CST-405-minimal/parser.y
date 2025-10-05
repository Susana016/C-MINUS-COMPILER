%{
/* SYNTAX ANALYZER (PARSER)
 * This is the second phase of compilation - checking grammar rules
 * Bison generates a parser that builds an Abstract Syntax Tree (AST)
 * The parser uses tokens from the scanner to verify syntax is correct
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

/* External declarations for lexer interface */
extern int yylex();      /* Get next token from scanner */
extern int yyparse();    /* Parse the entire input */
extern FILE* yyin;       /* Input file handle */

void yyerror(const char* s);  /* Error handling function */
ASTNode* root = NULL;          /* Root of the Abstract Syntax Tree */
%}

/* SEMANTIC VALUES UNION
 * Defines possible types for tokens and grammar symbols
 * This allows different grammar rules to return different data types
 */
%union {
    int num;                /* For integer literals */
    char* str;              /* For identifiers */
    struct ASTNode* node;   /* For AST nodes */
}

/* TOKEN DECLARATIONS with their semantic value types */
%token <num> NUM              /* Number token carries an integer value */
%token <str> ID               /* Identifier token carries a string */
%token INT PRINT /* IF ELSE */ /* Keywords have no semantic value; IF/ELSE disabled */
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE

/* NON-TERMINAL TYPES - Define what type each grammar rule returns */
%type <node> program stmt_list stmt decl assign expr print_stmt 

/* OPERATOR PRECEDENCE AND ASSOCIATIVITY */
%left '+'  /* Addition is left-associative: a+b+c = (a+b)+c */

%%

/* GRAMMAR RULES - Define the structure of our language */

/* PROGRAM RULE - Entry point of our grammar */
program:
    stmt_list { 
        /* Action: Save the statement list as our AST root */
        root = $1;  /* $1 refers to the first symbol (stmt_list) */
    }
    ;

/* STATEMENT LIST - Handles multiple statements */
stmt_list:
    stmt { 
        /* Base case: single statement */
        $$ = $1;  /* Pass the statement up as-is */
    }
    | stmt_list stmt { 
        /* Recursive case: list followed by another statement */
        $$ = createStmtList($1, $2);  /* Build linked list of statements */
    }
    ;

/* STATEMENT TYPES - The three kinds of statements we support */
stmt:
    decl        /* Variable declaration */
    | assign    /* Assignment statement */
    | print_stmt /* Print statement */
    ;

/* DECLARATION RULE - "int x;" */
decl:
    INT ID ';' { 
        /* Create declaration node and free the identifier string */
        $$ = createDecl($2);  /* $2 is the ID token's string value */
        free($2);             /* Free the string copy from scanner */
    }
    | INT ID '=' expr ';' {
        /* Declaration with initialization: int x = 5; */
        ASTNode* decl = createDecl($2);
        ASTNode* assign = createAssign($2, $4);
        $$ = createStmtList(decl, assign);
        free($2);
    }
    | INT ID LBRACKET NUM RBRACKET ';' { 
        /* 1D Array declaration (e.g., int arr[10];) */
        $$ = createArrayDecl($2, $4);  /* $2 = ID, $4 = NUM size */
        free($2);                      /* Free the identifier string */
    }
    | INT ID LBRACKET NUM RBRACKET LBRACKET NUM RBRACKET ';' { 
        /* 2D Array declaration (e.g., int matrix[3][4];) */
        $$ = createArray2DDecl($2, $4, $7);  /* $2=ID, $4=rows, $7=cols */
        free($2);                            /* Free the identifier string */
    }
    ;

/* ASSIGNMENT RULE - "x = expr;" */
assign:
    ID '=' expr ';' { 
        /* Create assignment node with variable name and expression */
        $$ = createAssign($1, $3);  /* $1 = ID, $3 = expr */
        free($1);                   /* Free the identifier string */
    }
    | ID LBRACKET expr RBRACKET '=' expr ';' { 
        /* 1D Array element assignment (e.g., arr[2] = expr;) */
        $$ = createArrayAssign($1, $3, $6);  /* $1=ID, $3=index expr, $6=value expr */
        free($1);                            /* Free the identifier string */
    }
    | ID LBRACKET expr RBRACKET LBRACKET expr RBRACKET '=' expr ';' { 
        /* 2D Array element assignment (e.g., matrix[1][2] = expr;) */
        $$ = createArray2DAssign($1, $3, $6, $9);  /* $1=ID, $3=row, $6=col, $9=value */
        free($1);                                  /* Free the identifier string */
    }
    ;

/* EXPRESSION RULES - Build expression trees */
expr:
    NUM { 
        /* Literal number */
        $$ = createNum($1);  /* Create leaf node with number value */
    }
    | ID { 
        /* Variable reference */
        $$ = createVar($1);  /* Create leaf node with variable name */
        free($1);            /* Free the identifier string */
    }
    | expr '+' expr { 
        /* Addition operation - builds binary tree */
        $$ = createBinOp('+', $1, $3);  /* Left child, op, right child */
    }
    | ID LBRACKET expr RBRACKET { 
        /* 1D Array element access (e.g., arr[2]) */
        $$ = createArrayAccess($1, $3);  /* $1=ID, $3=index expr */
        free($1);                        /* Free the identifier string */
    }
    | ID LBRACKET expr RBRACKET LBRACKET expr RBRACKET { 
        /* 2D Array element access (e.g., matrix[1][2]) */
        $$ = createArray2DAccess($1, $3, $6);  /* $1=ID, $3=row, $6=col */
        free($1);                              /* Free the identifier string */
    }
    ;

/* PRINT STATEMENT - "print(expr);" */
print_stmt:
    PRINT LPAREN expr RPAREN ';' { 
        /* Create print node with expression to print */
        $$ = createPrint($3);  /* $3 is the expression inside parens */
    }
    ;

/* IF/ELSE grammar removed - if/else functionality disabled. */
%%

/* ERROR HANDLING - Called by Bison when syntax error detected */
void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}