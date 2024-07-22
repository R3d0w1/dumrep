#include "stdio.h"
#define SIZE 10
int max_in_line(const int* line, int length);
int main()
{
    int result=0;
    int array[SIZE][SIZE];
    for (int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            scanf("%d",&array[i][j]);
        }
        result+=max_in_line(&array[i][0], SIZE);
    }
    printf("%d",result);

    return 0;
}
int max_in_line(const int* line, int length)
{
    int most = *line;
     for (int i=0;i<length;i++)
    {
        if (*(line+i)>most) most=*(line+i);
    }
    return most;
}