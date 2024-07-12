#include <stdio.h>

int main(){
	unsigned int i= 0, temp=1<<31;
	unsigned int n = 9;
	for(; i < 32; i++) {
        ((n & temp) == 0) ? printf("0") : printf("1");
        temp = temp >> 1;
    }
	n=n|(1<<1);
	printf("\n");
	temp=1<<31;
	for(i=0;i<32;i++){
		((n & temp) == 0) ? printf("0") : printf("1");
        temp = temp >> 1;
	}
}
