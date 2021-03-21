#include <stdio.h>
#include <stdbool.h>

bool has_zero(int a[], int n)
{
    int i;
    int flag;
    for(i=0; i<n; i++)
    {
        if(a[i]==0)
            flag+=0;
        else
            flag+=1;
    }
    if(flag==0)
        return true;
    else
        return false;
}
int main() {
    int n;
    printf("n=");
    scanf("%d", &n);

    int a[n];
    for(int i=0; i<n;i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);

        has_zero(a, n);
    }
    return 0;
}