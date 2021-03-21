#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    char word;
    int n=0;
    printf("Enter a word: ");
    word = getchar();

    while(word != '\n')
    {
        word = toupper(word);
        switch(word)
        {
            case 'A': case 'E': case 'I':  case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U': n+=1; break;
            case 'D': case 'G': n+=2; break;
            case 'B': case 'C': case 'M': case 'P': n+=3; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y': n+=4; break;
            case 'K': n+=5; break;
            case 'J': case 'X': n+=8; break;
            case 'Q': case 'Z': n+=10; break;
        }
        word = getchar();
    }

    printf("Scrabble value: %d", n);
    return 0;
}
