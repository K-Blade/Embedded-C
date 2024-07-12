// Program to find the area of a triangle, square, circle, volume of a sphere 
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

float areaTriangle(float base, float height) {
    return 0.5 * base * height;
}

float areaSquare(float side) {
    return side * side;
}

float areaCircle(float radius) {
    return PI * radius * radius;
}

float volumeSphere(float radius) {
    return (4/3) * PI * pow(radius, 3);
}

int main() {
    int choice;
    float base, height, side, radius;

    do {
        printf("\n***** Menu *****\n");
        printf("1. Area of Triangle\n");
        printf("2. Area of Square\n");
        printf("3. Area of Circle\n");
        printf("4. Volume of Sphere\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter base and height of the triangle: ");
                scanf("%f %f", &base, &height);
                printf("Area of Triangle: %.2f\n", areaTriangle(base, height));
                break;
            case 2:
                printf("Enter side of the square: ");
                scanf("%f", &side);
                printf("Area of Square: %.2f\n", areaSquare(side));
                break;
            case 3:
                printf("Enter radius of the circle: ");
                scanf("%f", &radius);
                printf("Area of Circle: %.2f\n", areaCircle(radius));
                break;
            case 4:
                printf("Enter radius of the sphere: ");
                scanf("%f", &radius);
                printf("Volume of Sphere: %.2f\n", volumeSphere(radius));
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
