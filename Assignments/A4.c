#include <stdio.h>

int main() {
    int n, original;
    long long factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        while (n > 1) {
            factorial *= n;
            n--;
        }

        printf("Factorial of %d is: %lld\n", original, factorial);
    }

    return 0;
}
