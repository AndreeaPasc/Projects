#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number=0;
    char sentence;
    printf("Enter a sentence: ");
    sentence = getchar();

    while(sentence!='\n')
    {
        switch (sentence)
        {
            case 'A': case 'a': case 'E': case 'e': case 'I': case 'i': case 'O': case 'o': case 'U': case 'u': number+=1; break;
        }
        sentence = getchar();
    }

    printf("Yout sentence contains %d vowels.", number);
    return 0;
}
