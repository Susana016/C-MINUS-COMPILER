%option noyywrap
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *yyin;

/* current position */
int words = 0;
int chars = 0;   /* number of characters consumed on current line */
int lines = 1;   /* current line number (1-based) */
int lexical_errors = 0;

/* helper: advance position counters */
void advance_pos(const char *s, int len) {
    for (int i = 0; i < len; ++i) {
        if (s[i] == '\n') {
            lines++;
            chars = 0;
        } else {
            chars++;
        }
    }
}
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

"/*"    {
            int start_line = lines;
            int start_col  = chars + 1;
            advance_pos(yytext, yyleng); /* count "/*" */

            int c;
            /* read until closing star-slash or EOF */
            while ((c = input()) != EOF) {
                if (c == '\n') { lines++; chars = 0; }
                else { chars++; }

                if (c == '*') {
                    int d = input();
                    if (d == EOF) break;
                    if (d == '/') {
                        chars++;
                        break; /* end of comment */
                    } else {
                        unput(d);
                    }
                }
            }

            if (c == EOF) {
                fprintf(stderr, "LEXICAL ERROR: unterminated comment starting at line %d, column %d\n",
                        start_line, start_col);
                exit(1);
            }
        }

{Keyword}   { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : KEYWORD (line %d,col %d)\n", yytext, sl, sc);
              /* return KEYWORD; */ }

{Type}      { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : TYPE (line %d,col %d)\n", yytext, sl, sc);
              /* return TYPE; */ }

{BinOp}     { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : BINOP (line %d,col %d)\n", yytext, sl, sc);
              /* return BINOP; */ }

"="         { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : EQ (line %d,col %d)\n", yytext, sl, sc);
              /* return EQ; */ }

{ID}        { int sl = lines, sc = chars + 1;
              words++;
              advance_pos(yytext, yyleng);
              printf("%s : IDENTIFIER (line %d,col %d)\n", yytext, sl, sc);
              /* return IDENTIFIER; */ }

{Number}    { int sl = lines, sc = chars + 1;
              words++;
              advance_pos(yytext, yyleng);
              printf("%s : NUMBER (line %d,col %d)\n", yytext, sl, sc);
              /* return NUMBER; */ }

{String}    { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : STRING (line %d,col %d)\n", yytext, sl, sc);
              /* return STRING; */ }

";"         { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : SEMICOLON (line %d,col %d)\n", yytext, sl, sc);
              /* return SEMICOLON; */ }

","         { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : COMMA (line %d,col %d)\n", yytext, sl, sc);
              /* return COMMA; */ }

"("         { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : LPAREN (line %d,col %d)\n", yytext, sl, sc);
              /* return LPAREN; */ }

")"         { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : RPAREN (line %d,col %d)\n", yytext, sl, sc);
              /* return RPAREN; */ }

"{"         { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : LBRACE (line %d,col %d)\n", yytext, sl, sc);
              /* return LBRACE; */ }

"}"         { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : RBRACE (line %d,col %d)\n", yytext, sl, sc);
              /* return RBRACE; */ }

"["         { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : LBRACKET (line %d,col %d)\n", yytext, sl, sc);
              /* return LBRACKET; */ }

"]"         { int sl = lines, sc = chars + 1;
              advance_pos(yytext, yyleng);
              printf("%s : RBRACKET (line %d,col %d)\n", yytext, sl, sc);
              /* return RBRACKET; */ }

\n          { lines++; chars = 0; }
{ws}        { advance_pos(yytext, yyleng); }

.           { int err_line = lines, err_col = chars + 1;
              advance_pos(yytext, yyleng);
              fprintf(stderr, "LEXICAL ERROR: '%s' at line %d, column %d\n",
                      yytext, err_line, err_col);
              exit(1); }

%%

int main(int argc, char **argv) {
    printf("Compiler started.\n\n");

    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    yylex();

    if (lexical_errors == 0) {
        printf("\nLexical analysis completed successfully. Source code is correct.\n");
    }

    return 0;
}
