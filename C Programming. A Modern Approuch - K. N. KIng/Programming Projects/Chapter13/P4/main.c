#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[20], first_word[10], last_word[10];
    printf("Enter the reverse command: ");
    scanf("%s", command);
    scanf("%s", command);

    strcpy(first_word, command);

    scanf("%s", command);
    scanf("%s", command);

    strcpy(last_word, command);

    printf("%s and %s", last_word, first_word);

    return 0;
}

/*
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    if (argc == 1)
    {
        printf("\nUsage: %s words as arguments like this\n\n", argv[0]);
        return 0;
    }
    putchar('\n');
    for (i = argc-1; i > 0; i--)
        printf("%s ", argv[i]);
    printf("\n\n");
    return 0;
}*/
