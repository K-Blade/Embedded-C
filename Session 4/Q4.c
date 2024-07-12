#include <stdio.h>

int main(){
    int i, a[] = {1, 2, 3, 4, 5};
    int *p = &a[0]; 

    for(i = 0; i < 5; i++){
        printf("%d ", *(p + i));
    }
    printf("\n");
    for(i=0; i < 5; i++, p++){
        printf("%d ", *p);
    }
    return 0;
}

