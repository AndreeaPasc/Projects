/// Print a string backward

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void stringReverse(const char array[], int size);

int main()
{
    char array[SIZE] = {"Ana are mere."};

    stringReverse(array, SIZE);
    return 0;
}

void stringReverse(const char array[], int size){
    int i;

    if(size >= 0 && array[size] >= '\0')
        printf("%c", array[size]);
    stringReverse(array, size - 1);

}
