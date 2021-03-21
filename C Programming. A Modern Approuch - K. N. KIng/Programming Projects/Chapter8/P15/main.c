#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i=0,j=0;
    char message, mark, messageArray[80];

    printf("Enter shift amount (1-25): ");
    scanf("%d", &n);

    printf("Enter message to be encrypted: ");
    scanf("%c", &message);

    while(message!='.'&&message!='!'&&message!='?')
    {
        messageArray[i]=message;
        i++;
        j++;
        message=getchar();
    }

    mark=message;

    for(i=0; i<j; i++)
    {
        if(messageArray[i]!=' ')
        {
            if(messageArray[i]>='a' && messageArray[i]<='z')
                messageArray[i]=((messageArray[i]-'a')+n)%26+'a';
            else
            {
                if(messageArray[i]>='A' && messageArray[i]<='Z')
                    messageArray[i]=((messageArray[i]-'A')+n)%26+'A';
            }
        }
        else
            printf(" ");
    }

    for(i=0; i<j; i++)
    {
        printf("%c", messageArray[i]);
    }

    printf("%c", mark);
    return 0;
}
