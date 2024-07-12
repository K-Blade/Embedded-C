#include <stdio.h>

int main(){
	int i = 5;
	char a='s';
	short int j= 20;
    int *p1 = &i; 
	char *p2 = &a;
	short int *p3 = &j;


    printf("%x   %x\n", p2, p2++);
    printf("%x   %x\n", p3, p3++);
    printf("%x   %x", p1, p1++);
    return 0;
}
