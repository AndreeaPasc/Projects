/// Enforcing privacy with cryptography

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, encrypted = 0, decrypted;
    printf("Enter a number: ");
    scanf("%d", &number);

    int aux;
    aux = (number / 1000 + 7) % 10 * 1000 + (number / 100 % 10 + 7) % 10 * 100 + (number / 10 % 10 + 7) %10 * 10 + (number % 10 + 7) % 10;
    encrypted = aux % 100 * 100 + aux / 100;
    printf("The encrypted number is: %d\n", encrypted);

    aux = encrypted % 100 * 100 + encrypted / 100;
    decrypted = (aux / 1000 + 3) % 10 * 1000 + (aux / 100 % 10 + 3) % 10 * 100 + (aux / 10 % 10 + 3) %10 * 10 + (aux % 10 + 3) % 10;
    printf("The decrypted number is: %d", decrypted);
    return 0;
}
