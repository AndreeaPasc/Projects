#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int minRecursive(int array[], int size);

int main()
{
    int array[SIZE] = {10 , 25, 4, 5, 15, 25, 30, 8, 14, 47};

    printf("The minimum of the array is: %d", minRecursive(array, SIZE));
    return 0;
}

int minRecursive(int array[], int size){
    int i;
    int min;
    min = array[0];
    for(i = 0; i < size; i++){
        if(array[i] < min)
            min = array[i];
        else
            minRecursive(array, size - 1);
    }
    return min;
}
