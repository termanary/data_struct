#include<stdio.h>
#include<string.h>

int main()
{
    int a[10],i,j,k,cnt;
    int b[]={22,41,53,46,30,13,01,67};
    memset(a,0x0,sizeof(b));
//    insert
    for(i=0;i<sizeof(b)/sizeof(int);i++)
    {
        j=(3*b[i])%11;
        if(a[j]==0)
        {
            a[j]=b[i];
        }
        else
        {
            for(k=(j+1)%11;k!=j && a[k]!=0;k=(k+1)%11);
            if(k==j)
                break;
            a[k]=b[i];
        }
    }
//    find
    for(i=0,cnt=0;i<sizeof(b)/sizeof(int);cnt++,i++)
    {
        k=(3*b[i])%11;
        if(a[k]==b[i])
        {
            continue;
        }
        for(j=(k+1)%11;j!=k && a[j]!=b[i];cnt++,j=(j+1)%11);
        if(j==k)
            break;
    }
//    printf("%lf\n",(double)cnt/(sizeof(b)/sizeof(int)));
    printf("%d\n",cnt/(sizeof(b)/sizeof(int)));
    return 0;
}
