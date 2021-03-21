#include <stdio.h>
#include <stdbool.h>

struct color{
    int red, green, blue;
};
struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);

int main() {

    return 0;
}

struct color make_color(int red, int green, int blue){
    struct color mix;
    if(mix.blue<0)
        mix.blue = 0;
    else if(mix.blue > 255)
        mix.blue = 255;

    if(mix.red<0)
        mix.red = 0;
    else if(mix.red> 255)
        mix.red = 255;

    if(mix.green<0)
        mix.green = 0;
    else if(mix.green > 255)
        mix.green = 255;

    return mix;
}

int getRed(struct color c){
    return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
    if(color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue)
        return true;
}

struct color brighter(struct color c){
    if (c.red == 0 && c.green == 0 && c.blue == 0)
        return (struct color) { 3, 3, 3 };

    if (c.red   > 0 && c.red   < 3) c.red   = 3;
    if (c.green > 0 && c.green < 3) c.green = 3;
    if (c.blue  > 0 && c.blue  < 3) c.blue  = 3;

    c.red   /= 0.7;
    c.green /= 0.7;
    c.blue  /= 0.7;

    if (c.red   > 255) c.red   = 255;
    if (c.green > 255) c.green = 255;
    if (c.blue  > 255) c.blue  = 255;

    return c;
}

struct color darker(struct color c)
{
    if (c.red == 0 && c.green == 0 && c.blue == 0)
        return (struct color) { 3, 3, 3 };

    if (c.red   > 0 && c.red   < 3) c.red   = 3;
    if (c.green > 0 && c.green < 3) c.green = 3;
    if (c.blue  > 0 && c.blue  < 3) c.blue  = 3;

    c.red   *= 0.7;
    c.green *= 0.7;
    c.blue  *= 0.7;

    if (c.red   > 255) c.red   = 255;
    if (c.green > 255) c.green = 255;
    if (c.blue  > 255) c.blue  = 255;

    return c;
}