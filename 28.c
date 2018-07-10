#include<stdio.h>
#include<stdlib.h>

//the bits of results need
#define N 510
//the circle calculate need
#define M 900

typedef struct node
{
    int data;
    struct node *pre,*next;
}node,*point;

point ini_link_list(void)
{
    int i;
    point head=NULL,p1=NULL,p2=NULL;
    for(i=0;i<N;i++)
    {
        p1=(point)calloc(1,sizeof(node));
        if(p1==NULL)
        {
            exit(1);
        }
//        this is added by me
//        p1->data=rand()%10;
        if(head==NULL)
        {
            head=p2=p1;
        }
        p1->pre=p2;
        p2->next=p1;
        p2=p1;
    }
    p1->next=head;
    head->pre=p1;
    return head;
}

int main()
{
    point sump=ini_link_list(),rnp=ini_link_list(),pp,sp;
    int son,mom,i,rem,tmp;
    int m;
    int j;
    scanf("%d",&m);
//    rnp->next->data=5;
    rnp->data=3;
    for(i=1;i<M;i++)
    {
        son=(2*i-1)*(2*i-1);
        mom=8*i*(2*i+1);
        //add
        for(sp=sump->pre,pp=rnp->pre,rem=0;;pp=pp->pre,sp=sp->pre)
        {
            sp->data=sp->data+pp->data+rem;
            rem=sp->data/10;
            sp->data%=10;
            if(pp==rnp)
            {
                break;
            }
        }
        //divide
        for(pp=rnp,rem=0,tmp=0;;)
        {
            tmp=rem*10+pp->data;
            rem=tmp%mom;
            pp->data=tmp/mom;
            pp=pp->next;
            if(pp==rnp)
            {
                break;
            }
        }
        //mutiply
        for(pp=rnp->pre,rem=0,tmp=0;;pp=pp->pre)
        {
            tmp=pp->data*son+rem;
            pp->data=tmp%10;
            rem=tmp/10;
            if(pp==rnp)
            {
                break;
            }
        }
    }
printf("3.");
for(j=0,pp=sump->next;j<m;j++)
{
    printf("%d",pp->data);
    pp=pp->next;
}
printf("\n");
    return 0;
}
