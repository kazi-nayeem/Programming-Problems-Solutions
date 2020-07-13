#include<cstdio>
#include<stack>
using namespace std;

int main()
{
    int n, m, k, te = 0;
    stack<int> st;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) return 0;
        if(te) putchar('\n');
        te = 1;
        while(scanf("%d", &k) == 1)
        {
            if(k == 0) break;
            m = 1;
            int flag = 0;
            while(!st.empty()) st.pop();
            if(k == m)
                m++;
            else
            {
                for(;m < k; m++)
                    st.push(m);
                m = k+1;
            }
            for(int i = 1; i < n; i++)
            {
                scanf("%d", &k);
                if(flag) continue;
                if(k == m)
                    m++;
                else if(m < k)
                {
                    for(;m<k;m++)
                        st.push(m);
                    m = k+1;
                }
                else if(!st.empty())
                {
                    if(st.top() == k)
                        st.pop();
                    else
                        flag = 1;
                }
                else
                    flag = 1;
            }
            if(flag == 0)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
