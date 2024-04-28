#include "stdio.h"
int digit_to_num(char c);
int main ()
{
    int sum = 0;
    char a;
    while((a=getchar())!='.')
    {
        sum+=digit_to_num(a);
    }
    printf("%d ",sum);

    return 0;
}

int digit_to_num(char c)
{
    int k=0;
    if ((c>47)&&(c<58))
        {
            k=(int)(c-48);
        }

    /* char line[100];
    scanf("%100[^.]",line);
    for (int i=0; i<100; i++)
    {
        if ((line[i]>47)&&(line[i]<58))
        {
            sum+=(int)line[i];
            sum-=48;
        }

        //putchar(line[i]);
    }*/
    return k;
}