#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%-8.1f\n", 52.3333);
    printf("%10.6e\n", 52.3333);
    printf("%-8.3f\n", 52.3333);
    printf("%6.0f", 52.3333);
    return 0;
}
