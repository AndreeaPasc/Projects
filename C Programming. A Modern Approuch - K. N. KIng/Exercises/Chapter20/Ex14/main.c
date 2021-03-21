#include <stdio.h>

struct float_bf {
    unsigned int sign: 1;
    unsigned int exp: 8;
    unsigned int frac: 23;
};

int main() {
    printf("Hello, World!\n");
    return 0;
}