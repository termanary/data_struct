#include<stdio.h>
#include<stdlib.h>

void input(int **p1,int *n1);
int cmp(int a,int b);

int main()
{
    int *p1,*p2,*p3,n1,n2;
    int i,j,r;
    input(&p1,&n1);
    input(&p2,&n2);
    p3=(int*)calloc(n1+n2,sizeof(int));
    if(p3==NULL)
    {
        exit(1);
    }
    for(r=0,i=0,j=0;(i<n1)&&(j<n2);r++)
    {
        if(cmp(p1[i],p2[j])==1)
        {
            p3[r]=p2[j];
            j++;
        }
        else
        {
            p3[r]=p1[i];
            i++;
        }
    }
    if(i==n1)
    {
        for(;j<n2;)
        {
            p3[r]=p2[j];
            r++;
            j++;
        }
    }
    else
    {
        for(;i<n1;)
        {
            p3[r]=p1[i];
            r++;
            i++;
        }
    }
    for(i=0,n1+=n2;i<n1;i++)
    {
        printf("%d\n",p3[i]);
    }
    free(p1);
    free(p2);
    free(p3);
    return 0;
}

void input(int **p1,int *n1)
{
    int i;
    scanf("%d",n1);
    *p1=(int *)calloc(*n1,sizeof(int));
    if(*p1==NULL)
    {
        exit(1);
    }
    for(i=0;i<*n1;i++)
    {
        scanf("%d",*p1+i);
    }
    return ;
}

int cmp(int a,int b)
{
    return a>=b?1:0 ;
}
