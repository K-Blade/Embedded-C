// Program to find the factorial of a number
#include <stdio.h>

unsigned long long fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int number;
    unsigned long long result;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        result = fact(number);
        printf("Factorial of %d is %llu.\n", number, result);
    }

    return 0;
}

