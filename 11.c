#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    k%=n;
    int *p;
    p=(int*)calloc(n+1,sizeof(int));
    if(p==NULL)
    {
        exit(1);
    }
    int i,j;
    for(i=1;i<=n;i++)
    {//input
        scanf("%d",p+i);
    }
    int tmp;
    for(i=0;i<k;i++)
    {//handle
        for(j=n,tmp=p[n];j>1;j--)
        {
            p[j]=p[j-1];
        }
        p[1]=tmp;
    }
    for(i=1;i<=n;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
    return 0;
}
