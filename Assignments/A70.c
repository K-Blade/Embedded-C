#include <stdio.h>
#include <ctype.h>

void countElements(FILE *file) {
    int chars = 0, word = 0, num = 0, space = 0, newline = 0, tab = 0;
    char ch, prevCh = ' ';
    
    while ((ch = fgetc(file)) != EOF) {
        chars++;

        if (isspace(ch)) {
            space++;
        }

        if (ch == '\n') {
            newline++;
        }

        if (ch == '\t') {
            tab++;
        }

        if (isspace(prevCh) && isalnum(ch)) {
            word++;
        }

        if (isdigit(ch)) {
            num++;
        }

        prevCh = ch;
    }

    if (!isspace(prevCh)) {
        Count++;
    }

    printf("Character count: %d\n", chars);
    printf("Word count: %d\n", word);
    printf("Number count: %d\n", num);
    printf("Space count: %d\n", space);
    printf("Newline count: %d\n", newline);
    printf("Tab count: %d\n", tab);
}

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    countElements(file);
    
    fclose(file);
    return 0;
}
