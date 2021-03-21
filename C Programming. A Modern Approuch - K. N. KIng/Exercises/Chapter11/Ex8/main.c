#include <stdio.h>
#include <stdlib.h>

#define N 3

int *find_largest(int a[], int n);

int main() {
    int a[N], i, *p;
    printf("Enter %d numbers.\n", N);
    for(i=0; i<N; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    p = find_largest(a, N);

    printf("The largest number is %d", p);
    return 0;
}

int *find_largest(int a[], int n)
{
    int i;
    int max = a[0];
    for(i=0; i<n; i++)
    {
        if(max<a[i])
            max = a[i];
    }

    return max;
}