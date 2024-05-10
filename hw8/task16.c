#include "stdio.h"
#include "stdlib.h"
void search(int* arr, int* bl);
int main()
{
    int arr[10];
    int count_list[10];
    for (int i=0;i<10;i++)
    {
        scanf("%d",arr+i);
        count_list[i]=1;
    }
    search(arr, count_list);
    return 0;
}

void search(int* arr, int* bl) 
{
    for(int l=0; l<10; l++)
    {
        for(int k=l+1; k<10; k++)
        {
            if(arr[l]==arr[k])
            {
                bl[l]++;
            }
        }       
    }
    int number=1;
    int index=0;
    for(int l=0; l<10; l++)
    {
        if(number<bl[l])
        {
            number=bl[l];
            index=l;
        }
    }
    printf("%d",arr[index]);
}