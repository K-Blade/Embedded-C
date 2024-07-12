// Program to set, reset, toggle, read a bit of a byte at a particular position.
#include <stdio.h>

void printbit(int n){
	unsigned int i= 0, temp=1<<31;
	for(; i < 32; i++) {
        ((n & temp) == 0) ? printf("0") : printf("1");
        temp = temp >> 1;
    }
}

int setbit(int val, int pos){
	val=val|(1<<pos);
	return val;
}

int resetbit(int val, int pos){
	val=val&(~(1<<pos));
	return val;
}

int togglebit(int val, int pos){
	val=val^(1<<pos);
	return val;
}

int readbit(int val, int pos){
	int temp=(val&(1<<pos))?1:0;
	printf("%d\n",temp);
	return temp;
}

int main(){
	unsigned int n, ch, pos;
	printf("Enter Number: ");
	scanf("%d", &n);
	printbit(n);
	while(1){
		printf("\nChoose an Option:\n1. SetBit\n2. ResetBit\n3. Toggle\n4. ReadBit\n5. Exit\n");
		scanf("%d", &ch);
		if(ch==1){
			printf("Enter Position: ");
			scanf("%d", &pos);
			printbit(setbit(n, pos));
		}else if(ch==2){
			printf("Enter Position: ");
			scanf("%d", &pos);
			printbit(resetbit(n, pos));
		}else if(ch==3){
			printf("Enter Position: ");
			scanf("%d", &pos);
			n= togglebit(n, pos);
			printbit(n);
		}else if(ch==4){
			printf("Enter Position: ");
			scanf("%d", &pos);
			readbit(n, pos);
		}else if(ch==5){
			break;
		}else{
			printf("Invalid Value");
		}
	}
	return 0;
}

