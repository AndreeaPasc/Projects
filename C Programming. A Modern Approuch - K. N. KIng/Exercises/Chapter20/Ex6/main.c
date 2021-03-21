#include <stdio.h>

unsigned short swap_bytes(unsigned short i)
{
    unsigned short right_byte_swap = (i<<8);
    unsigned short left_byte_swap = (i>>8);
    return right_byte_swap | left_byte_swap;

    /// return (i<<8) | (i>>8)
}
int main() {
    unsigned short num;

    printf("Enter a hexadecimal number (up to 4 digits): ");
    scanf(" %4hx", &num);
    printf("Number with bytes swapped: %.4x", swap_bytes(num));
    return 0;
}