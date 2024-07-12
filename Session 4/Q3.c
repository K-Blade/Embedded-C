#include <stdio.h>

int main(){
	int a=10, b=15;
	int* const ptr=&a;
	//ptr++;
	(*ptr)++;
	printf("%d", *ptr);
}
