#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<set>
using namespace std;

#define MX 10005

int low[MX], vis[MX], res, timer;
vector<int> adj[MX];
set<int> s;

void ariculation(int n,int par)
{
    int sz = adj[n].size();
    int v, f2 = 0;
    low[n] = vis[n] = timer++;
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(v == par) continue;
        if(low[v] == -1)
        {
            f2++;
            ariculation(v,n);
            low[n] = min(low[v],low[n]);
            if(vis[n] <= low[v] && n != 1) s.insert(n);
        }
        low[n] = min(vis[v],low[n]);
    }
    if((f2 > 1 && n == 1))
        s.insert(n);
}

int main()
{
    int te, ti, node, edge, u, v;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &node, &edge);
        for(int i = 0; i <= node; i++)
            adj[i].clear();
        memset(low,-1,sizeof low);
        for(int i = 0; i < edge; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        timer = 0;
        s.clear();
        ariculation(1,1);
        printf("Case %d: %d\n", te, (int)s.size());
    }
    return 0;
}
