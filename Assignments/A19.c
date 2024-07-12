// program to check whether two numbers are equal (with and without == operator)
#include <stdio.h>

void UsingEquals(int a, int b) {
    if (a == b) {
        printf("%d and %d are equal (using == operator)\n", a, b);
    } else {
        printf("%d and %d are not equal (using == operator)\n", a, b);
    }
}

void UsingBitwise(int a, int b) {
    if ((a ^ b) == 0) {
        printf("%d and %d are equal (using bitwise operators)\n", a, b);
    } else {
        printf("%d and %d are not equal (using bitwise operators)\n", a, b);
    }
}

int main() {
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    UsingEquals(num1, num2);
    UsingBitwise(num1, num2);

    return 0;
}

