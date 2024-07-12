// Program to find whether a number a amstrong number or not
#include <stdio.h>
#include <math.h>

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        count++;
        number /= 10;
    }
    return count;
}

int main() {
    int number, originalNumber, rem, digits;
    int sum = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    originalNumber = number;
    digits = countDigits(number);

    while (number != 0) {
        rem = number % 10;
        sum += pow(rem, digits);
        number /= 10;
    }

    if (sum == originalNumber) {
        printf("%d is an Armstrong number.\n", originalNumber);
    } else {
        printf("%d is not an Armstrong number.\n", originalNumber);
    }

    return 0;
}

