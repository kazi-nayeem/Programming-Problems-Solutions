#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

#define MX 10005

int low[MX], vis[MX], res, timer;
vector<int> adj[MX];

void ariculation(int n,int par)
{
    int sz = adj[n].size();
    int v, lower, flag = 0, f2 = 0;
    lower = low[n] = vis[n] = timer++;
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(v == par) continue;
        if(low[v] == -1)
        {
            ariculation(v,n);
            f2++;
            if(vis[n] <= low[v] && n != 1) flag = 1;
        }
        if(lower > low[v]) lower = low[v];
    }
    if((n!=1 && flag == 1) || (n == 1 && f2 > 1))
        res++;
    low[n] = lower;
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
        timer = res = 0;
        ariculation(1,0);
        printf("Case %d: %d\n", te, res);
    }
    return 0;
}
