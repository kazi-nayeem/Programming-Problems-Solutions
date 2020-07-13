#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;

#define MX 10005

vector<int> adj[MX];
int value[MX], res;

int dfs(int n, int par)
{
    int child = value[n]-1;
    for(int i = 0; i < adj[n].size(); i++)
    {
        if(adj[n][i] == par) continue;
        child += dfs(adj[n][i],n);
    }
    res += abs(child);
    //printf("child %d %d\n", n, child);
    return child;
}

int main()
{
    int te, ti, n, u, v, k;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) adj[i].clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &u);
            scanf("%d %d", &value[u], &k);
            for(int j = 0; j < k; j++)
            {
                scanf("%d", &v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        res = 0;
        dfs(1,1);
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
