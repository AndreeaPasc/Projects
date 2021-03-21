#include <stdio.h>

int main() {
    /// a)
    struct {
        double real;
        double imaginary;
    }c1, c2, c3;

    /// b)
    c1.real = 0.0; /// c1 = {0.0, 1.0}
    c1.imaginary = 1.0;

    c2.real = 1.0; /// c2 = {1.0,0.0}
    c2.imaginary = 0.0;

    /// c)
    c1 = c2;

    /// d)
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    return 0;
}