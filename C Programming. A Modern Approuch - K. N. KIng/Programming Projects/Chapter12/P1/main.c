#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {

    /// a)

    char sentence[N], input;
    int i;

    printf("Enter a message: ");
    for(i=0; i< N; i++)
    {
        if((input = getchar())== '\n')
            break;
        sentence[i] = input;
    }

    printf("Reversal is: ");
    for(i=i-1; i>=0; i--)
        printf("%c", sentence[i]);

    /// b)

    char *p;
    char inputB, sentenceB[N];
    printf("\nEnter a message: ");
    for(p=sentenceB; p<sentenceB+N; p++)
    {
        if((inputB = getchar()) == '\n')
            break;
        *p = inputB;
    }
    printf("Reversal is: ");
    for(p=p-1; p>=sentenceB; p--)
        printf("%c", *p);

    return 0;
}