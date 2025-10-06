# Minimal C Compiler - Cross-Platform Build

A educational C compiler that works on both Windows and Linux/Unix systems.

## Features
- Integer and double data types
- Arithmetic operations (+, -, *, /)
- 1D arrays
- Constant folding and propagation optimization
- MIPS assembly code generation

## Building the Compiler

### Windows

#### Prerequisites
- **GCC compiler**: Install MinGW-w64 or MSYS2
- **Make**: Install via MinGW, MSYS2, or Chocolatey (`choco install make`)
- **Flex & Bison**: Install via MSYS2 or download Windows binaries

#### Build Methods

**Option 1: Using the batch file**
```batch
build.bat
```

**Option 2: Using make directly**
```batch
make clean
make
```

**Option 3: Using PowerShell**
```powershell
make clean; make
```

### Linux/Unix/macOS

#### Prerequisites

**Ubuntu/Debian:**
```bash
sudo apt-get install gcc make flex bison
```

**Fedora/RHEL:**
```bash
sudo yum install gcc make flex bison
```

**Arch Linux:**
```bash
sudo pacman -S gcc make flex bison
```

**macOS (with Homebrew):**
```bash
brew install gcc make flex bison
```

#### Build Methods

**Option 1: Using the build script**
```bash
chmod +x build.sh
./build.sh
```

**Option 2: Using make directly**
```bash
make clean
make
```

## Running the Compiler

### Windows
```batch
minicompiler.exe input.c output.s
```

### Linux/Unix
```bash
./minicompiler input.c output.s
```

## Testing

The Makefile includes several test targets:

```bash
# Basic test
make test

# Test optimization features
make test-opt

# Test array support
make test-arrays

# Test double support
make test-doubles

# Test with your own file
make test-file FILE=myprogram.c
```

## Makefile Targets

- `make` or `make all` - Build the compiler
- `make clean` - Remove all generated files
- `make test` - Run basic test
- `make test-file FILE=<filename>` - Test with specific file
- `make test-opt` - Test optimization features
- `make test-arrays` - Test array support
- `make test-doubles` - Test double support
- `make help` - Show available targets
- `make info` - Show platform configuration

## Project Structure

```
.
├── scanner.l        # Lexical analyzer (Flex)
├── parser.y         # Parser (Bison)
├── ast.c/h         # Abstract Syntax Tree
├── symtab.c/h      # Symbol table
├── tac.c/h         # Three-Address Code & Optimization
├── codegen.c/h     # MIPS code generation
├── main.c          # Main driver program
├── Makefile        # Cross-platform build file
├── build.bat       # Windows build script
├── build.sh        # Linux/Unix build script
└── test_*.c        # Test files
```

## Cross-Platform Notes

The Makefile automatically detects your operating system and adjusts:
- Executable extension (.exe on Windows)
- File deletion commands (del vs rm)
- Path separators (\ vs /)
- Output commands (type vs cat)

## Troubleshooting

### Windows Issues

1. **"make: command not found"**
   - Install make via MSYS2, MinGW, or Chocolatey
   - Add the installation directory to your PATH

2. **"gcc: command not found"**
   - Install MinGW-w64 or MSYS2
   - Add `C:\mingw64\bin` (or similar) to PATH

3. **"flex/bison: command not found"**
   - Install via MSYS2: `pacman -S flex bison`
   - Or download Windows binaries from GnuWin32

### Linux Issues

1. **Permission denied**
   ```bash
   chmod +x build.sh
   chmod +x minicompiler
   ```

2. **Missing dependencies**
   - Run the appropriate install command for your distribution (see Prerequisites)

## Example Programs

### Simple Arithmetic (test_simple.c)
```c
int a;
int b;
int c;

a = 5;
b = 10;
c = a + b;
print(c);
```

### Arrays (test_arrays.c)
```c
int arr[5];
arr[0] = 10;
arr[1] = 20;
print(arr[0]);
print(arr[1]);
```

### Optimization Test (test_opt.c)
```c
int x;
x = 10 + 20;  // Folded to 30 at compile time
print(x);
```

## License
Educational project - free to use for learning purposes.
