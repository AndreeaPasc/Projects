/// Calculating the value of pi

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float i;
    float pi = 0;

    for(i = 1; i <= 10000000; i += 4){
        pi = pi + 4 / i - 4 / (i + 2);
    }

    printf("%.1f\t%.2f\t%.3f\t%.4f\t%.5f\t", pi, pi, pi, pi, pi);
    return 0;
}
