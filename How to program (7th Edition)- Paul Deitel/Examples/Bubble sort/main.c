/// Bubble sort

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    int a[SIZE] = {2, 6, 4, 8, 1, 12, 89, 68, 45, 37};
    int pass;
    size_t i;
    int hold;

    puts("Data items in original order");

    for(i = 0; i < SIZE; i++){
        printf("%4d", a[i]);
    }

    /// bubble sort
    for(pass = 1; pass < SIZE; ++pass){
        for(i = 0; i < SIZE; i++){
            if(a[i] > a[i+1]){
                hold = a[i];
                a[i] = a[i+1];
                a[i+1] = hold;
            }
        }
    }

    puts("\nData items in ascending order");
    for(i = 0; i < SIZE; ++i){
        printf("%4d", a[i]);
    }

    puts("");

    return 0;
}
