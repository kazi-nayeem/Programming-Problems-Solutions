//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000
#define step 20

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

struct data
{
    int v, w;
    data(int a, int b)
    {
        v = a;
        w = b;
    }
};

struct data2
{
    ll sq, a;
    int child;
    data2()
    {
        sq = 0;
        a = 0;
        child = 0;
    }
    data2 operator + (const data2 & p) const
    {
        data2 res = p;
        res.a += a;
        res.child += child;
        res.sq += sq;
        return res;
    }
    data2 operator - (const data2 & p) const
    {
        data2 res;
        res.a = a - p.a;
        res.child = child - p.child;
        res.sq = sq - p.sq;
        return res;
    }
};

int node, T;
int parent[MX][step+1];
int start[MX], finish[MX];
int distan[MX], level[MX];
vector<data> adj[MX];
data2 lower[MX];
data2 upper[MX];


void dfs(int u, int p, int dis, int lev)
{
    start[u] = T++;
    level[u] = lev;
    distan[u] = dis;
    parent[u][0] = p;
    for(int i = 1; i <= step; i++)
        parent[u][i] = parent[parent[u][i-1]][i-1];
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i].v;
        if(v != p)
        {
            dfs(v,u,dis+adj[u][i].w,lev+1);
            lower[u] = lower[u]+lower[v];
        }
    }
    finish[u] = T++;
    lower[u].sq += lower[u].a*2+lower[u].child;
    lower[u].a += lower[u].child;
    lower[u].child++;
    return;
}

void dfs(int u, int p, data2 par)
{
    par.sq += par.child + par.a*2;
    par.a += par.child;
    upper[u] = par;
    data2 total = upper[u]+lower[u];
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i].v;
        if(v == p) continue;
        data2 tem = lower[v];
        tem.sq += tem.child + tem.a*2;
        tem.a += tem.child;
        dfs(v,u,total-tem);
    }
}

bool Is_Anchestor(int u, int v)
{
    if(start[u] <= finish[v] && finish[u] >= finish[v])
        return true;
    return false;
}
int LCA_Query(int u, int v)
{
    if(Is_Anchestor(u,v)) return u;
    if(Is_Anchestor(v,u)) return v;
    int tem = u;
    for(int i = step; i>=0; i--)
        if(!Is_Anchestor(parent[tem][i],v))
            tem = parent[tem][i];
    return parent[tem][0];
}
int Kth_Query(int u, int k)
{
    int tem = u;
    for(int i = step; i>=0; i--)
        if((k>>i)&1 == 1)
            tem = parent[tem][i];
    return tem;
}
void lca_cls(void)
{
    for(int i = 0; i <= node; i++)
    {
        adj[i].clear();
        for(int j = 0; j <= step; j++)
            parent[i][j] = 1;
    }
}
void input()
{
    int u, v, w;
    scanf("%d", &node);
    lca_cls();
    for(int i = 1; i < node; i++)
    {
        u = i+1;
        w = 1;
        scanf("%d", &v);
        adj[u].push_back(data(v,w));
        adj[v].push_back(data(u,w));
    }
}

int distance_uv(int u, int v)
{
    int lca = LCA_Query(u,v);
    int res = distan[u]+distan[v]-2*distan[lca];
    return res;
}

int main()
{
    input();
    T = 0;
    dfs(1,1,0,1);
    dfs(1,1,data2());
    /*for(int i = 1; i <= node; i++)
        printf("%d ->%lld %lld %d\n", i, lower[i].sq, lower[i].a, lower[i].child);
    for(int i = 1; i <= node; i++)
        printf("%d ->%lld %lld %d\n", i, upper[i].sq, upper[i].a, upper[i].child);
    */
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if(u == v)
        {
            printf("%lld\n", lower[u].sq);
            continue;
        }
        ll dis = distance_uv(u,v);
        if(Is_Anchestor(v,u))
        {
            ll res = lower[u].sq;
            ll tem = upper[v].sq + 2*upper[v].a*dis + dis*dis*upper[v].child;
            res += upper[u].sq-tem;
            printf("%lld\n", res);
        }
        else
        {
            ll res = lower[v].sq + 2*lower[v].a*dis + dis*dis*lower[v].child;
            printf("%lld\n", res);
        }
    }
}


