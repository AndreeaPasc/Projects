#include <stdio.h>
#include <stdbool.h>

struct point {int x, y; };
struct rectangle {struct point  upper_left, lower_right; };

int main() {

    return 0;
}

int compute_area(struct rectangle r)
{
    int length = r.upper_left.y  - r.lower_right.y;
    int width  = r.lower_right.x - r.upper_left.x;
    return length * width;
}

struct point find_center(struct rectangle r)
{
    struct point center;
    center.x = r.lower_right.x / 2;
    center.y = r.upper_left.y  / 2;
    return center;
}

struct rectangle move_rect(struct rectangle r, int x, int y)
{
    r.upper_left.x += x;
    r.upper_left.y += y;
    r.lower_right.x += x;
    r.lower_right.y += y;
    return r;
}

bool point_is_in_rect(struct point p, struct rectangle r)
{
    if (p.x > r.upper_left.x && p.x < r.lower_right.x &&
        p.y < r.upper_left.y && p.y > r.lower_right.y)
        return true;
    else return false;
}