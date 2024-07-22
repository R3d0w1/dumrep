#include "stdio.h"
void convert_odd(int* number);
void convert_even(int* number);
int main()
{
    int array[10];
    int s=0;
    for (int i=0;i<10;i++)
    {
        scanf("%d",array+i);
        if(array[i]%2==0) s++;
        else s--;
    }
    if (s>0)
    {
        for (int i=0;i<10;i++)
        {
            convert_odd(array+i);
            printf("%d ", array[i]);
        }
    }
    else
    {
        for (int i=0;i<10;i++)
        {
            convert_even(array+i);
            printf("%d ", array[i]);
        }
    }
    return 0;
}
void convert_odd(int* number)
{
    int num = *number;
    if (num%2!=0)
    {
        int n=1,k;
        while(num>1)
        {
            if((k=num%10)%2!=0)
            {
                n*=k;
            }
            num/=10;
        }
        *number=n;
    }
}
void convert_even(int* number)
{
    int num = *number;
    if (num%2==0)
    {
        int n=1,k;
        while(num>1)
        {
            if((k=num%10)%2==0)
            {
                n*=k;
            }
            num/=10;
        }
        *number=n;
    }
}