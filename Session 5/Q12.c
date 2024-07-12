#include <stdio.h>

struct student{
	int roll;
	float mark;
	struct dateofbirth{
		int mm;
		int dd;
		int yy;
	}dob;
}st,*ptost;

int main(){
	struct student std;
	printf("Enter Student Roll No.: ");
	scanf("%d", &std.roll);
	printf("Enter Student Marks: ");
	scanf("%f", &std.mark);
	printf("Enter Student DOB [DD MM YY]: ");
	scanf("%d %d %d", &std.dob.dd, &std.dob.mm, &std.dob.yy);
	printf("\n");
	
	printf("Enter Student Roll No.: %d\n", std.roll);
	printf("Enter Student Marks: %.2f\n", std.mark);
	printf("Enter Student DOB [DD MM YY]: %d-%d-%d", std.dob.dd, std.dob.mm, std.dob.yy);
	return 0;
}
