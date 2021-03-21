#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 5, j, k;
    ///j = ++i;
    ///k = i++;
    i += 1;
    printf("%d %d %d", j, k, i);
    return 0;
}
