#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char phone, c;

    printf("Enter a phone number: ");
    phone = getchar();

    while(phone!='\n')
    {
        switch(phone)
        {
            case '0': printf("0"); break;
            case '1': printf("1"); break;
            case '2': printf("2"); break;
            case '3': printf("3"); break;
            case '4': printf("4"); break;
            case '5': printf("5"); break;
            case '6': printf("6"); break;
            case '7': printf("7"); break;
            case '8': printf("8"); break;
            case '9': printf("9"); break;
            case '-': printf("-"); break;
            case '.': printf("."); break;
            case '/': printf("/"); break;
            case 'A': case 'B': case 'C': printf("2"); break;
            case 'D': case 'E': case 'F': printf("3"); break;
            case 'G': case 'H': case 'I': printf("4"); break;
            case 'J': case 'K': case 'L': printf("5"); break;
            case 'M': case 'N': case 'O': printf("6"); break;
            case 'P': case 'R': case 'S': printf("7"); break;
            case 'T': case 'U': case 'V': printf("8"); break;
            case 'W': case 'X': case 'Y': case 'Z': printf("9"); break;
        }
        phone = getchar();
    }


    return 0;
}
