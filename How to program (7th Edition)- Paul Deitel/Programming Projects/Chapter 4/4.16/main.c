/// Triangle printing program

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k = 0;

    /// a)
    for(i = 1; i <= 10; i++){
        for(j = 1; j <= i; j++)
            printf("%s", "*");
        printf("\n");
    }

    printf("\n\n");

    /// b)
    for(i = 10; i >= 1; i--){
        for(j = i; j >=1; j--)
            printf("%s", "*");
        printf("\n");
    }

    printf("\n\n");

    /// c)
    for(i = 10; i >= 1; i--){
         k = 0;
            while(k != 10 - i){
                printf(" ");
                k++;
            }
        for(j = i; j >= 1; j--){
            printf("%s", "*");
        }
        printf("\n");
    }

    printf("\n\n");

    /// d)
    for(i = 1; i <= 10; i++){
         k = 0;
            while(k != 10 - i){
                printf(" ");
                k++;
            }
        for(j = 1; j <= i; j++){
            printf("%s", "*");
        }
        printf("\n");
    }

    return 0;
}
