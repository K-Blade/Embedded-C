#include <stdio.h>

void printbit(int n){
	unsigned int i= 0, temp=1<<31;
	for(; i < 32; i++) {
        ((n & temp) == 0) ? printf("0") : printf("1");
        temp = temp >> 1;
    }
    printf("\n");
}

int setbit(int val, int pos){
	val=val|(1<<pos);
	return val;
}

int resetbit(int val, int pos){
	val=val&(~(1<<pos));
	return val;
}

int readbit(int val, int pos){
	int temp=(val&(1<<pos))?1:0;
	return temp;
}

int togglebit(int val, int pos){
	val=val^(1<<pos);
	return val;
}

int main(){
	int (*bits[4])(int, int);
	int i,temp;
	bits[0]=setbit;
	bits[1]=resetbit;
	bits[2]=readbit;
	bits[3]=togglebit;
	
	for (i=0; i<4;i++){
		temp=bits[i](9,1);
		printf("bits gives:");
		if (i==2){
			printf("%d\n", temp);
			continue;
		}
		printbit(temp);
	}
	return 0;
}
