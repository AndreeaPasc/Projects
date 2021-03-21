#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("x = ");
    scanf("%d", &x);
    ///3x^5 + 2x^4 - 5x^3 - x^2 - +7x - 6
    printf("The value of the polynomial 3*%d^5 + 2*%d^4 - 5*%d^3 - %d^2 - +7*%d - 6 is: %d", x,x,x,x,x, 3*x*x*x*x*x+2*x*x*x*x-5*x*x*x-x*x+7*x-6);
    return 0;
}
