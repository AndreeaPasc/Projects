#include <stdio.h>
#include <stdlib.h>

#define N 3

void find_two_largest(int a[], int *largest, int *second_largest);

int main() {
    int a[N], largest, second_largest;
    printf("Enter %d numbers: ", N);
    for(int i = 0; i<N; i++)
    {
        printf("\na[%d] = ", i);
        scanf("%d", &a[i]);
    }

    find_two_largest(a, &largest, &second_largest);

    printf("The largest number is %d and the second largest number is %d.", largest, second_largest);

    return 0;
}

void find_two_largest(int a[], int *largest, int *second_largest)
{
    *largest = a[0];
    for(int i = 0; i<N; i++)
    {
        if(*largest<a[i])
            *largest = a[i];
    }
    *second_largest = a[0];
    for(int i = 0; i<N; i++)
    {
        if(a[i]< *largest && a[i]>*second_largest)
            *second_largest = a[i];
    }
}