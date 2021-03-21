#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *create_array(int n, int initial_value);

int main() {

    int i, *a = create_array(5, 8);
    printf("Contents of array a: ");
    for(i=0; i<5; i++)
        printf("\na[%d]: %d", i, a[i]);

    return 0;
}

int *create_array(int n, int initial_value)
{
    int *p, *array = malloc(n* sizeof(int));
    if (array == NULL)
        return NULL;
    for(p=array; p<array+n; p++)
        *p = initial_value;
    return array;
}