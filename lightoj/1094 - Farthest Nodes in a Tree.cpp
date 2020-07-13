#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;
#define MX 30005

struct data
{
    int v;
    ll w;
    data() {}
    data(int a, ll b)
    {
        v = a;
        w = b;
    }
};

char flag[MX];
vector<data> adj[MX];
ll res;

ll dfs(int node);

int main()
{
    int te, ti, node, u, v;
    ll w, max1, max2;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &node);
        for(int i = 0; i <= node; i++)
        {
            flag[i] = 0;
            adj[i].clear();
        }
        for(int i = 1; i < node; i++)
        {
            scanf("%d %d %lld", &u, &v, &w);
            adj[u].push_back(data(v,w));
            adj[v].push_back(data(u,w));
        }
        res = 0;
        dfs(0);
        printf("Case %d: %lld\n", te,res);
    }
    return 0;
}

ll dfs(int node)
{
    flag[node] = 1;
    int sz = adj[node].size(), v;
    ll su = 0, max1 = 0, max2 = 0;
    for(int i = 0; i < sz; i++)
    {
        v = adj[node][i].v;
        if(flag[v] == 1) continue;
        su = dfs(v) + adj[node][i].w;
        if(su > max2)
        {
            max1 = max2;
            max2 = su;
        }
        else if(max1 < su)
            max1 = su;
    }
    if(res < max1+max2) res = max1+max2;
    return max2;
}
