#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 20

int compute_scrabble_value(const char *word);

int main()
{

    char word[MAX_WORDS];

    printf("Enter a word: ");
    gets(word);
    word[strlen(word)-1] = '\0';
    printf("Scrabble value: %d", compute_scrabble_value(word));
    return 0;
}


int compute_scrabble_value(const char *word)
{
    char copy[MAX_WORDS];
    strcpy(copy, word);
    int i = 0;
    int n=0;
    while(copy[i] != '\0')
    {
        copy[i] = toupper(copy[i]);
        switch(copy[i])
        {
            case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S':
                case 'T': case 'U': n+=1; break;
            case 'D': case 'G': n+=2; break;
            case 'B': case 'C': case 'M': case 'P': n+=3; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y': n+=4; break;
            case 'K': n+=5; break;
            case 'J': case 'X': n+=8; break;
            case 'Q': case 'Z': n+=10; break;
        }
        i++;
    }
    return n;
}
