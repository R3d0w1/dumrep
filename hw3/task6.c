#include "stdio.h"

void main ()
{
    int d;
    scanf("%d",&d);
    d=((d/100)%10) * ((d/10)%10) * (d%10);
    printf("%d\n",d);
    getchar();
}