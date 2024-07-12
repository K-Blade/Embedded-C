#include <stdio.h>

int add(int a, int b){
	return a+b;
}

int main(){
	int (*fadd)(int, int);
	fadd=add;
	printf("%d", fadd(1,2));
}
