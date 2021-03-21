/// Print an array

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void recursivePrint(const int a[], int size);

int main()
{
    int array[SIZE];
    size_t i;

    for(i = 0; i < SIZE; i++){
        array[i] = 2 * i;
    }

    recursivePrint(array, SIZE);
    return 0;
}

void recursivePrint(const int array[], int size){
    if(size >= 0)
        printf("%d ", array[size]);
    else return;
    recursivePrint(array, size - 1);
}
