#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 8
#define LENGHT 12
#define WIDTH 10

int main(void)
{
    int volume;

    volume = HEIGHT * LENGHT * WIDTH;

    printf("Dimensions: %dx%dx%d\n", LENGHT, WIDTH, HEIGHT);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166);
    return 0;
}
