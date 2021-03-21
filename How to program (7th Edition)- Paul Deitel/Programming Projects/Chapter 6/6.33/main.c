/// Recursive Binary Search

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

size_t recursiveBinarySearch(const int b[], int searchKey, size_t low, size_t high);

int main()
{
    int a[SIZE];
    size_t i;
    int key;
    size_t result;

    for(i = 0; i < SIZE; i++)
    {
        a[i] = 2 * i;
    }

    printf("Enter a number between 0 and 18: ");
    scanf("%d", &key);

    result = recursiveBinarySearch(a, key, 0, SIZE - 1);

    if(result != -1)
    {
        printf("\n%d found in array element %d\n", key, result);
    }
    else
        printf("\n%d not found\n", key);
    return 0;
}

size_t recursiveBinarySearch(const int b[], int searchKey, size_t low, size_t high)
{
    int middle;
    while(low <= high)
    {
        middle = (low + high) / 2;
        if(searchKey == b[middle])
            return middle;
        else if(searchKey < b[middle])
            return recursiveBinarySearch(b, searchKey, low + 1, high - 1);
    }
    return -1;
}
