#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

enum visit{VISITED=1,NOVISITED};

typedef struct side
{
    int outnode;
    struct side *n;
}*sid;

struct vertex
{
    int node;
    enum visit flag;
    sid out;
};

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    struct vertex *p=NULL;
    p=(struct vertex *)calloc(n,sizeof(struct vertex));
    if(p==NULL)
    {
        exit(1);
    }
//    input vertex 
    for(i=0;i<n;i++)
    {
        scanf("%d",&( (p+i)->node ));
    }
    int in,out;
    sid save;
//    mount side 
    for(i=0;i<m;i++)
    {
        int tmp;
        save=(sid)calloc(1,sizeof(struct side));
        if(save==NULL)
        {
            exit(1);
        }
        scanf("%d%d",&in,&(save->outnode));
        for(tmp=0;tmp<n && (p+tmp)->node!=in;tmp++);
        if( (p+tmp)->out == NULL )
        {
            (p+tmp)->out=save;
        }
        else
        {
            sid p1;
            for(p1=(p+tmp)->out;p1->n!=NULL;p1=p1->n);
            p1->n=save;
        }
    }
//    search
    sid qin=NULL,qout=NULL,qtmp=NULL;
    int yes_or_no=0;
    scanf("%d%d",&in,&out);
    qtmp=(sid)calloc(1,sizeof(struct side));
    assert(qtmp);
    qtmp->outnode=in;
    qout=qin=qtmp;
    do
    {
        if(qout==NULL)
        {
            break;
        }
        for(i=0;i<n && (p+i)->node!=qout->outnode;i++);
        (p+i)->flag=VISITED;
//        in queue
        for(save=(p+i)->out;save!=NULL;save=save->n)
        {
            in=save->outnode;
            for(i=0;i<n && (p+i)->node!=in;i++);
            if( (p+i)->flag == VISITED )
            {
                continue;
            }
            qtmp=(sid)calloc(1,sizeof(struct side));
            assert(qtmp);
            qtmp->outnode=save->outnode;
            qin->n=qtmp;
            qin=qin->n;
        }
//        out queue
        in=qout->outnode;
        qtmp=qout;
        qout=qout->n;
        free(qtmp);
        if(in==out)
        {
            printf("yes\n");
            yes_or_no=1;
            break;
        }
    }while(1);
    if(yes_or_no==0)
    {
        printf("no\n");
    }
    return 0;
}
