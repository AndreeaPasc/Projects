#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("This program creates a magic square of a specific size.\nThe size must be an odd number between 1 and 99.");

    printf("\nEnter size of magic square: ");
    scanf("%d", &n);


    ///Create an array (not using VLA)

    int magic[99][99];
    int start = (n/2); ///The midle column
    int max = n*n; ///The final number
    magic[0][start]=1;

    ///Loop to start placing numbers in the magic square
    int row, col, nextRow, nextCol, i;

    for(i=2, row=0,col=start; i<max+1; i++)
    {
        if((row-1)<0) ///If going up one will leave the  side
        {
            nextRow = n-1;///Go to the bottom row
        }
        else
            nextRow = row - 1;///Otherwise go up one
        if((col+1)>(n-1))///If column will leave the side
        {
            nextCol=0;///Wrap to first column
        }
        else
        {
            nextCol = col+1; ///Otherwise go over one
        }

        if(magic[nextRow][nextCol]>0)///If the position is taken
        {
            if(row>(n-1))
                nextRow=0;
            else
            {
                nextRow = row+1;
                nextCol = col+1;
            }
        }
        row = nextRow;
        col = nextCol;
        magic[row][col] = i; ///Put the current value in that position
    }

    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%4d", magic[i][j]);
        printf("\n");
    }
    return 0;
}
