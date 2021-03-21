#include <stdio.h>
#define FRENCH

int main(void)
{
    printf("\n"
           #if defined(ENGLISH)
           "Insert Disk 1"
           #elif defined(FRENCH)
           "Inserez Le Diskque 1"
           #elif defined(SPANISH)
           "Inserte El Disco 1"
           #endif
           "\n\n");
    return 0;
}