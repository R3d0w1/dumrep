#include "stdio.h"

void main ()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if ((a+b)<=c){printf("NO");return;}
    if ((a+c)<=b){printf("NO");return;}
    if ((c+b)<=a){printf("NO");return;}
    printf("YES");
}