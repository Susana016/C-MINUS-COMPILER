# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an educational compiler for a minimal C-like language that demonstrates all compilation phases. It compiles a simple language (supporting integers, doubles, arrays, arithmetic, print statements, and while loops) into MIPS assembly code. The compiler is designed for teaching compiler design concepts with clear phase separation and extensive documentation.

## Build Commands

### Standard Development
```bash
# Build the compiler
make

# Clean build artifacts
make clean

# Build and run basic test
make test

# Test with a specific file
make test-file FILE=yourfile.c

# Test optimization features
make test-opt

# Test array support
make test-arrays

# Test double support
make test-doubles

# Show all available make targets
make help

# Show platform configuration
make info
```

### Running the Compiler
```bash
# Basic usage
./minicompiler <input.c> <output.s>

# Example
./minicompiler test.c output.s
```

The generated `.s` file contains MIPS assembly that can be run in simulators like MARS, SPIM, or QtSPIM.

## Architecture

### Compilation Pipeline

The compiler follows a classic multi-phase architecture:

1. **Lexical Analysis** (`scanner.l`): Tokenizes source code using Flex
2. **Syntax Analysis** (`parser.y`): Builds Abstract Syntax Tree using Bison
3. **AST Construction** (`ast.c`, `ast.h`): Creates hierarchical program representation
4. **Semantic Analysis** (`symtab.c`, `symtab.h`): Symbol table and type checking
5. **Intermediate Code** (`tac.c`, `tac.h`): Generates Three-Address Code (TAC)
6. **Optimization** (`tac.c`): Constant folding and propagation
7. **Code Generation** (`codegen.c`, `codegen.h`): Produces MIPS assembly

### Key Components

**AST (Abstract Syntax Tree)**
- Defined in `ast.h` with extensive node types (NODE_NUM, NODE_BINOP, NODE_ARRAY_ACCESS, etc.)
- Each node type has specific data structures in the union
- Supports 1D and 2D arrays, while loops, and various expressions
- Note: If/else statement structures exist in the AST definition but are currently disabled in the parser

**TAC (Three-Address Code)**
- Intermediate representation with maximum 3 operands per instruction
- Supports arithmetic (ADD, SUB, MUL, DIV, MOD), comparisons (CMP_LT, CMP_GT), control flow (GOTO, IF_FALSE, LABEL)
- Uses temporary variables (t0, t1, ...) for intermediate results
- Enables optimization passes before final code generation

**Symbol Table**
- Tracks variable declarations and their stack offsets
- Supports TYPE_INT and TYPE_DOUBLE
- Maximum 100 variables (MAX_VARS)
- Maps variable names to memory locations for code generation

**Memory Model**
- Variables allocated on the stack with a fixed 400-byte allocation
- Stack grows downward from high addresses
- Each variable has a 4-byte stack offset (even doubles occupy 4 bytes in current implementation)
- Uses MIPS registers: $sp for stack pointer, $t0-$t7 for temporaries

### Supported Language Features

**Currently Enabled:**
- Integer and double variable declarations: `int x;` `double y;`
- Declaration with initialization: `int x = 5;`
- 1D arrays: `int arr[3];` with access `arr[0]` and assignment `arr[0] = 5;`
- 2D arrays: `int matrix[2][2];` with access `matrix[0][1]` and assignment `matrix[0][1] = 5;`
- Arithmetic operators: `+` `-` `*` `/` `%`
- Comparison operators: `<` `>`
- Assignment: `x = 10;`
- Print statements: `print(x);`
- While loops: `while (x < 10) { ... }`

**Currently Disabled:**
- If/else statements (grammar and AST structures exist but creation functions are commented out)

## Cross-Platform Build System

The Makefile is designed to work on both Windows and Unix/Linux:
- Automatically detects OS and adjusts commands
- On Windows: uses `.exe` extension, Windows command syntax
- On Unix/Linux: uses standard Unix commands
- Dependencies: `gcc`, `flex`, `bison`

## File Organization

```
Core Compiler Files:
├── scanner.l          # Lexical analyzer rules (Flex)
├── parser.y           # Grammar and parser (Bison)
├── ast.c/h            # AST node creation and manipulation
├── symtab.c/h         # Symbol table management
├── tac.c/h            # Three-address code generation and optimization
├── codegen.c/h        # MIPS assembly code generation
└── main.c             # Driver program with phase orchestration

Build System:
└── Makefile           # Cross-platform build configuration

Test Files:
├── test.c             # Basic test program
├── test_modulo.c      # Modulo operator test
├── test_operations.c  # Various operations test
├── test_doubles.c     # Double type test
├── while_test.c       # While loop test
└── comprehensive_test.c # Comprehensive features test

Generated Files:
├── lex.yy.c           # Generated lexer
├── parser.tab.c/h     # Generated parser
├── *.o                # Object files
├── *.s                # Generated MIPS assembly
└── minicompiler(.exe) # Compiled compiler executable
```

## Development Notes

### Modifying the Language

To add new features:

1. **Add tokens** in `scanner.l` for new keywords or operators
2. **Update grammar** in `parser.y` with new production rules
3. **Extend AST** in `ast.h` with new node types and data structures
4. **Implement AST constructors** in `ast.c` for new nodes
5. **Generate TAC** in `tac.c` for new constructs
6. **Update code generation** in `codegen.c` to emit MIPS for new features
7. **Update symbol table** in `symtab.c` if new variable types are added

### TAC Optimization

Current optimizations in `tac.c`:
- **Constant folding**: Evaluates compile-time constant expressions
- **Constant propagation**: Replaces variables with known constant values

### MIPS Code Generation

Key aspects in `codegen.c`:
- Stack-based variable storage with fixed 400-byte allocation
- Temporaries use $t0-$t7 registers
- System calls for print (syscall 1 for integers)
- Label generation for control flow (while loops use unique labels)

### Testing

Test files demonstrate different features:
- Simple arithmetic and assignments
- Array operations (1D and 2D)
- While loops with comparisons
- Modulo operations
- Double precision values

Run tests individually with `make test-file FILE=<testfile>.c` to see full compilation output including AST, TAC, optimizations, and generated MIPS code.

## Educational Focus

This compiler prioritizes clarity and demonstration of compiler concepts:
- Extensive comments explaining "what" and "why"
- Visual phase separation in output with ASCII boxes
- Complete pipeline from source to assembly visible to users
- Each phase produces human-readable intermediate representations
