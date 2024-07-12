// program to find the sum of digits of a number (with and without recursion)
#include <stdio.h>

int sum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int sumRecursive(int num) {
    if (num == 0) {
        return 0;
    } else {
        return (num % 10) + sumRecursive(num / 10);
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int sum1 = sum(num);
    printf("Sum of digits (without recursion): %d\n", sum1);

    int sum2 = sumRecursive(num);
    printf("Sum of digits (using recursion): %d\n", sum2);

    return 0;
}

