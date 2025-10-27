#!/bin/bash

echo "Building compiler with array support..."

# Generate parser from parser.y
echo "1. Generating parser with Bison..."
bison -d parser.y

# Generate scanner from scanner.l
echo "2. Generating scanner with Flex..."
flex scanner.l

# Compile all C files
echo "3. Compiling C files..."
gcc -o minicompiler \
    main.c \
    ast.c \
    codegen.c \
    symtab.c \
    tac.c \
    parser.tab.c \
    lex.yy.c

if [ $? -eq 0 ]; then
    echo "✓ Build successful!"
    echo ""
    echo "Running test with arrays..."
  #  ./minicompiler test.c output.s
   # ./minicompiler while_test.c output_while.s#
   ./minicompiler new_test.c new_test.s
    
    echo ""
    echo "Generated MIPS code saved to output.s"
    echo "You can run it with: mars output.s"
    echo "or: spim -file output.s"
else
    echo "✗ Build failed!"
    exit 1
fi