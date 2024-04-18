#include "stdio.h"

void main ()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if ((b<=a)||(c<=b)||(c<=a)){printf("NO");return;}
    printf("YES");
}