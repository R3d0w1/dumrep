#include "stdio.h"
#define length 1000
void ispalindrom(char *string);
int main()
{
    FILE* f = fopen("input.txt","r");
    char buffer[length]={0};
    char c=0;
    fscanf(f,"%255[^\n\r]", buffer);
    fclose(f);
    ispalindrom(buffer);
    return 0;
}
void ispalindrom(char *string)
{
    int k, alphabet[26]={0};
    for (int i=0;i<length;i++)
    {
        if (96<(k=(int)*(string+i))<123)
        {
            *(alphabet+k-97)+=1;
        }
    }
    for (int i=0;i<26;i++)
    {
        *(alphabet+i)%=2;
    }
    k=0;
    for (int i=0;i<26;i++)
    {
        k+=*(alphabet+i);        
    }
    if(k==1)
    {
        printf("%s","YES");
    }
    else
    {
        printf("%s","NO");
    }
    return;
}