#include <stdio.h>

#define GET_RED(color) ((color) & 0xff)
#define GET_GREEN(color) ((color) >> 8 & 0xff)
#define GET_BLUE(color) ((color) >> 16 & 0xff)

int main() {

    return 0;
}