/// Linear search recursive

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

size_t recursiveLinearSearch(const int array[], int key, size_t size);

int main()
{
    int a[10];
    size_t x;
    int searchKey;
    size_t element;

    for(x = 0; x < SIZE; x++)
    {
        a[x] = x * 2;
    }

    puts("Enter integer search key: ");
    scanf("%d", &searchKey);

    element = recursiveLinearSearch(a, searchKey, SIZE);

    if(element != -1)
    {
        printf("Found value in element %d\n", element);
    }
    else
        puts("Value not found");

    return 0;
}

size_t recursiveLinearSearch(const int array[], int key, size_t size)
{
    if(size == 0)
        return -1;
    if(array[size - 1] == key)
        return size - 1;
    return recursiveLinearSearch(array, key, size - 1);
}
