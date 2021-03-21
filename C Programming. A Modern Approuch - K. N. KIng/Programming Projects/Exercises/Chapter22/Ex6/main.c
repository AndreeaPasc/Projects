#include <stdio.h>

int main() {
    printf("%d widget%s", widget, ((widget == 1) ? "" : "s"));
    return 0;
}