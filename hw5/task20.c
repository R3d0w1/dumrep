#include "stdio.h"

void main ()
{
    int a;
    scanf("%d",&a);
    if (a == 1)
        {
            printf ("%s", "NO");
            return;
        }
    for (int i=2; i<a; i++)
    {
        if (a%i == 0)
        {
            printf ("%s", "NO");
            return;
        }
    }
    printf ("%s", "YES");
}