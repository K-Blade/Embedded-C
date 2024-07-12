#include <stdio.h>

int main(){
	const int a=10;
	const int b=50;
	const int* ptr=&a;
	printf("Address Before Changing: %d\n", ptr);
	*ptr++;
	printf("Address After Changing: %d", ptr);
}