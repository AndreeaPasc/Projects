#include <stdio.h>

void remove_filename(char *url);

int main(void)
{
    char url[] = "https://www.youtube.com/index.html";
    remove_filename(url);
    puts(url);
    return 0;
}

void remove_filename(char *url)
{
    while (*url)
        url++; /* go to end of string */
    while (*(--url))
    {
        if (*url == '/')
        {
            *url = '\0';
            break;
        }
    }
}