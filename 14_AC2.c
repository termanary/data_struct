#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

enum tag {ATOM,LIST};

typedef struct list
{
    enum tag flag;
    struct list *tail;
    union 
    {
        char d;
        struct list *head;
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
//            putchar(t);
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
                    p->u.head=create_list();
                }
                break;
            case ',':
                for(tmp=p->u.head;tmp->tail!=NULL;tmp=tmp->tail);
                switch(t)
                {
                    case '(':
                        tmp->tail=create_list();
                        break;
                    default:
                        tmp->tail=(li)calloc(1,sizeof(struct list));
                        assert(tmp->tail);
                        tmp->tail->flag=ATOM;
                        tmp->tail->u.d=t;
                        t='\0';
                        break;
                }
                break;
            default:
                p->u.head=(li)calloc(1,sizeof(struct list));
                assert(p->u.head);
                p->u.head->flag=ATOM;
                p->u.head->u.d=h;
                break;
        }
    }
}

int depth(li p)
{
    if(p==NULL)
        return 0;
    if(p->flag==ATOM)
        return 0;
    int cnt,s; li tmp;
    cnt=depth(p->u.head);
    if(p->u.head==NULL)
    {
        return 1+cnt;
    }
    for(tmp=p->u.head->tail;tmp!=NULL;tmp=tmp->tail)
    {
        s=depth(tmp);
        cnt=cnt>s?cnt:s;
    }
    return 1+cnt;
}

int main()
{
    int i;
    i=depth(create_list());
    printf("%d\n%d\n",i,i);
//    int i=10;
//    while(i--)
//    {
//        printf("%d\n",depth(create_list()));
//        h='\0',t='\0',other='\0';
//    }
    return 0;
}
