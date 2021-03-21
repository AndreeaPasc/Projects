/// Square of asterisks

#include <stdio.h>
#include <stdlib.h>

void square(int a);

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    square(a);
    return 0;
}

void square(int a){
    int i = a;
    int j;
    for(i = 1; i <= a; i++){
        for(j = 1; j <= a; j++){
            printf("*");
        }
        printf("\n");
    }
}
