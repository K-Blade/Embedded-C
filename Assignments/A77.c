#include <stdio.h>

int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

int mul(int a, int b){
	return a*b;
}

int div(int a, int b){
	return a/b;
}

int main(){
	int (*arith[4])(int, int);
	int i;
	arith[0]=add;
	arith[1]=sub;
	arith[2]=mul;
	arith[3]=div;
	
	for (i=0; i<4;i++){
		printf("arith gives %d\n", arith[i](45,5));
	}
	return 0;
}
