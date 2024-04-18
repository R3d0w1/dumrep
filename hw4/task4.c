#include "stdio.h"
void main ()
{
    int a;
    int h=-2147483648;
    int l=2147483647;
    for(int i = 0; i<5; i++)
    {
        scanf("%d",&a);
        if (a>h) {h=a;}
        if (a<l) {l=a;}
    }
    printf("%d",h+l);
}