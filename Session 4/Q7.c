// Program to reverse a String using Pointers
#include <stdio.h>

int strlen(const char *str) {
    int length = 0;
    while (*(str + length) != '\0') {
        length++;
    }
    return length;
}

void revstr(char *str) {
    int i, len = strlen(str);
    for ( i = len - 1; i >= 0; i--) {
        printf("%c", *(str + i));
    }
    printf("\n");
}

int main() {
    char str[100];
    printf("Enter a String: ");
    fgets(str, sizeof(str), stdin);
    revstr(str);
    return 0;
}

