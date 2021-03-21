#include <stdio.h>

int evaluate_position(char board[8][8])
{
    int sumWhite = 0;
    int sumBlack = 0;
    int i, j;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            switch(board[i][j])
            {
                case 'Q': sumWhite+=9; break;
                case 'R': sumWhite+=5; break;
                case 'B': sumWhite+=3; break;
                case 'N': sumWhite+=3; break;
                case 'P': sumWhite+=1; break;
                case 'q': sumBlack+=9; break;
                case 'r': sumBlack+=5; break;
                case 'b': sumBlack+=3; break;
                case 'n': sumBlack+=3; break;
                case 'p': sumBlack+=1; break;
            }
        }
    }

    return printf("%d", sumWhite-sumBlack);

}


int main() {

    char board[8][8];
    int i, j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("board[%d][%d] = ", i, j);
            scanf(" %c", &board[i][j]);
        }
    }
    evaluate_position(board);
    return 0;
}