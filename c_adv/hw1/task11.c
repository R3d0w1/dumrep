/*#include "stdio.h"
#include "stdint.h"

int extractExp(float);



int main (void)
{
    float x = 0.001;
    
    printf("%u\n",extractExp(x));
    return 0;
}
 */
 int extractExp(float a)
 {
    uint32_t x = *((uint32_t*)&a);
    x=(x>>23)&255;
    return x;
 }
 