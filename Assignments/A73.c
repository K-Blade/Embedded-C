#include <stdio.h>

void Matrix(int *array, int rows, int cols) {
    int i,j;
	for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(array + i * cols + j));
        }
        printf("\n");
    }
}

int main() {
    int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    Matrix((int *)array, 3, 4);

    return 0;
}
