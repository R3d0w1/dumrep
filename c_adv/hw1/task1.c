#include "stdio.h"

int main (void)
{
    int num,a;
    int count = 1;
    int max = -2147483648;
    scanf("%d",&num);
    while(num)
    {
        scanf("%d",&a);
        if (a>max)
        {
            max=a;
            num--;
            continue;
        }
        if (a==max)
        {
            count++;
        }
        num--;
    }
    printf("%d",count);
    return 0;
}