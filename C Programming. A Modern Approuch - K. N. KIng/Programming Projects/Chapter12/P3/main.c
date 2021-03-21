#include <stdio.h>
#include <ctype.h>

#define N 100

int main() {
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