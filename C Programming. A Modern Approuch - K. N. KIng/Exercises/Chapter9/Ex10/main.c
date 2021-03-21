#include <stdio.h>

/// a)

int largest_element(int array[], int n)
{
    int i;
    int largest = array[0];
    for(i=1;i<n;i++)
    {
        if(largest<array[i])
            largest = array[i];
    }

    return printf("The largest element is: %d", largest);
}

/// b)

double average(int array[], int n)
{
    int i;
    double sum = 0;
    for(i=0;i<n;i++)
    {
        sum+=array[i];
    }

    return printf("\nThe average is: %lf", (sum/n));
}

/// c)

int positive(int array[], int n)
{
    int i, number=0;
    for(i=0;i<n;i++)
    {
        if(array[i]>0)
            number++;
    }

    return printf("\nThere are %d positive integers.", number);
}

int main() {

    int n, i;
    printf("n = ");
    scanf("%d", &n);

    int array[n];
    for(i=0; i<n;i++)
    {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    largest_element(array, n);
    average(array, n);
    positive(array, n);

    return 0;
}