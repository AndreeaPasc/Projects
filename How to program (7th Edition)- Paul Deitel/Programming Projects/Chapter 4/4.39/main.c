/// World population growth

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float population = 7.727, growth = 1.08, i;
    printf("YEAR\t\tWORLD POPULATION\tNUMERICAL INCREASE\n");
    for(i = 1; i <= 75; i++){
        printf("%.0f\t\t%f\t\t%f\n", i, population * growth, population * growth - population);
    }

    return 0;
}
