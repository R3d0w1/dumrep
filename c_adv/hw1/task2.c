#include "stdio.h"

int main (void)
{
    int N;
    char a=0;
    scanf("%d",&N);
    getchar();
    while(a!=46)
    {
        int shift=97;
        a=getchar();
        if ((a!=32)&&(a!=46))
        {
            if(a<97)
            {
                shift=65;
            }
            a=((a-shift)+N)%26+shift;
        }
        putchar(a);
    }
    return 0;
}