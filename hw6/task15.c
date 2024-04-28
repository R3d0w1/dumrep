#include "stdio.h"
int grow_up(int c);
void main ()
{
    int a;
    scanf("%d", &a);
    if (grow_up(a) == 1)
    {
        printf("%s","YES");
    }
    else
    {
        printf("%s","NO");
    }
    return 0;
}
int grow_up(int c)
{
    int k=9;
    while (c>0)
            {
                if(k<=(c%10))
                    {
                        return 0;
                    }
                k=c%10;
                c/=10;
            }
    return 1;
}