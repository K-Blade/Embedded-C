#include <stdio.h>

int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        str++;
        length++;
    }
    return length;
}

void stringReverse(char *str) {
    int i, len = stringLength(str);
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int stringCompare(char *str1, char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

void stringLower(char *str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *str = *str + ('a' - 'A');
        }
        str++;
    }
}

void stringUpper(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - ('a' - 'A');
        }
        str++;
    }
}

void stringToggle(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - ('a' - 'A');
        } else if (*str >= 'A' && *str <= 'Z') {
            *str = *str + ('a' - 'A');
        }
        str++;
    }
}

void stringCopy(char *dest, char *src) {
    while ((*dest++ = *src++) != '\0');
}

void stringConcat(char *dest, char *src) {
    while (*dest) {
        dest++;
    }
    while ((*dest++ = *src++) != '\0');
}

void trimNewline(char *str) {
    int len = stringLength(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char str1[100], str2[100];
    int choice;

    while (1) {
        printf("\n\n1. String Copy\n2. String Reverse\n3. String Compare\n4. String Length\n5. String Upper\n6. String Lower\n7. String Concatenate\n8. String Toggle\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter the source string: ");
                fgets(str1, sizeof(str1), stdin);
                trimNewline(str1);
                stringCopy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;
            case 2:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                trimNewline(str1);
                stringReverse(str1);
                printf("Reversed string: %s\n", str1);
                break;
            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                trimNewline(str1);
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                trimNewline(str2);
                int cmpResult = stringCompare(str1, str2);
                if (cmpResult == 0) {
                    printf("Strings are equal\n");
                } else if (cmpResult < 0) {
                    printf("First string is less than second string\n");
                } else {
                    printf("First string is greater than second string\n");
                }
                break;
            case 4:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                trimNewline(str1);
                printf("Length of string: %d\n", stringLength(str1));
                break;
            case 5:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                trimNewline(str1);
                stringUpper(str1);
                printf("Uppercase string: %s\n", str1);
                break;
            case 6:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                trimNewline(str1);
                stringLower(str1);
                printf("Lowercase string: %s\n", str1);
                break;
            case 7:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                trimNewline(str1);
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                trimNewline(str2);
                stringConcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 8:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                trimNewline(str1);
                stringToggle(str1);
                printf("Toggled case string: %s\n", str1);
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
