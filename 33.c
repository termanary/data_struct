#include<stdio.h>
#include<stdlib.h>

#define N 101

typedef struct tree
{
    int we;
    char flag;
    char code;
    int pa,lc,rc;
}*node;

void create_tree(node p,int to)
{
    int i;
    for(i=to+1,to=2*to; i<to ;i++)
    {
//        search
        int fl=0,sl=0,j;
//        initialize the fl and sl
        for(j=1;j<i && (fl==0 || sl==0);j++)
        {
            if( (p+j)->pa==0 )
            {
                if(fl==0)
                {
                    fl=j;
                }
                else
                {
                    sl=j;
                    if( (p+fl)->we > (p+sl)->we)
                    {
                        int swap;
                        swap=fl;
                        fl=sl;
                        sl=swap;
                    }
                }
            }
        }
//        printf("%d %d\n",fl,sl);

//        compare the rest
        for(;j<i;j++)
        {
            if( (p+j)->pa == 0 &&  (p+j)->we < (p+sl)->we )
            {
                if( (p+j)->we < (p+fl)->we )
                {
                    sl=fl;
                    fl=j;
                }
                else
                {
                    sl=j;
                }
            }
        }
//        printf("%d %d\n",fl,sl);

//        mount on one tree 
        (p+fl)->pa=i;
        (p+sl)->pa=i;
        (p+i)->lc=fl;
        (p+i)->rc=sl;
        (p+i)->we=(p+fl)->we+(p+sl)->we;
        (p+(p+i)->lc)->flag='0';
        (p+(p+i)->rc)->flag='1';

    }
    return ;
}

void encoding(char ex[],node p,int to)
{
    int i;
    char *ch=NULL;
    ch=(char*)calloc(to-1,sizeof(char));
    if(ch==NULL)
    {
        exit(1);
    }
    for(i=0;ex[i]!='\0';i++)
    {
        int j,top;
        for(j=1; j<=to && (p+j)->code!=ex[i] ;j++);
        for(top=0; j!=2*to-1 ;j=(p+j)->pa)
        {
//            putchar( (p+j)->flag );
//            just a stack
            ch[top]=(p+j)->flag;
            top++;
        }
//        output
        for(top--;top>=0;)
        {
            putchar(ch[top]);
            ch[top]='\0';
            top--;
        }
//        putchar('*');
    }
    putchar('\n');
    return ;
}

void traverse(node p,int to)
{
    if(to==0)
    {
        return ;
    }
    traverse(p,(p+to)->lc);
    putchar( (p+to)->flag );
    traverse(p,(p+to)->rc);
    return ;
}

int main()
{
    int to;
    scanf("%d",&to);
//    printf("%d",to);
    node p=NULL;
    int i;

    p=(node)calloc(2*to,sizeof(struct tree));
    if(p==NULL)
    {
        exit(1);
    }

    for(i=1;i<=to;i++)
    {
        scanf(" %c ",&((p+i)->code));
//        printf("%c*",((p+i)->code));
    }
    for(i=1;i<=to;i++)
    {
        scanf("%d",&((p+i)->we));
//        printf("%d",((p+i)->we));
    }

    create_tree(p,to);
//    traverse(p,2*to-1);
    char ex[N]={'\0'};
    getchar();
    gets(ex);
    encoding(ex,p,to);
    puts(ex);
    free(p);
    return 0;
}

