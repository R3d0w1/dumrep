#include "stdio.h"
#include "stdbool.h"
int main(void)
{
    int st[100];
    bool pool[900]={0};
    int n;
    for (n = 0; (st[n] = getchar()) != '\n'; n++);

        for (int i = 0; i < n - 2; ++i)
        {
            if (st[i]=='0') continue;
            for (int j = i + 1; j < n - 1; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    pool[((st[i] - '0') * 100 + (st[j] - '0') * 10 + (st[k] - '0'))-100] = true;
                }
            }
        }
    n=0;
    for (int v=0;v<900;v++)
    {
        n+=(int)pool[v];
    }
    printf("%d",n);

    return 0;
}
