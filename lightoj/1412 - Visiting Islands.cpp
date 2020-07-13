#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

#define MX 100005
#define inf 100000000

vector<int> adj[MX];
int res[MX];
char flag[MX];
int last, len, vis;

void dfs(int n, int dis)
{
    if(flag[n] != 0) return;
    flag[n] = 1;
    vis++;
    if(dis > len)
    {
        len = dis;
        last = n;
    }
    for(int i = 0; i < adj[n].size(); i++)
        dfs(adj[n][i], dis+1);
    return;
}

void dfs2(int n, int dis)
{
    if(flag[n] != 1) return;
    flag[n] = 2;
    if(dis > len)
    {
        len = dis;
    }
    for(int i = 0; i < adj[n].size(); i++)
        dfs2(adj[n][i], dis+1);
    return;
}

void func(int node)
{
    memset(flag,0,sizeof flag);
    for(int i = 1; i <= node; i++)
    {
        if(flag[i] != 0) continue;
        last = -1;
        len = -1;
        vis = 0;
        dfs(i,0);

        len = -1;
        dfs2(last,0);
        //printf("%d\n", vis);
        for(int i = 0; i <= len; i++)
            res[i+1] = min(res[i+1], i);
        for(int i = len+1; i < vis; i++)
            res[i+1] = min(res[i+1], len+(i-len)*2);
    }
}

int main()
{
    int te, ti, node, edge, q, k, u, v;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &node, &edge);
        for(int i = 0; i <= node; i++)
        {
            adj[i].clear();
            res[i] = inf;
        }

        for(int i = 0; i < edge; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        func(node);

        scanf("%d", &q);
        printf("Case %d:\n", te);
        for(int i = 0; i < q; i++)
        {
            scanf("%d", &k);
            if(k > node || res[k] == inf)
                puts("impossible");
            else
                printf("%d\n", res[k]);
        }
    }
    return 0;
}

