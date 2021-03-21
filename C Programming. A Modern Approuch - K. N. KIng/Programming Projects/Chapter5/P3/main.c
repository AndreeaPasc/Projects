#include <stdio.h>
#include <stdlib.h>

int main()
{
    float pricePerShare, numberOfShares, commission, rivalBroker;

    printf("Enter the number of shares: ");
    scanf("%f", &numberOfShares);

    printf("Enter the price per share: ");
    scanf("%f", &pricePerShare);

    if (numberOfShares<2000)
    {
        commission = 33 + pricePerShare*numberOfShares;
        rivalBroker = 33 + .003f*numberOfShares;
    }
    else
    {
        if(numberOfShares>=200)
        {
            commission = 33 + pricePerShare*numberOfShares;
            rivalBroker = 33 + .002f*numberOfShares;
        }
    }

    printf("Commission of original broker: %.2f", commission);
    printf("\nCommission of the rival broker: %.2f", rivalBroker);

    return 0;
}
