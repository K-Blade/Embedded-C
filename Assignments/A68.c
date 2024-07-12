#include <stdio.h>

void Numbers(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void Pattern(int n, int current) {
    if (current > n) {
        return;
    }
    Numbers(current);
    Pattern(n, current + 1);

    if (current != n) {
        Numbers(current);
    }
}

int main() {
    int n = 3;
    Pattern(n, 1);
    return 0;
}
