#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    char da;
    struct tree *lc,*rc;
}*ptr;

ptr create_tree(void)
{
    ptr root=NULL;
    char c;
    c=getchar();
    switch(c)
    {
        case '\n':
            exit(1);
            break;
        case '#':
            return root;
        default:
            root=(ptr)calloc(1,sizeof(struct tree));
            if(root==NULL)
            {
                exit(1);
            }
            root->da=c;
            root->lc=create_tree();
            root->rc=create_tree();
            return root;
    }
}

int traverse(ptr root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+traverse(root->lc)+traverse(root->rc);
}

int TRAVERSE(ptr root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->lc==NULL && root->rc==NULL)
    {
        return 1;
    }
    return TRAVERSE(root->lc)+TRAVERSE(root->rc);
}

void PRINT(ptr root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        printf("*%c*",root->da);
        PRINT(root->lc);
        PRINT(root->rc);
    }
    return ;
}

int main()
{
    ptr root=NULL;
    root=create_tree();
    printf("%d\n",TRAVERSE(root));
//    printf("%d\n",traverse(root));
//    PRINT(root);
    return 0;
}
