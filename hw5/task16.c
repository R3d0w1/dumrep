#include "stdio.h"
#include "stdlib.h"
void main ()
{
    int a,b,c;
    scanf("%d %d", &a, &b);
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    printf("%d ", abs(a));
        
}