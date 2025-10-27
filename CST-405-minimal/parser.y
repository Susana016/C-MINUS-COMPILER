%{
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
%}

%union {
    int num;
    double fnum;
    char* str;
    struct ASTNode* node;
}

/* TOKEN DECLARATIONS */
%token <num> NUM
%token <fnum> FLOAT_NUM
%token <str> ID
%token INT DOUBLE PRINT WHILE FOR IF ELSE VOID RETURN MAIN
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET COMMA

/* NON-TERMINAL TYPES */
%type <node> program function_list function_decl param_list
%type <node> global_decl_list global_decl
%type <node> stmt_list stmt decl assign expr print_stmt while_stmt for_stmt if_stmt

/* OPERATOR PRECEDENCE */
%left '+' '-'
%left '*' '/' '%'
%left '<' '>'

%%

/* ============================================
   PROGRAM STRUCTURE - Top level with global scope
   ============================================ */

program:
    global_decl_list function_list {
        /* Program consists of optional global declarations followed by functions */
        $$ = createProgram($1, $2);
        root = $$;
    }
    | function_list {
        /* Program with only functions, no global variables */
        $$ = createProgram(NULL, $1);
        root = $$;
    }
    | stmt_list {
        /* Old style: statements only - wrap in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, $1);
        $$ = createProgram(NULL, mainFunc);
        root = $$;
    }
    | global_decl_list stmt_list {
        /* Old style with globals: wrap statements in implicit main() */
        ASTNode* mainFunc = createFunction("main", "int", NULL, $2);
        $$ = createProgram($1, mainFunc);
        root = $$;
    }
    ;

/* GLOBAL DECLARATIONS - Variables declared outside functions */
global_decl_list:
    global_decl {
        $$ = $1;
    }
    | global_decl_list global_decl {
        $$ = createStmtList($1, $2);
    }
    ;

global_decl:
    INT ID ';' {
        /* Global variable: int x; */
        $$ = createGlobalDecl($2);
        free($2);
    }
    | DOUBLE ID ';' {
        /* Global double: double x; */
        $$ = createGlobalDeclDouble($2);
        free($2);
    }
    | INT ID '=' expr ';' {
        /* Global with initialization: int x = 10; */
        $$ = createGlobalDeclInit($2, $4);
        free($2);
    }
    | INT ID LBRACKET NUM RBRACKET ';' {
        /* Global 1D array: int arr[10]; */
        $$ = createGlobalArrayDecl($2, $4);
        free($2);
    }
    | INT ID LBRACKET NUM RBRACKET LBRACKET NUM RBRACKET ';' {
        /* Global 2D array: int matrix[5][5]; */
        $$ = createGlobalArray2DDecl($2, $4, $7);
        free($2);
    }
    ;

/* ============================================
   FUNCTION DECLARATIONS - Function scope
   ============================================ */

function_list:
    function_decl {
        $$ = $1;
    }
    | function_list function_decl {
        $$ = createFunctionList($1, $2);
    }
    ;

function_decl:
    INT ID LPAREN param_list RPAREN LBRACE stmt_list RBRACE {
        /* int function_name(params) { body } */
        $$ = createFunction($2, "int", $4, $7);
        free($2);
    }
    | VOID ID LPAREN param_list RPAREN LBRACE stmt_list RBRACE {
        /* void function_name(params) { body } */
        $$ = createFunction($2, "void", $4, $7);
        free($2);
    }
    | INT MAIN LPAREN RPAREN LBRACE stmt_list RBRACE {
        /* Special case: int main() { body } */
        $$ = createFunction("main", "int", NULL, $6);
    }
    | VOID MAIN LPAREN RPAREN LBRACE stmt_list RBRACE {
        /* void main() { body } */
        $$ = createFunction("main", "void", NULL, $6);
    }
    ;

/* PARAMETER LIST */
param_list:
    INT ID {
        $$ = createParameter($2, "int", NULL);
        free($2);
    }
    | DOUBLE ID {
        $$ = createParameter($2, "double", NULL);
        free($2);
    }
    | param_list COMMA INT ID {
        $$ = createParameter($4, "int", $1);
        free($4);
    }
    | param_list COMMA DOUBLE ID {
        $$ = createParameter($4, "double", $1);
        free($4);
    }
    | /* empty */ {
        $$ = NULL;
    }
    ;

/* ============================================
   STATEMENTS - Inside function scope
   ============================================ */

stmt_list:
    stmt {
        $$ = $1;
    }
    | stmt_list stmt {
        $$ = createStmtList($1, $2);
    }
    ;

stmt:
    decl
    | assign
    | print_stmt
    | while_stmt
    | for_stmt
    | if_stmt
    | RETURN expr ';' {
        $$ = createReturn($2);
    }
    | RETURN ';' {
        $$ = createReturn(NULL);
    }
    | ID LPAREN expr RPAREN ';' {
        /* Function call with argument */
        $$ = createCall($1, $3);
        free($1);
    }
    | ID LPAREN RPAREN ';' {
        /* Function call without arguments */
        $$ = createCall($1, NULL);
        free($1);
    }
    ;

/* LOCAL DECLARATIONS - Variables inside functions */
decl:
    INT ID ';' {
        $$ = createDecl($2);
        free($2);
    }
    | DOUBLE ID ';' {
        $$ = createDeclDouble($2);
        free($2);
    }
    | INT ID '=' expr ';' {
        $$ = createDeclInit($2, $4);
        free($2);
    }
    | INT ID LBRACKET NUM RBRACKET ';' {
        $$ = createArrayDecl($2, $4);
        free($2);
    }
    | INT ID LBRACKET NUM RBRACKET LBRACKET NUM RBRACKET ';' {
        $$ = createArray2DDecl($2, $4, $7);
        free($2);
    }
    ;

/* ASSIGNMENT */
assign:
    ID '=' expr ';' {
        $$ = createAssign($1, $3);
        free($1);
    }
    | ID LBRACKET expr RBRACKET '=' expr ';' {
        $$ = createArrayAssign($1, $3, $6);
        free($1);
    }
    | ID LBRACKET expr RBRACKET LBRACKET expr RBRACKET '=' expr ';' {
        $$ = createArray2DAssign($1, $3, $6, $9);
        free($1);
    }
    ;

/* ============================================
   EXPRESSIONS
   ============================================ */

expr:
    NUM {
        $$ = createNum($1);
    }
    | FLOAT_NUM {
        $$ = createFloatNum($1);
    }
    | ID {
        $$ = createVar($1);
        free($1);
    }
    | expr '+' expr {
        $$ = createBinOp('+', $1, $3);
    }
    | expr '-' expr {
        $$ = createBinOp('-', $1, $3);
    }
    | expr '*' expr {
        $$ = createBinOp('*', $1, $3);
    }
    | expr '/' expr {
        $$ = createBinOp('/', $1, $3);
    }
    | expr '%' expr {
        $$ = createBinOp('%', $1, $3);
    }
    | expr '<' expr {
        $$ = createBinOp('<', $1, $3);
    }
    | expr '>' expr {
        $$ = createBinOp('>', $1, $3);
    }
    | LPAREN expr RPAREN {
        $$ = $2;
    }
    | LBRACE stmt_list RBRACE {
        $$ = $2;
    }
    | ID LBRACKET expr RBRACKET {
        $$ = createArrayAccess($1, $3);
        free($1);
    }
    | ID LBRACKET expr RBRACKET LBRACKET expr RBRACKET {
        $$ = createArray2DAccess($1, $3, $6);
        free($1);
    }
    | ID LPAREN expr RPAREN {
        /* Function call with argument as expression */
        $$ = createCallExpr($1, $3);
        free($1);
    }
    | ID LPAREN RPAREN {
        /* Function call without arguments as expression */
        $$ = createCallExpr($1, NULL);
        free($1);
    }
    ;

/* PRINT STATEMENT */
print_stmt:
    PRINT LPAREN expr RPAREN ';' {
        $$ = createPrint($3);
    }
    ;

/* WHILE STATEMENT */
while_stmt:
    WHILE LPAREN expr RPAREN stmt {
        $$ = createWhile($3, $5);
    }
    | WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE {
        $$ = createWhile($3, $6);
    }
    ;

/* FOR STATEMENT */
for_stmt:
    FOR LPAREN ID '=' expr ';' expr ';' ID '=' expr RPAREN stmt {
        ASTNode* init = createAssign($3, $5);
        ASTNode* update = createAssign($9, $11);
        $$ = createFor(init, $7, update, $13);
        free($3);
        free($9);
    }
    | FOR LPAREN ID '=' expr ';' expr ';' ID '=' expr RPAREN LBRACE stmt_list RBRACE {
        ASTNode* init = createAssign($3, $5);
        ASTNode* update = createAssign($9, $11);
        $$ = createFor(init, $7, update, $14);
        free($3);
        free($9);
    }
    ;

if_stmt:
    IF LPAREN expr RPAREN stmt {
        $$ = createIf($3, $5);
    }
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE {
        $$ = createIf($3, $6);
    }
    | IF LPAREN expr RPAREN stmt ELSE stmt {
        $$ = createIfElse($3, $5, $7);
    }
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE stmt {
        $$ = createIfElse($3, $6, $9);
    }
    | IF LPAREN expr RPAREN stmt ELSE LBRACE stmt_list RBRACE {
        $$ = createIfElse($3, $5, $8);
    }
    | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE {
        $$ = createIfElse($3, $6, $10);
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}