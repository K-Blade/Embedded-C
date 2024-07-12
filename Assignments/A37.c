// Program to find whether a number is strong number or not
#include <stdio.h>

unsigned long long fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int number, originalNumber, digit;
    unsigned long long sum = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    originalNumber = number;

    while (number > 0) {
        digit = number % 10;
        sum += fact(digit);
        number /= 10;
    }

    if (sum == originalNumber) {
        printf("%d is a strong number.\n", originalNumber);
    } else {
        printf("%d is not a strong number.\n", originalNumber);
    }

    return 0;
}

