# Cross-platform Makefile for Minimal C Compiler
# Works on both Windows and Linux/Unix

# Compiler settings
CC = gcc
LEX = flex
YACC = bison
CFLAGS = -g -Wall

# Base target name
TARGET = minicompiler

# Object files
OBJS = lex.yy.o parser.tab.o main.o ast.o symtab.o codegen.o tac.o

# Detect operating system
ifeq ($(OS),Windows_NT)
    # Windows settings
    EXE_EXT = .exe
    RM = cmd /C del /F /Q
    RM_DIR = cmd /C rmdir /S /Q
    PATHSEP = \\
    CAT = type
    ECHO = @echo
    # Fix for Windows object file deletion
    CLEAN_OBJS = $(subst /,\,$(OBJS))
    CLEAN_FILES = lex.yy.c parser.tab.c parser.tab.h *.s *.exe
    NULL_REDIRECT = 2>nul || exit 0
else
    # Unix/Linux settings
    EXE_EXT = 
    RM = rm -f
    RM_DIR = rm -rf
    PATHSEP = /
    CAT = cat
    ECHO = @echo
    CLEAN_OBJS = $(OBJS)
    CLEAN_FILES = lex.yy.c parser.tab.c parser.tab.h *.s
    NULL_REDIRECT = 2>/dev/null || true
endif

# Full target with extension
TARGET_FULL = $(TARGET)$(EXE_EXT)

# Default target
all: $(TARGET_FULL)

# Main build target
$(TARGET_FULL): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET_FULL) $(OBJS)
	$(ECHO) "Build complete: $(TARGET_FULL)"

# Lexer generation
lex.yy.c: scanner.l parser.tab.h
	$(LEX) scanner.l

# Parser generation
parser.tab.c parser.tab.h: parser.y
	$(YACC) -d parser.y

# Object file compilation
lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

parser.tab.o: parser.tab.c
	$(CC) $(CFLAGS) -c parser.tab.c

main.o: main.c ast.h codegen.h tac.h
	$(CC) $(CFLAGS) -c main.c

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

symtab.o: symtab.c symtab.h
	$(CC) $(CFLAGS) -c symtab.c

codegen.o: codegen.c codegen.h ast.h symtab.h
	$(CC) $(CFLAGS) -c codegen.c

tac.o: tac.c tac.h ast.h
	$(CC) $(CFLAGS) -c tac.c

# Clean target - works on both platforms
clean:
ifeq ($(OS),Windows_NT)
	$(RM) $(CLEAN_OBJS) $(NULL_REDIRECT)
	$(RM) $(CLEAN_FILES) $(NULL_REDIRECT)
else
	$(RM) $(TARGET_FULL) $(CLEAN_OBJS) $(CLEAN_FILES)
endif
	$(ECHO) "Clean complete"

# Test target
test: $(TARGET_FULL)
	./$(TARGET_FULL) test.c test.s
	$(ECHO)
	$(ECHO) "=== Generated MIPS Code ==="
	$(CAT) test.s

# Test with specific file
test-file: $(TARGET_FULL)
	$(ECHO) "Usage: make test-file FILE=yourfile.c"
	./$(TARGET_FULL) $(FILE) output.s
	$(CAT) output.s

# Test optimization
test-opt: $(TARGET_FULL)
	./$(TARGET_FULL) test_simple_opt.c opt_output.s
	$(ECHO)
	$(ECHO) "=== Optimized MIPS Code ==="
	$(CAT) opt_output.s

# Test arrays
test-arrays: $(TARGET_FULL)
	./$(TARGET_FULL) test_arrays.c arrays_output.s
	$(ECHO)
	$(ECHO) "=== Array Test MIPS Code ==="
	$(CAT) arrays_output.s

# Test doubles
test-doubles: $(TARGET_FULL)
	./$(TARGET_FULL) test_doubles.c doubles_output.s
	$(ECHO)
	$(ECHO) "=== Doubles Test MIPS Code ==="
	$(CAT) doubles_output.s

# Help target
help:
	$(ECHO) "Available targets:"
	$(ECHO) "  all          - Build the compiler (default)"
	$(ECHO) "  clean        - Remove all generated files"
	$(ECHO) "  test         - Run basic test"
	$(ECHO) "  test-file    - Test with specific file (use FILE=filename.c)"
	$(ECHO) "  test-opt     - Test optimization features"
	$(ECHO) "  test-arrays  - Test array support"
	$(ECHO) "  test-doubles - Test double support"
	$(ECHO) "  help         - Show this help message"

# Platform info (for debugging)
info:
	$(ECHO) "Platform Configuration:"
ifeq ($(OS),Windows_NT)
	$(ECHO) "  OS: Windows"
else
	$(ECHO) "  OS: Unix/Linux"
endif
	$(ECHO) "  Compiler: $(CC)"
	$(ECHO) "  Lexer: $(LEX)"
	$(ECHO) "  Parser: $(YACC)"
	$(ECHO) "  Target: $(TARGET_FULL)"

.PHONY: all clean test test-file test-opt test-arrays test-doubles help info
