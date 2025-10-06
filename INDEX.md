# C-Minus Lexical Analyzer - Documentation Index

Welcome to the merged C-Minus Lexical Analyzer! This index will help you navigate the documentation.

## 📚 Documentation Files

### Quick Start
1. **[BUILD_INSTRUCTIONS.md](BUILD_INSTRUCTIONS.md)** - Start here!
   - How to build the lexer
   - How to run tests
   - Expected output examples

### Project Information
2. **[README.md](README.md)** - Project Overview
   - Features and capabilities
   - Technical details
   - Integration notes

3. **[PROJECT_STATUS.md](PROJECT_STATUS.md)** - Current Status
   - Directory structure
   - Verification results
   - Success metrics

### Merge Information
4. **[MERGE_COMPLETE.md](MERGE_COMPLETE.md)** - Merge Summary
   - What was merged
   - Key improvements
   - Quick start guide

5. **[MERGE_SUMMARY.md](MERGE_SUMMARY.md)** - Technical Details
   - Source directories
   - Feature comparison
   - Implementation notes

## 🚀 Quick Start Commands

```bash
# Build and test in one command
make test

# Just build
make

# Run on test program
./lexer testProg.cmm

# Run on your own program
./lexer your_program.cmm

# Clean up generated files
make clean

# Rebuild from scratch
make rebuild

# View Makefile help
make help
```

## 📁 Source Files

- **`lexer.l`** - Flex lexical analyzer specification (main source)
- **`testProg.cmm`** - Test program in C-Minus language
- **`Makefile`** - Build automation script
- **`.gitignore`** - Git version control ignore patterns

## 🔧 Generated Files (after build)

- **`lex.yy.c`** - Generated C code from flex
- **`lexer`** - Compiled executable
- **`lexer.dSYM/`** - Debug symbols (macOS)

## 📖 Reading Order

### For First-Time Users
1. Start with **BUILD_INSTRUCTIONS.md**
2. Run `make test` to see it work
3. Read **README.md** for understanding

### For Technical Review
1. Read **MERGE_SUMMARY.md** for technical details
2. Review **lexer.l** source code
3. Check **PROJECT_STATUS.md** for verification

### For Integration
1. Review **README.md** integration notes
2. Examine **lexer.l** token return statements (commented)
3. Check supported token types and patterns

## 🎯 Key Features

- ✅ Line and column position tracking
- ✅ Comprehensive token recognition
- ✅ Multi-line comment handling
- ✅ Detailed error reporting
- ✅ Scientific notation support
- ✅ String literal handling

## 📊 Token Types Supported

| Category | Examples |
|----------|----------|
| Keywords | `if`, `else`, `while`, `return`, `read`, `write` |
| Types | `int`, `char`, `bool`, `float`, `void` |
| Operators | `+`, `-`, `*`, `/`, `==`, `!=`, `&&`, `||` |
| Punctuation | `;`, `,`, `(`, `)`, `{`, `}`, `[`, `]` |
| Literals | Numbers, Strings, Identifiers |

## 🔍 Testing

### Test Program Features
The included `testProg.cmm` tests:
- Variable declarations
- Array syntax
- Function definitions
- Control structures (if/else, while)
- Operators and expressions
- Intentional lexical error (for validation)

### Expected Behavior
- All valid tokens recognized with correct positions
- One lexical error detected: `#` at line 19, column 6
- Final summary: "Lexical analysis completed with 1 error(s)."

## 🛠️ Build Requirements

- **flex** - Fast Lexical Analyzer generator
- **gcc** - GNU C Compiler (or compatible C compiler)
- **make** - Build automation tool

## 📝 Output Format

Each token is printed as:
```
TOKEN_TEXT : TOKEN_TYPE (line LINE#,col COL#)
```

Example:
```
int : TYPE (line 1,col 1)
x : IDENTIFIER (line 1,col 5)
; : SEMICOLON (line 1,col 6)
```

## ⚙️ Customization

### Adding New Keywords
Edit the `Keyword` pattern in `lexer.l`:
```lex
Keyword       (read|write|...|your_keyword)
```

### Adding New Token Types
Add a new rule in the rules section:
```lex
"your_token" { /* action */ }
```

## 🤝 Integration Notes

The lexer is designed to be integrated into a full compiler:
- Token return statements are commented out
- Can be uncommented when connecting to a parser
- Symbol table ready for semantic analysis
- Position tracking aids in error messages

## 📬 Project Structure

```
main/
├── Documentation (this file and others)
├── Source Code (lexer.l)
├── Test Files (testProg.cmm)
├── Build Files (Makefile, .gitignore)
└── Generated Files (created by build)
```

## 🎓 Learning Resources

- **Flex Documentation**: https://github.com/westes/flex
- **Compiler Design**: Dragon Book (Aho, Sethi, Ullman)
- **C-Minus Language**: See project documentation

## ✅ Verification Checklist

- [x] Code merged from both sources
- [x] Enhanced features retained
- [x] Build system created
- [x] Documentation complete
- [x] Tests passing
- [x] No build warnings
- [x] Error detection working

## 📞 Support

For issues or questions:
1. Review documentation in this directory
2. Check `lexer.l` comments for implementation details
3. Examine `testProg.cmm` for usage examples

---

**Last Updated**: October 5, 2025  
**Version**: 1.0 (Merged)  
**Status**: Production Ready ✅
