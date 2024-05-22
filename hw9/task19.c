#include "stdio.h"
int mid_line(const int* array);
int count_above_mid(const int* array, int mid);
int main()
{
    int array[5][5];
    for (int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
    printf("%d",count_above_mid(array,mid_line(array)));

    return 0;
}
int mid_line(const int* array)
{ 
    int sum=0;
    for (int i=0;i<5;i++)
    {
        sum+=*(array+i+i*5);
    }
    return sum/5;
}
int count_above_mid(const int* array, int mid)
{
    int c=0;
    for (int i=0;i<5;i++)
    {
         for(int j=0;j<5;j++)
        {
             if((*(array+j+i*5))>mid) c++;
        }
    }
    return c;
}