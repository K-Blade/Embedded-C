#include <stdio.h>

struct student{
	int roll;
	float mark;
}st,*ptost;

int main(){
	struct student arr[5];
	struct student *ptr=&arr[0];
	int i;
	for(i=0;i<5;i++){
		printf("Enter Student Roll No.: ");
		scanf("%d", &arr[i].roll);
		printf("Enter Student Marks: ");
		scanf("%f", &arr[i].mark);
		printf("\n");
	}
	
	for(i=0;i<5;i++){
		printf("Student Roll No.: %d\n", (ptr+i)->roll);
		printf("Student Marks: %.2f\n", (ptr+i)->mark);
		printf("\n");
	}
	return 0;
}
