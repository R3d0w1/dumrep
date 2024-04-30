#include "stdio.h"
int acounter(void);
int main ()
{
    printf("%d", acounter());
    return 0;
}
int acounter(void)
{

    char c = getchar();
    if (c=='a') 
    {
        return acounter()+1;
    }
    if (c=='.') 
    {
        return 0;
    }
    else 
    return acounter();
}