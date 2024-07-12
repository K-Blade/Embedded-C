#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))


int main() {

    printf("Radius: %.2f\n", 5.0);
    printf("Area: %.2f\n", PI * SQUARE(5.0));

    #ifdef RUN
        printf("Program Running\n");
    #else
        printf("Program NOT Running?!\n");
    #endif

    #undef PI
    #define PI 3.14

    float circumference = 2 * PI * radius;
    printf("Circumference with new PI: %.2f\n", circumference);

    return 0;
}
