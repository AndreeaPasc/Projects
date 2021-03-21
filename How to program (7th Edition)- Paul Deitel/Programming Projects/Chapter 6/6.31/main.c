/// Palindrome recursive

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int palindrome(char sentence[], int size);

int main()
{
    char sentence[SIZE] = {"a man a plan a canal panama"};
    size_t i;

    if(palindrome(sentence, SIZE) == 1){
        printf("Palindrome");
    }
    else
        printf("Not a palindrome");
    return 0;
}

int palindrome(char sentence[], int size){
    size_t i, j;
    char backWards[SIZE];

    j = 0;
    for(i = 0; i < SIZE; i++){
        if(sentence[j] != ' '){
            backWards[i] = sentence[j];
        }
        j++;
    }

    for(i = 0, j = size; i < size, j > 0; i++, j--){
        if(backWards[i] == backWards[j])
            return 1;
        else return palindrome(backWards, size-1);
    }
    return 0;
}
