%option noyywrap
%{
#include <stdio.h>
#include <string.h>

FILE *yyin;

int words = 0;
int chars = 0;
int lines = 1;

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

"/*"    				{
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


{Keyword}    { printf("%s : KEYWORD\n", yytext); }
{Type}       { printf("%s : TYPE\n", yytext); }

{BinOp}      { printf("%s : BINOP\n", yytext); }
"="          {chars++;
              printf("%s : EQ\n", yytext);
             }

        
{ID}         {words++; chars += strlen(yytext);
              printf("%s : IDENTIFIER\n",yytext);
             }

{Number}     {words++; chars += strlen(yytext);
               printf("%s : NUMBER\n",yytext);
             }

{String}     { printf("%s : STRING\n", yytext); }

            
";"          { chars++; printf("%s : SEMICOLON\n", yytext); }
","          { chars++; printf("%s : COMMA\n", yytext); }
"("          { chars++; printf("%s : LPAREN\n", yytext); }
")"          { chars++; printf("%s : RPAREN\n", yytext); }
"{"          { chars++; printf("%s : LBRACE\n", yytext); }
"}"          { chars++; printf("%s : RBRACE\n", yytext); }
"["          { chars++; printf("%s : LBRACKET\n", yytext); }
"]"          { chars++; printf("%s : RBRACKET\n", yytext); }


\n           { lines++; chars = 0; }
{ws}         { chars += yyleng; }


.            { printf("UNKNOWN: %s\n", yytext); }

%%


int main(int argc, char **argv) {
    printf("Compiler started. \n\n");

    if (argc > 1){
        if(!(yyin = fopen(argv[1], "r")))
            {
        perror(argv[1]);
        return(1);
        }
    }
    yylex();
}
