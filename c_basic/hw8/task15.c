#include "stdio.h"
#include "stdlib.h"
void sort(int* arr, int* pos, int* neg);
int main()
{
    int arr[10];
    int pos[10];
    int neg[10];
    for (int i=0;i<10;i++)
    {
        scanf("%d",arr+i);
    }
    sort(arr,pos,neg);
    return 0;
}

void sort(int* arr, int* pos, int* neg) 
{
    int pos_num=0;
    int neg_num=0;
    for(int i=0; i<10; i++)
    {
        if (arr[i]>0)
        {
            pos[pos_num]=arr[i];
            pos_num++;
        }
        if (arr[i]<0)
        {
            neg[neg_num]=arr[i];
            neg_num++;
        }
    }

    for(int i=0; i<pos_num; i++)
    {
       printf("%d ",pos[i]);
    }
    for(int i=0; i<neg_num; i++)
    {
       printf("%d ",neg[i]);
    }
}