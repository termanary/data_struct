#include<stdio.h>

void push(char stack[],int *top,char tmp);
char pop(char stack[],int *top);

int main()
{
    char stack[1000]={0};
    int top=-1,flag=1;
    char tmp;
    while(flag)
    {
        tmp=getchar();
        switch(tmp)
        {
            case '\n':
                if(top==-1)
                {
                    printf("yes");
                }
                else
                {
                    printf("n-no");
                }
                flag=0;
                break;
            case '(': case '[': case '{': 
                push(stack,&top,tmp);
                break;
            case ')':
                if(pop(stack,&top)!='(')
                {
                    printf("()no");
                    flag=0;
                }
                break;
            case ']':
                if(pop(stack,&top)!='[')
                {
                    printf("[]no");
                    flag=0;
                }
                break;
            case '}': 
                if(pop(stack,&top)!='{')
                {
                    printf("{}no");
                    flag=0;
                }
                break;
        }
    }
    return 0;
}

char pop(char stack[],int *top)
{
    (*top)--;
    return stack[*top+1];
}


void push(char stack[],int *top,char tmp)
{
    (*top)++;
    stack[*top]=tmp;
    return ;
}
