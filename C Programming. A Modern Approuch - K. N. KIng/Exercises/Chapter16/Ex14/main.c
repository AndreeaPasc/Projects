#define PI 3.1415926535
enum { RECTANGLE, CIRCLE };

struct point { int x, y; };

struct shape {
    int shape_kind;           /* RECTANGLE or CIRCLE */
    struct point center;      /* coordinates of center */
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

/// a)
int compute_area(struct shape s)
{
    if (s.shape_kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
    else /* if shape is CIRCLE */
        return PI * s.u.circle.radius * s.u.circle.radius;
}

/// b)
struct shape move_shape(struct shape s, int x, int y)
{
    s.center.x += x;
    s.center.y += y;
    return s;
}

/// c)
struct shape scale_shape(struct shape s, double c)
{
    if (s.shape_kind == RECTANGLE)
    {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    }
    else
        s.u.circle.radius *= c;
    return s;
}