/// Table of decimal, binary, octal, and hexadecimal equivalents

#include <stdio.h>
#include <math.h>

int main(){
    int i, binary = 0, j, aux, reverse = 0;
    printf("DECIMAL\tBINARY\tOCTAL\tHEXADECIMAL\n");

    for(i = 1; i <= 256; i++){
        j = i;
        binary = 0;
        reverse = 0;
        if(i == 2 || i == 4 || i == 8 || i == 16 || i == 32 || i == 64 || i == 128 || i == 256){
            switch(i){
                case 2 : reverse = 10; break;
                case 4 : reverse = 100; break;
                case 8 : reverse = 1000; break;
                case 16 : reverse = 10000; break;
                case 32 : reverse = 100000; break;
                case 64 : reverse = 1000000; break;
                case 128 : reverse = 10000000; break;
                case 256 : reverse = 100000000; break;
            }
        }
        else{
            while(j != 0){
                binary = binary * 10 + j % 2;
                j /= 2;
            }
            aux = binary;
            while(aux != 0){
                reverse = reverse * 10 + aux % 10;
                aux /= 10;
            }
        }
        printf("%d\t%d\t%o\t%x\n", i, reverse, i, i);
    }

    return 0;
}
