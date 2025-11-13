int main() {

    int x = 10;
    int y = 3;

    int sum = x + y;
    int diff = x - y;
    int prod = x * y;
    int quot = x / y;
    int mod = x % y;

    print(sum);
    print(diff);
    print(prod);
    print(quot);
    print(mod);

    int choice = 2;
    int result;

    switch (choice) {
        case 1:
            result = 100;
            print(result);
            break;
        case 2:
            result = 200;
            print(result);
            break;
        case 3:
            result = 300;
            print(result);
            break;
        default:
            result = 999;
            print(result);
            break;
    }
}
