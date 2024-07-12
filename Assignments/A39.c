// Program to find whether a processor is endian or not using typecast
#include <stdio.h>

int main() {
    unsigned int num = 11;
    char *ptr = (char *)&num;

    if (*ptr == 1) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }

    printf("%d\n", *ptr);

    return 0;
}

