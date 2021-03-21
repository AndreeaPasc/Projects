/// "The Twelve Days of Christmas" song

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day;
    printf("Enter the day: ");
    scanf("%d", &day);

    printf("On the ");
    switch(day){
        case 1 : printf("first"); break;
        case 2 : printf("second"); break;
        case 3 : printf("third"); break;
        case 4 : printf("fourth"); break;
        case 5 : printf("fifth"); break;
        case 6 : printf("sixth"); break;
        case 7 : printf("seventh"); break;
        case 8 : printf("eighth"); break;
        case 9 : printf("ninth"); break;
        case 10 : printf("tenth"); break;
        case 11 : printf("eleventh"); break;
        case 12 : printf("twelfth"); break;
    }

    printf(" day of Chiristmas\nMy true love gave to me\n");

    switch(day){
        case 12 : printf("Twelve drummers drummin'\n");
        case 11 : printf("Eleven pipers pipin'\n");
        case 10 : printf("Ten lords a leapin'\n");
        case 9 : printf("Nine ladies dancin'\n");
        case 8 : printf("Eight maids a milkin'\n");
        case 7 : printf("Seven swans a swimmin'\n");
        case 6 : printf("Six geese a layin'\n");
        case 5 : printf("Five golden rings\n");
        case 4 : printf("Four calling birds\n");
        case 3 : printf("Three french hens\n");
        case 2 : printf("Two turtles doves\n");
        case 1 : printf("A patridge in a pear tree\n");
    }
    return 0;
}
