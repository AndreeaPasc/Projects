#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, j=0;
    char name, ch;
    char lastNameArray[j];

    printf("Enter a first and a last name: ");
    scanf("%c", &name);

    ch = name;

    while(name!=' ')
    {
       name = getchar();
    }

    while(name!='\n')
    {
        lastNameArray[i]=name;
        i++;
        j++;
        name = getchar();
    }

    printf("You entered the name: ");
    for(i=0;i<j;i++)
    {
        if(lastNameArray[i]!='\0')
            printf("%c", lastNameArray[i]);
    }

    printf(", %c.", ch);

    return 0;
}
