#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

char input[100];

void print(void)
{
    char outp[100], ch;
    stack<char> st;
    int pos = 0;
    //gets(input);
    int len = strlen(input);
    st.push('(');
    input[len] = ')';
    for(int i = 0; i <= len; i++)
    {
        ch = input[i];
        if(ch >= '0' && ch <= '9')
            outp[pos++] = ch;
        else if(ch == '(')
            st.push('(');
        else if(ch == ')')
        {
            while(st.top() != '(')
            {
                outp[pos++] = st.top();
                st.pop();
            }
            st.pop();
        }
        else if(ch == '+')
        {
            while(st.top() == '*' || st.top() == '/' || st.top() == '-' || st.top() == '+')
            {
                outp[pos++] = st.top();
                st.pop();
            }
            st.push('+');
        }
        else if(ch == '-')
        {
            while(st.top() == '*' || st.top() == '/' || st.top() == '+' || st.top() == '-')
            {
                outp[pos++] = st.top();
                st.pop();
            }
            st.push('-');
        }
        else if(ch == '*')
        {
            while(st.top() == '/' || st.top() == '*')
            {
                outp[pos++] = st.top();
                st.pop();
            }
            st.push('*');
        }
        else if(ch == '/')
        {
            while(st.top() == '*' || st.top() == '/')
            {
                outp[pos++] = st.top();
                st.pop();
            }
            st.push('/');
        }
    }
    outp[pos] = '\0';
    puts(outp);
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    char ch[5];
    int ti;
    scanf("%d", &ti);
    getchar();
    getchar();
    int pos = 0;
    while(ti--)
    {
        pos = 0;
        while(gets(ch))
        {
            if(ch[0] == '\n'|| ch[0] == '\0')
            {
                break;
            }
            input[pos++] = ch[0];
        }
        input[pos] = '\0';
        print();
        if(ti) puts("");
    }
    return 0;
}
