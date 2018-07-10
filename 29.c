#include<stdio.h>
#include<stdlib.h>

typedef struct matrix
{
    int raw,column,data;
}node;

int main()
{
//    the raw and column;
    int n,m;
    scanf("%d%d",&n,&m);
//    input
    node matrix;
    for(;;)
    {
        scanf("%d%d%d",&matrix.raw,&matrix.column,&matrix.data);
        if((matrix.raw==0)&&(matrix.column==0)&&(matrix.data==0))
        {
            break;
        }
        printf("%d %d %d\n",matrix.column,matrix.raw,matrix.data);
    }
    return 0;
}
