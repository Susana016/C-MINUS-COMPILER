# Lexical Analyzer for C-Minus Language
## CST-405 Compiler Design Project

This is a merged lexical analyzer implementation combining the best features from both the 2D-array and lexical analyzer versions.

## Features

- **Line and Column Tracking**: Accurate position reporting for all tokens
- **Comprehensive Token Recognition**: 
  - Keywords: `read`, `write`, `writeln`, `return`, `break`, `if`, `else`, `while`
  - Types: `int`, `char`, `bool`, `string`, `void`, `float`
  - Operators: Binary operators, assignment operator
  - Identifiers and Numbers (including scientific notation)
  - String literals
  - Punctuation: `;`, `,`, `(`, `)`, `{`, `}`, `[`, `]`
- **Comment Handling**: Multi-line C-style comments (`/* ... */`)
- **Error Detection**: Reports lexical errors with precise line and column information
- **Error Counting**: Tracks total number of lexical errors found

## Building and Running

### Prerequisites
- flex (Fast Lexical Analyzer)
- gcc (GNU C Compiler)

### Compilation Steps

```bash
# Step 1: Generate the lexer from the specification
flex lexer.l

# Step 2: Compile the generated C code
gcc -o lexer lex.yy.c

# Step 3: Run the lexer on a test program
./lexer testProg.cmm
```

## Example Output

For the input program `testProg.cmm`, the lexer produces:

```
int : TYPE (line 1,col 1)
x : IDENTIFIER (line 1,col 5)
; : SEMICOLON (line 1,col 6)
char : TYPE (line 2,col 1)
y : IDENTIFIER (line 2,col 6)
[ : LBRACKET (line 2,col 7)
10 : NUMBER (line 2,col 8)
] : RBRACKET (line 2,col 10)
; : SEMICOLON (line 2,col 11)
...
LEXICAL ERROR: '#' at line 19, column 6
...

Lexical analysis completed with 1 error(s).
```

## Test Program

The included `testProg.cmm` contains:
- Variable declarations with arrays
- Function definitions
- Control structures (if/else, while)
- Expressions and operators
- An intentional lexical error (`#`) for testing error detection

## Key Improvements Over Original Versions

1. **Enhanced Error Tracking**: 
   - Proper error counter incrementation
   - Final error summary in output

2. **Better Position Tracking**:
   - Consistent line and column reporting across all tokens
   - Accurate position tracking through comments and whitespace

3. **Robust Comment Handling**:
   - Detects unterminated comments
   - Maintains position tracking inside comments

## Files

- `lexer.l` - Flex lexer specification (merged version)
- `testProg.cmm` - Test program in C-Minus language
- `README.md` - This file

## Integration Notes

This lexical analyzer is designed to be integrated into a full compiler pipeline for the C-Minus language. The commented-out `return` statements in the rule actions indicate where token types would be returned to a parser in a complete compiler implementation.

## Source

Merged from:
- `CST-405-Susana-2D-array` (line/column tracking version)
- `CST-405-Susana016-Lexical` (base lexical analyzer)

Key features retained from 2D-array version:
- Line and column position tracking
- Enhanced output formatting
- Improved error reporting
