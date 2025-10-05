int x;
int y;
int z;

x = 10;
y = 20;
z = x + y;
print(z);

if (x) {
    print(x);
}

x = z + 5;
print(x);

if (y) {
    print(y);
} else {
    print(x);
}

y = x + y + z;
print(y);

if (z) {
    int a;
    a = 100;
    print(a);
} else {
    int b;
    b = 200;
    print(b);
}