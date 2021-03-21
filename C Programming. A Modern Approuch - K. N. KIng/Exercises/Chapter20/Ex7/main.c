#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main() {
    unsigned int num = 0x12345678;
    int bits_to_shift = 4;

    printf("\nNumber before: %x\n", num);
    printf("Number rotated by %d bits to the: \n", bits_to_shift);
    printf("left 0x%x\n", rotate_left(num, bits_to_shift));
    printf("right 0x%x\n\n", rotate_right(num, bits_to_shift));

    return 0;
}

unsigned int rotate_left(unsigned int i, int n)
{
    return (i>>(32-n) | (i<<n));
}

unsigned int rotate_right(unsigned int i, int n)
{
    return (i << (32 - n)) | (i >> n);
}
