#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool digit_seen[10] = {false};
    int digit,i;
    long n[1024];

    for(i=0; i<1024; i++)
    {
        printf("Enter a number: ");
        scanf("%ld", &n[i]);

        if(n[i]>0)
        {


            while(n[i]>0)
            {
                digit = n[i]%10;
                if(digit_seen[digit])
                    break;
                digit_seen[digit] = true;
                n[i]/=10;
            }

            if(n[i]>0)
                printf("Repteated digit\n");
            else
                printf("No repeated digit\n");
        }
        else break;
    }
    return 0;
}
