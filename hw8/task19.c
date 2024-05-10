#include "stdio.h"
#include "stdlib.h"
#include "math.h"
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
        printf("%d ", arr[i]);
    }
    
    free(arr);
    return 0;
}

int length(int n) 
{
    int l;
    for(l=1; n/=10; l++);
    return l;
}