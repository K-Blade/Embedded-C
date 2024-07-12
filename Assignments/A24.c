// Program to multiply 2 numbers without using * operator
#include <stdio.h>

int multiply(int a, int b) {
    int result = 0;

    while (b != 0) {
        if (b & 1) {
            result += a;
        }
        
        a <<= 1;
        b >>= 1;
    }

    return result;
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int product = multiply(num1, num2);

    printf("Product: %d\n", product);

    return 0;
}

