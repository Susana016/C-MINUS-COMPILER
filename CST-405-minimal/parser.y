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
    double fnum;            /* For floating-point literals */
    char* str;              /* For identifiers */
    struct ASTNode* node;   /* For AST nodes */
}

/* TOKEN DECLARATIONS with their semantic value types */
%token <num> NUM              /* Number token carries an integer value */
%token <fnum> FLOAT_NUM       /* Floating-point number token */
%token <str> ID               /* Identifier token carries a string */
%token INT DOUBLE PRINT /* IF ELSE */ /* Keywords have no semantic value; IF/ELSE disabled */
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET/* Braces and parentheses */

/* NON-TERMINAL TYPES - Define what type each grammar rule returns */
%type <node> program stmt_list stmt decl assign expr print_stmt /* if_stmt if_else_stmt disabled */

/* OPERATOR PRECEDENCE AND ASSOCIATIVITY */
%left '+' '-'  /* Addition and subtraction (lowest precedence) */
%left '*' '/'  /* Multiplication and division (higher precedence) */

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

/* DECLARATION RULE - "int x;" or "double x;" */
decl:
    INT ID ';' { 
        /* Create integer declaration node */
        $$ = createDecl($2);
        free($2);
    }
    | DOUBLE ID ';' { 
        /* Create double declaration node */
        $$ = createDeclDouble($2);
        free($2);
    }
    | INT ID LBRACKET NUM RBRACKET ';' {
        /* Simple array declaration */
        $$ = createDecl($2);
        free($2);
    }
    ;

/* ASSIGNMENT RULE - "x = expr;" */
assign:
    ID '=' expr ';' { 
        /* Create assignment node with variable name and expression */
        $$ = createAssign($1, $3);  /* $1 = ID, $3 = expr */
        free($1);                   /* Free the identifier string */
    }
    ;

/* EXPRESSION RULES - Build expression trees */
expr:
    NUM { 
        /* Integer literal */
        $$ = createNum($1);
    }
    | FLOAT_NUM {
        /* Floating-point literal */
        $$ = createFloatNum($1);
    }
    | ID { 
        /* Variable reference */
        $$ = createVar($1);
        free($1);
    }
    | expr '+' expr { 
        /* Addition operation */
        $$ = createBinOp('+', $1, $3);
    }
    | expr '-' expr { 
        /* Subtraction operation */
        $$ = createBinOp('-', $1, $3);
    }
    | expr '*' expr { 
        /* Multiplication operation */
        $$ = createBinOp('*', $1, $3);
    }
    | expr '/' expr { 
        /* Division operation */
        $$ = createBinOp('/', $1, $3);
    }
    | LPAREN expr RPAREN { 
        /* Parenthesized expression */
        $$ = $2;
    }
    | LBRACE stmt_list RBRACE { 
        /* Block of statements */
        $$ = $2;
    }
    | LBRACKET expr RBRACKET { 
        /* Array access expression */
        $$ = createArrayAccess($2);
    }
    ;

/* PRINT STATEMENT - "print(expr);" */
print_stmt:
    PRINT LPAREN expr RPAREN ';' { 
        /* Create print node with expression to print */
        $$ = createPrint($3);
    }
    ;

/* IF/ELSE grammar removed - if/else functionality disabled. */
%%

/* ERROR HANDLING - Called by Bison when syntax error detected */
void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}
