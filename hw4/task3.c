#include "stdio.h"

void main ()
{
    int a,b,c,d;
    scanf("%d",&d);
    a=(d/100)%10;
    b=(d/10)%10;
    c=d%10;
    if (b>a){a=b;}
    if (c>a){a=c;}
    printf("%d\n",a);
}