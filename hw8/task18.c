#include "stdio.h"
#include "stdlib.h"
void search(int* arr, int* blr);
int main()
{
    int arr[10];
    int ban_list[5];
    for (int i=0;i<10;i++)
    {
        scanf("%d",arr+i);
    }
    search(arr, ban_list);
    return 0;
}

void search(int* arr, int* bl) 
{
    int counter=0;
    for(int l=0; l<10; l++)
    {
        for(int k=l+1; k<10; k++)
        {
            if(arr[l]==arr[k])
            {
                bl[counter]=arr[l];
                counter++;
                break;
            }
        }       
    }
    for(int l=0; l<10; l++)
    {
        int marker=1;
        for(int k=0; k<counter; k++)
        {
           if (arr[l]==bl[k]) marker=0;
        }
        if (marker) printf("%d ", arr[l]);
    }
}