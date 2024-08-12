#include "stdio.h"
int zero_counter(int a);
int main(void)
{
    int n,k;
    int num=0;
    scanf("%d %d", &n,&k);
    n++;
    for (int i=1;i<n;i++)
    {
        if (zero_counter(i)==k)
        {
            num++;
        }
    }
    printf("%d",num);
    return 0;
}
int zero_counter(int a)
{
    
    int template = 32768;
    int zeros=0;
    while ((a&template)!=template)
    {
        template>>=1;
    }
    while (template!=0)
    {
        if ((a&template)==0)
        {
            zeros++;
        }
        template>>=1;
    }
    return zeros;
}
