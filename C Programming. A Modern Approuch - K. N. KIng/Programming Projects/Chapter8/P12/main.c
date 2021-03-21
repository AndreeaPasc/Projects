#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int value[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10,
                    1 , 1, 1, 1, 4, 4 , 8, 4, 10};
    char word;
    int i, sum=0;
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R' ,
                        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    printf("Enter a SCRABBLE word: ");
    scanf("%c", &word);

    while(word!='\n')
    {
        word = toupper(word);
        for(i=0;i<26;i++)
        {
            if(word==alphabet[i])
            {
                sum+=value[i];
            }
        }
        word = getchar();
    }

    printf("The value is: %d", sum);
    return 0;
}
