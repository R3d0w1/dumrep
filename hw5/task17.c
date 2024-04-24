#include "stdio.h"

void main ()
{
    int n;
  
    scanf("%d", &n);
    for (int i=11;i<=n;i++)
    {   
        int sum=0;
        int mul=1;
        int n=i;
        while (n>0)
        {
            sum+=n%10;
            mul*=n%10;
            n/=10;
        }

        if(sum==mul)
        {
            printf("%d ", i);
        }
        
    }
}