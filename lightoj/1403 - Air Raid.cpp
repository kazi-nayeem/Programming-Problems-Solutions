#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 1005

vector<int> adj[MX];
int flag[MX];
int match[MX];
int te, ti, n, m, u, v, total, now;

bool Bipartite_Match(int n)
{
    int v;
    int sz = adj[n].size();
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(flag[v] == now) continue;
        flag[v] = now;
        if(match[v] == -1 || Bipartite_Match(match[v]))
        {
            match[v] = n;
            return true;
        }
    }
    return false;
}

void graph_cls(void)
{
    for(int i = 0; i <= n; i++) adj[i].clear();
    memset(match,-1,sizeof match);
    total = 0;
}

void input()
{
    scanf("%d%d", &n, &m);
    graph_cls();
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
}

int main()
{
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        input();
        for(int i = 1; i <= n; i++)
        {
            now++;
            if(Bipartite_Match(i)) total++;
        }
        printf("Case %d: %d\n", te, n-total);
    }
    return 0;
}
