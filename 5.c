#include<stdio.h>
#include<stdlib.h>

typedef struct data_node
{
    int a;
    struct data_node *next;
}*data;

typedef struct data_pointer
{
    int na,nb,nc;
    data a,b,c;
}*pointer;

void input(pointer p);
void get_input(data *p,int m);
void deal(pointer p);
data find(int m,data *p,data p1);
void output(const data p);
void free_all(data p);
data search(data p,data p1);

int main()
{
    struct data_pointer cacual={0};
    input(&cacual);
//output(cacual.a);
    deal(&cacual);
    output(cacual.a);
    free_all(cacual.a);
    free_all(cacual.b);
    free_all(cacual.c);
    return 0;
}

data search(data p,data p1)
{
    data p2;
    if(p==p1)
    {
        return p1;
    }
    for(p2=p1;(p2!=NULL)&&(p2->next!=p);p2=p2->next);
    return p2;
}

void free_all(data p)
{
    data tmp;
    if(p==NULL)
    {
        return ;
    }
    tmp=p->next;
    for(;;)
    {
        free(p);
        p=tmp;
        if(tmp==NULL)
        {
            break;
        }
        tmp=tmp->next;
    }
    return ;
}

void output(const data p)
{
    data pp;
    for(pp=p;pp!=NULL;pp=pp->next)
    {
        printf("%d ",pp->a);
    }
    printf("\n");
    return ;
}

data find(int m,data *p,data p1)
{
    data pn=*p;
    if(*p==NULL)
    {
        return NULL;
    }
    while(m>pn->a)
    {
        pn=pn->next;
        if(pn==NULL)
        {
            *p=pn;
            return NULL;
        }
    }
    if(m==pn->a)
    {
        return search(pn,p1);
    }
    else
    {
        *p=pn;
        return NULL;
    }
}

void deal(pointer p)
{
    data save_a,save_b,save_c;
    data save_free,tmp;
    for(save_a=p->a,save_b=p->b,save_c=p->c ; save_b!=NULL ; save_b=save_b->next)
    {
        if(find(save_b->a,&save_c,p->c)!=NULL)
        {
            for(tmp=find(save_b->a,&save_a,p->a);tmp!=NULL;tmp=find(save_b->a,&save_a,p->a))
            {
                    if(p->a->a==save_b->a)
                    {
                        save_free=p->a;
                        p->a=p->a->next;
                        free(save_free);
                    }
                    else
                    {
                        save_free=tmp->next;
                        tmp->next=save_free->next;
                        free(save_free);
                    }
            }
        }
    }
    return ;
}

void get_input(data *p,int m)
{
    int i;
    data pp,pn;
    for(i=0;i<m;i++)
    {
        pn=(data)calloc(1,sizeof(struct data_node));
        if(pn==NULL)
            exit(1);
        scanf("%d",&(pn->a));
        if(*p==NULL)
        {
            *p=pp=pn;
        }
        else
        {
            pp->next=pn;
            pp=pn;
        }
    }
    return ;
}

void input(pointer p)
{
    scanf("%d%d%d",&p->na,&p->nb,&p->nc);
    get_input(&(p->a),p->na);
    get_input(&(p->b),p->nb);
    get_input(&(p->c),p->nc);
    return ;
}
