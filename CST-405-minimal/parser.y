%{
/* SYNTAX ANALYZER (PARSER)
 * Enhanced with proper global and function scope support
 * CONFLICT-FREE VERSION
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

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
%token INT VOID DOUBLE OUTPUT INPUT
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON LBRACKET RBRACKET
%token COMMA
%token MAIN RETURN PRINT WHILE FOR IF ELSE

/* Logical operators */
%token AND OR NOT EQ LE GE NEQ

/* Multi-value equality */
%token IS

/* Switch-case tokens */
%token SWITCH CASE DEFAULT BREAK COLON

/* NON-TERMINAL TYPES */
%type <node> program top_level_list top_level_item
%type <node> function_decl param_list non_empty_param_list param
%type <node> global_decl
%type <node> stmt_list stmt decl assign expr print_stmt while_stmt for_stmt if_stmt
%type <node> value_list arg_list
%type <node> switch_stmt case_list case_stmt
%type <node> block

/* OPERATOR PRECEDENCE - From lowest to highest precedence */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%right IS
%left OR
%left AND
%left EQ NEQ
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right UMINUS
%right NOT
%left LBRACKET
%left LPAREN

%%

program:
    top_level_list {
        $$ = $1;
        root = $$;
    }
    ;

top_level_list:
    top_level_item {
        $$ = $1;
    }
    | top_level_list top_level_item {
        $$ = createStmtList($1, $2);
    }
    ;

top_level_item:
    global_decl {
        $$ = $1;
    }
    | function_decl {
        $$ = $1;
    }
    ;

global_decl:
    INT ID ';' {
        $$ = createGlobalDecl($2);
        free($2);
    }
    | DOUBLE ID ';' {
        $$ = createGlobalDeclDouble($2);
        free($2);
    }
    | INT ID '=' expr ';' {
        $$ = createGlobalDeclInit($2, $4);
        free($2);
    }
    | INT ID LBRACKET NUM RBRACKET ';' {
        $$ = createGlobalArrayDecl($2, $4);
        free($2);
    }
    | INT ID LBRACKET NUM RBRACKET LBRACKET NUM RBRACKET ';' {
        $$ = createGlobalArray2DDecl($2, $4, $7);
        free($2);
    }
    ;

function_decl:
    INT MAIN LPAREN param_list RPAREN LBRACE stmt_list RBRACE {
        $$ = createFunction("main", "int", $4, $7);
        /* Note: "main" is hardcoded string, not freed */
    }
    | VOID MAIN LPAREN param_list RPAREN LBRACE stmt_list RBRACE {
        $$ = createFunction("main", "void", $4, $7);
    }
    | INT ID LPAREN param_list RPAREN LBRACE stmt_list RBRACE {
        $$ = createFunction($2, "int", $4, $7);
        free($2);  /* Following ownership pattern from copilot instructions */
    }
    | VOID ID LPAREN param_list RPAREN LBRACE stmt_list RBRACE {
        $$ = createFunction($2, "void", $4, $7);
        free($2);
    }
    ;

/* Ensure param_list handles void properly */
param_list:
    /* empty */ {
        $$ = NULL;
    }
    | VOID {
        $$ = NULL;
    }
    | non_empty_param_list {
        $$ = $1;
    }
    ;

non_empty_param_list:
    param {
        $$ = $1;
    }
    | non_empty_param_list COMMA param {
        $$ = createStmtList($1, $3);
    }
    ;

param:
    INT ID {
        $$ = createParameter($2, "int", NULL);
        free($2);
    }
    | INT ID LBRACKET RBRACKET {
        $$ = createParameter($2, "int[]", NULL);
        free($2);
    }
    ;

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
    | switch_stmt
    | block {
        $$ = $1;
    }
    | BREAK ';' {
        $$ = createBreak();
    }
    | RETURN expr ';' {
        $$ = createReturn($2);
    }
    | RETURN ';' {
        $$ = createReturn(NULL);
    }
    | OUTPUT LPAREN expr RPAREN ';' {
        $$ = createOutput($3);
    }
    | expr ';' {
        $$ = $1;  // Allow expression statements (void function calls)
    }
    ;

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
    | INPUT LPAREN RPAREN {
        $$ = createInput();
    }
    | ID LPAREN RPAREN {
        $$ = createCallExpr($1, NULL);
        free($1);
    }
    | ID LPAREN arg_list RPAREN {
        $$ = createCallExpr($1, $3);
        free($1);
    }
    | ID LBRACKET expr RBRACKET {
        $$ = createArrayAccess($1, $3);
        free($1);
    }
    | ID LBRACKET expr RBRACKET LBRACKET expr RBRACKET {
        $$ = createArray2DAccess($1, $3, $6);
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
    | expr EQ expr {
        $$ = createBinOp(EQ, $1, $3);
    }
    | expr NEQ expr {
        $$ = createBinOp(NEQ, $1, $3);
    }
    | expr LE expr {
        $$ = createBinOp(LE, $1, $3);
    }
    | expr GE expr {
        $$ = createBinOp(GE, $1, $3);
    }
    | expr AND expr {
        $$ = createBinOp(AND, $1, $3);
    }
    | expr OR expr {
        $$ = createBinOp(OR, $1, $3);
    }
    | NOT expr {
        $$ = createUnaryOp(NOT, $2);
    }
    | '-' expr %prec UMINUS {
        $$ = createUnaryOp('-', $2);
    }
    | LPAREN expr RPAREN {
        $$ = $2;
    }
    ;

value_list:
    expr {
        $$ = createValueList($1, NULL);
    }
    | value_list COMMA expr {
        $$ = createValueList($3, $1);
    }
    ;

arg_list:
    expr {
        $$ = $1;
    }
    | arg_list COMMA expr {
        $$ = createArgList($1, $3);
    }
    ;

print_stmt:
    PRINT LPAREN expr RPAREN ';' {
        $$ = createPrint($3);
    }
    ;

while_stmt:
    WHILE LPAREN expr RPAREN stmt {
        $$ = createWhile($3, $5);
    }
    ;

for_stmt:
    FOR LPAREN ID '=' expr ';' expr ';' ID '=' expr RPAREN stmt {
        ASTNode* init = createAssign($3, $5);
        ASTNode* update = createAssign($9, $11);
        $$ = createFor(init, $7, update, $13);
        free($3);
        free($9);
    }
    ;

if_stmt:
    IF LPAREN expr RPAREN stmt %prec LOWER_THAN_ELSE {
        $$ = createIf($3, $5);
    }
    | IF LPAREN expr RPAREN stmt ELSE stmt {
        $$ = createIfElse($3, $5, $7);
    }
    ;

switch_stmt:
    SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE {
        $$ = createSwitch($3, $6);
    }
    ;

case_list:
    case_stmt {
        $$ = $1;
    }
    | case_stmt case_list {
        $1->data.casestmt.next = $2;
        $$ = $1;
    }
    ;

case_stmt:
    CASE NUM COLON stmt_list {
        $$ = createCase($2, $4, NULL);
    }
    | CASE NUM COLON {
        $$ = createCase($2, NULL, NULL);
    }
    | DEFAULT COLON stmt_list {
        $$ = createDefault($3);
    }
    | DEFAULT COLON {
        $$ = createDefault(NULL);
    }
    ;

block:
    LBRACE stmt_list RBRACE {
        $$ = $2;  /* Block is just a statement list wrapper */
    }
    | LBRACE RBRACE {
        $$ = NULL;  /* Empty block */
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, s);
}