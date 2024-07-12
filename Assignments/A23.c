// program to print a identity matrix in simplest logic
#include <stdio.h>

void IMatrix(int n) {
	int i,j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (i == j) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the identity matrix: ");
    scanf("%d", &n);

    printf("Identity matrix of size %d:\n", n);
    IMatrix(n);

    return 0;
}

