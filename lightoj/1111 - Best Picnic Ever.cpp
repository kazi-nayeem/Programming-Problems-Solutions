#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int visit[1005], flag[1005], pos[105];
int total, k;
vector<int> adj[1005];

void dfs(int node);
void dfs2(int node);

int main()
{
    int n, m, te, ti, u, v;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d", &k, &n, &m);

        for(int i = 0; i <= n; i++) adj[i].clear();
        memset(visit,0,sizeof visit);

        for(int i = 0; i < k; i++)
            scanf("%d", &pos[i]);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
        }
        total = 0;
        for(int i = 1; i < k; i++)
        {
            memset(flag,0,sizeof flag);
            dfs2(pos[i]);
        }
        memset(flag,0,sizeof flag);
        dfs(pos[0]);
        printf("Case %d: %d\n", te, total);
    }
    return 0;
}

void dfs(int node)
{
    if(flag[node] == 1) return;
    visit[node]++;
    flag[node] = 1;
    if(visit[node] == k) total++;
    int sz = adj[node].size();
    for(int i = 0; i < sz; i++)
        dfs(adj[node][i]);
    return;
}

void dfs2(int node)
{
    if(flag[node] == 1) return;
    visit[node]++;
    flag[node] = 1;
    int sz = adj[node].size();
    for(int i = 0; i < sz; i++)
        dfs(adj[node][i]);
    return;
}
