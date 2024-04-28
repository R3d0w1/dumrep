#include "stdio.h"
int is_happy_number(int c);
void main ()
{
    int a;
    scanf("%d", &a);
    
    
    if (is_happy_number(a) == 1)
    {
        printf("%s","YES");
    }
    else
    {
        printf("%s","NO");
    }

    return 0;
}

int is_happy_number(int c)
{
    int sum=0;
    int mul=1;
        while (c>0)
            {
                sum+=c%10;
                mul*=c%10;
                c/=10;
            }
        if (mul==sum)
            {
                return 1;
            }
        return 0;
}