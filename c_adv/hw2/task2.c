/*#include "stdio.h"


typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;
size_t totalMemoryUsage(list *head);


int main (void)
{
    int a,b,c,d,e,f;
    list ex6={&a,5000,"text1",NULL};
    list ex5={&b,30,"text1",&ex6};
    list ex4={&c,400,"text1",&ex5};
    list ex3={&d,30,"text1",&ex4};
    list ex2={&e,20,"text1",&ex3};
    list ex1={&f,100,"text1",&ex2};
    printf("%d\n",totalMemoryUsage(&ex1));
    return 0;
}
*/
size_t totalMemoryUsage(list *head)
{
    if(head->next==NULL)
    {
        return 0;
    }
    size_t total_size=0;

    while(head)
    {
        total_size+=head->size;
        head=head->next;
    }
    return total_size;
}

 