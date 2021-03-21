#include <stdio.h>
#include <stdlib.h>

#define N 3

int find_largest(int a[N]);

int main() {
    int a[N];
    for(int i = 0; i<N; i++)
        scanf("%d", &a[i]);

    printf("%d", find_largest(a));
    return 0;
}

int find_largest(int a[N])
{
    int *p, max = a[0];
    for(p=a+1; p<a+N; p++)
    {
        if(max<*p)
            max = *p;
    }

    return max;
}