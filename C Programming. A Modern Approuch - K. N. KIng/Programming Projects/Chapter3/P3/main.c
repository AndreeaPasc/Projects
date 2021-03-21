#include <stdio.h>
#include <stdlib.h>

int main()
{
    int GSI, groupID, publisherCode, itemNumber, checkDigit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &GSI, &groupID, &publisherCode, &itemNumber, &checkDigit);
    printf("GSI prefix: %d", GSI);
    printf("\nGroup identifier: %d", groupID);
    printf("\nPublisher code: %d", publisherCode);
    printf("\nItem number: %d", itemNumber);
    printf("\nCheck digit: %d", checkDigit);
    return 0;
}
