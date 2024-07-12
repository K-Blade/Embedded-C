// Program to find the consonants and vowels in a sentence.
#include <stdio.h>

int main() {
    char s[100];
    int vow= 0, con= 0;
    char *ptr;

    printf("Enter a string: ");
    scanf("%s", &s);

    ptr = s;

    while (*ptr != '\0') {
        if ((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z')) {
            char ch = (*ptr >= 'A' && *ptr <= 'Z') ? *ptr + ('a' - 'A') : *ptr;
            
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vow++;
            } else {
                con++;
            }
        }
        ptr++;
    }

    printf("Vowels: %d\n", vow);
    printf("Consonants: %d\n", con);

    return 0;
}
