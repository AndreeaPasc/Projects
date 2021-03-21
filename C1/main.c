#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/// exercises chapter 1
/// probleme propuse

int main()
{
    /// 18
    int a;
    float area, height;
    scanf("%d", &a);
    height = a * sqrt(3) / 2;
    area = a * height / 2;
    printf("a = %d, height = %f, area = %f",a, height, area);

    /// 19

    return 0;
}
