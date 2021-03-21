#include <stdio.h>

union IEEE_float{
    float f;
    struct {
        unsigned int frac: 23;
        unsigned int exp: 8;
        unsigned int sign: 1;
    } bits;
};

int main() {
    union IEEE_float num;

    num.bits.sign = 1;
    num.bits.exp = 128;
    num.bits.frac = 0;

    printf("Float bits: %d %d %d\n", num.bits.sign, num.bits.exp, num.bits.frac);
    printf("Float value: %.1f", num.f);

    return 0;
}