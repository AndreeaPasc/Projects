#include <stdio.h>

#define N 10

double ident[N][N], *p;
int consec_zeros = N;

    for(p=ident; p<ident+N*N; p++)
    {
        if(consec_zeros == N)
        {
            *p = 1.0;
            consec_zeros = 0;
        }
        else
        {
            *p = 0.0;
            consec_zeros++;
        }
    }
    return 0;
