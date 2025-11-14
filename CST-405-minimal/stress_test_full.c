int a;
int b;

a = 1;
b = 5;

if (a > b) {
    print(1);
} else {
    print(0);
}

a = 10;
b = 5;
int c = 20;
int d = 10;

while (a > b) {
    if (c > d) {
        print(97);
        print(61);
        
        int result = 0;
        if (a > b) {
            result = 1;
        }
        if (c > d) {
            if (result == 1) {
                result = 1;
            } else {
                result = 0;
            }
        } else {
            result = 0;
        }
        
        print(result);
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
    int x_plus_1 = x + 1;
    if (x_plus_1 < numLength) {
        if (num[x] < num[x_plus_1]) {
            int temp = num[x];
            num[x] = num[x_plus_1];
            num[x_plus_1] = temp;
        }
    }
    x = x + 1;
}

print(num[0]);
print(num[1]);
print(num[2]);
print(num[3]);
print(num[4]);
