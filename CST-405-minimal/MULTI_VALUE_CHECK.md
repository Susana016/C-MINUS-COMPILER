# Multi-Value Equality Check Feature

## Overview

The Multi-Value Equality Check is a new language feature that provides syntactic sugar for checking if a value matches any value in a list. This feature simplifies code readability and reduces redundancy when checking multiple equality conditions.

## Syntax

```c
if (expression is value1, value2, value3, ...) {
    // code
}
```

## How It Works

### User-Facing Syntax

Instead of writing verbose OR chains like:
```c
if (day == 0 || day == 6) {
    print(1);  // Weekend
}
```

You can now write:
```c
if (day is 0, 6) {
    print(1);  // Weekend
}
```

### Internal Implementation (Desugaring)

The compiler transforms (desugars) the multi-value check into a series of equality comparisons connected by logical OR operations:

**Input:**
```c
if (day is 0, 6) {
    print(1);
}
```

**Desugared to:**
```c
if ((day == 0) || (day == 6)) {
    print(1);
}
```

### Three-Address Code (TAC) Generation

In the intermediate representation, the multi-value check is further broken down:

```
t0 = day == 0       // First comparison
t1 = day == 6       // Second comparison
t2 = t0 || t1       // Combine with OR
IF_FALSE t2 GOTO L0 // Jump if false
PRINT 1
LABEL L0:
```

### Complex Example

For more complex checks with many values:

**Input:**
```c
if (month is 1, 3, 5, 7, 8, 10, 12) {
    print(31);  // Months with 31 days
}
```

**TAC Generation:**
```
t3 = month == 1
t4 = month == 3
t5 = t3 || t4
t6 = month == 5
t7 = t5 || t6
t8 = month == 7
t9 = t7 || t8
t10 = month == 8
t11 = t9 || t10
t12 = month == 10
t13 = t11 || t12
t14 = month == 12
t15 = t13 || t14
IF_FALSE t15 GOTO L1
```

## Use Cases

### 1. Weekend Detection
```c
if (day is 0, 6) {
    print(1);  // It's the weekend!
}
```

### 2. Month Days Calculation
```c
if (month is 1, 3, 5, 7, 8, 10, 12) {
    print(31);
} else if (month is 4, 6, 9, 11) {
    print(30);
} else {
    print(28);  // February
}
```

### 3. Grade Ranges
```c
if (score is 85, 90, 95, 100) {
    print(999);  // Excellent scores
}
```

### 4. State Machine Transitions
```c
if (state is 1, 3, 7, 9) {
    // Handle specific states
    nextState = 0;
}
```

## Implementation Details

### Compilation Phases

#### 1. Lexical Analysis (`scanner.l`)
- Added `is` keyword token
- Added `==` operator for equality comparison
- Recognizes comma (`,`) for value lists

#### 2. Syntax Analysis (`parser.y`)
- Added `IS` token declaration
- Added `value_list` non-terminal for parsing comma-separated values
- Added grammar rule: `expr IS value_list`
- Values can be any expression, not just constants

#### 3. Abstract Syntax Tree (`ast.h`/`ast.c`)
- Added `NODE_MULTI_VALUE_CHECK` node type
- Added `NODE_VALUE_LIST` node type
- Stores expression and linked list of values to check

#### 4. Intermediate Code Generation (`tac.c`)
- Added `TAC_CMP_EQ` operation for equality comparison
- Multi-value check is desugared into:
  - Multiple equality comparisons (`expr == value`)
  - Chained OR operations combining results
  - Short-circuit evaluation supported

#### 5. Optimization (`tac.c`)
- Constant folding for equality comparisons
- If both operands are constants, evaluates at compile-time
- Example: `5 == 5` → `1`, `3 == 7` → `0`

#### 6. MIPS Code Generation (`codegen.c`)
- Uses `seq` (set on equal) MIPS instruction
- Equality comparison: `seq $t0, $t1, $t2` sets `$t0` to 1 if `$t1 == $t2`
- Expression value is saved to stack to prevent register clobbering across multiple comparisons
- Each comparison reloads the expression from stack and compares with the next value
- Results are combined using `or` and normalized with `sne` (set not equal to zero)

## Technical Benefits

1. **Readability**: More intuitive syntax for multiple equality checks
2. **Maintainability**: Easier to add/remove values from the check list
3. **Educational**: Demonstrates desugaring and syntactic sugar
4. **Optimization-friendly**: Creates opportunities for compile-time optimization

## Optimization Opportunities

The compiler can optimize multi-value checks in several ways:

### Constant Folding
If the expression is a constant:
```c
if (5 is 3, 5, 7) { ... }
```
Can be optimized to:
```c
if (1) { ... }  // Always true
```

### Short-Circuit Evaluation
Once a match is found, remaining comparisons can be skipped (handled by OR semantics).

### Range Optimization (Future)
Could be extended to detect ranges and generate optimized comparison code:
```c
if (x is 1, 2, 3, 4, 5) { ... }
// Could optimize to: if (x >= 1 && x <= 5) { ... }
```

## Comparison with Other Languages

### Python
```python
if day in [0, 6]:
    print("Weekend")
```

### Swift
```swift
if [0, 6].contains(day) {
    print("Weekend")
}
```

### Our Implementation
```c
if (day is 0, 6) {
    print(1);
}
```

## Testing

Run the test file:
```bash
./minicompiler.exe test_multi_value.c output_multi_value.s
```

Expected output shows:
1. AST with `MULTI_VALUE_CHECK` nodes
2. TAC with desugared equality and OR operations
3. Generated MIPS assembly code

## Limitations

1. **Current**: Only works with expressions (including constants and variables)
2. **Current**: Each comparison is independent (no range shortcuts)
3. **Future Enhancement**: Could add range syntax like `is 1..5`

## Educational Value

This feature demonstrates several compiler concepts:

1. **Syntactic Sugar**: Providing convenient syntax that maps to existing operations
2. **Desugaring**: Transforming high-level constructs into primitive operations
3. **AST Design**: Representing language features in tree form
4. **IR Generation**: Converting AST to linear intermediate code
5. **Code Generation**: Translating to target assembly language

## Future Enhancements

Potential improvements:

1. **Range Syntax**: `if (x is 1..10) { ... }`
2. **Type Checking**: Ensure all values have compatible types
3. **Pattern Matching**: Extend to more complex patterns
4. **Optimization**: Detect contiguous values and use range comparisons
5. **Not-In Check**: `if (x is not 0, 6) { ... }`

## Summary

The Multi-Value Equality Check feature (`is` operator) provides a clean, readable way to check if a value matches any of several options. It's implemented through desugaring into standard equality and OR operations, making it a perfect example of how compilers can provide syntactic convenience while maintaining simplicity in the underlying implementation.
