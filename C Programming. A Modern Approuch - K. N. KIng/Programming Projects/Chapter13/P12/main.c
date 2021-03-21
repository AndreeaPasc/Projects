#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define ROW 30
#define COL 20

int main() {
    int i=0, j=0;
    char sentence, mark, sentenceArray[ROW][COL+1]={{0}};
    printf("Enter a sentence: ");
    scanf("%c", &sentence);

    bool space = 0;

    while((sentence!='.') && (sentence!='!') && (sentence!='?'))
    {
        if(space == 0)
        {
            sentenceArray[i][j]=sentence;
            j++;
        }
        space = 0;
        sentence=getchar();
        if(sentence == ' ')
        {
            sentenceArray[i][j] = '\0';
            j=0;
            i++;
            space = 1;
        }
    }

    mark = sentence;
    printf("The reversal of the sentence is: ");
    for(i; i>=0; i--)
    {
        j=0;
        while(sentenceArray[i][j]!='\0')
        {
            printf("%c", sentenceArray[i][j]);
            j++;
        }
        if(i!=0)
            printf(" ");
    }

    printf("%c", mark);

    return 0;
}