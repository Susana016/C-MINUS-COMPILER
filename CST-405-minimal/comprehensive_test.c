int gx = 5;
int gy = 3;

int getNumber() {
    int result;
    result = 42;
    return result;
}

int testScope() {
    int gx;
    gx = 100;
    return gx;
}

int addGlobals() {
    return gx + gy;
}

int main() {
    int sum = gx + gy;
    int diff = gx - gy;
    int prod = gx * gy;
    int quot = gx / gy;
    int mod = gx % gy;
    print(sum);
    print(diff);
    print(prod);
    print(quot);
    print(mod);

    int funcResult = getNumber();
    print(funcResult);

    int arr[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    int arrSum = arr[0] + arr[1] + arr[2];
    print(arrSum);

    int matrix[2][2];
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 3;
    matrix[1][1] = 4;
    int diagonal = matrix[0][0] + matrix[1][1];
    print(diagonal);

    int i = 0;
    int loopSum = 0;
    while (i < 5) {
        loopSum = loopSum + i;
        i = i + 1;
    }
    print(loopSum);

    int complex = gx * 2 + arr[1] / 2 - mod;
    print(complex);

    int testVal = 7;
    if (testVal > 7) {
        print(100);
    } else {
        print(200);
    }

    int forSum = 0;
    int j;
    for (j = 0; j < 5; j = j + 1) {
        forSum = forSum + j;
    }
    print(forSum);

    int scopeTest = testScope();
    print(scopeTest);

    int globalSum = addGlobals();
    print(globalSum);

    int localGx;
    localGx = 999;
    print(localGx);
    print(gx);

    return 0;
}
