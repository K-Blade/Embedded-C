#include <stdio.h>
#include <stdlib.h>

int countCharacters(FILE *fp) {
    int count = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        count++;
    }
    return count;
}

int isWhitespace(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t';
}

int countWords(FILE *fp) {
    int count = 0;
    char ch;
    int inWord = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (isWhitespace(ch)) {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

void displayFile(FILE *fp) {
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
}

int main() {
    FILE *fp;
    int choice;

    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
    }

    do {
        printf("\nMenu:\n");
        printf("1. Display file\n");
        printf("2. Count the number of characters\n");
        printf("3. Count the number of words\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        fp = fopen("file.txt", "r");
    	if (fp == NULL) {
        	printf("Error opening file");
    	}

        switch (choice) {
            case 1:
                displayFile(fp);
                break;
            case 2:
                printf("Number of characters: %d\n", countCharacters(fp));
                break;
            case 3:
                printf("Number of words: %d\n", countWords(fp));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    fclose(fp);
    return 0;
}

