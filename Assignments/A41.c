// Program to check whether a number is pallindrome or not.
#include <stdio.h>

int main() {
    int number, originalNumber, rev = 0, rem;

    printf("Enter a number: ");
    scanf("%d", &number);

    originalNumber = number;

    while (number != 0) {
        rem = number % 10;
        rev = rev * 10 + rem;
        number /= 10;
    }

    if (originalNumber == rev) {
        printf("%d is a palindrome.\n", originalNumber);
    } else {
        printf("%d is not a palindrome.\n", originalNumber);
    }

    return 0;
}

