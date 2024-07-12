// Program to Integer Array Using Pointers
#include <stdio.h>

void reversePrintIntArray(int *arr, int size) {
    int i;
	for (i = size - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    reversePrintIntArray(arr, size);
    return 0;
}

