#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

double compute_average_word_length(const char *sentence);

int main() {
    char sentence[LEN];
    printf("Enter a sentence: ");
    fgets(sentence, LEN, stdin);

    printf("The average length: %.2f", compute_average_word_length(sentence));
    return 0;
}

double compute_average_word_length(const char *sentence)
{
    char last = 0;
    int characters = 0, words = 0;

    for(; *sentence!='\n'; sentence++)
    {
        if(*sentence != ' ')
        {
            characters++;
            if(words == 0)
                words++;
        }
        else if(last != ' ')
            words++;
        last = *sentence;
    }

    return (double) characters/words;
}