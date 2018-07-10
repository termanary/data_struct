#include<stdio.h>

int main()
{
    char c,ope[100]={0};
    int top,end;
    int end_pop;
    for(end=1,top=0;end!=0;)
    {
        c=getchar();
        if((c>='a')&&(c<='z'))
        {
            putchar(c);
            continue;
        }
        switch(c)
        {
            case '\n':
                for(;top!=0;)
                {
                    putchar(ope[top]);
                    top--;
                }
                end=0;
                break;
            case '+': case '-':
                while((top!=0)&&(ope[top]!='('))
                {
                    putchar(ope[top]);
                    top--;
                }
                top++;
                ope[top]=c;
                break;
            case '*': case '/':
                if((ope[top]!='*')&&(ope[top]!='/'))
                {
                    top++;
                    ope[top]=c;
                }
                else
                {
                    if(top!=0)
                    {
                        putchar(ope[top]);
                        top--;
                    }
                }
                break;
            case '(':
                top++;
                ope[top]=c;
                break;
            case ')':
                for(end_pop=1;end_pop;)
                {
                    switch(ope[top])
                    {
                        case '(': 
                            top--;
                            end_pop=0;
                            break;
                        default:
                            putchar(ope[top]);
                            top--;
                    }
                }
                break;
        }
    }
}
