#include <stdio.h>

void castChar(void *ptr) {
    printf("Value as char: %c\n", *(char *)ptr);
}
void castInt(void *ptr) {
    printf("Value as int: %d\n", *(int *)ptr);
}

int main() {
    float value = 65.1234;

    char *charPtr;
    int *intPtr;

    charPtr = (char *)&value;
    intPtr = (int *)&value;

    castChar(charPtr);
    castInt(intPtr);

    return 0;
}