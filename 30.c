#include<stdio.h>
#include<stdlib.h>

typedef struct matrix
{
    int raw,col,data;
}node;

int main()
{
    int m,n,t1,t2;
    scanf("%d%d%d%d",&m,&n,&t1,&t2);
    node *p1,*p2;
    p1=(node*)calloc(t1,sizeof(node));
    p2=(node*)calloc(t2,sizeof(node));
    if((p1==NULL)||(p2==NULL))
    {
        exit(1);
    }
    int i;
    for(i=0;i<t1;i++)
    {
        scanf("%d%d%d",&p1[i].raw,&p1[i].col,&p1[i].data);
    }
    for(i=0;i<t2;i++)
    {
        scanf("%d%d%d",&p2[i].raw,&p2[i].col,&p2[i].data);
    }
    int j,tmpr,tmpc;
    for(i=0,j=0;(i<t1)&&(j<t2);)
    {
        tmpr=p1[i].raw-p2[j].raw;
        if(tmpr<0)
        {
            printf("%d %d %d\n",p1[i].raw,p1[i].col,p1[i].data);
            i++;
        }
        else
        {
            if(tmpr>0)
            {
                printf("%d %d %d\n",p2[j].raw,p2[j].col,p2[j].data);
                j++;
            }
            else
            {
                tmpc=p1[i].col-p2[j].col;
                if(tmpc<0)
                {
                    printf("%d %d %d\n",p1[i].raw,p1[i].col,p1[i].data);
                    i++;
                }
                else
                {
                    if(tmpc>0)
                    {
                        printf("%d %d %d\n",p2[j].raw,p2[j].col,p2[j].data);
                        j++;
                    }
                    else
                    {
                        printf("%d %d %d\n",p1[i].raw,p1[i].col,p1[i].data+p2[j].data);
                        i++;
                        j++;
                    }
                }
            }
        }
    }
    int bo;
    node *p3;
    for(bo=i==t1,i=bo?j:i,t1=bo?t2:t1,p3=bo?p2:p1;i<t1;i++)
    {
        printf("%d %d %d\n",p3[i].raw,p3[i].col,p3[i].data);
    }
    free(p1);
    free(p2);
    return 0;
}
