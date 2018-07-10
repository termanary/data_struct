#include<stdio.h>
#include<stdlib.h>

//the better way is initial when input

struct sort
{
    int m;
    int *p;
    struct adt *head;
};

typedef struct adt
{
    int a;
    struct adt *next;
}*cc;

void input(struct sort *p);
void array(struct sort *p);
void link(struct sort *p);
void swap(int *a,int *b);
cc change(cc head);

int main()
{
    struct sort a={0};
    input(&a);
    array(&a);
    link(&a);
    return 0;
}

void input(struct sort *p)
{
    int i;
    cc p1,p2;
    scanf("%d",&p->m);
    p->p=(int*)calloc(p->m,sizeof(int));
    if(p->p==NULL)
        exit(1);
    for(i=0;i<p->m;i++)
    {
        scanf("%d",(p->p+i));
        p1=(cc)calloc(1,sizeof(struct adt));
        if(p1==NULL)
            exit(1);
        p1->a=p->p[i];
        if(p->head==NULL)
        {
            p->head=p2=p1;
        }
        else
        {
            p2->next=p1;
            p2=p1;
        }
    }
    return ;
}

void array(struct sort *p)
{
    int l,r,i;
    for(i=0,l=0,r=p->m-1;l<=r;l++,r--)
    {
        swap(p->p+l,p->p+r);
    }
    for(i=0;i<p->m;i++)
    {
        printf("%d ",p->p[i]);
    }
    printf("\n");
    return ;
}

void link(struct sort *p)
{
    cc head;
    head=change(p->head);
    for(;;)
    {
        printf("%d ",head->a);
        head=head->next;
        if(head==NULL)
            break;
    }
    printf("\n");
    return ;
}

void swap(int *a,int *b)
{
    int r;
    r=*a;
    *a=*b;
    *b=r;
    return ;
}

cc change(cc head)
{
    cc p1=head,p2=head->next;
    for(p1->next=NULL;;)
    {
        head=p2->next;
        p2->next=p1;
        p1=p2;
        if(head==NULL)
        {
            head=p2;
            break;
        }
        p2=head;
    }
    return head;
}
