/// Towers of Hanoi

#include <stdio.h>
#include <stdlib.h>

void towers(int n, int beg, int end, int aux);

int main()
{
    int n, peg1 = 1, peg2 = 2, peg3 = 3;
    printf("Enter the number of disks on your peg: ");
    scanf("%d", &n);

    towers(n, peg1, peg3, peg2);
    return 0;
}

void towers(int n, int beg, int end, int aux){
    int i;
    if(n == 1){
        printf("%d -> %d\n", beg, end);
        return;
    }
    towers(n-1, beg, aux, end);
    printf("%d -> %d\n", beg, end);
    towers(n-1, aux, end, beg);

}
