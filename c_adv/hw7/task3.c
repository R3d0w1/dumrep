#include "stdio.h"
#include "stdlib.h"
typedef struct tree {
    int key;
    struct tree *left, *right;
    struct tree *parent; 
} tree;

tree* preorder(tree *root, int brother);
tree* insert(tree *p, int k, tree* dad);
tree* find_sibling(tree* brother);
tree* find_brother(tree *root, int key);

int main(void)
{
    tree *a = insert(NULL,10,NULL);
    insert(a,5,NULL);
    insert(a,15,NULL);
    insert(a,3,NULL);
    insert(a,7,NULL);
    insert(a,1,NULL);
    insert(a,6,NULL);
    insert(a,13,NULL);
    insert(a,18,NULL);
    tree* traget = find_brother(a,3);
    return 0;
}
tree* insert(tree *p, int k, tree* dad) 
{
    if( p==NULL ) 
    {
        p=malloc(sizeof(tree));
        p->key=k;
        p->parent = dad;
        p->left = p->right=NULL;
        return p;
    }
    if( k < p->key )
        p->left = insert(p->left,k,p);
    else
        p->right = insert(p->right,k,p);
    return p;
}
tree* preorder(tree *root, int brother) //searching for the value specified
{
    tree* result = 0;
    if(root->key == brother)
        return root;
    if(root->left)
        result = preorder(root->left, brother);
    if(result)
        return result;
    if(root->right)
        result = preorder(root->right, brother);

    return result;
}
tree* find_sibling(tree* brother)       //finding neighbor's address
{
    if (brother->parent->left == brother)
        return brother->parent->right;
    else
        return brother->parent->left;
}
tree* find_brother(tree *root, int key) //both of the above, combined
{
    tree *target = preorder(root,key);
    return find_sibling(target);
}