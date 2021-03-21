/// Dice rolling

#include <stdio.h>
#include <stdlib.h>

#define SIZE 13

int main()
{
    int die1[36000], die2[36000];
    int frequency[SIZE] = {0};
    int sum = 0;
    size_t i, j;

    for(i = 0; i < 36000; i++){
        die1[i] = rand() % 6 + 1;
    }

    for(i = 0; i < 36000; i++){
        die2[i] = rand() % 6 + 1;
    }

    for(i = 0; i < 36000; i++){
        for(j = 0; j < 36000; j++){
            sum = die1[i] + die2[j];
            frequency[sum]++;
        }
    }

    for(i = 2; i < 13; i++){
        printf("%d\n", frequency[i]);
    }
    return 0;
}
