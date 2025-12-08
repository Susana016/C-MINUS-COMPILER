/* ========================================
   TEST 1: Basic While Loop
   ======================================== */
void testBasicWhile(void) {
    int i;
    i = 0;
    while (i < 5) {
        output(i);
        i = i + 1;
    }
    /* Expected output: 0 1 2 3 4 */
}

/* ========================================
   TEST 2: Nested While Loops
   ======================================== */
void testNestedWhile(void) {
    int i;
    int j;
    i = 0;
    while (i < 3) {
        j = 0;
        while (j < 2) {
            output(i * 10 + j);
            j = j + 1;
        }
        i = i + 1;
    }
    /* Expected output: 0 1 10 11 20 21 */
}

/* ========================================
   TEST 3: While Loop with Break Condition
   ======================================== */
void testWhileWithCondition(void) {
    int sum;
    int i;
    sum = 0;
    i = 1;
    while (i <= 10) {
        sum = sum + i;
        i = i + 1;
    }
    output(sum);
    /* Expected output: 55 */
}

/* ========================================
   TEST 4: Order of Operations - Arithmetic
   ======================================== */
void testArithmeticOrder(void) {
    int result;
    
    /* Test 1: Multiplication before addition */
    result = 2 + 3 * 4;
    output(result);
    /* Expected: 14 (not 20) */
    
    /* Test 2: Division before subtraction */
    result = 20 - 8 / 2;
    output(result);
    /* Expected: 16 (not 6) */
    
    /* Test 3: Left-to-right for same precedence */
    result = 10 - 5 - 2;
    output(result);
    /* Expected: 3 (not 7) */
    
    /* Test 4: Multiple operations */
    result = 2 + 3 * 4 - 10 / 2;
    output(result);
    /* Expected: 9 (2 + 12 - 5) */
}

/* ========================================
   TEST 5: Order of Operations - Parentheses
   ======================================== */
void testParenthesesOrder(void) {
    int result;
    
    /* Test 1: Parentheses override precedence */
    result = (2 + 3) * 4;
    output(result);
    /* Expected: 20 */
    
    /* Test 2: Nested parentheses */
    result = ((2 + 3) * (4 + 1)) / 5;
    output(result);
    /* Expected: 5 */
    
    /* Test 3: Multiple parentheses groups */
    result = (10 - 5) * (3 + 2);
    output(result);
    /* Expected: 25 */
}

/* ========================================
   TEST 6: Order of Operations - Comparison
   ======================================== */
void testComparisonOrder(void) {
    int result;
    
    /* Arithmetic before comparison */
    if (2 + 3 > 4) {
        result = 1;
    } else {
        result = 0;
    }
    output(result);
    /* Expected: 1 (5 > 4) */
    
    if (10 - 5 < 3 * 2) {
        result = 1;
    } else {
        result = 0;
    }
    output(result);
    /* Expected: 1 (5 < 6) */
}

/* ========================================
   TEST 7: Loop with Complex Expressions
   ======================================== */
void testLoopWithExpressions(void) {
    int i;
    int result;
    i = 1;
    while (i * 2 < 10) {
        result = i * i + 2 * i;
        output(result);
        i = i + 1;
    }
    /* Expected: 3 8 15 24 (for i=1,2,3,4) */
}

/* ========================================
   TEST 8: Order of Operations - Logical
   ======================================== */
void testLogicalOrder(void) {
    int result;
    
    /* Comparison before logical AND/OR */
    if (5 > 3 && 2 < 4) {
        result = 1;
    } else {
        result = 0;
    }
    output(result);
    /* Expected: 1 */
    
    if (5 < 3 || 2 < 4) {
        result = 1;
    } else {
        result = 0;
    }
    output(result);
    /* Expected: 1 */
}

/* ========================================
   TEST 9: Complex Loop Conditions
   ======================================== */
void testComplexLoopCondition(void) {
    int i;
    int j;
    i = 0;
    j = 10;
    while (i < j && i + j < 15) {
        output(i);
        output(j);
        i = i + 1;
        j = j - 1;
    }
    /* Expected: 0 10 1 9 2 8 */
}

/* ========================================
   TEST 10: Order of Operations - Unary
   ======================================== */
void testUnaryOperations(void) {
    int result;
    int x;
    
    x = 5;
    result = -x + 10;
    output(result);
    /* Expected: 5 (-5 + 10) */
    
    result = 2 * -x;
    output(result);
    /* Expected: -10 */
    
    if (!0) {
        result = 1;
    } else {
        result = 0;
    }
    output(result);
    /* Expected: 1 */
}

/* ========================================
   TEST 11: Countdown Loop
   ======================================== */
void testCountdownLoop(void) {
    int count;
    count = 5;
    while (count > 0) {
        output(count);
        count = count - 1;
    }
    /* Expected output: 5 4 3 2 1 */
}

/* ========================================
   TEST 12: Array Access with Expressions
   ======================================== */
void testArrayWithExpressions(void) {
    int arr[5];
    int i;
    
    i = 0;
    while (i < 5) {
        arr[i] = i * 2 + 1;
        i = i + 1;
    }
    
    i = 0;
    while (i < 5) {
        output(arr[i]);
        i = i + 1;
    }
    /* Expected: 1 3 5 7 9 */
}

/* ========================================
   MAIN - Run All Tests
   ======================================== */
void main(void) {
    output(999);  /* Test separator */
    testBasicWhile();
    
    output(999);
    testNestedWhile();
    
    output(999);
    testWhileWithCondition();
    
    output(999);
    testArithmeticOrder();
    
    output(999);
    testParenthesesOrder();
    
    output(999);
    testComparisonOrder();
    
    output(999);
    testLoopWithExpressions();
    
    output(999);
    testLogicalOrder();
    
    output(999);
    testComplexLoopCondition();
    
    output(999);
    testUnaryOperations();
    
    output(999);
    testCountdownLoop();
    
    output(999);
    testArrayWithExpressions();
}