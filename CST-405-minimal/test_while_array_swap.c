/* Test while loops with arrays and swap function */
/* This program demonstrates bubble sort using while and if statements */

int num[5];

/* Swap function that swaps two adjacent elements in the global array */
void swap(int idx) {
    int temp;
    temp = num[idx];
    num[idx] = num[idx + 1];
    num[idx + 1] = temp;
    return;
}

int main() {
    int numLength = 5;
    int x;
    int i;

    /* Initialize array with unsorted values */
    num[0] = 64;
    num[1] = 34;
    num[2] = 25;
    num[3] = 12;
    num[4] = 22;

    /* Print original array */
    print(1111);
    print(num[0]);
    print(num[1]);
    print(num[2]);
    print(num[3]);
    print(num[4]);

    /* Bubble sort using while loop and if statements */
    i = 0;
    while (i < numLength) {
        x = 0;
        while (x < numLength - 1) {
            /* If current element is greater than next, swap them */
            if (num[x] > num[x + 1]) {
                swap(x);
            }
            x = x + 1;
        }
        i = i + 1;
    }

    /* Print sorted array */
    print(2222);
    print(num[0]);
    print(num[1]);
    print(num[2]);
    print(num[3]);
    print(num[4]);

    return 0;
}
