#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grade;
    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    grade = grade/10;
    if (grade > 0)
    {
        switch(grade)
        {
        case 0 :
        case 1 :
        case 2 :
        case 3 :
        case 4 :
        case 5 :
            printf("F");
            break;
        case 6 :
            printf("D");
            break;
        case 7 :
            printf("C");
            break;
        case 8 :
            printf("B");
            break;
        case 9 :
        case 10 :
            printf("A");
            break;
        default :
            printf("ERROR");
        }
    }
    else
        printf("ERROR");
    return 0;
}
