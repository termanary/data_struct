//descending 
#include<stdio.h>
#include<stdlib.h>

typedef struct data_node
{
    int a;
    struct data_node *next;
}*data;

typedef struct link_list
{
    int na,nb;
    data a,b;
}*pointer;


void input(pointer p);
void get_node(data *p,int m);
void insert(pointer p);
void output(data p);

int main()
{
    struct link_list one;
    input(&one);
    insert(&one);
    output(one.a);
    return 0;
}

void input(pointer p)
{
    scanf("%d%d",&p->na,&p->nb);
    get_node(&p->a,p->na);
    get_node(&p->b,p->nb);
    return ;
}

void get_node(data *p,int m)
{
    int i;
    data save;
    for(i=0,save=NULL;i<m;i++)
    {
        *p=(data)calloc(1,sizeof(struct data_node));
        if(*p==NULL)
            exit(1);
        scanf("%d",&((*p)->a));
        (*p)->next=save;
        save=*p;
    }
    return ;
}

void insert(pointer p)
{
    data ap,an;
    data save;
    for(an=p->a,ap=NULL;p->b!=NULL;)
    {
        while((an->a > p->b->a)&&(an!=NULL))
        {
            ap=an;
            an=an->next;
        }
        if(an==NULL)
        {
            ap->next=p->b;
            break;
        }
        save=p->b->next;
        if(an==p->a)
        {
            p->b->next=p->a;
            p->a=p->b;
            ap=p->a;
        }
        else
        {
            p->b->next=ap->next;
            ap->next=p->b;
            ap=ap->next;
        }
        p->b=save;
    }
    return ;
}

void output(data p)
{
    data save;
    while(p!=NULL)
    {
        printf("%d ",p->a);
        save=p;
        p=p->next;
        free(save);
    }
    printf("\n");
    return ;
}

