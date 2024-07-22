#include "stdio.h"
void main ()
{
    int a;
    int b=2147483647;
    for(int i = 0; i<5; i++)
    {
        scanf("%d",&a);
        if (a<b) {b=a;}
    }
    printf("%d",b);
}