#include <stdio.h>

#define MAX 5

int main() {
    printf("Starting Program....\n");
    
    #ifdef MAX
        printf("%d\n", MAX);
        #define MAX 2
    #else
        printf("MAX is Undefined.\n");
    #endif
    
    #ifdef MAX
        printf("%d\n", MAX);
    #else
        printf("MAX is Undefined.\n");
    #endif
    
    return 0;
}

