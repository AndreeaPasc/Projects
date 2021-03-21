#include <stdio.h>

/// a)
typedef enum  {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} piece;
typedef enum {B, W} color;

/// b)
typedef struct {
    piece p;
    color c;
} Square;

/// c)
Square board[8][8];

/// d)
Square board[8][8] =
        {{{ ROOK,  W }, { KNIGHT, B }, { BISHOP, W }, { KING,  B }, /* row 1 */
                 { QUEEN, B }, { BISHOP, W }, { KNIGHT, B }, { ROOK,  W }},
         {{ PAWN,  W }, { PAWN,   B }, { PAWN,   W }, { PAWN,  B }, /* row 2 */
                 { PAWN,  B }, { PAWN,   W }, { PAWN,   B }, { PAWN,  W }},
         {{ EMPTY, B }, { EMPTY,  W }, { EMPTY,  B }, { EMPTY, W }, /* row 3 */
                 { EMPTY, W }, { EMPTY,  B }, { EMPTY,  W }, { EMPTY, B }},
         {{ EMPTY, B }, { EMPTY,  W }, { EMPTY,  B }, { EMPTY, W }, /* row 4 */
                 { EMPTY, W }, { EMPTY,  B }, { EMPTY,  W }, { EMPTY, B }},
         {{ EMPTY, B }, { EMPTY,  W }, { EMPTY,  B }, { EMPTY, W }, /* row 5 */
                 { EMPTY, W }, { EMPTY,  B }, { EMPTY,  W }, { EMPTY, B }},
         {{ EMPTY, B }, { EMPTY,  W }, { EMPTY,  B }, { EMPTY, W }, /* row 6 */
                 { EMPTY, W }, { EMPTY,  B }, { EMPTY,  W }, { EMPTY, B }},
         {{ PAWN,  W }, { PAWN,   B }, { PAWN,   W }, { PAWN,  B }, /* row 7 */
                 { PAWN,  B }, { PAWN,   W }, { PAWN,   B }, { PAWN,  W }},
         {{ ROOK,  W }, { KNIGHT, B }, { BISHOP, W }, { KING,  B }, /* row 8 */
                 { QUEEN, B }, { BISHOP, W }, { KNIGHT, B }, { ROOK,  W }}};

int main() {
    printf("Hello, World!\n");
    return 0;
}