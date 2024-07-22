#include "stdio.h"
#include "stdint.h"
int main (void)
{
    uint32_t N,K;
    scanf("%d %d",&N,&K);
    N=(N>>K)|(N<<(32-K));
    printf("%d",N);
    return 0;
}