#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello";

    printf("Using strlen on '%s' gives: %d\n", str, strlen(str));

    printf("\nUsing sizeof on '%s' gives: %d\n",str, sizeof(str));

    return 0;
}
