#include "stdio.h"

void main ()
{ 
int n,sum;
scanf("%d", &n);

        while (n>0)
        {
            sum+=n%10;
            n/=10;
        }

        if(sum==10)
        {
            printf("%s", "YES");
        }
        else
        {
            printf ("%s", "NO");
        }
        
}