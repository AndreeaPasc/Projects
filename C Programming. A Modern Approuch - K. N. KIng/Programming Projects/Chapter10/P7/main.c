#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/**
 *      0
 *      _
 *  5 |6_| 1
 *  4 | _| 2
 *      3
 */

#define MAX_DIGITS 10

const int segments[10][7] = {{1, 1 ,1, 1, 1, 1 ,0}, ///0
                             {0, 1, 1, 0, 0, 0, 0}, ///1
                             {1, 1, 0, 1, 1, 0, 1}, ///2
                             {1, 1, 1, 1, 0, 0, 1}, ///3
                             {0, 1, 2, 0, 0, 1, 1}, ///4
                             {1, 0, 1, 1, 0, 1, 1}, ///5
                             {1, 0, 1, 1, 1, 1, 1}, ///6
                             {1, 1, 1, 0, 0, 0, 0}, ///7
                             {1, 1, 1, 1, 1, 1, 1}, ///8
                             {1, 1, 1, 1, 0, 1, 1}  ///9
                            };
int digits[4][MAX_DIGITS*4];

void clear_digits_array(void);
void process_digit (int digit, int position);
void print_digits_array(void);

int main()
{
    char input;
    int num_digits = 0;

    clear_digits_array();

    printf("\nEnter a number: ");
    while ((input = getchar()) != '\n')
    {
        if (num_digits == MAX_DIGITS) break;
        if (input >= '0' && input <= '9')
            process_digit(input - '0', num_digits++);
    }

    print_digits_array();

    return 0;
}

void clear_digits_array(void)
{
    int row, col;
    for(row=0; row<4; row++)
        for(col=0; col<(MAX_DIGITS*4); col++)
            digits[row][col] = ' ';
}

void process_digit(int digit, int position)
{
    int offset = position * 4;
    digits[0][offset + 1] = segments[digit][0] ? '_' : ' ';
    digits[1][offset]     = segments[digit][5] ? '|' : ' ';
    digits[1][offset + 1] = segments[digit][6] ? '_' : ' ';
    digits[1][offset + 2] = segments[digit][1] ? '|' : ' ';
    digits[2][offset]     = segments[digit][4] ? '|' : ' ';
    digits[2][offset + 1] = segments[digit][3] ? '_' : ' ';
    digits[2][offset + 2] = segments[digit][2] ? '|' : ' ';
}

void print_digits_array(void)
{
    int row, col;
    for (row = 0; row < 4; row++)
    {
        for (col = 0; col < (MAX_DIGITS * 4); col++)
            putchar(digits[row][col]);
        putchar('\n');
    }
}