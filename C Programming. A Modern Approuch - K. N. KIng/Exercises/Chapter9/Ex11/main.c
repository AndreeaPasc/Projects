#include <stdio.h>
#include <stdio.h>
#include <ctype.h>

float compute_gpa(char grades[], int n)
{
    int i;
    float sum=0;

    for(i=0;i<n;i++)
    {
        grades[i] = toupper(grades[i]);
        switch(grades[i])
        {
            case 'A': sum+=4; break;
            case 'B': sum+=3; break;
            case 'C': sum+=2; break;
            case 'D': sum+=1; break;
            case 'F': sum+=0; break;
        }
    }
    return printf("The average is: %f", sum/n);
}

int main() {
    int n, i;

    printf("Enter the number of grades: ");
    scanf("%d", &n);

    char grades[n];
    for(i=0;i<n;i++)
    {
        printf("grades[%d] = ", i);
        scanf(" %c ", &grades[i]);
    }
    compute_gpa(grades, n);

    return 0;
}