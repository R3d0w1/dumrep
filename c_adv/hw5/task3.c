#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 1000
#define MAX_NUM_SIZE 100
int st[MAX_STACK_SIZE];
int pst=0;
void push(int v);
int pop();
void operate(char c);

int main(void)
{
    char c;
    char num_buffer[MAX_NUM_SIZE];
    printf("Input inverse string: ");
    while(1)
    {
        c=getchar();
        if((c>='0')&&(c<='9'))
        {
            for (int i=0;i<MAX_NUM_SIZE;i++)
            {
                num_buffer[i]=0;
            }
            num_buffer[0]=c;
            for (int i=1;(c=getchar())!=' ';i++)
            {
                num_buffer[i]=c;
            }
            push(atoi(num_buffer));
        }
        else if((c=='+')||(c=='-')||(c=='*')||(c=='/'))
            operate(c);
        else if(c=='.')
            break;
    }
    printf("%d\n",pop());
    return 0;
}


void push(int v)
{
    st[pst++]=v;
}
int pop()
{
    if(pst<=0) 
    {
        fprintf(stderr, "Error. Stack underflow");
        return 1;
    } else if(pst>MAX_STACK_SIZE) 
    {
        fprintf(stderr, "Error. Stack overflow");
        return 1;
    }
    return st[--pst];
}

void operate(char c)
{
    int arg1=pop(),arg2=pop();
    if (c=='+') push(arg1+arg2);
    else if (c=='-') push(arg1-arg2);
    else if (c=='*') push(arg1*arg2);
    else if (c=='/') push(arg2/arg1);
}
