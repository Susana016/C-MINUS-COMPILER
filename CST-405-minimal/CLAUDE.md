# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an educational C compiler that demonstrates all phases of compilation. It compiles a minimal C-like language to MIPS assembly, suitable for running on MIPS simulators (MARS, SPIM, QtSPIM).

## Language Features

The compiler supports a C-like language with:
- Integer and double variable declarations (local and global)
- 1D and 2D arrays
- Binary operators: `+`, `-`, `*`, `/`, `%`, `<`, `>`
- While loops
- Functions with parameters and return statements
- Function calls (including as expressions)
- Print statements

Note: No actual if/else statements are currently implemented, but the AST structures exist for if/else and goto/label support.

## Build Commands

```bash
# Build the compiler
make

# Clean generated files
make clean

# Build and run a test
make test

# Test with a specific file
make test-file FILE=yourfile.c

# Platform information
make info
```

The Makefile is cross-platform compatible (Windows and Linux/Unix).

## Compilation Pipeline

The compiler follows a classic multi-phase architecture:

1. **Lexical Analysis** (`scanner.l`) - Tokenization using Flex
2. **Syntax Analysis** (`parser.y`) - Parsing and AST construction using Bison
3. **Semantic Analysis** (`symtab.c`) - Symbol table with scope management
4. **Intermediate Code** (`tac.c`) - Three-Address Code (TAC) generation
5. **Optimization** (`tac.c`) - Constant folding and copy propagation
6. **Code Generation** (`codegen.c`) - MIPS assembly output

## Key Architecture Components

### Abstract Syntax Tree (AST) - `ast.h` / `ast.c`

The AST supports a hierarchical program structure:
- **Program level**: Contains optional global declarations and function list
- **Global declarations**: Variables, arrays, and initialized variables
- **Functions**: With parameters, local variables, and statements
- **Statements**: declarations, assignments, print, while loops, return statements, function calls
- **Expressions**: Variables, numbers, binary operations, array accesses, function calls

Key node types:
- `NODE_PROGRAM` - Top-level program with globals and functions
- `NODE_FUNCTION` / `NODE_FUNCTION_LIST` - Function definitions
- `NODE_GLOBAL_DECL` variants - Global variable declarations
- `NODE_ARRAY_DECL`, `NODE_ARRAY_2D_DECL` - Array declarations (1D and 2D)
- `NODE_WHILE` - While loop control flow
- `NODE_RETURN`, `NODE_CALL`, `NODE_CALL_EXPR` - Function support

### Symbol Table - `symtab.h` / `symtab.c`

Hierarchical scope-based symbol table:
- Maintains a linked list of scopes with parent pointers
- Global scope is always accessible
- Function scopes are entered/exited during compilation
- Tracks variables (with types and stack offsets) and functions (with parameter types and return types)

Key functions:
- `initSymTab()` - Initialize with global scope
- `enterScope()` / `exitScope()` - Manage function/block scopes
- `addVar()`, `addFunction()`, `addParameter()` - Add symbols
- `lookupSymbol()` - Search current and parent scopes
- `isInCurrentScope()` - Check only the current scope

### Three-Address Code (TAC) - `tac.h` / `tac.c`

Intermediate representation with instructions limited to 3 operands:
- Arithmetic: `TAC_ADD`, `TAC_SUB`, `TAC_MUL`, `TAC_DIV`, `TAC_MOD`
- Comparison: `TAC_CMP_LT`, `TAC_CMP_GT`
- Control flow: `TAC_GOTO`, `TAC_IF_FALSE`, `TAC_LABEL`
- Functions: `TAC_FUNC_BEGIN`, `TAC_FUNC_END`, `TAC_PARAM`, `TAC_CALL`, `TAC_RETURN`
- Other: `TAC_ASSIGN`, `TAC_DECL`, `TAC_PRINT`, `TAC_ARRAY_ACCESS`

Key functions:
- `initTAC()` - Initialize TAC generation
- `generateTAC(ASTNode*)` - Convert AST to TAC
- `newTemp()` - Generate temporary variables (t0, t1, ...)
- `newLabel()` - Generate unique labels for control flow
- `optimizeTAC()` - Perform constant folding and copy propagation
- `freeTAC()` - Clean up allocated memory

### Code Generation - `codegen.h` / `codegen.c`

Generates MIPS assembly from the AST:
- Variables are stored on the stack with $sp-relative offsets
- Uses $t0-$t7 for temporary values
- System calls for print operations (syscall 1 for integers, syscall 3 for doubles)
- Function calls follow MIPS calling conventions

Main function: `generateMIPS(ASTNode* root, const char* filename)`

## Development Workflow

When adding new features:

1. **Update the lexer** (`scanner.l`) if new tokens are needed
2. **Update the parser** (`parser.y`) to recognize new grammar rules
3. **Add AST node types** in `ast.h` and constructors in `ast.c`
4. **Update symbol table** (`symtab.c`) if new semantic checks are needed
5. **Extend TAC generation** (`tac.c`) to handle new constructs
6. **Update code generator** (`codegen.c`) to emit MIPS for new features
7. **Test** with example programs in `.c` files

## Memory Model

The compiler uses a stack-based memory model:
- Stack grows downward (high addresses to low)
- $sp points to the current top of stack
- Local variables are allocated at fixed offsets from $sp
- Arrays reserve contiguous memory (4 bytes per integer, 8 bytes per double)

## Testing

Test files are in the root directory:
- `test.c` - Basic test with arrays and 2D arrays
- `test_operations.c` - Test arithmetic operations
- `test_doubles.c` - Test double precision support
- `while_test.c` - Test while loops
- `comprehensive_test.c` - Comprehensive feature tests
- `simple_test.c`, `new_test.c`, `test_modulo.c` - Various feature tests

Run the compiler: `./minicompiler <input.c> <output.s>`
Then run the output in a MIPS simulator.

## Important Notes

- The parser requires semicolons after all statements
- All variables must be declared before use
- The compiler generates detailed output showing each compilation phase
- Array indices and 2D array indices are computed at runtime
- While loops use labels and conditional jumps in TAC
- Functions can be nested in the AST but code generation may have limitations
- Global variables and local variables are handled separately in the symbol table
