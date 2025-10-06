# Makefile for C-Minus Lexical Analyzer
# Merged version with line/column tracking

# Compiler and tools
LEX = flex
CC = gcc
CFLAGS = -Wall -g

# Output executable name
LEXER = lexer

# Source files
LEX_SOURCE = lexer.l
LEX_OUTPUT = lex.yy.c
TEST_PROGRAM = testProg.cmm

# Default target
all: $(LEXER)

# Build the lexer
$(LEXER): $(LEX_OUTPUT)
	$(CC) $(CFLAGS) -o $(LEXER) $(LEX_OUTPUT)

# Generate C code from flex specification
$(LEX_OUTPUT): $(LEX_SOURCE)
	$(LEX) $(LEX_SOURCE)

# Run the lexer on test program
test: $(LEXER)
	./$(LEXER) $(TEST_PROGRAM)

# Clean generated files
clean:
	rm -f $(LEXER) $(LEX_OUTPUT)

# Clean and rebuild
rebuild: clean all

# Show help
help:
	@echo "C-Minus Lexical Analyzer Makefile"
	@echo "=================================="
	@echo "Targets:"
	@echo "  all     - Build the lexer (default)"
	@echo "  test    - Build and run the lexer on testProg.cmm"
	@echo "  clean   - Remove generated files"
	@echo "  rebuild - Clean and rebuild"
	@echo "  help    - Show this help message"

.PHONY: all test clean rebuild help
