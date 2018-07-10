#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct tree
{
    int d;
    struct tree *lc,*rc;
}*sort;

sort create_tree(void)
{
    int a;
    sort root=NULL;
    scanf("%d",&a);
    if(a==-1)
        return root;
    root=(sort)calloc(1,sizeof(struct tree));
    assert(root);
    root->d=a;
    root->lc=create_tree();
    root->rc=create_tree();
    return root;
}

void add(sort root,int d)
{
    if(root==NULL)
        return ;
    if(root->d==d)
        ;
    else
    {
        if(d < root->d)
        {
            if(root->lc != NULL)
                add(root->lc,d);
            else
            {
                root->lc=(sort)calloc(1,sizeof(struct tree));
                assert(root->lc);
                root->lc->d=d;
            }
        }
        else
        {
            if(root->rc != NULL)
                add(root->rc,d);
            else
            {
                root->rc=(sort)calloc(1,sizeof(struct tree));
                assert(root->rc);
                root->rc->d=d;
            }
        }
    }
    return ;
}

void traverse(sort r1,sort r2,int flag)
{
    if(r1==NULL)
        return ;
    traverse(r1->lc,r2,flag);
    switch(flag)
    {
        case 0:
            printf("%d ",r1->d);
            break;
        case 1:
            add(r2,r1->d);
//    traverse(r2,NULL,0);
//    printf("\n");
            break;
        default:
            exit(1);
    }
    traverse(r1->rc,r2,flag);
    return ;
}

int main()
{
    sort r1,r2;
    r1=create_tree();
//    traverse(r1,NULL,0);
//    printf("\n");
    r2=create_tree();
//    traverse(r2,NULL,0);
//    printf("\n");
    traverse(r1,r2,1);
    traverse(r2,NULL,0);
    printf("\n");
    return 0;
}
