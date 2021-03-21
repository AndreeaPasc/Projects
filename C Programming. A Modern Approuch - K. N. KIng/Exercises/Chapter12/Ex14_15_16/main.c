#include <stdio.h>
#include <stdbool.h>

bool search(const int a[], int n, int key);
int find_largest(int a[], int n);

int main(void)
{
    int temperatures[7][24] = {{ 12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       13, 52, 1, 3 },
                               { 12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       13, 52, 1, 3 },
                               { 12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       13, 52, 1, 3 },
                               { 12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       12, 34, 21, 31, 32, 36, 78, 43, 21, 56,
                                       13, 52, 1, 3 },
                               { 12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       13, 52, 1, 3 },
                               { 12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       13, 52, 1, 3 },
                               { 12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       12, 34, 21, 31, 25, 36, 78, 43, 21, 56,
                                       13, 52, 1, 3 }};

    if (search(&temperatures[0][0], 7*24, 32))
        printf("\nArray contains 32.\n\n");
    else
        printf("\nArray doesn't have 32.\n\n");

    int row = 1;
    int *p;
    for (p = &temperatures[row][0]; p < &temperatures[row][24]; p++)
        printf("%d ", *p);


    int i;
    for(i=0; i<7;i++)
    {
        printf("\nLargest temperature of week %d is %d.", i+1, find_largest(&temperatures[i][0], 24));
    }
    return 0;
}

bool search(const int a[], int n, int key)
{
    int *p;

    for (p = a; p < a + n; p++)
        if (*p == key)
            return true;

    return false;
}

int find_largest(int a[], int n)
{
    int *p, max;

    max = *a;
    for (p = a + 1; p < a + n; p++)
        if (*p > max)
            max = *p;
    return max;
}