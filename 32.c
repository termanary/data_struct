#include<stdio.h>
#include<stdlib.h>

typedef struct matrix_node
{
    int ra,co,da;
}*node;

typedef struct matrix
{
    int ra,co,nu,*rea,*rec;
    node po;
}*ma;

void input(ma m)
{
    scanf("%d%d",&m->ra,&m->co);
    m->po=(node)calloc(m->ra * m->co,sizeof(struct matrix_node));
    m->rea=(int*)calloc(m->ra+1,sizeof(int));
    m->rec=(int*)calloc(m->co+1,sizeof(int));
    if((m->po==NULL)||(m->rea==NULL)||(m->rec==NULL))
    {
        exit(1);
    }
    for(m->nu=0;;m->nu++)
    {
        scanf("%d%d%d",&(m->po)[m->nu].ra,&(m->po)[m->nu].co,&(m->po)[m->nu].da);
        if((m->po)[m->nu].ra == 0 && (m->po)[m->nu].co == 0 && (m->po)[m->nu].da == 0)
        {
            m->nu--;
            break;
        }
        (m->rea)[(m->po)[m->nu].ra]++;
        (m->rec)[(m->po)[m->nu].co]++;
    }
//    printf("%d==\n",m->nu);
    return ;
}

void transposition(ma m)
{
    int i;
    node con;
    int *save;
    con=(node)calloc(m->nu+1,sizeof(struct matrix_node));
    save=(int*)calloc(m->co+1,sizeof(int));
    if((con==NULL)||(save==NULL))
    {
        exit(1);
    }
//    the position of each raw 
    for(i=0;i<m->co;i++)
    {
//        (m->rea)[i+1]+=(m->rea)[i];
//        printf(";%d;\n",(m->rec)[i+1]);
        (m->rec)[i+1]+=(m->rec)[i];
        save[i+1]=(m->rec)[i+1];
    }
    int *swap;
    swap=m->rea;
    m->rea=m->rec;
    m->rec=swap;
    int tmp;
//    printf("%d\n",m->nu);
    for(i=0;i<=m->nu;i++)
    {
        tmp=m->rea[(m->po)[i].co-1];
        m->rea[(m->po)[i].co-1] ++ ;
        con[tmp].ra=(m->po)[i].co;
        con[tmp].co=(m->po)[i].ra;
        con[tmp].da=(m->po)[i].da;
//        printf("%d+%d+%d=%d=%d\n",i,tmp,con[tmp].ra,con[tmp].co,con[tmp].da);
    }
    free(m->po);
    free(m->rea);
    m->rea=save;
    m->po=con;
    tmp=m->ra;
    m->ra=m->co;
    m->co=tmp;
    return ;
}

void mutiply(ma m1,ma m2)
{
    int i,j;
    for(i=0;i<=m1->ra;i++)
    {
        (m1->rea)[i+1]+=(m1->rea)[i];
    }
    int be1,en1,be2,en2,tmp;
    for(i=1;i<=m1->ra;i++)
    {
        for(j=1;j<=m2->ra;j++)
        {
            tmp=0;
            be1=(m1->rea)[i-1];
            en1=(m1->rea)[i];
            be2=(m2->rea)[j-1];
            en2=(m2->rea)[j];
            for(;(be1<en1)&&(be2<en2);)
            {
//                printf("%d*%d\n",i,j);
//                printf("%d=%d=%d=%d\n",be1,en1,be2,en2);
//                printf("%d-%d-%d-",(m1->po)[be1].ra,(m1->po)[be1].co,(m1->po)[be1].da);
//                printf("%d-%d-%d\n",(m2->po)[be2].ra,(m2->po)[be2].co,(m2->po)[be2].da);
                if((m1->po)[be1].co==(m2->po)[be2].co)
                {
                    tmp+=(m1->po)[be1].da * (m2->po)[be2].da;
                    be1++;
                    be2++;
                }
                else
                {
                    if(((m1->po)[be1].co < (m2->po)[be2].co))
                    {
                        be1++;
                    }
                    else
                    {
                        be2++;
                    }
                }
            }
            if(tmp!=0)
            {
                printf("%d %d %d\n",(m1->po)[(m1->rea)[i-1]].ra,(m2->po)[(m2->rea)[j-1]].ra,tmp);
            }
        }
    }
    return ;
}

int main()
{
    struct matrix m1,m2;
    input(&m1);
    input(&m2);
//    don't worry to check the input 
    transposition(&m2);
//    int i;
//    for(i=0;i<=m2.nu;i++)
//    {
//        printf("%d-%d-%d\n",(m2.po)[i].ra,(m2.po)[i].co,(m2.po)[i].da);
//    }
    mutiply(&m1,&m2);
    return 0;
}

