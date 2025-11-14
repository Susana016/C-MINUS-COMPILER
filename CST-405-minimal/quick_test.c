int a = 1;
int b = 5;

if (a > b) {
    print(1);
} else {
    print(0);
}

a = 10;
b = 5;

while (a > b) {
    print(a);
    a = a - 1;
}

int arr[5];
arr[0] = 9;
arr[1] = 3;
arr[2] = 7;
arr[3] = 1;
arr[4] = 5;

print(arr[0]);
print(arr[1]);
print(arr[2]);
print(arr[3]);
print(arr[4]);

int choice = 2;
int result;

switch (choice) {
    case 1:
        result = 100;
        break;
    case 2:
        result = 200;
        break;
    case 3:
        result = 300;
        break;
    default:
        result = 999;
        break;
}

print(result);

int x = 5 % 3;
int y = 10 / 2;
int z = 4 * 5;

print(x);
print(y);
print(z);
