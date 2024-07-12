#include <stdio.h>

#define FACTORIAL_MACRO(n) ({int fact = 1; for (int i = 1; i <= n; ++i) { fact *= i; } fact;})

int factorial_recursion(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial_recursion(n - 1);
    }
}

int main() {
    int num, fact;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        fact = 1;
        for (int i = 1; i <= n; ++i) {
            fact *= i;
        }
        printf("Factorial using loop: %d! = %d\n", num, fact);

        printf("Factorial using recursion: %d! = %d\n", num, factorial_recursion(num));

        printf("Factorial using macro: %d! = %d\n", num, FACTORIAL_MACRO(num));
    }

    return 0;
}
