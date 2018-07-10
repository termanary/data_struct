#include<stdio.h>
#include<stdlib.h>

struct data
{
    int na,*a,ia;
    int nb,*b,ib;
    int nc,*c,ic;
};

void input(struct data *p);
void get_for(int **p,int m);
void count(struct data *p);
int find(int f,int *p,int *nu,int ip);
void del(int m,int *p,int *np);

int main()
{
    struct data cacual={0};
    input(&cacual);
    count(&cacual);
    int i,m;
    for(i=0,m=cacual.na;i<m;i++)
    {
        printf("%d ",cacual.a[i]);
    }
    printf("\n");
    free(cacual.a);
    free(cacual.b);
    free(cacual.c);
    return 0;
}

void input(struct data *p)
{
    scanf("%d%d%d",&p->na,&p->nb,&p->nc);
    get_for(&p->a,p->na);
    get_for(&p->b,p->nb);
    get_for(&p->c,p->nc);
    return ;
}

void get_for(int **p,int m)
{
    int i;
    *p=(int *)calloc(m,sizeof(int));
    if(*p==NULL)
        exit(0);
    for(i=0;i<m;i++)
    {
        scanf("%d",*p+i);
    }
    return ;
}

void count(struct data *p)
{
    int i,m;
    for(i=0;i<p->nb;i++)
    {
        if(find(p->b[i],p->c,&p->ic,p->nc)!=-1)
        {
            for(;;)
            {
                m=find(p->b[i],p->a,&p->ia,p->na);
                if(m!=-1)
                {
                    del(m,p->a,&p->na);
                }
                else
                {
                    break;
                }
            }
        }
    }
    return ;
}


int find(int f,int *p,int *nu,int ip)
{
    int i;
    for(i=*nu;i<ip;i++)
    {
        if(f==p[i])
        {
            *nu=i;
            return i;
        }
    }
    return -1;
}

void del(int m,int *p,int *np)
{
    int i;
    (*np)--;
    for(i=m;i<*np;i++)
    {
        p[i]=p[i+1];
    }
    return ;
}


