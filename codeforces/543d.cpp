#include<cstdio>
#include<cstring>
#include<iostream>
#include<cctype>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
#define MX 200005

const ll mod = 1000000007ll;

vector<int> adj[MX];
ll total[MX];
ll tree[MX];

ll bigmod(ll a, ll p, ll mod)
{
    if(p == 0) return 1ll;
    ll res = bigmod(a,p/2ll,mod);
    res = (res*res)%mod;
    if((p%2ll) == 1ll)
        res = (res*a)%mod;
    return res;
}

ll dfs(int node, int par)
{
    ll res = 1;
    for(int i = 0; i < adj[node].size(); i++)
    {
        if(par == adj[node][i]) continue;
        ll tem = (dfs(adj[node][i], node)+1ll)%mod;
        res *= tem;
        res %= mod;
    }
    return tree[node] = res;
}

void dfs2(int node, int par)
{
    total[node] = total[par];
    total[node] *= bigmod((tree[node]+1)%mod,mod-2,mod);
    total[node] %= mod;
    total[node]++;
    total[node] %= mod;
    total[node] *= tree[node];
    total[node] %= mod;
    for(int i = 0; i < adj[node].size(); i++)
    {
        if(par == adj[node][i]) continue;
        dfs2(adj[node][i], node);
    }
    return ;
}

int main()
{
    int node, u, v;
    scanf("%d", &node);
    for(int i = 2; i <= node; i++)
    {
        scanf("%d", &v);
        adj[v].push_back(i);
        adj[i].push_back(v);
    }
    total[1] = dfs(1,1);
    for(int i = 0; i < adj[1].size(); i++)
        dfs2(adj[1][i],1);
    for(int i = 1; i <= node; i++)
        cout<<total[i]<<" ";
        puts("");
    for(int i = 1; i <= node; i++)
        cout<<tree[i]<<" ";
    return 0;
}
