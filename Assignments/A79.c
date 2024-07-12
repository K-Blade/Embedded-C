#include <stdio.h>

struct stud {
    char gend;
    int rno;
} st;

int main() {
    printf("size of Struct: %d\n", sizeof(st));
    return 0;
}