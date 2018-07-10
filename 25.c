#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct tree
{
    int d,fre;
    struct tree *lc,*rc,*n;
}*sort;

sort input(void)
{
    sort root=NULL;
    int in;
    scanf("%d",&in);
    if(in==-1)
        return root;
    root=(sort)calloc(1,sizeof(struct tree));
    root->d=in;
    root->lc=input();
    root->rc=input();
    return root;
}

sort pre=NULL;

void traverse_inorder(sort root)
{
    if(root==NULL)
        return ;
    traverse_inorder(root->lc);
    if(pre!=NULL)
        pre->n=root;
    pre=root;
    traverse_inorder(root->rc);
    return ;
}

int a,b;

sort find(sort root)
{
    if(root==NULL)
        return root;
    if(a==root->d)
        return root->n;
    if(a<root->d)
    {
        if(root->lc==NULL)
        {
            return root;
        }
        else
        {
            return find(root->lc);
        }
    }
    if(a>root->d)
    {
        if(root->rc==NULL)
        {
            return root->n;
        }
        else
        {
            return find(root->rc);
        }
    }
}

sort insert(sort root)
{
    if(root==NULL)
    {
        root=(sort)calloc(1,sizeof(struct tree));
        assert(root);
        root->d=a;
        return root;
    }
    if(a==root->d)
    {
        root->fre++;
        return root;
    }
    if(a<root->d)
        root->lc=insert(root->lc);
    else
        root->rc=insert(root->rc);
    return root;
}

void traverse_print(sort root)
{
    int i;
    if(root==NULL)
        return ;
    traverse_print(root->lc);
    for(i=0;i<root->fre+1;i++)
    {
        printf("%d",root->d);
        if(i<root->fre)
            printf(" ");
    }
    if(root->n!=NULL)
        printf(" ");
    traverse_print(root->rc);
    return ;
}

sort del(sort root)
{
    if(root==NULL)
        return root;
    sort tmp;
    if(a==root->d)
    {
        if(root->fre>0)
        {
            root->fre--;
            return root;
        }
        if(root->lc==NULL && root->rc==NULL)
        {
            free(root);
            root=NULL;
        }
        else
        {
            if(root->lc==NULL || root->rc==NULL)
            {
                tmp=root->lc!=NULL?root->lc:root->rc;
                free(root);
                root=tmp;
            }
            else
            {
                root->d=root->n->d;
                a=root->n->d;
                root->rc=del(root->rc);
            }
        }
        return root;
    }
    if(a<root->d)
        root->lc=del(root->lc);
    else
        root->rc=del(root->rc);
    return root;
}

void search(sort root)
{
    if(root==NULL)
        return ;
    search(root->lc);
    if( a < root->d && root->d < b)
        printf("%d ",root->d);
    search(root->rc);
    return ;
}

int main()
{
    sort root=NULL,tmp;

    root=input();
    pre=NULL;
    traverse_inorder(root);
    if(pre!=NULL)
        pre->n=NULL;
    pre=NULL;

    scanf("%d%d",&a,&b);
//    next line:a better solution
//    search(root);
    tmp=find(root);
    if( tmp!=NULL && tmp->d < b )
    {
        while(1)
        {
            printf("%d",tmp->d);
            tmp=tmp->n;
            if(tmp!=NULL && tmp->d < b)
                printf(" ");
            else
                break;
        }
    }
    printf("\n");

    scanf("%d",&a);
    root=insert(root);
    pre=NULL;
    traverse_inorder(root); 
    if(pre!=NULL)
        pre->n=NULL;
    pre=NULL;
    traverse_print(root);
    printf("\n");

    root=del(root);
    pre=NULL;
    traverse_inorder(root); 
    if(pre!=NULL)
        pre->n=NULL;
    pre=NULL;

    scanf("%d",&a);
    pre=NULL;
    root=del(root);
    traverse_inorder(root); 
    if(pre!=NULL)
        pre->n=NULL;
    pre=NULL;
    traverse_print(root);
    printf("\n");

    return 0;
}

