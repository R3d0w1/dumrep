#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define WORD_LENGTH 20
typedef struct list {
   char word[WORD_LENGTH];
   struct list *next;
 } list;
void word_copy(char * dst,char * src, int size);
void add_to_end(list *head, char* word);
void clear_buffer(char * buffer);
void print_list (list * head);
void swap_elements(list * element);
void sort_list(list * head);
void read_to_struct(list * head);
void remove_list (list * head);

int main(void)
{
    list* L = calloc(1,sizeof(list));
    read_to_struct(L);
    sort_list(L);
    print_list(L);
    remove_list(L);
    return 0;
}
void print_list (list * head)
{
    list *p = head->next;
    while (p)
    {
        printf("%s ", p->word);
        p=p->next;
    }
}
void add_to_end(list *head, char* word)
{
    struct list *new = calloc(1, sizeof(list));
    word_copy(new->word, word, WORD_LENGTH);
    struct list *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = new;
}
void word_copy(char * dst, char * src, int size)
{
    while ( size-- )
        *dst++ = *src++;
}
void clear_buffer(char * buffer)
{
    int i = WORD_LENGTH;
    while(i--)
        buffer[i]=0;
}
void swap_elements(list * element)
{
    int counter=0;
    list *c = element;
    list *p = c->next;  //   the swapped
    list *e = p->next;  //   ones
    p->next = e->next;
    c->next = e;
    e->next = p;
}
void sort_list(list * head)
{
    list *first = head;
    int counter = 0;
    int a;
    int flag = 1;
    while(flag == 1)
    {
        flag = 0;
        while (first->next->next->word)      // untill pointer to the last of the two compared elements points out of bounds
        {
            a = strcmp(first->next->word, first->next->next->word);  
            if (a>0)
            {
                swap_elements(first);
                flag=1;         // indicator for at least one more lap
            }
            first = first->next;
        }
        first = head;
    }
}
void read_to_struct(list * head)
{
    char buffer[20];
    char a;
    int i=0;
    clear_buffer(buffer);
    while((a = getchar()) != '\n')
    {
        if((a != ' ')&&(a != '.'))
        {
            buffer[i] = a;
            i++;
        }
        else
        {
            add_to_end(head,buffer);
            clear_buffer(buffer);
            i=0;
        }
    }
}
void remove_list (list * head)
{
    struct list *p = head;
    struct list *a;
    while (p != NULL)
    {
        a = p;
        p = p->next;
        free(a);
    }
}