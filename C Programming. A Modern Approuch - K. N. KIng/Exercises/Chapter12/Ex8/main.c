#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void store_zeros(int a[], int n);

int main() {
    int n, *p;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];

    store_zeros(a, n);

    for(p=a; p<a+n; p++)
        printf("%d ", *p);

    return 0;
}

void store_zeros(int a[], int n)
{
    int *p;
    for(p=a; p<a+n; p++)
        *p=0;
}