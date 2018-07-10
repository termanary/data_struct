#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define N 10000

int main()
{
    int n,*p=NULL,i,j,k,m;
    scanf("%d",&n);
    p=(int *)calloc(n*n,sizeof(int));
    assert(p);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",(p+i*n+j));
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if( *(p+i*n+k)!=N &&  *(p+k*n+j)!=N && *(p+i*n+j) > *(p+i*n+k) + *(p+k*n+j))
                {
                     *(p+i*n+j) = *(p+i*n+k) + *(p+k*n+j);
                }
            }
        }
    }
    scanf("%d",&m);
    for(k=0;k<m;k++)
    {
        scanf("%d%d",&i,&j);
        printf("%d\n",*(p+i*n+j));
    }
    free(p);
    return 0;
}
