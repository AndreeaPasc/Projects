#include <stdio.h>
#include <math.h>

float polynomial(float x)
{
    float result;
    result = 3*pow(x, 5)+2*pow(x,4)-5*pow(x,3)-x*x+7*x-6;
    return printf("3*%f^5+2*%f^4-5*%f^3-%f^2+7*%f-6=%f",
            x,x,x,x,x,result);

}

int main() {
    float x;
    printf("x=");
    scanf("%f", &x);
    polynomial(x);
    return 0;
}