#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

int main()
{
    stack<char> stk;
    char str[55], ch, ch2;
    int test, i;
    scanf("%d", &test);
    getchar();
    getchar();

    while(test--)
    {
        i = 0;
        while(!stk.empty()) stk.pop();
        stk.push('(');
        while(1)
        {
            ch = getchar();
            if(ch != '\n')
                getchar();
            if(ch == '\n' || ch == ')')
            {
                while(1)
                {
                    ch2 = stk.top();
                    stk.pop();
                    if(ch2 == '(') break;
                    str[i++] = ch2;
                }
                if(ch == '\n') break;
            }
            if(ch >= '0' && ch <= '9')
            {
                str[i++] = ch;
                continue;
            }
            if(ch == '*' || ch == '/')
            {
                stk.push(ch);
                continue;
            }
            if(ch == '-' || ch == '+')
            {
                while(1)
                {
                    ch2 = stk.top();
                    if(ch2 == '*' || ch2 == '/')
                    {
                        stk.pop();
                        str[i++] = ch2;
                    }
                    else
                        break;
                }
                stk.push(ch);
            }
        }
        str[i] = '\0';
        puts(str);
        if(test)
            putchar('\n');
    }
    return 0;
}
