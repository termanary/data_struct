#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    char da;
    struct tree *lc,*rc;
}*node;

char ba='\0',fa='\0';

node create_tree(void)
{
    node root=NULL;
    while(1)
    {
        ba=fa;
        if(ba!='\n')
        {
            fa=getchar();
        }
        else
        {
            fa='\0';
        }
//        putchar(fa);
        switch(ba)
        {
            case '\n':case '\0':
                return root;
            case '(':
                root->lc=create_tree();
                break;
            case ',':
                root->rc=create_tree();
                break;
            case ')':
                return root;
            default:
                root=(node)calloc(1,sizeof(struct tree));
                if(root==NULL)
                {
                    exit(1);
                }
                root->da=ba;
//            case '#':
                if(fa==',' || fa==')')
                {
                    return root;
                }
                break;
        }
    }
}

void traverse(node root)
{
    if(root==NULL)
    {
        return ;
    }
    putchar(root->da);
    traverse(root->lc);
    traverse(root->rc);
    return ;
}

int main()
{
    node root;
    fa=getchar();
    root=create_tree();
    traverse(root);
    return 0;
}
