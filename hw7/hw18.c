#include "stdio.h"
void print_digits(int n);
int main ()
{
    int k;
    scanf("%d",&k);
    print_digits(k);
    return 0;
}
void print_digits(int n)
{
    int mid = n%10;
    if ((n/=10)==0)
    {
        printf("%d ", mid);
        return;
    }
    print_digits(n);
    printf("%d ", mid);
}