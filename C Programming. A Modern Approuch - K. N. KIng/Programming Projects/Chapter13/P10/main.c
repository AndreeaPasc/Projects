#include <stdio.h>
#include <ctype.h>

#define FALSE 0
#define LEN 50 /* max length of name */

void reverse_name(char *name);

int main(void)
{
    char full_name[LEN], first_name[LEN/2], last_name[LEN/2];

    printf("\nEnter a first and last name: ");
    scanf("%s %s", first_name, last_name);
    sprintf(full_name, "%s %s", first_name, last_name);

    reverse_name(full_name);

    return 0;
}

void reverse_name(char *name)
{
    char first_name_letter = 0;
    int space = FALSE;

    for (; *name; name++)
    {
        if (!first_name_letter)
        {
            if (*name != ' ')
                first_name_letter = *name;
        }
        else if (space == FALSE)
        {
            if (*name == ' ')
                space = 1;
        }
        else if (*name != ' ')
            putchar(*name);
    }

    printf(", %c.\n\n", first_name_letter);
}