#include<stdio.h>
#include<stdlib.h>

typedef struct matrix
{
    int ra,co,da;
}*sparse;

int main()
{
    int t1,t2;
    scanf("%d%d",&t1,&t2);
    sparse a,b,c;
    a=(sparse)calloc(t1,sizeof(struct matrix));
    b=(sparse)calloc(t2,sizeof(struct matrix));
    c=(sparse)calloc(t1+t2,sizeof(struct matrix));
    if((NULL==a)||(NULL==b)||(NULL==c))
    {
        exit(1);
    }
    int i;
    for(i=0;i<t1;i++)
    {
        scanf("%d%d%d",&a[i].ra,&a[i].co,&a[i].da);
    }
    for(i=0;i<t2;i++)
    {
        scanf("%d%d%d",&b[i].ra,&b[i].co,&b[i].da);
    }
    int cnt,j;
    sparse tmp;
    for(i=0,j=0,cnt=0;i<t1 && j< t2;)
    {
        if(a[i].ra == b[j].ra && a[i].co == b[j].co)
        {
            if(a[i].da+b[j].da!=0)
            {
                c[cnt].ra=a[i].ra;
                c[cnt].co=a[i].co;
                c[cnt].da=a[i].da+b[j].da;
                cnt++;
            }
            i++; j++;
        }
        else
        {
            if(a[i].ra < b[j].ra || (a[i].ra == b[j].ra && a[i].co < b[j].co))
            {
                tmp=a+i;
                i++;
            }
            else
            {
                tmp=b+j;
                j++;
            }
            c[cnt].ra=tmp->ra;
            c[cnt].co=tmp->co;
            c[cnt].da=tmp->da;
            cnt++;
        }
    }
    if(i==t1)
    {
        tmp=b;
        i=j;
        t1=t2;
    }
    else
    {
        tmp=a;
    }
    for(;i<t1;i++)
    {
        c[cnt].ra=(tmp+i)->ra;
        c[cnt].co=(tmp+i)->co;
        c[cnt].da=(tmp+i)->da;
    }
    for(i=0;i<cnt;i++)
    {
        printf("%d %d %d\n",c[i].ra,c[i].co,c[i].da);
    }
    return 0;
}
