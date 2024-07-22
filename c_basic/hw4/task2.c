#include "stdio.h"

void main ()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if (b>a) {a=b;}
    if (c>a) {a=c;}
    printf("%d",a);
}