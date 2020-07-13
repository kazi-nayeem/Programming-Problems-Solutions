#include<stdio.h>

#define MAX 140

int main()
{
    char strin[MAX], ch;
    int n;
    register int i, flag;
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        flag = 1;
        i = 0;
        ch = getchar();
        while(ch != '\n')
        {
            if(flag)
            {
                if(ch == '(' || ch == '[')
                {
                    strin[i++] = ch;
                }
                else if(ch == ')')
                {
                    if(i == 0)
                        flag = 0;
                    else if(strin[i - 1] == '(')
                    {
                        strin[--i] = 0;
                    }
                    else
                        flag = 0;
                }
                else if(ch == ']')
                {
                    if(i == 0)
                        flag = 0;
                    else if(strin[i - 1] == '[')
                    {
                        strin[--i] = 0;
                    }
                    else
                        flag = 0;
                }
                else
                    flag = 0;
            }
            ch = getchar();
        }
        if(flag && i == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
