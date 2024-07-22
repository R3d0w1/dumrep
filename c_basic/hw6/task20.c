#include "stdio.h"
void checker(void);
int main ()
{
    checker();
    return 0;
}

void checker(void)
{
    int counter = 0;
    char a;
    while((a=getchar())!='.')
    {
        if (a=='(')
        {
            counter++;
        }
         if (a==')')
        {
            counter--;
        }
        if (counter < 0)
        {
            printf("%s","NO");
            return;
        }
    }
    if (counter == 0)
        printf("%s","YES");
        else
        printf("%s","NO"); 
}