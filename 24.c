#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct tree
{
    int n;
    struct tree *lc,*rc;
}*tr;

tr input(void)
{
    tr root=NULL;
    int a;
    scanf("%d",&a);
    if(a==-1)
        return root;
    root=(tr)calloc(1,sizeof(struct tree));
    assert(root);
    root->n=a;
    root->lc=input();
    root->rc=input();
    return root;
}

int test(tr root)
{
    if( root == NULL )
        return 0;
    if( root->lc != NULL && root->lc->n > root->n )
        return 1;
    if( root->rc != NULL && root->rc->n < root->n )
        return 1;
    return test(root->lc)+test(root->rc);
}

int main()
{
    if( test(input()) == 0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}
