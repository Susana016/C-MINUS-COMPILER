int a;
int b;
int c;
int d;

a = 1;
b = 5;

if (a > b) {
    print(1);
} else {
    print(0);
}

a = 10;
b = 5;
c = 20;
d = 10;

while (a > b) {
    if (c > d) {
        print(a);
        print(b);
        print(c);
        print(d);
        a = a - 1;
    }
}

int x = 0;
int numLength = 5;
int num[10];

num[0] = 5;
num[1] = 2;
num[2] = 8;
num[3] = 1;
num[4] = 9;

while (x < numLength) {
    int next = x + 1;
    if (num[x] < num[next]) {
        int temp = num[x];
        num[x] = num[next];
        num[next] = temp;
    }
    x = x + 1;
}

print(num[0]);
print(num[1]);
print(num[2]);
print(num[3]);
print(num[4]);
