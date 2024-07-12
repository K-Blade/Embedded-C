#include <stdio.h>

int subtract(int a, int b) {
    return a + ((~b) + 1);
}

int main() {
    int num1 = 1;
    int num2 = 3;
    
    int result = subtract(num1, num2);
    printf("%d - %d = %d\n", num1, num2, result);
    
    return 0;
}

