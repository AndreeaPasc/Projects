#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20
#define MAX_WORDS 50

char *word[MAX_WORDS];
int num_words = 0;

int read_line();

int main() {

    int smallest, i, j;
    char *temp;

    putchar('\n');
    for(i=0; ; i++)
    {
        printf("Enter a word: ");
        if(read_line() == 0)
            break;
        if(num_words == MAX_WORDS)
            break;
    }

    for(i=0; i<num_words; i++)
    {
        smallest = i;
        for(j=i+1; j<num_words; j++)
            if(strcmp(word[j], word[smallest])<0)
                smallest = j;
            temp = word[i];
            word[i] = word[smallest];
            word[smallest] = temp;
    }

    printf("In sorted order: ");
    for(i=0; i<num_words; i++)
    {
        printf("%s%s", word[i], i==num_words? "":" ");
    }
    return 0;
}

int read_line(char str[], int n)
{
    word[num_words] = malloc(MAX_LEN + 1);
    int ch, i=0;

    if(!word[num_words])
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    while((ch = getchar()) != '\n')
    {
        if(i<n)
            word[num_words][i++] = ch;
        else if(ch == ' ')
            break;
    }
    word[num_words][i] = '\0';
    num_words++;
    return i;

}