// Program to concatenate one string to another
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

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", &str);
    char str2[100];
    printf("Enter another string: ");
    scanf("%s", &str2);
	
	printf("1st: %s\n", str);
    printf("2nd: %s\n", str2);

    strcat(str2, str);

    printf("Final: %s\n", str);

    return 0;
}


