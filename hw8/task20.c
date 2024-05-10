#include "stdio.h"
#include "stdlib.h"
#include "math.h"
void sort_arr(int* arr,int length);
int length(int n);
int main()
{
    int target,l;
    scanf("%d",&target);
    l=length(target);
    int* arr = (int*)calloc(l,sizeof(int));
    for(int i=0;i<l;i++)
    { 
        arr[i]=(target/((int)pow(10,(l-i-1))))%10;
        //printf("%d ", arr[i]);
    }
    sort_arr(arr,l);
    for(int i=0;i<l;i++)
    { 
        printf("%d", arr[i]);
    }


    free(arr);
    return 0;
}
void sort_arr(int* arr, int length)
{
    int bubble;
    for (int i=1;i<length;i++)
    {
         for (int k=1;k<length;k++)
         {
            if (arr[k]>arr[k-1])
            {
                bubble=arr[k-1];
                arr[k-1]=arr[k];
                arr[k]=bubble;
            }
         }
    }
}
int length(int n) 
{
    int l;
    for(l=1; n/=10; l++);
    return l;
}