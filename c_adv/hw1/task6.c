#include "stdio.h"
#include "stdint.h"
int main (void)
{
    uint32_t N;
    uint32_t c=0;
    scanf("%u",&N);
    for (int i=0;i<31;i++)
    {
        c+=(N&1);
        N>>=1;
    }
    printf("%d",c);
    return 0;
}