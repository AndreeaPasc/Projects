/// Rounding numbers

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float original, rounded;
    printf("Enter a number (-1 to end): ");
    scanf("%f", &original);
    while(original != -1){
        printf("The original number is: %f and the rounded one is %f", original, floor(original + 0.5));
        printf("\n\nEnter a number (-1 to end): ");
        scanf("%f", &original);
    }
    return 0;
}
