#include<stdio.h>
#include<stdlib.h>

typedef struct matrix
{
    int raw,column,data;
}node;

int main()
{
//    the raw and column;
    int n,m,*record;
    scanf("%d%d",&n,&m);
    record=(int *)calloc(m+1,sizeof(int));
    if(record==NULL)
    {
        exit(1);
    }
//    input
    node *matrix;
    matrix=(node*)calloc(n*m+1,sizeof(node));
    if(matrix==NULL)
    {
        exit(1);
    }
    int i,j;
    for(i=0;;i++)
    {
        scanf("%d%d%d",&matrix[i].raw,&matrix[i].column,&matrix[i].data);
        if((matrix[i].raw==0)&&(matrix[i].column==0)&&(matrix[i].data==0))
        {
            break;
        }
        record[matrix[i].column]++;
//        int end;
//        node tmp;
//        for(tmp=matrix[i],j=i-1,end=1;(j>=0)&&(end);)
//        {
//            if(tmp.raw<matrix[j].raw)
//            {
//                matrix[j+1]=matrix[j];
//                j--;
//            }
//            else
//            {
//                if(tmp.raw>matrix[j].raw)
//                {
//                    matrix[j+1]=tmp;
//                    end=0;
//                }
//                else
//                {
//                    for(;;)
//                    {
//                        if(tmp.column>matrix[j].column)
//                        {
//                            matrix[j+1]=tmp;
//                            end=0;
//                            break;
//                        }
//                        else
//                        {
//                            matrix[j+1]=matrix[j];
//                            j--;
//                            if(j==-1)
//                            {
//                                end=0;
//                                break;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        if(j==-1)
//        {
//            matrix[0]=tmp;
//        }
    }
//    printf("%d\n",m);
//    printf("%d->%d-\n",0,record[0]);
    for(j=1;j<m;j++)
    {
        record[j+1]+=record[j];
//        printf("%d->%d-\n",j,record[j]);
    }
    node *result;
    result=(node*)calloc(i,sizeof(node));
    if(result==NULL)
    {
        exit(1);
    }
//    swap
//    int swap;
    int tmp;
    for(j=0;j<i;j++)
    {
        tmp=record[matrix[j].column-1];
        result[tmp].raw=matrix[j].column;
        result[tmp].column=matrix[j].raw;
        result[tmp].data=matrix[j].data;
        record[matrix[j].column-1]++;
//        swap=matrix[j].raw;
//        matrix[j].raw=matrix[j].column;
//        matrix[j].column=swap;
//        result[record[matrix[j].raw-1]]=matrix[j];
//        record[matrix[j].raw-1]++;
    }
    for(j=0;j<i;j++)
    {
        printf("%d %d %d\n",result[j].raw,result[j].column,result[j].data);
    }
    free(record);
    free(result);
    free(matrix);
    return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//
//#define N 20
//#define M 20
//
//int main()
//{
//    int a,b;
//    printf("%d %d\n",N,M);
//    for(a=1;a<N;a++)
//    {
//        for(b=1;b<M;b++)
//        {
//            if(rand()%2)
//            {
//                printf("%d %d %d\n",a,b,9);
//            }
//        }
//    }
//    return 0;
//}
