#include <stdio.h>

int main() {
    unsigned int i;
    (i & 8) ? i &= ~8 : i |= 8;
    return 0;
}