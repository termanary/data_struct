#include<stdio.h>
#include<stdlib.h>

int main()
{
    int max,k;
    scanf("%d%d",&max,&k);
    int *p;
    p=(int*)calloc(k,sizeof(int));
    if(p==NULL)
    {
        exit(1);
    }
    int tmp,rear;
    for(p[0]=1,rear=0;;)
    {
//        if(rear==0)
//        {
//            tmp=p[rear]+p[k-1];
//        }
//        else
//        {
//            tmp=p[rear]+p[rear-1];
//        }
        int i;
        for(i=rear,rear=(rear+1)%k,tmp=0;;rear=(rear+1)%k)
        {
            tmp+=p[rear];
            if(rear==i)
            {
                break;
            }
        }
        if(tmp>max)
        {
            tmp=rear;
            rear=(rear+1)%k;
            for(;;rear=(rear+1)%k)
            {
//                if(p[rear]==0)
//                {
//                    continue;
//                }
                printf("%d",p[rear]);
                if(rear==tmp)
                {
                    printf("\n");
                    break;
                }
                else
                {
                    printf(" ");
                }
            }
            break;
        }
        else
        {
            rear=(rear+1)%k;
            p[rear]=tmp;
        }
    }
    return 0;
}
