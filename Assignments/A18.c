// program to swap two numbers (without and without third variable )
#include <stdio.h>

void WithThirdVariable(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void WithoutThirdVariable(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Before swapping:\nnum1 = %d, num2 = %d\n", num1, num2);

	WithThirdVariable(&num1, &num2);
    printf("After swapping with third variable:\nnum1 = %d, num2 = %d\n", num1, num2);

    WithoutThirdVariable(&num1, &num2);
    printf("After swapping without third variable:\nnum1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
