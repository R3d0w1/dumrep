#include "stdio.h"
int recurs_power(int n, int p);
int main ()
{
    int a,b;
    scanf("%d %d", &a,&b);
    printf("%d", recurs_power(a,b));
    return 0;
}

int recurs_power(int n, int p)
{
    if (p==0) 
    {
        return 1;
    }
    
    if (p>0)
    {
        return n*recurs_power(n,--p);
    }
}