#include <stdio.h>

void swap(int a, int b){
	a=a+b;
	b=a-b;
	a=a-b;
	printf("Values Inside Swap:\na: %d\tb: %d\n", a,b);
}

void swapRef(int *a, int *b){
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
	printf("Values Inside SwapRef:\na: %d\tb: %d\n", a,b);
}

int main(){
	int a=1, b=2;
	printf("Values Before Swap:\na: %d\tb: %d\n", a,b);
	swap( a, b);
	printf("Values Inside Main:\na: %d\tb: %d\n", a,b);
	swapRef( &a, &b);
	printf("Values Inside Main:\na: %d\tb: %d\n", a,b);
}
