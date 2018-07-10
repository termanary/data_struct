#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,*p;
    scanf("%d",&n);
    p=(int*)calloc(n,sizeof(int));
    if(p==NULL)
    {
        exit(1);
    }
    int rear,length;
    int out,head;
    char c;
    char wa[10];
    for(rear=0,length=0;;)
    {
        if(rear<n)
        {
            scanf("%d",p+rear);
            rear++;
            length++;
        }
        else
        {
            scanf("%d",&out);
        }
        c=getchar();
        if(c=='\n')
        {
            break;
        }
    }
    gets(wa);
    scanf("%d",&out);
    for(rear=0;rear<length;rear++)
    {
        if(p[rear]==out)
        {
            for(rear++,head=p[rear];rear<length;rear++)
            {
                printf("%d ",p[rear]);
//                if(rear!=length)
//                {
//                    printf(" ");
//                }
            }
            printf("\n%d\n",head);
            break;
        }
    }
    free(p);
    return 0;
}
