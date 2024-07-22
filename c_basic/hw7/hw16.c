#include "stdio.h"
int is2pow(int n);
int main ()
{
    int m;
    scanf("%d",&m);
    if (is2pow(m))
    {
        printf("%s","YES");
    }
    else
    {
        printf("%s","NO");
    }

    return 0;
}
int is2pow(int n)
{   
    if ((n==2)||(n==1))
    {
        return 1;
    }
    if((n%2)==0)
    {
        return is2pow(n/2);
    }
    else
    {
        return 0;
    }
}