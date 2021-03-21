#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

void encrypt(char *message, int shift);

int main() {
    int i, shift;
    char input, sentence[LEN+1]={0};

    printf("Enter message to be encrypted: ");
    for(i=0; (input = getchar()) != '\n'; i++)
    {
        if(i<LEN)
            sentence[i] = input;
    }
    sentence[LEN] = '\0'; ///sentence[i+1]

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);


    encrypt(sentence, shift);

    printf("Encrypted message: ");
    for(i=0; i<LEN; i++)
    {
        putchar(sentence[i]);
    }
    return 0;
}

void encrypt(char *message, int shift)
{
    for (; *message; message++)
    {
        if (*message >= 'A' && *message <= 'Z')
        {
            *message = ((*message - 'A') + shift) % 26 + 'A';
        }
        if (*message >= 'a' && *message <= 'z')
        {
            *message = ((*message - 'a') + shift) % 26 + 'a';
        }
    }
}