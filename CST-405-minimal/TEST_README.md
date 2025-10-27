# Test Files

## Test Files

### comprehensive_test.c (Primary Test)
Complete feature test covering all compiler capabilities:
- ✅ Global variable declarations and initialization
- ✅ Function definitions and calls
- ✅ All arithmetic operations (+, -, *, /, %)
- ✅ 1D array declaration, assignment, and access
- ✅ 2D array declaration, assignment, and access
- ✅ While loops with comparison operators
- ✅ Complex expressions
- ✅ Return statements

**Expected Output:**
```
8
2
15
1
2
42
60
5
10
18
```

**Compile and Run:**
```bash
./minicompiler.exe comprehensive_test.c output.s
# Then run output.s in MARS, SPIM, or QtSPIM
```

### test.c (Legacy Test)
Original test file demonstrating:
- Global variable initialization
- 1D and 2D array operations
- Old-style code (no explicit functions, auto-wrapped in main)

**Note:** Use comprehensive_test.c for demonstrations as it's more complete and modern.
