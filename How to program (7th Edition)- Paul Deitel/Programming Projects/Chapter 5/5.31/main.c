/// Coin tossing

#include <stdio.h>
#include <stdlib.h>

int flip();

int main()
{
    int coin, i;

    for(i = 1; i <= 100; i++)
    {
        coin = rand() % 2;
        if(coin == 0)
            printf("Heads\t%d\n", flip());
        else
            printf("Tails\t%d\n", flip());
    }

    return 0;
}

int flip(){
    int coin;
    coin = rand() % 2;
    if(coin == 0)
        return 1;
    else
        return 0;
}
