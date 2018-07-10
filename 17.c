#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    char da;
    struct tree *lc,*rc;
}*node;

node traverse_input(void)
{
    node root=NULL;
    char c;
    c=getchar();
    if(c!='#')
    {
        root=(node)calloc(1,sizeof(struct tree));
        if(root==NULL)
        {
            exit(1);
        }
        root->da=c;
        root->lc=traverse_input();
        root->rc=traverse_input();
    }
    return root;
}

void traverse_output(node root)
{
    if(root==NULL)
    {
        return ;
    }
    traverse_output(root->lc);
    putchar(root->da);
    traverse_output(root->rc);
}

int main()
{
    node root=NULL;
    root=traverse_input();
    traverse_output(root);
    return 0;
}
