#include <stdio.h>

void selection_sort(int array[], int n)
{
    int i, max, maxIndex=0, temp;
    max=array[0];
    for(i=0;i<n;i++)
    {
        if(max<array[i])
        {
            max = array[i];
            maxIndex=i;
        }
    }
    if(max!=array[n-1])
    {
        temp = array[n-1];
        array[n-1]=max;
        array[maxIndex] = temp;
    }

    if(n>1)
        selection_sort(array, n-1);

}

int main() {
    int n;
    printf("n=");
    scanf("%d", &n);

    int array[n];
    int i;
    for(i=0; i<n;i++)
    {
        printf("array[%d]=", i);
        scanf("%d", &array[i]);
    }

    selection_sort(array, n);

    for(i=0;i<n;i++)
    {
        printf("\narray[%d] = %d", i, array[i]);
    }

    return 0;
}