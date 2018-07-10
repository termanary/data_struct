#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    struct node *pre,*next;
    int freq;
}*data;

data input(int m);
data search(int m,data head);
void output_free(data head);
data find(char c,data head);
data insert(data p,data head);

int main()
{
    data head;
    int nodes,freq;
    scanf("%d%d",&nodes,&freq);
//    head=input(nodes);
    int i1;
    data head1=NULL,pp,pn;
    getchar();
    for(i1=0;i1<nodes;i1++)
    {
        pn=(data)calloc(1,sizeof(struct node));
        if(pn==NULL)
            exit(1);
//        scanf(" %c ",&(pn->data));
        pn->data=getchar();
        getchar();
        if(head1==NULL)
        {
            head1=pp=pn;
            head1->pre=head1->next=head1;
        }
        else
        {
            pp->next=pn;
            pn->pre=pp;
            pp=pn;
        }
    }
    head1->pre=pn;
    pn->next=head1;
    head=head1;

//        output_free(head);
//    head=search(freq,head);

    data just_save=head;
//data search(int m,data head)
    int i;
    char c;
    data tmp;
//    getchar();
    for(i=0;i<freq;i++)
    {
//        scanf("%c ",&c);
        c=getchar();
        getchar();
        tmp=find(c,just_save);
        if(tmp==NULL)
        {
            continue;
        }
        just_save=insert(tmp,just_save);
    }
    head=just_save;
//
    output_free(head);
    return 0;
}

data insert(data p,data head)
{
    data tmp=p;
    if(p==head)
    {
        return head;
    }
    while((p!=head)&&(tmp->freq > p->pre->freq))p=p->pre;
    if(p==tmp)
    {
        return head;
    }
    else
    {
        tmp->pre->next=tmp->next;
        tmp->next->pre=tmp->pre;
        tmp->next=p;
        tmp->pre=p->pre;
        tmp->pre->next=tmp;
        tmp->next->pre=tmp;
        if(p==head)
        {
            return tmp;
        }
        else
        {
            return head;
        }
    }
}

data find(char c,data head)
{
    data save=head;
    while(1)
    {
        if(c==head->data)
        {
            (head->freq)++;
            return head;
        }
        head=head->next;
        if(head==save)
        {
            return NULL;
        }
    }
}

data search(int m,data head)
{
    int i;
    char c;
    data tmp;
    for(i=0;i<m;i++)
    {
        scanf("%c ",&c);
        tmp=find(c,head);
        if(tmp==NULL)
        {
            continue;
        }
        head=insert(tmp,head);
    }
    return head;
}

void output_free(data head)
{
    data tmp,save=head;
    for(;;)
    {
        printf("%c ",head->data);
        tmp=head->next;
        free(head);
        head=tmp;
        if(save==head)
        {
            printf("\n");
            break;
        }
    }
    return ;
}

data input(int m)
{
    int i;
    data head=NULL,pp,pn;
    getchar();
    for(i=0;i<m;i++)
    {
        pn=(data)calloc(1,sizeof(struct node));
        if(pn==NULL)
            exit(1);
        scanf("%c ",&(pn->data));
        if(head==NULL)
        {
            head=pp=pn;
            head->pre=head->next=head;
        }
        else
        {
            pp->next=pn;
            pn->pre=pp;
            pp=pn;
        }
    }
    head->pre=pn;
    pn->next=head;
    return head;
}

