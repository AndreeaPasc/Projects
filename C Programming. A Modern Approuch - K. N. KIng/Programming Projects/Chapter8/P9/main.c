#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
int main (void) {

int i, j, k, direction;
char board[ROWS][COLS];
const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

srand ((unsigned) time(NULL));

for (i = 0; i < ROWS; i++)
  for (j = 0; j < COLS; j++)
    board[i][j] = '.';

printf("Initial board: \n");

for(i=0;i<ROWS;i++)
{
    for(j=0;j<COLS;j++)
        printf("%c ", board[i][j]);
    printf("\n");
}
i = 0;
j = 0;
k = 1;
board[i][j] = letters[0];  //set array[0][0] to first element
while (k < 26) {
  direction = rand() % 4;

if (board[i][j] == '.')
board[i][j] = letters[k++];
if (board[i][j + 1] != '.' && board[i + 1][j] != '.' && board[i - 1][j] != '.' && board[i][j - 1] != '.')
break;
    switch (direction) {
      case 0: if (j < ROWS - 1 && board[i][j + 1] == '.'){
              j++;
              break;     }
      case 1: if (i < COLS -1 && board[i + 1][j] == '.') {
              i++;
              break; }
      case 2: if (i > 0 && board[i - 1][j] == '.'){
              i--;
              break;  }
      case 3: if (j > 0 && board[i][j - 1] == '.') { //move left
              j--;
              break; }
}
}

printf("\nThe walk: \n");

for (i = 0; i < ROWS; i++) {
  for (j = 0; j < COLS; j++)
    printf ("%c ", board[i][j]);
  printf ("\n");
}

return 0;

}
