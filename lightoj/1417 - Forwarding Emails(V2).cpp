#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define MX 50005

int adj[MX];
int col[MX];
stack<int> st;

int dfs(int n)
{
    if(col[n] == 1) return 0;
    col[n] = 1;
    return 1+dfs(adj[n]);
}

int main()
{
    int te, ti, node, u, v;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &node);
        for(int i = 1; i <= node; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u] = v;
        }
        int mx = 0, no = 0, tm, tmd;
        memset(col,0, sizeof col);
        for(int i = 1; i <= node; i++)
        {
            if(col[i] == 0)
            {
                st.push(i);
                dfs(i);
            }
        }
        memset(col,0, sizeof col);
        while(!st.empty())
        {
            tm = st.top();
            st.pop();
            if(col[tm] == 0)
            {
                tmd = dfs(tm);
                if(tmd > mx) mx = tmd, no = tm;
            }
        }
        printf("Case %d: %d\n",te, no);
    }
    return 0;
}
