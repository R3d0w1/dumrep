#include "stdio.h"
#include "stdint.h"
int main (void)
{
    uint32_t N,K,c;
    scanf("%u",&N);
    while(N--)
    {
        scanf("%u",&K);
        c^=K;
    }
    printf("%u",c);
    return 0;
}