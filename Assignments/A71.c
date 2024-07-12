#include <stdio.h>

int main(){
	const int a=10;
	const int* ptr=&a;
	//(*ptr)++;
	ptr++;
	printf("%d", *ptr);
}