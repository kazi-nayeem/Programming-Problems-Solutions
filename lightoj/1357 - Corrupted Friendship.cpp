#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

#define MX 100005
#define ll long long

vector<int> adj[MX];
int child[MX], vis;
ll res;

int dfs(int n)
{
    if(child[n] != -1) return 0;
    child[n] = 0;
    vis++;
    for(int i = 0; i < adj[n].size(); i++)
    {
        int a = dfs(adj[n][i]);
        res += (ll) child[n]*a;
        child[n] += a;
    }
    child[n]++;
    return child[n];
}

int main()
{
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int node, u, v;
        scanf("%d", &node);
        for(int i = 0; i <= node; i++) adj[i].clear();
        memset(child, -1, sizeof child);
        for(int i = 1; i < node; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        vis = 0;
        res = 0;
        dfs(1);
        printf("Case %d: %d %lld\n", te, vis-1, res);
    }
    return 0;
}
