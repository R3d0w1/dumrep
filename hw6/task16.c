#include "stdio.h"
int is_prime(int c);
void main ()
{
    int a;
    scanf("%d", &a);
    
    
    if (is_prime(a) == 1)
    {
        printf("%s","YES");
    }
    else
    {
        printf("%s","NO");
    }
    return 0;
}

int is_prime(int c)
{
    if (c<2)
    {
        return 0;
    } 
    for (int i=2;i<c;i++)
    {
        if((c%i)==0)
        {
            return 0;
        }
    }
    return 1;    
}