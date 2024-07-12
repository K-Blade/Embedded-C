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

int countbit(int n,int val){
	unsigned int i, count =0, bit, temp=1<<31, flag=0;
	for(i= 0; i < 32; i++) {
        bit = ((n & temp) == 0) ? 0: 1;
        temp = temp >> 1;
        if (bit==1){
        	flag=1;
		}
        if(val==bit){
        	if(flag==0){
        		continue;
			}
			count++;
		}
    }
    return count;
}

int main(){
	unsigned int n, ch, pos;
	printf("Enter Number: ");
	scanf("%d", &n);
	printbit(n);
	while(1){
		printf("\nChoose an Option:\n1. SetBit\n2. ResetBit\n3. Toggle\n4. ReadBit\n5. CountBit\n6. Exit\n");
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
			printbit(readbit(n, pos));
		}else if(ch==5){
			printf("Enter Bit: ");
			scanf("%d", &pos);
			printf("%d", countbit(n, pos));
		}else if(ch==6){
			break;
		}else{
			printf("Invalid Value");
		}
	}
	return 0;
}
