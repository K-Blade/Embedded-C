#include <stdio.h>

int main() {
    int i;
    
    for (i = 0; i <= 255; ++i) {
        printf("ASCII value: %d, Character: %c\n", i, (char)i);
    }
    
    return 0;
}
