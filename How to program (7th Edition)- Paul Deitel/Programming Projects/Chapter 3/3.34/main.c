/// Palindrome test

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, aux = 0, palindrome = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    aux = number;
    while(aux != 0){
        palindrome = palindrome * 10 + aux % 10;
        aux /= 10;
    }

    if(palindrome == number)
        printf("%d is a palindrome", number);
    else
        printf("%d is not a palindrome", number);
    return 0;
}
