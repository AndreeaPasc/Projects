#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch, c;
    printf("Enter a first and a last name: ");
    scanf("%c", &c);
    ch=c;
    while(c!=' ')
    {
        scanf("%c", &c);
    }
    while(c!='\n')
    {
        scanf("%c", &c);
        if(c=='\n') break;
        printf("%c", c);
    }
    printf(", %c.", ch);
    return 0;
}
