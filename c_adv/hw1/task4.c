#include "stdio.h"
#include "stdint.h"
int main (void)
{
    uint32_t N,K,ones=0xFFFFFFFF;
    scanf("%u %u",&N,&K);
    N=N&(ones>>(32-K));
    printf("%d",N);
    return 0;
}