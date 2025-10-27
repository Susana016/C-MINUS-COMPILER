int x = 5;
int y = x + 3;

int arr[3];

arr[0] = x;
arr[1] = y;
arr[2] = arr[0] + arr[1];

int total;
total = arr[0] + arr[1] + arr[2];

print(total);


int matrix[2][2];

matrix[0][0] = 1;
matrix[0][1] = 2;
matrix[1][0] = 3;
matrix[1][1] = 4;

int sum;
sum = matrix[0][0] + matrix[0][1];
sum = sum + matrix[1][0];
sum = sum + matrix[1][1];


print(sum);