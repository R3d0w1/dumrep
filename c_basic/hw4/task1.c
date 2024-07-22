#include "stdio.h"

void main ()
{
    int a,b;
    scanf("%d %d", &a, &b);
    if (b>a)
        {
            b=a^b;
            a=a^b;
            b=a^b;
        }
    printf("%d %d",b,a);
}