#include<stdio.h>
#include<stdlib.h>

int *input(void);
int search(int *p);
void insert(int *p,int r);
void output(int *p);

int main()
{
    int *p=input();
    insert(p,search(p));
    output(p);
    return 0;
}

int *input(void)
{
    int *p,m,i;
    scanf("%d",&m);
    p=(int *)calloc(m+2,sizeof(int));
    p[0]=m;
    for(i=1;i<=m;i++)
    {
        scanf("%d",(p+i));
    }
    return p;
}

int search(int *p)
{
    int m;
    scanf("%d",&m);
    p[0]++;
    p[p[0]]=m;
    //find in order:
    //int i;
    //for(i=1;(i<=p[0])&&(m>p[i]);i++);
    //return i;
    int l,r,mid;
    for(l=1,r=p[0]-1;l<=r;)
    {
        mid=(l+r)>>1;
        if(p[mid]>m)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return r+1;
}

void insert(int *p,int r)
{
    int i,m=p[p[0]];
    for(i=p[0];i>r;i--)
    {
        p[i]=p[i-1];
    }
    p[r]=m;
    return ;
}

void output(int *p)
{
    int i;
    for(i=1;i<=p[0];i++)
    {
        printf("%d ",p[i]);
    }
    return ;
}
