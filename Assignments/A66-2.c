#include <stdio.h>

#define MAX 2

int main() {
    #if MAX == 1
        printf("MAX = 1\n");
    #elif MAX == 2
        printf("MAX = 2\n");
    #elif MAX == 3
        printf("MAX = 3\n");
    #else
        printf("MAX is set to a value other than 1, 2, or 3\n");
    #endif

    return 0;
}
