#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char buffer[256];
    printf("Enter text to write to the file:\n");
    fgets(buffer, sizeof(buffer), stdin);
    
    buffer[strcspn(buffer, "\n")] = '\0';
    
    fprintf(file, "%s", buffer);
    fclose(file);
}

void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char buffer[256];
    printf("Enter text to append to the file:\n");
    fgets(buffer, sizeof(buffer), stdin);
    
    buffer[strcspn(buffer, "\n")] = '\0';
    
    fprintf(file, "%s", buffer);
    fclose(file);
}

int main() {
    int choice;
    char filename[]="file.txt";

    while (1) {
        printf("\nChoose an option:\n1. Read File\n2. Write File\n3. Append File\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                readFile(filename);
                break;
            case 2:
                writeFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
