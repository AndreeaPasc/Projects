/// Total sales

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sales[5][4] = {{4, 10, 8, 0},
                        {9, 11, 6, 7},
                        {20, 3, 15, 9},
                        {15, 14, 9, 10},
                        {13, 30, 20, 8}};
    int sum = 0;
    size_t i, j;
    printf("\tSALESPERSON\t\t\t\t\t\t\tTOTAL\nPRODUCT");
    for(i = 0; i < 5; i++){
        sum = 0;
        for(j = 0; j < 4; j++){
            printf("%\t%d\t", sales[i][j]);
            sum += sales[i][j];
        }
        printf("\t%d", sum);
        puts("");
    }

    printf("TOTAL   ");

    for(j = 0; j < 4; j++){
            sum = 0;
        for(i = 0; i < 5; i++){
            sum += sales[i][j];
        }
        printf("%d\t\t", sum);
    }
    return 0;
}
