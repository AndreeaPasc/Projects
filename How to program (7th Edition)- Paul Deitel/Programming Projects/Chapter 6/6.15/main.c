/// Duplicate elimination

#include <stdio.h>
#include <stdbool.h> //used this library for the ability to use true and false
#define SIZE 20

bool searchArray(int integer, unsigned int j); //prototype for the searchArray function

int main (void)
{

    bool print;
    int numbers[20];
    unsigned int i;

    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &numbers[i]);
        print = searchArray(numbers[i], i); //receives true or false

        if (print == true)
        {
            printf("\nNumber at element %d: %d\n", i, numbers[i]);
        }
        else if (print == false)
        {
            printf("\nThis element has a copy in the array already\n");
        }
    }
}

bool searchArray(int integer, unsigned int j) //function that helps decide whether or not to print out the integer
{
    static int numberscopy[20];
    unsigned int n;


    numberscopy[j] = integer;

    for (n = 0; n < SIZE; n++)
    {

        if (numberscopy[n] == numberscopy[j] && n != j)
        {
            return false;
        }

    }
    return true;
}

