#include <stdio.h>

struct stt {
    int a;
    char b;
};

size_t size_of_struct() {
    struct stt arr[2];
    return (char*)&arr[1] - (char*)&arr[0];
}

int main() {
    size_t struct_size = size_of_struct();
    printf("Size of struct Example: %d bytes\n", struct_size);

    return 0;
}

