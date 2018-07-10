#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef struct dijkstra
{
    int d,in;
    struct dijkstra *n;
}*dj;

int main()
{
    int i,j,n,m,*a;
    dj p,tmp,sa;
    scanf("%d%d",&n,&m);

//    input
    p=(dj)calloc(n+1,sizeof(struct dijkstra));
    assert(p);
    for(j=0;j<m;j++)
    {
        sa=(dj)calloc(1,sizeof(struct dijkstra));
        assert(sa);
        scanf("%d%d%d",&i,&sa->d,&sa->in);
        for(tmp=p+i;tmp->n!=NULL;tmp=tmp->n);
        tmp->n=sa;
//        sa->n=p[i].n;
//        p[i].n=sa;
    }

    a=(int*)calloc(n+1,sizeof(int));
    assert(a);
    memset(a,0xff,(n+1)*sizeof(int));

//    dijkstra
    for(i=1;i<n;i++)
    {
//        find
        for(tmp=p+1,sa=p+1;tmp->n!=NULL;tmp=tmp->n)
        {
            if(sa->n->in > tmp->n->in)
                sa=tmp;
        }
        if(sa->n==NULL)
        {
//            printf("break;");
            break;
        }

//        in
        printf("%d %d %d\n",1,sa->n->d,sa->n->in);
        j=sa->n->d;
        a[j]=sa->n->in;
        tmp=sa->n->n;
        free(sa->n);
        sa->n=tmp;

//        adjust
        for(tmp=p[j].n;tmp!=NULL;tmp=tmp->n)
        {
            if(tmp->d==1)
                continue;
            if(a[tmp->d]!=-1)
                continue;
            for(sa=p[1].n; sa!=NULL && sa->d!=tmp->d ;sa=sa->n);
            if(sa!=NULL)
            {
                sa->in=sa->in>tmp->in+a[j]?tmp->in+a[j]:sa->in;
            }
            else
            {
//                printf("%d %d %dcalloc\n",1,tmp->d,tmp->in+a[j]);
                sa=(dj)calloc(1,sizeof(struct dijkstra));
                assert(sa);
                sa->d=tmp->d;
                sa->in=tmp->in+a[j];
                sa->n=p[1].n;
                p[1].n=sa;
            }
        }

    }

//    otherwise
    for(i=2;i<=n;i++)
    {
        if(a[i]==-1)
        {
            printf("%d %d %d\n",1,i,a[i]);
        }
    }

    return 0;
}
