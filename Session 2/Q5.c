#include <stdio.h>

void strcat(char *str2, char *str){
	while (*str != '\0') {
        str++;
    }
    while (*str2 != '\0') {
        *str = *str2;
        str2++;
        str++;
    }
    *str = '\0';
}

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
    char str2[]="Robert!";
	
	printf("1st: %s\n", str);
    printf("2nd: %s\n", str2);

    strcat(str2, str);

    printf("Final: %s\n", str);

    return 0;
}

