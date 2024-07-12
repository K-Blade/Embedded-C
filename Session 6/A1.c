#include <stdio.h>

void castChar(void *ptr);
void castInt(void *ptr);
void castFloat(void *ptr);

int main() {
    float value = 65.1234;

    char *charPtr;
    int *intPtr;
    float *floatPtr;

    charPtr = (char *)&value;
    intPtr = (int *)&value;
    floatPtr = &value;

    printf("\nUsing function calls:\n");
    castChar(charPtr);
    castInt(intPtr);
    castFloat(floatPtr);

    return 0;
}

void castChar(void *ptr) {
    printf("Value as char: %c\n", *(char *)ptr);
}

void castInt(void *ptr) {
    printf("Value as int: %d\n", *(int *)ptr);
}

void castFloat(void *ptr) {
    printf("Value as float: %f\n", *(float *)ptr);
}

