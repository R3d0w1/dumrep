#include "stdio.h"
#include "stdint.h"
int main (void)
{
    uint32_t N;
    scanf("%u",&N);
    N^=4278190080;
    printf("%u",N);
    return 0;
}