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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    return 0;
}

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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int node, T;
int parent[MX][step+1];
int start[MX], finish[MX];
int distan[MX], level[MX];
vector<data> adj[MX];

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
        v = adj[u][i].v;
        if(v != p)
            dfs(v,u,dis+adj[u][i].w,lev+1);
    }
    finish[u] = T++;
    return;
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
    scanf("%d", &node);
    lca_cls();
    for(int i = 1; i < node; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(data(v,w));
        adj[v].push_back(data(u,w));
    }
}
int main()
{
    input();
    T = 0;
    dfs(1,1,0,1);
    lca = LCA_Query(u,v);
    res = distan[u]+distan[v]-2*distan[lca];
    ///distance
    w--;///find w'th node
    if(level[u]-level[lca] == w) res = lca;
    else if(level[u]-level[lca] > w)
        res = Kth_Query(u,w);
    else
        res = Kth_Query(v,level[u]+level[v]-2*level[lca]-w);
}


