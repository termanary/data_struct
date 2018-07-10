#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//100*10000+1
#define MAX 1000001
#define PRESENT 10000
#define NOVISITED -1

typedef struct dijkstra
{
    int weight,*p;
}*path;

int main()
{
    int n,i,j,in,out,*p=NULL;
    path s=NULL;
    scanf("%d",&n);
    p=(int*)calloc(n*n,sizeof(int));
    s=(path)calloc(n,sizeof(struct dijkstra));
    assert(p); assert(s);

//    initialize
    for(i=0;i<n;i++)
    {
        s[i].weight=NOVISITED;
        s[i].p=(int*)calloc(n+1,sizeof(int));
        assert(s->p);
        for(j=0;j<n;j++)
        {
            scanf("%d",(p+i*n+j));
            if( *(p+i*n+j) == PRESENT )
            {
                *(p+i*n+j)=MAX;
            }
        }
    }
    scanf("%d%d",&in,&out);

//    caculate
//    printf("%d\n",in);
    int min;
    for(j=1,s[in].weight=0;j<n;j++)
    {

//        initialize min
        for(i=0;i<n;i++)
        {
//            printf("i=%d\n",i);
            if(i==in)
            {
                continue;
            }
            if( s[i].weight==NOVISITED )
            {
                min=i;
                break;
            }
        }
//        printf("min=%d\n",min);

//        find the minimum
        for(i=0;i<n;i++)
        {
            if(i==in)
            {
                continue;
            }
            if( s[i].weight==NOVISITED && *(p+in*n+i) < *(p+in*n+min) )
            {
                min=i;
            }
        }
//    printf("Hello,World\n");

//        adjust the rest
        for(s[min].weight=*(p+in*n+min),i=0;i<n;i++)
        {
            if( *(p+in*n+i) > *(p+in*n+min) + *(p+min*n+i) )
            {
                *(p+in*n+i) = *(p+in*n+min) + *(p+min*n+i) ;
                (s[i].p[0])++;
                s[i].p[ (s[i].p[0]) ]=min;
            }
        }
    }
//    output

    printf("%d\n",in);
    for(i=1;i<=s[out].p[0];i++)
    {
        printf("%d\n",s[out].p[i]);
    }
    printf("%d\n",out);

//    free memory
    for(i=0;i<n;i++)
    {
        free(s[i].p);
    }
    free(p);
    free(s);
    return 0;
}
