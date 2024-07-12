#include <stdio.h>

int main() {
    int i = 1;
    
    while (i <= 10) {
        if (i == 7 || i == 9) {
            i++;
            continue;
        }
        
        printf("%d ", i);
        
        if (i == 10) {
            break;
        }
        
        i++;
    }
    
    printf("\n");
    
    return 0;
}
