#include <stdio.h>

void CharArray(void *ptr, int length);
void IntArray(void *ptr, int length);
void FloatArray(void *ptr, int length);

int main() {
    float values[] = {65.1234, 66.5678, 67.9101, 68.1121};
    int length = sizeof(values) / sizeof(values[0]);

    char *charArray;
    int *intArray;
    float *floatArray;

    charArray = (char *)values;
    intArray = (int *)values;
    floatArray = values;

    printf("Using function calls:\n");
    CharArray(charArray, sizeof(values));
    IntArray(intArray, length);
    FloatArray(floatArray, length);

    return 0;
}

void CharArray(void *ptr, int length) {
	int i;
    char *charPtr = (char *)ptr;
    printf("Values as char array:\n");
    for (i = 0; i < length; i++) {
        printf("%c ", charPtr[i]);
    }
    printf("\n");
}

void IntArray(void *ptr, int length) {
	int i;
    int *intPtr = (int *)ptr;
    printf("Values as int array:\n");
    for (i = 0; i < length; i++) {
        printf("%d ", intPtr[i]);
    }
    printf("\n");
}

void FloatArray(void *ptr, int length) {
	int i;
    float *floatPtr = (float *)ptr;
    printf("Values as float array:\n");
    for (i = 0; i < length; i++) {
        printf("%f ", floatPtr[i]);
    }
    printf("\n");
}

