#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//100*10000+1
#define MAX 1000001
#define PRESENT 10000
#define NOVISITED -1

int main()
{
    int n,*p=NULL,*s=NULL,i,j;
    scanf("%d",&n);
    s=(int*)calloc(n,sizeof(int));
    p=(int*)calloc(n*n,sizeof(int));
    assert(s);
    assert(p);
//    input and initialize
    for(i=0;i<n;i++)
    {
        *(s+i)=NOVISITED;
        for(j=0;j<n;j++)
        {
            scanf("%d",(p+i*n+j));
            if( *(p+i*n+j)== PRESENT)
            {
                *(p+i*n+j)=MAX;
            }
        }
    }
//    caculate
    int min;
    for(j=1,*(s+0)=0;j<n;j++)
    {
        for(i=1,min=-1; *(s+i)!=NOVISITED && i<n ;i++);
        min=i;
//        printf("%d ",min);
        for(i=1;i<n;i++)
        {
            if( *(s+i)==NOVISITED && *(p+0*n+i)< *(p+0*n+min) )
            {
                min=i;
            }
        }
//        printf("%d\n",min);
        *(s+min)=*(p+0*n+min);
        for(i=1;i<n;i++)
        {
            if( *(p+0*n+i) > *(p+0*n+min)+*(p+min*n+i) )
            {
                *(p+0*n+i) = *(p+0*n+min)+*(p+min*n+i);
            }
        }
    }
//    output
    for(i=0;i<n;i++)
    {
        if( *(s+i) == MAX )
        {
            printf("%d\n",PRESENT);
        }
        else
        {
            printf("%d\n",*(s+i));
        }
    }
    return 0;
}
