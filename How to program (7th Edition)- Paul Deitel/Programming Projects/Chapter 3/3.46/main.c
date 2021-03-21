/// World-population-growth calculator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float population = 7.7, growth;
    int counter = 1;
    growth = 1.08 / 100;

    while(counter <= 5){
        population = population + population * growth;
        printf("In %d year(s) the population will be %f billion\n", counter, population);
        counter++;
    }
    return 0;
}
