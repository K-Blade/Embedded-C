// Program to use preprocessor constants in GCC
#include <stdio.h>

#define PI 3.14159
int main() {
    float rad, area;
	printf("Enter the radius: ");
    scanf("%f", &rad);
    area = PI * rad * rad;

    printf("Area: %0.2f\n", area);

    return 0;
}

