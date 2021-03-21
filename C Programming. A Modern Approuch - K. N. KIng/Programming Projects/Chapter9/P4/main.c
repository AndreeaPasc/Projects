#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

void read_word(int counts[26])
{
    char word;
    printf("Enter a word: ");
    scanf("%c", &word);

    while(word!='\n')
    {
        if(isalpha(word)!=0)
        {
            switch(word)
            {
                case 'a':
                    counts[0]+=1;
                    break;
                case 'b':
                    counts[1]+=1;
                    break;
                case 'c':
                    counts[2]+=1;
                    break;
                case 'd':
                    counts[3]+=1;
                    break;
                case 'e':
                    counts[4]+=1;
                    break;
                case 'f':
                    counts[5]+=1;
                    break;
                case 'g':
                    counts[6]+=1;
                    break;
                case 'h':
                    counts[7]+=1;
                    break;
                case 'i':
                    counts[8]+=1;
                    break;
                case 'j':
                    counts[9]+=1;
                    break;
                case 'k':
                    counts[10]+=1;
                    break;
                case 'l':
                    counts[11]+=1;
                    break;
                case 'm':
                    counts[12]+=1;
                    break;
                case 'n':
                    counts[13]+=1;
                    break;
                case 'o':
                    counts[14]+=1;
                    break;
                case 'p':
                    counts[15]+=1;
                    break;
                case 'q':
                    counts[16]+=1;
                    break;
                case 'r':
                    counts[17]+=1;
                    break;
                case 's':
                    counts[18]+=1;
                    break;
                case 't':
                    counts[19]+=1;
                    break;
                case 'u':
                    counts[20]+=1;
                    break;
                case 'v':
                    counts[21]+=1;
                    break;
                case 'w':
                    counts[22]+=1;
                    break;
                case 'x':
                    counts[23]+=1;
                    break;
                case 'y':
                    counts[24]+=1;
                    break;
                case 'z':
                    counts[25]+=1;
                    break;
            }
        }
        word = getchar();
    }
}

bool equal_array(int count1[26], int count2[26])
{
    int i, flag=0;
    for(i=0;i<26;i++)
    {
        if(count1[i]==count2[i])
            flag+=1;
        else
            flag+=0;
    }

    if(flag == 26)
        return true;
    else
        return false;
}

int main() {
    int array1[26], array2[26];
    for(int i=0; i<26;i++)
    {
        array1[i]=0;
        array2[i]=0;
    }
    read_word(array1);
    read_word(array2);
    equal_array(array1, array2);

    return 0;

}