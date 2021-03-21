#include <stdio.h>

/// a)
struct complex{
    double real, imaginary;
};

struct complex make_complex(double mem1, double mem2);
struct complex add_complex(struct complex com1, struct complex com2);

int main() {

    /// b)
    struct complex c1, c2, c3;

    return 0;
}

/// c)
struct complex make_complex(double mem1, double mem2)
{
    return (struct complex) {mem1, mem2};
}

/// d)
struct complex add_complex(struct complex com1, struct complex com2)
{
    struct complex sum;
    sum.real = com1.real + com2.real;
    sum.imaginary = com1.imaginary + com2.imaginary;
    return sum;
}