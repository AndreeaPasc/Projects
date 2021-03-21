#include <stdio.h>

int main() {

    switch (direction)
    {
        case NORTH:
            --y;
            break;
        case EAST:
            ++x;
            break;
        case SOUTH:
            ++y;
            break;
        case WEST:
            --x;
            break;
    };

    return 0;
}