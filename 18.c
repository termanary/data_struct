#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100

typedef struct tree
{
    char da;
    struct tree *lc,*rc;
}*node;

node create_tree(char pr[],char in[],int n)
{
    node root=NULL;
    root=(node)calloc(1,sizeof(struct tree));
    if(root==NULL)
    {
        exit(1);
    }
    root->da=pr[0];
    int i;
    for(i=0;i<n;i++)
    {
        if(in[i]==pr[0])
        {
            break;
        }
    }
    if(i==n)
    {
        exit(1);
    }
    if(i!=0)
    {
        root->lc=create_tree(pr+1,in,i);
    }
    if(i!=n-1)
    {
        i++;
        root->rc=create_tree(pr+i,in+i,n-i);
    }
    return root;
}

void traverse_post(node root)
{
    if(root==NULL)
    {
        return ;
    }
    traverse_post(root->lc);
    traverse_post(root->rc);
    putchar(root->da);
    return ;
}

int main()
{
    char pr[N],in[N];
    gets(pr);
    gets(in);
    if(strlen(pr)>N || strlen(in)>N || strlen(pr)!=strlen(in))
    {
        exit(1);
    }
    node root;
    root=create_tree(pr,in,strlen(pr));
    traverse_post(root);
    return 0;
}
