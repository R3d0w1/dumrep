#include "stdio.h"
#define length 1000
void wiper(char *string, int l);
int main()
{
    FILE* f = fopen("input.txt","r");
    char buffer[length]={0};
    char c=0;
    int l=0;
    while ((buffer[l]=fgetc(f))!=EOF)
    {
        l++;
    }
    buffer[l]=0;
    l--;
    fclose(f);
    wiper(buffer,l);
    f = fopen("output.txt","w");
    fputs(buffer,f);
    fclose(f);
    return 0;
}
void wiper(char *string, int l)
{
    int k;
   
    for (int i=0;i<l;i++)
    {
        if (*(string+i)==' ')
        {
           while (*(string+i+1)==' ')
           {
            for(int j=i;j<l;j++)
            {
                *(string+j)=*(string+j+1);
            }
            *(string+l)=0;
            l--;
           }
        }
    }

    if (*string == ' ')
    {
       for(int i=0;i<l;i++)
        {
            *(string+i)=*(string+i+1);
        }
        *(string+l)=0;
        l--;
    }
    return;
}