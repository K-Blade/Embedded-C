#include <stdio.h>

int main() {
	char name[20];
	int age;
	float percent;
	printf("Enter Name: ");
	scanf("%s", &name);
	printf("Enter Age: ");
	scanf("%d", &age);
	printf("Enter percentage: ");
	scanf("%f", &percent);

	printf("Name: %s \nAge: %d\nPercentage: %0.2f", name, age, percent);
	return 0;
}
