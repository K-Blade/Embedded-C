// Program to copy one string to another.
#include <stdio.h>

void strcpy(char *str2, char *str) {
    while (*str != '\0') {
        *str2 = *str;
        str2++;
        str++;
    }
    *str2 = '\0';
}

int main() {
    char str[] = "Hello, ";
    char str2[50];
    
    strcpy(str2, str);

    printf("%s\n", str2);

    return 0;
}
