// Test program for all arithmetic operations
int a;
int b;
int c;
int d;
int e;

a = 10;
b = 3;

// Test subtraction
c = a - b;      // 10 - 3 = 7
print(c);

// Test multiplication
d = a * b;      // 10 * 3 = 30
print(d);

// Test division
e = a / b;      // 10 / 3 = 3 (integer division)
print(e);

// Test mixed operations with precedence
int result;
result = a + b * c - d / b;  // 10 + (3 * 7) - (30 / 3) = 10 + 21 - 10 = 21
print(result);
