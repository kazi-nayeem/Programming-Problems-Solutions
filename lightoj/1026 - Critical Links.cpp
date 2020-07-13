#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#include<algorithm>
using namespace std;

#define MX 10005

struct data
{
    int u, v;
    data() {}
    data(int a, int b): u(a), v(b) {}
    bool operator < (const data & p) const
    {
        if(u == p.u) return v<p.v;
        return u<p.u;
    }
};

int low[MX], vis[MX];
vector<int> adj[MX];
vector<data> vc;
int timer;

void dfs(int n, int par)
{
    int sz = adj[n].size();
    int v, lower;
    lower = vis[n] = low[n] = timer++;
    for(int i = 0; i < sz; i++)
    {
        v = adj[n][i];
        if(v == par) continue;
        if(low[v] == -1)
            dfs(v,n);
        lower = min(lower,low[v]);
        if(vis[n] < low[v])
        {
            if(n < v)
                vc.push_back(data(n,v));
            else
                vc.push_back(data(v,n));
        }
    }
    low[n] = lower;
}


int main()
{
    int te, ti, node, edge, u, v;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        timer = 1;
        scanf("%d", &node);
        for(int i = 0; i <= node; i++)
            adj[i].clear();
        memset(low, -1, sizeof low);
        for(int i = 0; i < node; i++)
        {
            scanf("%d (%d)", &u, &edge);
            while(edge--)
            {
                scanf("%d", &v);
                adj[u].push_back(v);
                //adj[v].push_back(u);
            }
        }
        vc.clear();
        for(int i = 0; i < node; i++)
            if(low[i] == -1)
                dfs(i,0);
        int v, sz;
        sz = vc.size();
        sort(vc.begin(),vc.end());
        printf("Case %d:\n", te);
        printf("%d critical links\n", sz);
        for(int i = 0; i < sz; i++)
            printf("%d - %d\n", vc[i].u, vc[i].v);
    }
    return 0;
}
