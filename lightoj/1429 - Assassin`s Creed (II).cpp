#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;

#define MX 2000

vector<int>  adj[MX], radj[MX], newadj[MX];
map<int,int> mp[MX];
int vis[MX], timer, node, edge;

stack<int> st;

void scc_cls()
{
    for(int i = 0; i <= node; i++)
    {
        adj[i].clear();
        radj[i].clear();
    }
}

void scc_dfs(int n)
{
    if(vis[n] == -1) return;
    vis[n] = -1;
    for(int i = 0; i < adj[n].size(); i++)
        scc_dfs(adj[n][i]);
    st.push(n);
    return;
}

void scc_dfs2(int n)
{
    vis[n] = timer;
    int v;
    for(int i = 0; i < radj[n].size(); i++)
    {
        v = radj[n][i];
        if(vis[v] == -1)
            scc_dfs2(v);
    }
    return;
}

int scc()
{
    while(!st.empty()) st.pop();
    memset(vis,0,sizeof vis);
    for(int i = 1; i <= node; i++)
    {
        scc_dfs(i);
    }
    int a;
    timer = 0;
    while(!st.empty())
    {
        a = st.top();
        st.pop();
        if(vis[a] == -1)
        {
            timer++;
            scc_dfs2(a);
        }
    }
    return timer;
}

void scc_connect(int a, int b)
{
    adj[a].push_back(b);
    radj[b].push_back(a);
}

int newnode, now;

void new_dfs(int n, int par)
{
    if(vis[n] == now) return;
    vis[n] = now;
    for(int i = 0; i < newadj[n].size(); i++)
    {
        new_dfs(newadj[n][i], par);
    }
    if(n != par)
        adj[par].push_back(n);
}

int match[MX];

bool Bipartite_Match(int n)
{
    int v;
    int sz = adj[n].size();
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(vis[v] == now) continue;
        vis[v] = now;
        if(match[v] == -1 || Bipartite_Match(match[v]))
        {
            match[v] = n;
            return true;
        }
    }
    return false;
}

int func()
{
    memset(vis,0,sizeof vis);
    for(int i = 1; i <= newnode; i++)
    {
        now++;
        new_dfs(i,i);
    }
    int total = 0;
    memset(match,-1,sizeof match);
    for(int i = 1; i <= newnode; i++)
    {
        now++;
        if(Bipartite_Match(i)) total++;
    }
    return newnode - total;
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &node, &edge);
        scc_cls();
        for(int i = 1; i <= edge; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            scc_connect(a,b);
        }
        newnode = scc();
        //printf("%d\n", newnode);
        //for(int i = 1; i <= node; i++)
        //  printf("%d ", vis[i]);
        //puts("\n");
        for(int i = 0; i <= newnode; i++)
        {
            newadj[i].clear();
            mp[i].clear();
        }
        int u, v;
        for(int i = 1; i <= node; i++)
        {
            u = vis[i];
            for(int j = 0; j < adj[i].size(); j++)
            {
                v = vis[adj[i][j]];
                if(mp[u].find(v) == mp[u].end())
                {
                    mp[u][v] = 1;
                    newadj[u].push_back(v);
                }
            }
        }
        scc_cls();
        int ans = func();
        printf("Case %d: %d\n", te, ans);

    }
}
