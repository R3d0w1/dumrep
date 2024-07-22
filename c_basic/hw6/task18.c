#include "stdio.h"
int is_digit(char c);
int main ()
{
    int sum = 0;
    char a;
    while((a=getchar())!='.')
    {
        sum+=is_digit(a);
    }
    printf("%d ",sum);
    return 0;
}

int is_digit(char c)
{
    if ((c>47)&&(c<58))
        {
            return 1;
        }
    return 0;
}