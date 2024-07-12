// Program to print all visible ASCII values and ASCII characters using a C program.
#include <stdio.h>

int main(){
	int ascii = 1;
	
	while(ascii<=255){
		printf("%c : %d\n", ascii, ascii);
		ascii++;
	}
	
	return 0;
}

