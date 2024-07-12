#include <stdio.h>
#include <stdlib.h>

void displayFile(FILE *fp) {
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
}

int main() {
    FILE *fp1, *fp2;
	char ch;
    fp1 = fopen("file.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening file1");
    }
	fp2 = fopen("file2.txt", "w");
    if (fp2 == NULL) {
        printf("Error opening file2");
    }
    while((ch = fgetc(fp1)) != EOF){
    	fputc(ch,fp2);
	}

    fclose(fp1);
    fclose(fp2);
    return 0;
}
