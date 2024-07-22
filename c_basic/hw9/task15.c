/*#include "stdio.h"
#include "math.h"
#define SIZE 10
int count_bigger_abs(int n, int a[]);
int main()
{
    int array[SIZE];
    for (int i=0;i<SIZE;i++)
    {
        scanf("%d",array+i);
    }
    printf("%d",count_bigger_abs(SIZE, array));
    return 0;
}*/
int count_bigger_abs(int n, int a[])
{

    int top=a[0],result=0;
    for (int i=1;i<n;i++)
    {
        if(top<a[i])
        {
            top=a[i];
        }
    }
    for (int i=0;i<n;i++)
    {
        if(abs(a[i])>top)
        {
            result++;
        }
    }
    return result;
}