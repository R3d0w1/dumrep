#include "stdio.h"
void convert();
int main()
{
    FILE *f;
    char input_word[20]={0};
    char coded_word[20];
    for (int i=1;i<20;i++){coded_word[i]='0';}
    f = fopen("input.txt","r");
    fscanf(f,"%s", input_word);
    fclose(f);
    convert(input_word,coded_word);
    f = fopen("output.txt","w");
    for (int i=0;i<4;i++)
    {
        int l = fputc(coded_word[i],f);
    }
    fclose(f);
    return 0;
}
void convert(char* input, char* output)
{
    int c=1;
    char k=0;
    *output=*input;
    for (int i=1;i<20;i++)
    {
        if(k&&((*(output+(c-1))/*coded_word[c-1]*/)!=k))
        {
            *(output+(c))/*coded_word[c]*/=k;
            c++;
        }
        k=0;
        switch (*(input+i)/*input_word[i]*/)
        {
            case 'b':
            case 'f':
            case 'p':
            case 'v':
                k='1';
                continue;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z':
                k='2';
                continue;         
            case 'd':
            case 't':
                k='3';
                continue;
            case 'l':
                k='4';
                continue;
            case 'm':
            case 'n':
                k='5';
                continue;
            case 'r':
                k='6';
                continue;
            case 0:
                break;
        }
    }
}