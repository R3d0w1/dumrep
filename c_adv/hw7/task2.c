#include "stdio.h"
#include "stdlib.h"
typedef struct tree {
    int key;
    struct tree *left, *right;
} tree;
tree* insert(tree *p, int k);
void print_left(tree *p);
void print_right(tree *p);
void btUpView(tree *root);

int main(void)
{
    tree *a = insert(NULL,10);
    insert(a,5);
    insert(a,15);
    insert(a,3);
    insert(a,7);
    insert(a,1);
    insert(a,6);
    insert(a,13);
    insert(a,18);
    btUpView(a);
    return 0;
}
tree* insert(tree *p, int k) 
{
    if( p==NULL ) 
    {
        p=malloc(sizeof(tree));
        p->key=k;
        p->left = p->right=NULL;
        return p;
    }
    if( k < p->key )
        p->left = insert( p->left,k);
    else
        p->right = insert( p->right,k);
    return p;
}
void print_left(tree *p)        //recursive left side
{
    int a = p->key;   
    if(p->left)
    {
        p=p->left;
        print_left(p);
    }   
    printf("%d ",a);    
}
void print_right(tree *p)       //staight right side
{  
    while(p)
    {
        printf("%d ",p->key);
        p=p->right;
    }     
}
void btUpView(tree *root)       //both sides with root in the middle
{
    print_left(root->left);
    printf("%d ", root->key);
    print_right(root->right);
}