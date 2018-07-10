#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

enum FLAG {ATOM=1,LIST=2}flag;

typedef struct list
{
    enum FLAG flag;
    union 
    {
        char d;
        struct 
        {
            struct list *head,*tail;
        }p;
    }u;
}*li;

char h='\0',t='\0',other='\0';

li create_list(void)
{
    li p=NULL,tmp;
    while(1)
    {
        h=t;
        if(other=='\0')
        {
            t=getchar();
        }
        else
        {
            t=other;
            other='\0';
        }
        switch(h)
        {
            case '\0':
                break;
            case '\n':
                exit(1);
                break;
            case ')':
                return p;
                break;
            case '(':
                if(p==NULL)
                {
                    p=(li)calloc(1,sizeof(struct list));
                    assert(p);
                    p->flag=LIST;
                }
                else
                {
                    other=t; t=h; h='\0';
                    p->u.p.head=(li)calloc(1,sizeof(struct list));
                    assert(p->u.p.head);
                    p->u.p.head=create_list();
                }
                break;
            case ',':
                if(p->u.p.tail==NULL)
                {
                    tmp=p;
                }
                else
                {
                    for(tmp=p->u.p.tail;tmp->u.p.tail!=NULL;tmp=tmp->u.p.tail);
                }
                tmp->u.p.tail=(li)calloc(1,sizeof(struct list));
                assert(tmp->u.p.tail);
                tmp->u.p.tail->flag=LIST;
                switch(t)
                {
                    case '(':
                        tmp->u.p.tail->u.p.head=create_list();
                        break;
                    default :
                        tmp->u.p.tail->u.p.head=(li)calloc(1,sizeof(struct list));
                        assert(tmp->u.p.tail->u.p.head);
                        tmp->u.p.tail->u.p.head->flag=ATOM;
                        tmp->u.p.tail->u.p.head->u.d=t;
                        t='\0';
                }
                break;
            default:
                tmp=(li)calloc(1,sizeof(struct list));
                assert(tmp);
                tmp->u.d=h;
                tmp->flag=ATOM;
                p->u.p.head=tmp;
                break;
        }
    }
}

int traverse(li p)
{
    if(p==NULL)
        return 0;
    if(p->flag==ATOM)
        return 0;
    int cnt,tmp;
    li p1;
    for(cnt=traverse(p->u.p.head),p1=p->u.p.tail;p1!=NULL;p1=p1->u.p.tail)
    {
        tmp=traverse(p1->u.p.head);
        cnt=cnt<tmp?tmp:cnt;
    }
    return 1+cnt;
}

int main()
{
    int a;
    a=traverse(create_list());
    printf("%d\n%d\n",a,a);
//    int i=10;
//    while(i--)
//    {
//        printf("%d\n",traverse(create_list()));
//        h='\0',t='\0',other='\0';
//    }
    return 0;
}
