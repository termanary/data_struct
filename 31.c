#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int ra,co;
    int da;
    struct node *rn,*dn;
}*node_pointer;

struct head
{
    node_pointer *rh,*ch;
};

struct head init(int m,int n,int t)
{
//    printf("t=%d\n",t);
    struct head re;
//    memory allocate
    re.rh=(node_pointer *)calloc(m,sizeof(node_pointer));
    re.ch=(node_pointer *)calloc(n,sizeof(node_pointer));
    if((re.rh==NULL)||(re.ch==NULL))
    {
        exit(2);
    }
    int i;
    node_pointer p;
    for(i=0;i<t;i++)
    {
        //    input
        p=(node_pointer)calloc(1,sizeof(struct node));
        if(p==NULL)
        {
            exit(2);
        }
        scanf("%d%d%d",&p->ra,&p->co,&p->da);
//        printf("%d-%d-%d\n",p->ra,p->co,p->da);
        node_pointer tmp;

        //    mount in raw
        if(re.rh[p->ra-1]==NULL)
        {
            re.rh[p->ra-1]=p;
//            p->rn=re.rh[p->ra-1];
//            break;
        }
        else
        {
//            only one node_pointer 
            if(NULL== re.rh[p->ra-1]->rn)
            {
                if(re.rh[p->ra-1]->co > p->co)
                {
                    p->rn=re.rh[p->ra-1];
                    re.rh[p->ra-1]=p;
                }
                else
                {
                    re.rh[p->ra-1]->rn=p;
                }
            }
            else
            {
                tmp=re.rh[p->ra-1];
                while((tmp->rn!=NULL)&&(p->co > tmp->rn->co))tmp=tmp->rn;
                if(tmp ==NULL)
                {
//                    p->rn=tmp;
                    tmp->rn=p;
                }
                else
                {
                    p->rn=tmp->rn;
                    tmp->rn=p;
                }
            }
        }

//        printf("OK\n");
        //    mount in column
        if(re.ch[p->co-1]==NULL)
        {
            re.ch[p->co-1]=p;
//            p->dn=re.ch[p->co-1];
//            break;
        }
        else
        {
//            only one node_pointer 
            if(NULL== re.ch[p->co-1]->dn)
            {
                if(re.ch[p->co-1]->ra > p->ra)
                {
                    p->dn=re.ch[p->co-1];
                    re.ch[p->co-1]=p;
                }
                else
                {
                    re.ch[p->co-1]->dn=p;
                }
            }
            else
            {
                tmp=re.ch[p->co-1];
                while((tmp->dn!=NULL)&&(p->ra > tmp->dn->ra))tmp=tmp->dn;
                if(tmp == NULL)
                {
//                    p->dn=tmp;
                    tmp->dn=p;
                }
                else
                {
                    p->dn=tmp->dn;
                    tmp->dn=p;
                }
            }
        }
    }
    return re;
}

int judge(node_pointer t1,node_pointer t2,node_pointer i1,node_pointer i2)
{
    if((t1==i1)&&(t2==i2))
    {
        return 0;
    }
    else
    {
        if((t1!=i1)&&(t2!=i2))
        {
            return 1;
        }
        else
        {
            node_pointer tmp,pause,save;
            if(t1==i1)
            {
                tmp=t2;
                pause=i2;
            }
            else
            {
                tmp=t1;
                pause=i1;
            }
            for(;tmp!=pause;)
            {
                printf("%d %d %d\n",tmp->ra,tmp->co,tmp->da);
                save=tmp;
                tmp=tmp->rn;
                free(save);
            }
            return 0;
        }
    }
}

void add(struct head h1,struct head h2,int m)
{
    int i;
    node_pointer tmp,inih1,inih2;
    for(i=0;i<m;i++)
    {
        for(inih1=NULL,inih2=NULL;(h1.rh[i]!=NULL)||(h2.rh[i]!=NULL);)
        {
            if(judge(h1.rh[i],h2.rh[i],inih1,inih2)==0)
            {
//                printf("judge\n");
                h1.rh[i]=h2.rh[i]=NULL;
                continue;
            }
            if(h1.rh[i]->co == h2.rh[i]->co)
            {
                printf("%d %d %d\n",h1.rh[i]->ra,h1.rh[i]->co,h1.rh[i]->da+h2.rh[i]->da);
                tmp=h1.rh[i];
                h1.rh[i]=h1.rh[i]->rn;
                free(tmp);
                tmp=h2.rh[i];
                h2.rh[i]=h2.rh[i]->rn;
                free(tmp);
            }
            else
            {
                if(h1.rh[i]->co < h2.rh[i]->co)
                {
                    printf("%d %d %d\n",h1.rh[i]->ra,h1.rh[i]->co,h1.rh[i]->da);
                    tmp=h1.rh[i];
                    h1.rh[i]=h1.rh[i]->rn;
                    free(tmp);
                }
                else
                {
                    printf("%d %d %d\n",h2.rh[i]->ra,h2.rh[i]->co,h2.rh[i]->da);
                    tmp=h2.rh[i];
                    h2.rh[i]=h2.rh[i]->rn;
                    free(tmp);
                }
            }
//                remember to judge if they are NULL 
//---------------------------------------------------------------------------------
        }
    }
    free(h1.rh); free(h1.ch); free(h2.rh); free(h2.ch);
    return ;
}

int main()
{
    int m,n,t1,t2;
    struct head h1,h2;
    scanf("%d%d%d%d",&m,&n,&t1,&t2);
    h1=init(m,n,t1);
//    node_pointer for test
    h2=init(m,n,t2);
//    int i;
//    for(i=0;i<m;i++)
//    {
//        if(h2.rh[i]!=NULL)
//        {
//            node_pointer tmp=h2.rh[i];
//            printf("%d-%d-%d\n",tmp->ra,tmp->co,tmp->da);
//            for(tmp=h2.rh[i]->rn;tmp!=NULL;tmp=tmp->rn)
//            {
//                printf("%d-%d-%d\n",tmp->ra,tmp->co,tmp->da);
//            }
//        }
//    }
    add(h1,h2,m);
    return 0;
}

