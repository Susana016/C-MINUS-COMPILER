int main() {
    int x;
    int y;
    int z;
    int result;

    x = 10;
    y = 5;
    z = 0;

    // ===== BASIC IF STATEMENTS =====

    // Test 1: Simple if (true condition)
    if (x > 5) {
        print(1);  // Expected: 1
    }

    // Test 2: Simple if (false condition)
    if (x < 5) {
        print(999);  // Should NOT print
    }

    // Test 3: If without braces
    if (y == 5)
        print(2);  // Expected: 2

    // ===== IF-ELSE STATEMENTS =====

    // Test 4: If-else (true path)
    if (x > 5) {
        print(3);  // Expected: 3
    } else {
        print(999);  // Should NOT print
    }

    // Test 5: If-else (false path)
    if (x < 5) {
        print(999);  // Should NOT print
    } else {
        print(4);  // Expected: 4
    }

    // Test 6: If-else without braces
    if (y == 3)
        print(999);  // Should NOT print
    else
        print(5);  // Expected: 5

    // Test 7: If-else with mixed braces
    if (x == 5) {
        print(999);  // Should NOT print
    } else
        print(6);  // Expected: 6

    // ===== NESTED IF STATEMENTS =====

    // Test 8: Nested if statements
    if (x > 5) {
        if (y == 5) {
            print(7);  // Expected: 7
        }
    }

    // Test 9: Nested if-else
    if (x > 5) {
        if (y > 10) {
            print(999);  // Should NOT print
        } else {
            print(8);  // Expected: 8
        }
    }

    // Test 10: Multiple levels of nesting
    if (x > 0) {
        if (y > 0) {
            if (z == 0) {
                print(9);  // Expected: 9
            }
        }
    }

    // ===== IF WITH COMPARISON OPERATORS =====

    // Test 11: Less than
    if (y < x) {
        print(10);  // Expected: 10
    }

    // Test 12: Greater than
    if (x > y) {
        print(11);  // Expected: 11
    }

    // Test 13: Equality (using ==)
    if (y == 5) {
        print(12);  // Expected: 12
    }

    // ===== IF WITH LOGICAL OPERATORS =====

    // Test 14: AND operator (both true)
    if (x > 5 && y < 10) {
        print(13);  // Expected: 13
    }

    // Test 15: AND operator (first false)
    if (x < 5 && y < 10) {
        print(999);  // Should NOT print
    }

    // Test 16: AND operator (second false)
    if (x > 5 && y > 10) {
        print(999);  // Should NOT print
    }

    // Test 17: OR operator (both true)
    if (x > 5 || y < 10) {
        print(14);  // Expected: 14
    }

    // Test 18: OR operator (first true, second false)
    if (x > 5 || y > 10) {
        print(15);  // Expected: 15
    }

    // Test 19: OR operator (first false, second true)
    if (x < 5 || y < 10) {
        print(16);  // Expected: 16
    }

    // Test 20: OR operator (both false)
    if (x < 5 || y > 10) {
        print(999);  // Should NOT print
    }

    // Test 21: NOT operator (negating true)
    if (!(x < 5)) {
        print(17);  // Expected: 17
    }

    // Test 22: NOT operator (negating false)
    if (!(x > 5)) {
        print(999);  // Should NOT print
    }

    // Test 23: Complex logical expression
    if (x > 5 && y < 10 || z == 0) {
        print(18);  // Expected: 18
    }

    // ===== IF WITH ARITHMETIC IN CONDITIONS =====

    // Test 24: Arithmetic in condition
    if (x + y > 10) {
        print(19);  // Expected: 19 (10 + 5 = 15 > 10)
    }

    // Test 25: Multiple arithmetic operations
    if (x * y < 100) {
        print(20);  // Expected: 20 (10 * 5 = 50 < 100)
    }

    // Test 26: Modulo in condition
    if (x % 2 == 0) {
        print(21);  // Expected: 21 (10 % 2 = 0)
    }

    // ===== IF-ELSE CHAINS (ELSE-IF SIMULATION) =====

    // Test 27: Else-if chain simulation
    result = 15;
    if (result < 10) {
        print(999);  // Should NOT print
    } else {
        if (result < 20) {
            print(22);  // Expected: 22
        } else {
            print(999);  // Should NOT print
        }
    }

    // Test 28: Longer else-if chain
    result = 25;
    if (result < 10) {
        print(999);  // Should NOT print
    } else {
        if (result < 20) {
            print(999);  // Should NOT print
        } else {
            if (result < 30) {
                print(23);  // Expected: 23
            } else {
                print(999);  // Should NOT print
            }
        }
    }

    // ===== IF WITH VARIABLES IN BODY =====

    // Test 29: Variable assignment in if body
    result = 0;
    if (x > 5) {
        result = 24;
        print(result);  // Expected: 24
    }

    // Test 30: Multiple statements in if body
    if (y == 5) {
        result = 25;
        z = 100;
        print(result);  // Expected: 25
    }

    // ===== IF WITH CONSTANT EXPRESSIONS =====

    // Test 31: Constant true condition
    if (10 > 5) {
        print(26);  // Expected: 26
    }

    // Test 32: Constant false condition
    if (5 > 10) {
        print(999);  // Should NOT print
    }

    // Test 33: Constant in AND
    if (1 && x > 5) {
        print(27);  // Expected: 27
    }

    // Test 34: Zero as false
    if (0 || x > 5) {
        print(28);  // Expected: 28
    }

    // ===== COMPLEX NESTED SCENARIOS =====

    // Test 35: If-else nested in if-else
    if (x > 0) {
        if (y > 0) {
            print(29);  // Expected: 29
        } else {
            print(999);  // Should NOT print
        }
    } else {
        if (y > 0) {
            print(999);  // Should NOT print
        } else {
            print(999);  // Should NOT print
        }
    }

    // Test 36: Multiple if statements in sequence
    if (x == 10) {
        print(30);  // Expected: 30
    }
    if (y == 5) {
        print(31);  // Expected: 31
    }
    if (z == 0) {
        print(32);  // Expected: 32
    }

    // ===== IF WITH FUNCTION CALLS (if supported) =====

    // Test 37: Print inside nested if with complex condition
    if (x > 5 && y > 0) {
        if (z == 0 || x < 20) {
            print(33);  // Expected: 33
        }
    }

    // Test 38: Final comprehensive test
    x = 100;
    y = 50;
    if (x > y) {
        if (x > 75 && y < 75) {
            result = 34;
            print(result);  // Expected: 34
        }
    } else {
        print(999);  // Should NOT print
    }

    print(999);  // Final marker: 999

    return 0;
}
