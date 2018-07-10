#include<stdio.h>
#include<stdlib.h>

enum visit{VISITED=1,UNVISITED};

typedef struct side
{
    int out;
    struct side *n;
}*sd;

struct vertex
{
    int node;
    enum visit flag;
    sd outo;
};

int search(struct vertex *p,int in,int out,int n)
{
    sd save;
    int tmp;
    for(tmp=0; tmp<n && in!=(p+tmp)->node ;tmp++);
    if( (p+tmp)->flag==VISITED )
    {
        return 0;
    }
    for(save=(p+tmp)->outo,(p+tmp)->flag=VISITED;save!=NULL;save=save->n)
    {
        if(save->out==out)
        {
            return 1;
        }
        else
        {
            if(search(p,save->out,out,n)==1)
            {
                return 1;
            }
            
        }
    }
    return 0;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    struct vertex *p=NULL;
    p=(struct vertex *)calloc(n,sizeof(struct vertex));
    if(p==NULL)
    {
        exit(1);
    }
    int i;
//    scanf vertex
    for(i=0;i<n;i++)
    {
        scanf("%d",&( (p+i)->node ));
    }
//    scanf side 
    int in,out,tmp;
    sd sp,save;
    for(i=0;i<m;i++)
    {
        sp=(sd)calloc(1,sizeof(struct side));
        if(sp==NULL)
        {
            exit(1);
        }
        scanf("%d%d",&in,&(sp->out));
        for(tmp=0; tmp<n && in!=(p+tmp)->node ;tmp++);
        if( (p+tmp)->outo==NULL )
        {
            (p+tmp)->outo=sp;
        }
        else
        {
            for(save=(p+tmp)->outo;save->n!=NULL;save=save->n);
            save->n=sp;
        }
    }
    scanf("%d%d",&in,&out);
//    search
    if(search(p,in,out,n)==0)
    {
        printf("no\n");
    }
    else
    {
        printf("yes\n");
    }
    return 0;
}
