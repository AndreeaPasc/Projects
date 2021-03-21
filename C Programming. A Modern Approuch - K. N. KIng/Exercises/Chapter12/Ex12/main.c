#include <stdio.h>
#include <stdlib.h>

void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main() {
    int n, largest, second_largest;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i<n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    find_two_largest(&a, n, &largest, &second_largest);

    printf("The largest is %d and the second largest is %d.", largest, second_largest);

    return 0;
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    int *p;
    *largest = *a;
    for(p=a+1; p<a+n; p++)
    {
        if(*largest<*p)
            *largest = *p;
    }

    *second_largest = *a;
    for(p=a+1; p<a+n; p++)
    {
        if(*second_largest<*p && *p != *largest)
            *second_largest = *p;
    }
}