#include "stdio.h"
int counter();
void builder(int row_number);
int checker(int number);
int main()
{
    builder(checker(counter()));
    return 0;
}
int counter()
{
    FILE* f = fopen("input.txt","r");
    int character,counter=0;
    while ((character=fgetc(f))!=EOF)
    {
        if (character == 42)
        {
            counter++;
        }
    }
    fclose(f);
    return counter;
}
int checker(int number)
{
    for (int i=3,c=3;i<1000;i+=(c++))
    {
        if (number == i)
        return c-1;
    }
        return 0;
}
void builder(int row_number)
{
    FILE* f = fopen("output.txt","w");
    if(row_number==0)
    {
        fputs("NO",f);
        fclose(f);
        return;
    }
    for (int j = 0;j<row_number;j++)
    {
        for (int i = row_number-j-1;i>0;i--)
            {
                fputc(32,f);
            }
        for (int i = j;i>0;i--)
            {
                fputc(42,f);
                fputc(32,f);
            }
        fputc(42,f);
        fputc(10,f);
    }
    fclose(f);
}