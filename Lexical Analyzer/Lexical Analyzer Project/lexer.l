%option noyywrap
%{
#include <stdio.h>
#include <string.h>

FILE *yyin;

int words = 0;
int chars = 0;
int lines = 1;

// Normally you would also have a tokens.h file with definitions like:
// #define IDENTIFIER  258
// #define NUMBER      259
// etc.
// For now, just showing where the return statements would go.

%}

letter        [a-zA-Z]
digit         [0-9]
ID            {letter}({letter}|{digit})*
delim         [ \t\n]
Number        {digit}+(\.{digit}+)?(E[+\-]?{digit}+)? 
Keyword       (read|write|writeln|return|break|if|else|while)
Type          (int|char|bool|string|void|float)
String        \"([^\\\"]|\\.)*\" 
BinOp         (\+|\-|\*|\/|==|!=|<=|<|>=|>|&&|\|\|)
ws            {delim}+

%%

"/*" {
        int c;
        while((c = input()) != 0) {
            if(c == '*') {
                if((c = input()) == '/')
                    break;
                else
                    unput(c);
            }
        }
     }

{Keyword}   { printf("%s : KEYWORD\n", yytext); /* return KEYWORD; */ }
{Type}      { printf("%s : TYPE\n", yytext);   /* return TYPE; */ }

{BinOp}     { printf("%s : BINOP\n", yytext); /* return BINOP; */ }
"="         { chars++; printf("%s : EQ\n", yytext); /* return EQ; */ }

{ID}        { words++; chars += strlen(yytext);
              printf("%s : IDENTIFIER\n",yytext);
              /* return IDENTIFIER; */
            }

{Number}    { words++; chars += strlen(yytext);
              printf("%s : NUMBER\n",yytext);
              /* return NUMBER; */
            }

{String}    { printf("%s : STRING\n", yytext); /* return STRING; */ }

";"         { chars++; printf("%s : SEMICOLON\n", yytext); /* return SEMICOLON; */ }
","         { chars++; printf("%s : COMMA\n", yytext);     /* return COMMA; */ }
"("         { chars++; printf("%s : LPAREN\n", yytext);    /* return LPAREN; */ }
")"         { chars++; printf("%s : RPAREN\n", yytext);    /* return RPAREN; */ }
"{"         { chars++; printf("%s : LBRACE\n", yytext);    /* return LBRACE; */ }
"}"         { chars++; printf("%s : RBRACE\n", yytext);    /* return RBRACE; */ }
"["         { chars++; printf("%s : LBRACKET\n", yytext);  /* return LBRACKET; */ }
"]"         { chars++; printf("%s : RBRACKET\n", yytext);  /* return RBRACKET; */ }

\n          { lines++; chars = 0; }
{ws}        { chars += yyleng; }

.           { printf("UNKNOWN: %s\n", yytext); /* return ERROR; */ }

%%

int main(int argc, char **argv) {
    printf("Compiler started. \n\n");

    if (argc > 1){
        if(!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return(1);
        }
    }
    yylex();
}