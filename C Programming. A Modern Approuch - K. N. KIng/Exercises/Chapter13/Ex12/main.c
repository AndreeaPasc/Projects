#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STR_LEN 20
#define EXT 5

void get_extension(const char *file_name, char *extension);

int main() {
    char file_name[STR_LEN], extension[EXT];
    printf("Enter a file name: ");
    gets(file_name);

    get_extension(file_name, extension);

    printf("The extension is: %s", extension);

    return 0;
}

void get_extension(const char *file_name, char *extension)
{
    char *s = file_name;
    char *p = extension;
    while(*s!='.')
        *s++;
    *s++;
    while(*s!='\0')
    {
        strcpy(p, s);
        *s++;
        *p++;
    }
}