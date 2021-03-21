#include <stdio.h>
#include <math.h>

#define DISP(f,x) printf("f(%g) = %g\n", x, f(x))
#define DISP2(f,x,y) printf("f(%g, %g) = %g\n", x, y, f(x, y))

int main(void)
{
    putchar('\n');

    DISP(sqrt, 25.0);
    DISP2(fmod, 11.0, 5.0);

    putchar('\n');
    return 0;
}