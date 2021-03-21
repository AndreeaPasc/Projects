#include <stdio.h>
#include <stdlib.h>

int main()
{
    float flag = 0, space=1;
    char sentence;

    printf("Enter a sentence: ");
    sentence = getchar();

        while(sentence!='\n')
        {
            flag++;
            if (sentence == ' ')
                {
                    space++;
                    flag--;
                }
            sentence = getchar();
        }

    printf("Average word length: %.1f", flag/space);
    return 0;
}
