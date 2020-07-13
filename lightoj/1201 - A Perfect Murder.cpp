#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MX 1005

vector<int> adj[MX];
int flag[MX];
int match[MX];

bool Bipartite_Match(int n)
{
    int v;
    int sz = adj[n].size();
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(flag[v] == 1) continue;
        flag[v] = 1;
        if(match[v] == -1 || Bipartite_Match(match[v]))
        {
            match[v] = n;
            return true;
        }
    }
    return false;
}

int main()
{
    int te, ti, n, m, u, v, total;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++) adj[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(match,-1,sizeof match);
        total = 0;
        for(int i = 1; i <= n; i++)
        {
            memset(flag,0,sizeof flag);
            if(Bipartite_Match(i)) total++;
        }
        printf("Case %d: %d\n", te, n - total/2);
    }
    return 0;
}
