#include <stdio.h>
#include <ctype.h>

#define BUF 50

int main(void)
{

    /// a)

    int i, j;
    char input, msg[BUF] = {0};
    printf("\nEnter a message: ");

    i = 0;
    while ((input = tolower(getchar())) != '\n')
        if (isalpha(input))
            msg[i++] = input;

    for (j = i-1, i = 0; i < BUF; i++)
    {
        if (msg[i] == 0) break;
        if (msg[i] != msg[j])
        {
            printf("Not a palindrome\n\n");
            return 0;
        }
        j--;
    }
    printf("Palindrome\n\n");

    /// b)

    char *pa, *pb;
    char inputB, msgB[BUF] = {0};
    printf("\nEnter a message: ");

    pa = &msgB[0];
    while ((inputB = tolower(getchar())) != '\n')
        if (isalpha(inputB))
            *pa++ = inputB;

    pb = pa-1;
    pa = &msgB[0];
    while (pa < &msgB[0] + BUF)
    {
        if (*pa == 0) break;
        if (*pa != *pb)
        {
            printf("Not a palindrome\n\n");
            return 0;
        }
        pa++, pb--;
    }
    printf("Palindrome\n\n");

}
