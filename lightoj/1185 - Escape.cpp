#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector <int> adj[101];
int flag[101][2];
int total, k;

void dfs(int node, int f)
{
    if(flag[node][f] == 1) return;
    if(f&&k) total++;
    if(k) flag[node][f] = 1;
    k = 1;
    f = (f+1)&1;
    int sz = adj[node].size();

    for(int i = 0; i < sz; i++)
        dfs(adj[node][i],f);

    return;
}

int main()
{
    int te, ti, n, u, v, m;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n,&m);
        for(int i = 1; i <= n; i++)
            adj[i].clear();
        memset(flag,0,sizeof flag);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        total = 0;
        k = 0;
        dfs(1,1);
        printf("Case %d: %d\n", te, total);
    }
    return 0;
}
