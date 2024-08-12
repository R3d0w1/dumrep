#include "stdio.h"
#include <string.h>
#define LENGTH 104

int pref_suff(char* st1, char* st2, int st1len, int st2len);
int keep_check(char* st1, char* st2, int j, int limit);

int main(void)
{
    char st1[LENGTH]={0};
    char st2[LENGTH]={0};
    fgets(st1,LENGTH,stdin);
    fgets(st2,LENGTH,stdin);
    int a = pref_suff(st1,st2,strlen(st1)-1,strlen(st2)-1);
    int b = pref_suff(st2,st1,strlen(st2)-1,strlen(st1)-1);
    printf("%d %d",a,b);
    return 0;
} 


int pref_suff(char* st1, char* st2, int st1len, int st2len)
{
    int res;            
    for (int j = 0;j<st2len;j++)
    {
        if(res=keep_check(st1,st2,j,st2len))
            return res;
    }
    return 0;
}
int keep_check(char* st1, char* st2, int j, int limit)
{
    int i = 0;
    int counter = 0;
    while (st1[i]==st2[j])
        {
            i++;
            j++;
            counter++;
            if(j==limit)
                return counter;
        }
    return 0;
}