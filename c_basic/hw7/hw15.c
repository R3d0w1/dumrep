#include "stdio.h"
int max_find(int max);
int main ()
{
    printf ("%d",max_find(-2147483647));

    return 0;
}
int max_find(int max)
{
    int m;
    scanf("%d",&m);
    if(m==0)
    {
        return max;
    }
    if(m>max)
    {
        return max_find(m);
    }
    if(m<=max)
    {
        return max_find(max);
    } 
}