#include <stdio.h>

struct time{
    int hours, minutes, seconds;
};

struct time split_time(long total_seconds);

int main() {

}

struct time split_time(long total_seconds)
{
    struct time conversion;

    conversion.seconds = total_seconds % 60;
    conversion.minutes = total_seconds / 60;
    conversion.hours = total_seconds / 60 / 60;

    return conversion;
}
