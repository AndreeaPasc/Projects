#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define LEN 50
#define true 1
#define false 0

bool are_anagrams(const char *word1, const char *word2);

int main() {
    char word1[LEN+1], word2[LEN+1], input1, input2;
    int i=0;

    printf("Enter the first word: ");
    for(i=0; (input1 = getchar()) != '\n'; i++)
    {
        if(i<LEN)
            word1[i] = input1;
    }
    word1[i+1] = '\0';

    printf("Enter the second word: ");
    for(i=0; (input2 = getchar()) != '\n'; i++)
    {
        if(i<LEN)
            word2[i] = input2;
    }
    word2[i+1] = '\0';

    if(are_anagrams(word1, word2))
        printf("The words are anagrams.");
    else
        printf("The words are not anagrams.");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int i, letters_seen[26]={0};

    for(; *word1 != '\0'; word1++)
        if(isalpha(*word1))
            letters_seen[*word1 - 'a']++;

    for (; *word2 != '\0'; word2++)
        if (isalpha(*word2))
            letters_seen[*word2 - 'a']--;

    for(i=0; i<26; i++)
    {
            if(letters_seen[i] != 0)
                return false;
    }
    return true;
}