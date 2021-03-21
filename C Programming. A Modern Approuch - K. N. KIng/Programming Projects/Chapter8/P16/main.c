#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char word1, word2;
    int i, n=0, wordArray[26]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    printf("Enter first word: ");
    scanf("%c", &word1);

    word1=tolower(word1);

    while(word1!='\n')
    {
        if(isalpha(word1)!=0)
        {
            switch(word1)
            {
            case 'a':
                wordArray[0]+=1;
                break;
            case 'b':
                wordArray[1]+=1;
                break;
            case 'c':
                wordArray[2]+=1;
                break;
            case 'd':
                wordArray[3]+=1;
                break;
            case 'e':
                wordArray[4]+=1;
                break;
            case 'f':
                wordArray[5]+=1;
                break;
            case 'g':
                wordArray[6]+=1;
                break;
            case 'h':
                wordArray[7]+=1;
                break;
            case 'i':
                wordArray[8]+=1;
                break;
            case 'j':
                wordArray[9]+=1;
                break;
            case 'k':
                wordArray[10]+=1;
                break;
            case 'l':
                wordArray[11]+=1;
                break;
            case 'm':
                wordArray[12]+=1;
                break;
            case 'n':
                wordArray[13]+=1;
                break;
            case 'o':
                wordArray[14]+=1;
                break;
            case 'p':
                wordArray[15]+=1;
                break;
            case 'q':
                wordArray[16]+=1;
                break;
            case 'r':
                wordArray[17]+=1;
                break;
            case 's':
                wordArray[18]+=1;
                break;
            case 't':
                wordArray[19]+=1;
                break;
            case 'u':
                wordArray[20]+=1;
                break;
            case 'v':
                wordArray[21]+=1;
                break;
            case 'w':
                wordArray[22]+=1;
                break;
            case 'x':
                wordArray[23]+=1;
                break;
            case 'y':
                wordArray[24]+=1;
                break;
            case 'z':
                wordArray[25]+=1;
                break;
            }
        }
        word1 = getchar();
    }

    printf("Enter second word: ");
    scanf("%c", &word2);

    word2=tolower(word2);
    while(word2!='\n')
    {
        if(isalpha(word2)!=0)
        {
            switch(word2)
            {
            case 'a':
                wordArray[0]-=1;
                break;
            case 'b':
                wordArray[1]-=1;
                break;
            case 'c':
                wordArray[2]-=1;
                break;
            case 'd':
                wordArray[3]-=1;
                break;
            case 'e':
                wordArray[4]-=1;
                break;
            case 'f':
                wordArray[5]-=1;
                break;
            case 'g':
                wordArray[6]-=1;
                break;
            case 'h':
                wordArray[7]-=1;
                break;
            case 'i':
                wordArray[8]-=1;
                break;
            case 'j':
                wordArray[9]-=1;
                break;
            case 'k':
                wordArray[10]-=1;
                break;
            case 'l':
                wordArray[11]-=1;
                break;
            case 'm':
                wordArray[12]-=1;
                break;
            case 'n':
                wordArray[13]-=1;
                break;
            case 'o':
                wordArray[14]-=1;
                break;
            case 'p':
                wordArray[15]-=1;
                break;
            case 'q':
                wordArray[16]-=1;
                break;
            case 'r':
                wordArray[17]-=1;
                break;
            case 's':
                wordArray[18]-=1;
                break;
            case 't':
                wordArray[19]-=1;
                break;
            case 'u':
                wordArray[20]-=1;
                break;
            case 'v':
                wordArray[21]-=1;
                break;
            case 'w':
                wordArray[22]-=1;
                break;
            case 'x':
                wordArray[23]-=1;
                break;
            case 'y':
                wordArray[24]-=1;
                break;
            case 'z':
                wordArray[25]-=1;
                break;
            }
        }
        word2 = getchar();
    }

    for(i=0; i<26; i++)
    {
        if(wordArray[i]==0)
            n+=1;
    }

    if(n==26)
        printf("The words are anagrams.");
    else
        printf("The words are not anagrams.");

    return 0;
}
