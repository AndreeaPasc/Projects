#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, size=0;
    char message[30], ch;
    printf("Enter message: ");
    scanf("%c ", &ch);
    while(ch!='\n')
    {
        message[i] = ch;
        ch = getchar();
        i++;
    }
    printf("In B1FF-speak: ");
    for(i=0; i<30; i++)
    {
        if(message[i] == 'A' || message[i]== 'a')
            printf("4");
        else
        {
            if(message[i] == 'B' || message[i]== 'b')
                printf("8");
            else
            {
                if(message[i] == 'E' || message[i]== 'e')
                    printf("3");
                else
                {
                    if(message[i] == 'I' || message[i]== 'i')
                        printf("1");
                    else
                    {
                        if(message[i] == 'O' || message[i]== 'o')
                            printf("0");
                        else
                        {
                            if(message[i] == 'S' || message[i]== 's')
                                printf("5");
                            else
                            {
                                if(message[i] == ' ')
                                    printf(" ");
                                else printf("%c", message[i]);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("!!!!!!!!");
    return 0;
}
