#include <stdio.h>

int myfunc_char(int *ptr) {
    printf("Value as char: %d\n", *ptr);
    return *ptr;
}

int main() {
    char c = 'S';
    char *d = &c;
    
    myfunc_char((int *)d);
    return 0;
}

