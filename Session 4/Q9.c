// Program to reverse a float array using Pointers
#include <stdio.h>

void reversePrintFloatArray(float *arr, int size) {
	int i;
    for (i = size - 1; i >= 0; i--) {
        printf("%.2f ", *(arr + i));
    }
    printf("\n");
}

int main() {
    float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int size = sizeof(arr) / sizeof(arr[0]);
    reversePrintFloatArray(arr, size);
    return 0;
}

