#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    short s;
    long l;
    float f;
    double d;
    long double ld;

    printf("%d %d %d %d %d %d", sizeof(i), sizeof(s), sizeof(l), sizeof(f), sizeof(d), sizeof(ld));

    return 0;
}
