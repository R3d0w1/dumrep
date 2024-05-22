#include "stdio.h"
#define SIZE 5
int mid_line(const int* array, int sz);
int main()
{
    int array[SIZE][SIZE];
    for (int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
    printf("%d",mid_line((int*)array,SIZE));

    return 0;
}
int mid_line(const int* array, int sz)
{ 
    int sum=0;
    for (int i=0;i<sz;i++)
    {
        sum+=*(array+i+i*SIZE);
    }
    return sum;
}