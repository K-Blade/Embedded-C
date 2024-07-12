// Program to input student details from structure, save them to a file, and read from the file.
#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    float mark;
    struct dateofbirth {
        int mm;
        int dd;
        int yy;
    } dob;
} st, *ptost;

void write(struct student *st) {
    FILE *file = fopen("student.txt", "a");
    if (!file) {
        perror("Unable to open file for writing");
        exit(1);
    }
    fprintf(file, "Roll: %d\tMark: %.2f\tDate of Birth: %02d-%02d-%04d\n", 
            st->roll, st->mark, st->dob.dd, st->dob.mm, st->dob.yy);
    fclose(file);
    printf("Data written to file successfully.\n");
}

void read(struct student *st) {
    FILE *file = fopen("student.txt", "r");
    if (!file) {
        printf("No data in the file.\n");
        return;
    }

    char temp[100];
    int count = 0;
    while (fgets(temp, sizeof(temp), file)) {
        printf("%s", temp);
        count++;
    }

    if (count == 0) {
        printf("No data in the file.\n");
    }

    fclose(file);
}

void input(struct student *st) {
    printf("Enter roll number: ");
    scanf("%d", &st->roll);
    printf("Enter mark: ");
    scanf("%f", &st->mark);
    printf("Enter date of birth (dd mm yyyy): ");
    scanf("%d %d %d", &st->dob.dd, &st->dob.mm, &st->dob.yy);

    char saveOption;
    printf("Do you want to save to file? (y/n): ");
    scanf(" %c", &saveOption);

    if (saveOption == 'y' || saveOption == 'Y') {
        write(st);
    } else {
        printf("Data not saved to file.\n");
    }
}

int main() {
    int choice;
    ptost = &st;

    while (1) {
        printf("1. Enter Student details\n");
        printf("2. Read from file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input(ptost);
                break;
            case 2:
                read(ptost);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}