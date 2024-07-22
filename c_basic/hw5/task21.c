#include "stdio.h"

void main ()
{
    
    char line[100];
    scanf("%100[^.]",line);
    for (int i=0; i<100; i++)
    {
        if ((line[i]>64)&&(line[i]<91))
        {
            line[i]+=32;
        }

        //putchar(line[i]);
    }
    printf ("%s", line);
}