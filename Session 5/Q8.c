#include <stdio.h>

struct date{
	int mm:4;
	int dd:5;
	int yy:12;
}dat;

int main(){
	dat.mm=12;
	dat.dd=33;
	printf("date = %d\n",dat.dd);
	printf("size of struct %d\n",sizeof(dat));
}
