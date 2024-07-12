#include <stdio.h>

void printIdentityMatrix(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the identity matrix: ");
    scanf("%d", &n);

    printIdentityMatrix(n);

    return 0;
}
