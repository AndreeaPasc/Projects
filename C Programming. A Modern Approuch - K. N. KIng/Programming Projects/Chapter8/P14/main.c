#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i=0,j=0, length=0, k=0;
    char sentence, sentenceArray[1024], mark, reverse[1024];

    printf("Enter a sentence: ");
    scanf("%c", &sentence);

    while((sentence!='.') && (sentence!='!') && (sentence!='?'))
    {
        sentenceArray[i]=sentence;
        i++;
        j++;
        sentence=getchar();
    }

    mark=sentence;

    printf("Reversal of the sentence is: ");
    for(i=j-1; i>=0; i--)
    {
        if(sentenceArray[i]!=' ' && sentenceArray[i]!='\n')
        {
            reverse[k]=sentenceArray[i];
            k++;
            length++;
        }
        else
        {
            for(k=length-1; k>=0; k--)
                {
                    printf("%c", reverse[k]);
                }
            printf(" ");
            k=0;
            length=0;
        }
    }

    i=0;
    while(sentenceArray[i]!=' ')
    {
        printf("%c", sentenceArray[i]);
        i++;
    }

    printf("%c", mark);

    return 0;
}
