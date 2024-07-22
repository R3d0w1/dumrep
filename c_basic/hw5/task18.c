#include "stdio.h"

void main ()
{
    int c,n;
    int a=0;
    int b=1;
  
    scanf("%d", &n);
    for (int i=0;i<n;i++)
    {
        printf("%d ", b);
        c=a;
        a=b;
        b=c+a;
    }
}