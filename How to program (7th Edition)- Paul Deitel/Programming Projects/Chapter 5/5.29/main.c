/// Greatest common divisor

#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b);

int main()
{
    int a, b;
    printf("Enter 2 integers: ");
    scanf("%d %d", &a, &b);

    printf("Their greatest common divisor is: %d", GCD(a, b));
    return 0;
}

int GCD(int a, int b){
    int i, max;
    for(i = 1; i <= a, i <= b; i++){
        if(a % i == 0 && b % i == 0)
            max = i;
    }
    return max;
}
