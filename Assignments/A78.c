#include <stdio.h>

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    return length-1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

	int (*len)(char[]);
	len=stringLength;

    printf("Length of the string: %d\n", len(str));
    return 0;
}