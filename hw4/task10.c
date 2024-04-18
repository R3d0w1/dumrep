#include "stdio.h"

void main ()
{
    int a;
    scanf("%d",&a);
    switch (a%12)
    {
        case 0 ... 2:
        printf("winter");
        return;
        case 3 ... 5:
        printf("spring");
        return;
        case 6 ... 8:
        printf("summer");
        return;
        case 9 ... 11:
        printf("autumn");
        return;
    }
}