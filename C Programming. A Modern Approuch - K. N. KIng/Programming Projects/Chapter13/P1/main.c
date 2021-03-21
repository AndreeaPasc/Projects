#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD 20

int main() {

    char word[WORD], smallest_word[WORD], largest_word[WORD];
    printf("Enter a word: ");
    gets(word);

    strcpy(smallest_word, word);
    strcpy(largest_word, word);
    while(strlen(word)!=4)
    {
        printf("Enter a word: ");
        gets(word);
        if(strcmp(word, smallest_word) < 0)
            strcpy(smallest_word, word);
        if(strcmp(word, largest_word) > 0)
            strcpy(largest_word, word);
    }

    printf("Smallest word: %s", smallest_word);
    printf("\nLargest word: %s", largest_word);

    return 0;
}