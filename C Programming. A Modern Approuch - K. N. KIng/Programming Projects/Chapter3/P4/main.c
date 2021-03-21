#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prefix, first, second;
    printf("Enter phone number [(xxx) xxx-xxx]: ");
    scanf("(%d) %d-%d", &prefix, &first, &second);
    printf("You entered: %d.%d.%d", prefix, first, second);
    return 0;
}
