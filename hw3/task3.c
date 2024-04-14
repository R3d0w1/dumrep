#include "stdio.h"

void main ()
{
    int a,b,c;
    float d;
    scanf("%d %d %d", &a, &b, &c);
    d=(float)(a+b+c)/3;
    printf("%f\n",d);
    getchar();
}