/*
    MD. Kazi Nayeem
    SUST
    Bangladesh
*/

#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

#define MX 16005

vector<int> adj[MX], res;
vector<int> radj[MX];
int vis[MX];
int timer;
stack<int> st;

void dfs(int n)
{
    vis[n] = -1;
    int sz = adj[n].size();
    for(int i = 0; i < sz; i++)
    {
        if(vis[adj[n][i]] == -1) continue;
        dfs(adj[n][i]);
    }
    st.push(n);
    return;
}
void dfs2(int n)
{
    vis[n] = timer;
    int sz = radj[n].size(), v;
    for(int i = 0; i < sz; i++)
    {
        v = radj[n][i];
        if(vis[v] == -1)
            dfs2(v);
    }
    return;
}
int main()
{
    int te, ti, n, m, a, b;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= (m<<1); i++)
            adj[i].clear(), radj[i].clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            adj[m-a].push_back(m+b);
            adj[m-b].push_back(m+a);
            radj[m+a].push_back(m-b);
            radj[m+b].push_back(m-a);
        }
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= m; i++)
        {
            if(vis[m-i] == 0)
            {
                dfs(m-i);
            }
            if(vis[m+i] == 0)
            {
                dfs(i+m);
            }
        }
        timer = 1;
        while(!st.empty())
        {
            a = st.top();
            st.pop();
            if(vis[a] == -1)
                dfs2(a);
            timer++;
        }
        res.clear();
        bool flag = false;
        for(int i = 1; i <= m; i++)
        {
            if(vis[i+m] == vis[m-i])
            {
                flag = true;
                //printf("%d\n", i);
                break;
            }
            if(vis[i+m] > vis[m-i])
                res.push_back(i);
        }
        if(flag)
        {
            printf("Case %d: No\n", te);
            continue;
        }
        printf("Case %d: Yes\n%d", te, res.size());
        for(int i = 0; i < res.size(); i++)
            printf(" %d", res[i]);
        putchar('\n');
    }
    return 0;
}
