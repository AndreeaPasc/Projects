/// Printing numbers from a loop

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 1;
    while(number <= 10){
        printf("%d   ", number++);
    }
    return 0;
}
