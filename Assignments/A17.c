#include <stdio.h>

void EvenOdd(int num) {
    if ((num & 1) == 0) {
        printf("%d is even\n", num);
    } else {
        printf("%d is odd\n", num);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    EvenOdd(num);
    return 0;
}