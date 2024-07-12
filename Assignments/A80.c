#include <stdio.h>

struct stud {
    char gend __attribute__((__packed__));
    int rno __attribute__((__packed__));
} st __attribute__((__packed__));

int main() {
    printf("Size of Struct: %d\n", sizeof(st));
    return 0;
}
