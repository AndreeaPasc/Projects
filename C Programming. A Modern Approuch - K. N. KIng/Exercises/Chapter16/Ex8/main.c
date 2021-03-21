#include <stdio.h>

int main() {
    struct color{
        int red;
        int green;
        int blue
    };

    /// a)
    const struct color MAGENTA = {255, 0, 255};

    /// b)
    const struct color magenta = {.red = 255, .blue = 255};

    return 0;
}