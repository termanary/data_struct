#include<stdio.h>
#include<stdlib.h>

typedef struct matrix
{
    int ra,co,da;
    struct matrix *rn,*cn;
}*node;

node input(int m,int n,int t1)
{
    node p;
    p=(node)calloc((m>n?m:n)+1,sizeof(struct matrix));
    if(p==NULL)
    {
        exit(1);
    }
    p[0].ra=m;
    p[0].co=n;
    int i;
    node tmp;
    for(i=0;i<t1;i++)
    {
        tmp=(node)calloc(1,sizeof(struct matrix));
        if(tmp==NULL)
        {
            exit(1);
        }
        scanf("%d%d%d",&tmp->ra,&tmp->co,&tmp->da);
//        printf("%d-%d-%d-\n",tmp->ra,tmp->co,tmp->da);
//        insert to raw
        node save;
        save=p+tmp->ra;
        while( save->rn!=NULL && save->rn->co < tmp->co )save=save->rn;
        tmp->rn=save->rn;
        save->rn=tmp;
//        insert to column
        save=p+tmp->co;
        while( save->cn!=NULL && save->cn->ra < tmp->ra )save=save->cn;
        tmp->cn=save->cn;
        save->cn=tmp;
//        output(p);
//        printf("*%d*\n",i);
    }
    return p;
}

void add(node a,node b)
{
    int i;
    node tmp;
    for(i=1;i<=b[0].ra;i++)
    {
        while(b[i].rn!=NULL)
        {
            tmp=b[i].rn;
            b[i].rn=b[i].rn->rn;
            node save;
            for(save=a+tmp->ra; save->rn!=NULL && save->rn->co < tmp->co ;save=save->rn);
            if( save->rn==NULL || save->rn->co > tmp->co )
            {
                tmp->rn=save->rn;
                save->rn=tmp;
            }
            else
            {
                save->rn->da+=tmp->da;
                free(tmp);
                if(save->rn->da==0)
                {
                    tmp=save->rn;
                    save->rn=save->rn->rn;
                    free(tmp);
                }
            }
        }
    }
    free(b);
    return ;
}

void output(node a)
{
    int i;
    for(i=1;i<=a[0].ra;i++)
    {
        node tmp,save;
        for(tmp=a+i;tmp->rn!=NULL;)
        {
            printf("%d %d %d\n",tmp->rn->ra,tmp->rn->co,tmp->rn->da);
            save=tmp->rn;
            tmp->rn=tmp->rn->rn;
            free(save);
//            tmp=tmp->rn;
        }
    }
    free(a);
    return ;
}

int main()
{
    int m,n,t1,t2;
    scanf("%d%d%d%d",&m,&n,&t1,&t2);
    node a,b;
    a=input(m,n,t1);
    b=input(m,n,t2);
    add(a,b);
    output(a);
    return 0;
}
