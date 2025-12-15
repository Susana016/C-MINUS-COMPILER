/*
 * Comprehensive Test File for C-Minus Compiler
 * Tests ALL major features of the language
 */

/* ========================================
   GLOBAL VARIABLES
   ======================================== */
int globalX;
int globalY;
int globalArray[10];

/* ========================================
   ARITHMETIC OPERATIONS
   ======================================== */
int testArithmetic(int a, int b) {
    int sum;
    int diff;
    int prod;
    int quot;
    int mod;
    
    sum = a + b;
    diff = a - b;
    prod = a * b;
    quot = a / b;
    mod = a % b;
    
    return sum + diff + prod + quot;
}

/* ========================================
   RELATIONAL OPERATIONS
   ======================================== */
int testRelational(int x, int y) {
    int result;
    result = 0;
    
    if (x < y) {
        result = result + 1;
    }
    if (x <= y) {
        result = result + 10;
    }
    if (x > y) {
        result = result + 100;
    }
    if (x >= y) {
        result = result + 1000;
    }
    if (x == y) {
        result = result + 10000;
    }
    if (x != y) {
        result = result + 100000;
    }
    
    return result;
}

/* ========================================
   IF-ELSE STATEMENTS
   ======================================== */
int testIfElse(int value) {
    int result;
    
    if (value > 50) {
        result = 1;
    } else {
        result = 0;
    }
    
    if (value > 100) {
        result = 100;
    } else {
        if (value > 50) {
            result = 50;
        } else {
            result = 0;
        }
    }
    
    return result;
}

/* ========================================
   WHILE LOOPS
   ======================================== */
int testWhileLoop(int n) {
    int sum;
    int i;
    
    sum = 0;
    i = 1;
    
    while (i <= n) {
        sum = sum + i;
        i = i + 1;
    }
    
    return sum;
}

/* ========================================
   NESTED LOOPS
   ======================================== */
int testNestedLoops(int rows, int cols) {
    int total;
    int i;
    int j;
    
    total = 0;
    i = 0;
    
    while (i < rows) {
        j = 0;
        while (j < cols) {
            total = total + 1;
            j = j + 1;
        }
        i = i + 1;
    }
    
    return total;
}

/* ========================================
   LOCAL ARRAYS
   ======================================== */
int testLocalArray() {
    int arr[5];
    int i;
    int sum;
    
    i = 0;
    while (i < 5) {
        arr[i] = i * 2;
        i = i + 1;
    }
    
    sum = 0;
    i = 0;
    while (i < 5) {
        sum = sum + arr[i];
        i = i + 1;
    }
    
    return sum;
}

/* ========================================
   ARRAY AS PARAMETER
   ======================================== */
void fillArray(int arr[], int size) {
    int i;
    i = 0;
    while (i < size) {
        arr[i] = i + 1;
        i = i + 1;
    }
}

int sumArray(int arr[], int size) {
    int sum;
    int i;
    
    sum = 0;
    i = 0;
    while (i < size) {
        sum = sum + arr[i];
        i = i + 1;
    }
    
    return sum;
}

/* ========================================
   RECURSION - FACTORIAL
   ======================================== */
int factorial(int n) {
    int result;
    int temp;
    
    if (n <= 1) {
        result = 1;
    } else {
        temp = n - 1;
        result = n * factorial(temp);
    }
    
    return result;
}

/* ========================================
   RECURSION - FIBONACCI
   ======================================== */
int fibonacci(int n) {
    int result;
    int n1;
    int n2;
    
    if (n <= 1) {
        result = n;
    } else {
        n1 = n - 1;
        n2 = n - 2;
        result = fibonacci(n1) + fibonacci(n2);
    }
    
    return result;
}

/* ========================================
   POWER FUNCTION
   ======================================== */
int power(int base, int exp) {
    int result;
    int temp;
    
    if (exp == 0) {
        result = 1;
    } else {
        temp = exp - 1;
        result = base * power(base, temp);
    }
    
    return result;
}

/* ========================================
   GCD (Greatest Common Divisor)
   ======================================== */
int gcd(int a, int b) {
    int temp;
    int remainder;
    
    while (b != 0) {
        temp = a / b;
        remainder = a - temp * b;
        a = b;
        b = remainder;
    }
    
    return a;
}

/* ========================================
   FIND MAX IN ARRAY
   ======================================== */
int findMax(int arr[], int size) {
    int max;
    int i;
    
    max = arr[0];
    i = 1;
    
    while (i < size) {
        if (arr[i] > max) {
            max = arr[i];
        }
        i = i + 1;
    }
    
    return max;
}

/* ========================================
   FIND MIN IN ARRAY
   ======================================== */
int findMin(int arr[], int size) {
    int min;
    int i;
    
    min = arr[0];
    i = 1;
    
    while (i < size) {
        if (arr[i] < min) {
            min = arr[i];
        }
        i = i + 1;
    }
    
    return min;
}

/* ========================================
   PRIME NUMBER CHECK
   ======================================== */
int isPrime(int n) {
    int i;
    int temp;
    int result;
    
    if (n <= 1) {
        result = 0;
    } else {
        result = 1;
        i = 2;
        while (i < n) {
            temp = n / i;
            temp = temp * i;
            if (temp == n) {
                result = 0;
                i = n;
            } else {
                i = i + 1;
            }
        }
    }
    
    return result;
}

/* ========================================
   COUNT PRIMES UP TO N
   ======================================== */
int countPrimes(int limit) {
    int count;
    int i;
    int primeCheck;
    
    count = 0;
    i = 2;
    
    while (i <= limit) {
        primeCheck = isPrime(i);
        if (primeCheck == 1) {
            count = count + 1;
        }
        i = i + 1;
    }
    
    return count;
}

/* ========================================
   LINEAR SEARCH
   ======================================== */
int linearSearch(int arr[], int size, int target) {
    int i;
    int found;
    
    i = 0;
    found = -1;
    
    while (i < size) {
        if (arr[i] == target) {
            found = i;
            i = size;
        } else {
            i = i + 1;
        }
    }
    
    return found;
}

/* ========================================
   BUBBLE SORT
   ======================================== */
void bubbleSort(int arr[], int size) {
    int i;
    int j;
    int temp;
    int limit1;
    int limit2;
    int jPlus1;
    
    i = 0;
    limit1 = size - 1;
    while (i < limit1) {
        j = 0;
        limit2 = size - i;
        limit2 = limit2 - 1;
        while (j < limit2) {
            jPlus1 = j + 1;
            if (arr[j] > arr[jPlus1]) {
                temp = arr[j];
                arr[j] = arr[jPlus1];
                arr[jPlus1] = temp;
            }
            j = j + 1;
        }
        i = i + 1;
    }
}

/* ========================================
   REVERSE ARRAY
   ======================================== */
void reverseArray(int arr[], int size) {
    int left;
    int right;
    int temp;
    
    left = 0;
    right = size - 1;
    
    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left = left + 1;
        right = right - 1;
    }
}

/* ========================================
   COPY ARRAY
   ======================================== */
void copyArray(int source[], int dest[], int size) {
    int i;
    
    i = 0;
    while (i < size) {
        dest[i] = source[i];
        i = i + 1;
    }
}

/* ========================================
   ARRAY EQUAL CHECK
   ======================================== */
int arrayEqual(int arr1[], int arr2[], int size) {
    int i;
    int equal;
    
    equal = 1;
    i = 0;
    
    while (i < size) {
        if (arr1[i] != arr2[i]) {
            equal = 0;
            i = size;
        } else {
            i = i + 1;
        }
    }
    
    return equal;
}

/* ========================================
   ABSOLUTE VALUE
   ======================================== */
int absoluteValue(int x) {
    int result;
    int negX;
    
    if (x < 0) {
        negX = 0 - x;
        result = negX;
    } else {
        result = x;
    }
    
    return result;
}

/* ========================================
   SIGN FUNCTION
   ======================================== */
int sign(int x) {
    int result;
    
    if (x < 0) {
        result = -1;
    } else {
        if (x > 0) {
            result = 1;
        } else {
            result = 0;
        }
    }
    
    return result;
}

/* ========================================
   SUM OF SQUARES
   ======================================== */
int sumOfSquares(int n) {
    int sum;
    int i;
    int iSquared;
    
    sum = 0;
    i = 1;
    
    while (i <= n) {
        iSquared = i * i;
        sum = sum + iSquared;
        i = i + 1;
    }
    
    return sum;
}

/* ========================================
   SUM OF CUBES
   ======================================== */
int sumOfCubes(int n) {
    int sum;
    int i;
    int iSquared;
    int iCubed;
    
    sum = 0;
    i = 1;
    
    while (i <= n) {
        iSquared = i * i;
        iCubed = iSquared * i;
        sum = sum + iCubed;
        i = i + 1;
    }
    
    return sum;
}

/* ========================================
   CALCULATE MEAN
   ======================================== */
int calculateMean(int arr[], int size) {
    int sum;
    int i;
    
    sum = 0;
    i = 0;
    
    while (i < size) {
        sum = sum + arr[i];
        i = i + 1;
    }
    
    return sum / size;
}

/* ========================================
   COUNT OCCURRENCES
   ======================================== */
int countOccurrences(int arr[], int size, int value) {
    int count;
    int i;
    
    count = 0;
    i = 0;
    
    while (i < size) {
        if (arr[i] == value) {
            count = count + 1;
        }
        i = i + 1;
    }
    
    return count;
}

/* ========================================
   LEFT SHIFT (SIMULATED)
   ======================================== */
int leftShift(int n, int bits) {
    int result;
    int i;
    
    result = n;
    i = 0;
    
    while (i < bits) {
        result = result * 2;
        i = i + 1;
    }
    
    return result;
}

/* ========================================
   RIGHT SHIFT (SIMULATED)
   ======================================== */
int rightShift(int n, int bits) {
    int result;
    int i;
    
    result = n;
    i = 0;
    
    while (i < bits) {
        result = result / 2;
        i = i + 1;
    }
    
    return result;
}

/* ========================================
   MULTIPLE PARAMETERS (3)
   ======================================== */
int add3(int a, int b, int c) {
    return a + b + c;
}

int max3(int a, int b, int c) {
    int max;
    max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int multiply3(int a, int b, int c) {
    int temp;
    int result;
    
    temp = a * b;
    result = temp * c;
    return result;
}

/* ========================================
   COMPLEX EXPRESSION TESTING
   ======================================== */
int testComplexExpressions(int a, int b, int c) {
    int result;
    int temp1;
    int temp2;
    int temp3;
    int temp4;

    /* Multiple operations with precedence */
    /* a + (b * c) - (a / b) = 10 + (5 * 3) - (10 / 5) = 10 + 15 - 2 = 23 */
    temp1 = b * c;
    temp2 = a / b;
    temp3 = a + temp1;
    result = temp3 - temp2;

    /* Nested parentheses */
    /* ((a + b) * (c - a)) / (b + 1) = ((10 + 5) * (3 - 10)) / (5 + 1) = (15 * -7) / 6 = -105 / 6 = -17 */
    temp1 = a + b;
    temp2 = c - a;
    temp3 = temp1 * temp2;
    temp4 = b + 1;
    result = temp3 / temp4;

    /* Long expression */
    /* (a * b) + (c * a) - (b / c) + a - b + c */
    /* = (10 * 5) + (3 * 10) - (5 / 3) + 10 - 5 + 3 */
    /* = 50 + 30 - 1 + 10 - 5 + 3 = 87 */
    temp1 = a * b;
    temp2 = c * a;
    temp3 = b / c;
    temp4 = temp1 + temp2;
    temp4 = temp4 - temp3;
    temp4 = temp4 + a;
    temp4 = temp4 - b;
    result = temp4 + c;

    return result;
}

/* ========================================
   MULTIPLE PARAMETERS (4)
   ======================================== */
int add4(int a, int b, int c, int d) {
    int temp1;
    int temp2;
    int result;
    
    temp1 = a + b;
    temp2 = c + d;
    result = temp1 + temp2;
    return result;
}

/* ========================================
   VOID FUNCTIONS
   ======================================== */
void printValue(int x) {
    print(x);
}

void printArray(int arr[], int size) {
    int i;
    
    i = 0;
    while (i < size) {
        print(arr[i]);
        i = i + 1;
    }
}

/* ========================================
   MAIN FUNCTION
   ======================================== */
void main(void) {
    int result;
    int arr[10];
    int arr2[10];
    int i;
    int temp;
    
    /* Test 1: Arithmetic Operations (20+5=25, 20-5=15, 20*5=100, 20/5=4 => 25+15+100+4=144) */
    print(1);
    result = testArithmetic(20, 5);
    print(result);
    
    /* Test 2: Relational Operations (5 < 10) => 100011 */
    print(2);
    result = testRelational(5, 10);
    print(result);
    
    /* Test 3: Relational Operations (10 > 5) => 101100 */
    print(3);
    result = testRelational(10, 5);
    print(result);
    
    /* Test 4: If-Else (value = 75) => 50 */
    print(4);
    result = testIfElse(75);
    print(result);
    
    /* Test 5: While Loop (sum 1 to 10 = 55) */
    print(5);
    result = testWhileLoop(10);
    print(result);
    
    /* Test 6: Nested Loops (3x4 = 12) */
    print(6);
    result = testNestedLoops(3, 4);
    print(result);
    
    /* Test 7: Local Array (0+2+4+6+8 = 20) */
    print(7);
    result = testLocalArray();
    print(result);
    
    /* Test 8: Array Parameter (1+2+3+4+5 = 15) */
    print(8);
    fillArray(arr, 5);
    result = sumArray(arr, 5);
    print(result);
    
    /* Test 9: Factorial (5! = 120) */
    print(9);
    result = factorial(5);
    print(result);
    
    /* Test 10: Fibonacci (fib(7) = 13) */
    print(10);
    result = fibonacci(7);
    print(result);
    
    /* Test 11: Power (2^5 = 32) */
    print(11);
    result = power(2, 5);
    print(result);
    
    /* Test 12: GCD (48, 18) = 6 */
    print(12);
    result = gcd(48, 18);
    print(result);
    
    /* Test 13: Find Max [3,7,2,9,5] => 9 */
    print(13);
    arr[0] = 3;
    arr[1] = 7;
    arr[2] = 2;
    arr[3] = 9;
    arr[4] = 5;
    result = findMax(arr, 5);
    print(result);
    
    /* Test 14: Find Min [3,7,2,9,5] => 2 */
    print(14);
    result = findMin(arr, 5);
    print(result);
    
    /* Test 15: isPrime(17) = 1 */
    print(15);
    result = isPrime(17);
    print(result);
    
    /* Test 16: isPrime(18) = 0 */
    print(16);
    result = isPrime(18);
    print(result);
    
    /* Test 17: Count Primes up to 20 = 8 (2,3,5,7,11,13,17,19) */
    print(17);
    result = countPrimes(20);
    print(result);
    
    /* Test 18: Linear Search - find 9 in arr => index 3 */
    print(18);
    result = linearSearch(arr, 5, 9);
    print(result);
    
    /* Test 19: Bubble Sort */
    print(19);
    arr[0] = 5;
    arr[1] = 2;
    arr[2] = 8;
    arr[3] = 1;
    arr[4] = 9;
    bubbleSort(arr, 5);
    printArray(arr, 5);
    
    /* Test 20: Reverse Array [1,2,3,4,5] => [5,4,3,2,1] */
    print(20);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    reverseArray(arr, 5);
    printArray(arr, 5);
    
    /* Test 21: Copy Array and Compare */
    print(21);
    copyArray(arr, arr2, 5);
    result = arrayEqual(arr, arr2, 5);
    print(result);
    
    /* Test 22: Absolute Value |-15| = 15 */
    print(22);
    result = absoluteValue(-15);
    print(result);
    
    /* Test 23: Sign function */
    print(23);
    result = sign(-5);
    print(result);
    result = sign(5);
    print(result);
    result = sign(0);
    print(result);
    
    /* Test 24: Sum of Squares (1+4+9+16+25 = 55) */
    print(24);
    result = sumOfSquares(5);
    print(result);
    
    /* Test 25: Sum of Cubes (1+8+27+64+125 = 225) */
    print(25);
    result = sumOfCubes(5);
    print(result);
    
    /* Test 26: Calculate Mean [2,4,6,8,10] => 6 */
    print(26);
    arr[0] = 2;
    arr[1] = 4;
    arr[2] = 6;
    arr[3] = 8;
    arr[4] = 10;
    result = calculateMean(arr, 5);
    print(result);
    
    /* Test 27: Count Occurrences [5,5,3,5,7] count of 5 => 3 */
    print(27);
    arr[0] = 5;
    arr[1] = 5;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 7;
    result = countOccurrences(arr, 5, 5);
    print(result);
    
    /* Test 28: Left Shift (3 << 2 = 12) */
    print(28);
    result = leftShift(3, 2);
    print(result);
    
    /* Test 29: Right Shift (16 >> 2 = 4) */
    print(29);
    result = rightShift(16, 2);
    print(result);
    
    /* Test 30: add3(10, 20, 30) = 60 */
    print(30);
    result = add3(10, 20, 30);
    print(result);
    
    /* Test 31: max3(5, 12, 8) = 12 */
    print(31);
    result = max3(5, 12, 8);
    print(result);
    
    /* Test 32: multiply3(2, 3, 4) = 24 */
    print(32);
    result = multiply3(2, 3, 4);
    print(result);
    
    /* Test 33: add4(1, 2, 3, 4) = 10 */
    print(33);
    result = add4(1, 2, 3, 4);
    print(result);
    
    /* Test 34: Complex Expressions (10, 5, 3) => 87 */
    print(34);
    result = testComplexExpressions(10, 5, 3);
    print(result);
    
    /* Test 35: Global Variables */
    print(35);
    globalX = 100;
    globalY = 200;
    result = globalX + globalY;
    print(result);
    
    /* Test 36: Void Function */
    print(36);
    printValue(999);
    
    /* All tests complete */
    print(0);
}
