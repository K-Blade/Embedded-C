#include <stdio.h>

#define ARRSIZE 5

int inc(int n){
	return n+1;
}

int dec(int n){
	return n-1;
}

void my_objective(int *arr, const int SIZE, int (*f)(int)){
	int i=0;
	for(i=0; i< SIZE; i++){
		arr[i] = f(arr[i]);
	}
}

int main(){
	int i=0;
	int arr[ARRSIZE]={0,1,2,3,4};
	my_objective(arr, ARRSIZE, dec);
	
	for(i=0; i< ARRSIZE; i++){
		printf("%d  ", arr[i]);
	}
	putchar('\n');
}
