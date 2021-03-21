/// Sales commissions

#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int main()
{
    int array[SIZE] = {200, 250, 450, 890, 784, 2000, 8000, 700, 1000};
    size_t i;
    int frequency[SIZE] = 0;

    for(i = 0; i < SIZE; i++)
    {
        if(array[i] >= 200 && array[i] <= 299)
            frequency[0]++;
    }
    else if(array[i] >= 300 && array[i] <= 399)
    {
        frequency[1]++;
    }
    else if(array[i] >= 400 && array[i] <= 499)
    {
        frequency[2]++;
    }
    else if(array[i] >= 500 && array[i] <= 599)
    {
        frequency[3]++;
    }
    else if(array[i] >= 600 && array[i] <= 699)
    {
        frequency[4]++;
    }
    else if(array[i] >= 700 && array[i] <= 799)
    {
        frequency[5]++;
    }
    else if(array[i] >= 800 && array[i] <= 899)
    {
        frequency[6]++;
    }
    else if(array[i] >= 900 && array[i] <= 999)
    {
        frequency[7]++;
    }
    else if(array[i] >= 1000)
    {
        frequency[8]++;
    }

    return 0;
}
