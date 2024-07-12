#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int value;
} Node;

int main() {
    Node n1, n2, n3;
    char name[] = "This is name";
    
    n1.name=name;
    n1.value = 1336;

    n2 = n1;

    n3.value = n1.value;
    n3.name = strdup(n1.name);
	

    printf("\nn1:\n");
    printf("Name: %s\n", n1.name);
    printf("Value: %d\n", n1.value);
    printf("Address of n1.name: 0x%x\n", *(&n1.name));

    printf("\nn2 :\n");
    printf("Name: %s\n", n2.name);
    printf("Value: %d\n", n2.value);
    printf("Address of n2.name: 0x%x\n", *(&n2.name));

    printf("\nn3 :\n");
    printf("Name: %s\n", n3.name);
    printf("Value: %d\n", n3.value);
    printf("Address of n3.name: 0x%x\n", *(&n3.name));

    free(n3.name);

    return 0;
}

