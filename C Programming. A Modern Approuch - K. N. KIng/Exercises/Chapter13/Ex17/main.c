#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define false 0
#define true 1
typedef int bool;

bool test_extension(const char *file_name,
                    const char *extension);

int main(void)
{
    char *fn = "memo.txt", *ext = "TXT";

    printf("\nFile name: %s\nExtension check: %s", fn, ext);
    printf("\nResult: %s\n\n", test_extension(fn, ext) ? "true" : "false");
    return 0;
}

bool test_extension(const char *file_name,
                    const char *extension)
{
    while (*file_name)
    {
        if (*file_name++ == '.')
        {
            while (*file_name)
                if (toupper(*file_name++) != *extension++)
                    return false;
            return true;
        }
    }
    return false;
}