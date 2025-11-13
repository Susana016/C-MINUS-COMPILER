%{
/* LEXICAL ANALYZER (SCANNER)
 * This is the first phase of compilation - breaking input into tokens
 * Flex generates a scanner from these rules that reads character by character
 */
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"  /* Token definitions from Bison */
%}

/* Flex options to suppress warnings for unused functions */
%option nounput
%option noinput

%%

"/*"([^*]|\*+[^*/])*\*+"/"  { }
"//".*          { /* ignore single-line comments */ }


"int"           { return INT; }
"double"        { return DOUBLE; }
"print"         { return PRINT; }
"while"         { return WHILE; }
"for"           { return FOR; }
"if"            { return IF; }
"else"          { return ELSE; }
"return"        { return RETURN; }
"void"          { return VOID; }
"main"          { return MAIN; }
"is"            { return IS; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"break"         { return BREAK; }

[a-zA-Z_][a-zA-Z0-9_]* { 
    yylval.str = strdup(yytext);
    return ID; 
}

[0-9]+\.[0-9]+  { 
    yylval.fnum = atof(yytext);
    return FLOAT_NUM; 
}

[0-9]+          { 
    yylval.num = atoi(yytext);
    return NUM; 
}


"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"%"             { return '%'; }
"=="            { return EQ; }
"="             { return '='; }
"<"             { return '<'; }
">"             { return '>'; }
"!"             { return NOT; }
"&&"            { return AND; }
"||"            { return OR; }
";"             { return ';'; }
":"             { return COLON; }
"("             { return LPAREN; }  
")"             { return RPAREN; }   
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
","             { return COMMA; }



[ \t\n]         { }

.               { printf("Lexical Error: Unknown character '%c'\n", *yytext); }

%%

/* Required by Flex - signals end of input */
int yywrap() {
    return 1;  /* 1 means no more input files */
}