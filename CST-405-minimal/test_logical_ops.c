int main() {
    int x;
    int y;
    int result;

    x = 10;
    y = 5;

    // Test 1: Simple AND with two variables
    result = x > 5 && y < 10;
    print(result);  // Expected: 1 (true)

    // Test 2: Simple OR with two variables
    result = x < 5 || y > 3;
    print(result);  // Expected: 1 (true, because y > 3)

    // Test 3: Constant folding - constant comparison
    result = 12 > 5;
    print(result);  // Expected: 1 (true, optimized at compile time)

    // Test 4: Short-circuit AND with constant TRUE
    result = 12 > 5 && x < 20;
    print(result);  // Expected: 1 (12 > 5 is always true, so check x < 20)

    // Test 5: Short-circuit AND with constant FALSE
    result = 3 > 10 && x < 20;
    print(result);  // Expected: 0 (3 > 10 is always false, don't need to check x)

    // Test 6: Short-circuit OR with constant TRUE
    result = 12 > 5 || x < 2;
    print(result);  // Expected: 1 (12 > 5 is always true, don't need to check x)

    // Test 7: Short-circuit OR with constant FALSE
    result = 3 > 10 || y > 2;
    print(result);  // Expected: 1 (3 > 10 is false, but y > 2 is true)

    // Test 8: Complex expression with AND and OR
    result = x > 5 && y < 10 || x < 3;
    print(result);  // Expected: 1 (x > 5 && y < 10 is true)

    // Test 9: Multiple ANDs
    result = x > 5 && y > 3 && x < 20;
    print(result);  // Expected: 1 (all conditions are true)

    // Test 10: Multiple ORs
    result = x < 5 || y < 3 || x > 8;
    print(result);  // Expected: 1 (x > 8 is true)

    // Test 11: False AND
    result = x > 5 && y > 10;
    print(result);  // Expected: 0 (y > 10 is false)

    // Test 12: False OR
    result = x < 5 || y > 10;
    print(result);  // Expected: 0 (both conditions are false)

    // Test 13: Constant-only AND (should be optimized)
    result = 5 > 3 && 10 < 20;
    print(result);  // Expected: 1 (both true, optimized to 1)

    // Test 14: Constant-only OR (should be optimized)
    result = 5 < 3 || 10 > 20;
    print(result);  // Expected: 0 (both false, optimized to 0)

    // Test 15: Mixed constant and variable
    result = 1 && x > 5;
    print(result);  // Expected: 1 (1 is true, x > 5 is true)

    // Test 16: Zero as false in AND
    result = 0 && x > 5;
    print(result);  // Expected: 0 (0 is false, short-circuit)

    // Test 17: Zero as false in OR
    result = 0 || x > 5;
    print(result);  // Expected: 1 (0 is false, but x > 5 is true)

    // Test 18: Using result in while loop
    x = 3;
    while (x > 0 && x < 10) {
        print(x);
        x = x + 1;
        if (x > 5) {
            x = 0;
        }
    }
    // Expected output: 3, 4, 5

    return 0;
}
