#include "stdio.h"
#include "stdint.h"
int main (void)
{
    uint32_t N,template;
    int K,max=-2147483648; 
    scanf("%u %d",&N,&K);
    template = (int)0x80000000>>(K-1);
    int i=33-K;
    while(i)
    {
        K=((N&template)>>(i-1));
        if(K>max)
        {
            max=K;
        }
        template>>=1;
        i--;
    }
    printf("%d",max);
    return 0;
}