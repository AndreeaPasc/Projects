#include <stdio.h>

enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

/// a)
const int piece_valueA[] = { 200, 9, 5, 3, 3, 1 };

/// b)
const int piece_valueB[] = { [KING]   = 200,
        [QUEEN]  = 9,
        [ROOK]   = 5,
        [BISHOP] = 3,
        [KNIGHT] = 3,
        [PAWN]   = 1, };

int main() {
    printf("Hello, World!\n");
    return 0;
}