# Commands to Build and Run

## Quick Start
```bash
make test
```

## Step-by-Step Commands

### Method 1: Using Makefile (Recommended)
```bash
# Build the lexer
make

# Run tests
make test

# Clean up
make clean

# Rebuild from scratch
make rebuild
```

### Method 2: Manual Commands
```bash
# Step 1: Generate the lexer from the specification
flex lexer.l

# Step 2: Compile the generated C code
gcc -o lexer lex.yy.c

# Step 3: Run the lexer on a test program
./lexer testProg.cmm
```

## Expected Output

When running the lexer on `testProg.cmm`, you should see:

```
Compiler started.

int : TYPE (line 1,col 1)
x : IDENTIFIER (line 1,col 5)
; : SEMICOLON (line 1,col 6)
char : TYPE (line 2,col 1)
y : IDENTIFIER (line 2,col 6)
[ : LBRACKET (line 2,col 7)
10 : NUMBER (line 2,col 8)
] : RBRACKET (line 2,col 10)
; : SEMICOLON (line 2,col 11)
int : TYPE (line 4,col 1)
add : IDENTIFIER (line 4,col 5)
( : LPAREN (line 4,col 8)
int : TYPE (line 4,col 9)
a : IDENTIFIER (line 4,col 13)
, : COMMA (line 4,col 14)
int : TYPE (line 4,col 16)
b : IDENTIFIER (line 4,col 20)
) : RPAREN (line 4,col 21)
{ : LBRACE (line 4,col 23)
int : TYPE (line 5,col 5)
result : IDENTIFIER (line 5,col 9)
; : SEMICOLON (line 5,col 15)
result : IDENTIFIER (line 6,col 5)
= : EQ (line 6,col 12)
a : IDENTIFIER (line 6,col 14)
+ : BINOP (line 6,col 16)
b : IDENTIFIER (line 6,col 18)
; : SEMICOLON (line 6,col 19)
return : KEYWORD (line 7,col 5)
result : IDENTIFIER (line 7,col 12)
; : SEMICOLON (line 7,col 18)
} : RBRACE (line 8,col 1)
void : TYPE (line 10,col 1)
main : IDENTIFIER (line 10,col 6)
( : LPAREN (line 10,col 10)
) : RPAREN (line 10,col 11)
{ : LBRACE (line 10,col 13)
int : TYPE (line 11,col 5)
a : IDENTIFIER (line 11,col 9)
; : SEMICOLON (line 11,col 10)
int : TYPE (line 12,col 5)
b : IDENTIFIER (line 12,col 9)
; : SEMICOLON (line 12,col 10)
int : TYPE (line 13,col 5)
c : IDENTIFIER (line 13,col 9)
; : SEMICOLON (line 13,col 10)
a : IDENTIFIER (line 14,col 5)
= : EQ (line 14,col 7)
5 : NUMBER (line 14,col 9)
; : SEMICOLON (line 14,col 10)
b : IDENTIFIER (line 15,col 5)
= : EQ (line 15,col 7)
10 : NUMBER (line 15,col 9)
; : SEMICOLON (line 15,col 11)
c : IDENTIFIER (line 16,col 5)
= : EQ (line 16,col 7)
add : IDENTIFIER (line 16,col 9)
( : LPAREN (line 16,col 12)
a : IDENTIFIER (line 16,col 13)
, : COMMA (line 16,col 14)
b : IDENTIFIER (line 16,col 16)
) : RPAREN (line 16,col 17)
; : SEMICOLON (line 16,col 18)
write : KEYWORD (line 17,col 5)
c : IDENTIFIER (line 17,col 11)
; : SEMICOLON (line 17,col 12)
writeln : KEYWORD (line 18,col 5)
; : SEMICOLON (line 18,col 12)
y : IDENTIFIER (line 19,col 5)
LEXICAL ERROR: '#' at line 19, column 6
z : IDENTIFIER (line 19,col 7)
= : EQ (line 19,col 9)
20 : NUMBER (line 19,col 11)
; : SEMICOLON (line 19,col 13)
if : KEYWORD (line 21,col 5)
( : LPAREN (line 21,col 8)
a : IDENTIFIER (line 21,col 9)
< : BINOP (line 21,col 11)
b : IDENTIFIER (line 21,col 13)
) : RPAREN (line 21,col 14)
{ : LBRACE (line 21,col 16)
read : KEYWORD (line 22,col 9)
a : IDENTIFIER (line 22,col 14)
; : SEMICOLON (line 22,col 15)
} : RBRACE (line 23,col 5)
else : KEYWORD (line 23,col 7)
{ : LBRACE (line 23,col 12)
b : IDENTIFIER (line 24,col 9)
= : EQ (line 24,col 11)
b : IDENTIFIER (line 24,col 13)
- : BINOP (line 24,col 15)
1 : NUMBER (line 24,col 17)
; : SEMICOLON (line 24,col 18)
} : RBRACE (line 25,col 5)
while : KEYWORD (line 26,col 5)
( : LPAREN (line 26,col 11)
a : IDENTIFIER (line 26,col 12)
!= : BINOP (line 26,col 14)
b : IDENTIFIER (line 26,col 17)
) : RPAREN (line 26,col 18)
{ : LBRACE (line 26,col 20)
a : IDENTIFIER (line 27,col 9)
= : EQ (line 27,col 11)
a : IDENTIFIER (line 27,col 13)
+ : BINOP (line 27,col 15)
1 : NUMBER (line 27,col 17)
; : SEMICOLON (line 27,col 18)
} : RBRACE (line 28,col 5)
{ : LBRACE (line 30,col 5)
int : TYPE (line 31,col 9)
temp : IDENTIFIER (line 31,col 13)
; : SEMICOLON (line 31,col 17)
temp : IDENTIFIER (line 32,col 9)
= : EQ (line 32,col 14)
0 : NUMBER (line 32,col 16)
; : SEMICOLON (line 32,col 17)
} : RBRACE (line 33,col 5)
} : RBRACE (line 34,col 1)

Lexical analysis completed with 1 error(s).
```

## Testing Custom Programs

To test with your own C-Minus program:
```bash
./lexer your_program.cmm
```

## Notes

- The lexer tracks line and column positions accurately
- Lexical errors are reported with their exact location
- The program includes an intentional error (`#` character) for testing error detection
