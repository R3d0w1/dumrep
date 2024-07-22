#include "stdio.h"
#define length 1000
void liner(char *string);
int main()
{
    FILE* f = fopen("input.txt","r");
    char buffer[length]={0};
    char c=0;
    fscanf(f,"%1000[^\n\r]", buffer);
    fclose(f);
    liner(buffer);
    return 0;
}
void liner(char *string)
{
    int k, alphabet[26]={0};
    for (int i=0;i<length;i++)
    {
        if (96<(k=(int)*(string+i))<123)
        {
            *(alphabet+k-97)+=1;
        }
    }
    for (int i=25;i>=0;i--)
    {
        if(*(alphabet+i)%2==1)
            {
                k=i+97;
                *(alphabet+i)-=1;
            }
    }
    FILE* f = fopen("output.txt","w");
    for (int i=0;i<26;i++)
    {
        int num = *(alphabet+i);
        num/=2;
        while(num--)
        {
            fputc((i+97),f);
        }
    }
    fputc(k,f);
    for (int i=25;i>=0;i--)
    {
        int num = *(alphabet+i);
        num/=2;
        while(num--)
        {
            fputc((i+97),f);
        }
    }
    fclose(f);
    return;
}