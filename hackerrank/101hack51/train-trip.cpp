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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

struct data
{
    int u;
    ll c;
    data(int u, ll c): u(u), c(c) {}
    bool operator<(const data & p) const
    {
        return c>p.c;
    }
};

const ll mod = 1000000007ll;

vector<int> adj[MX];


void bfs(int n, int s, ll dis[MX])
{
    for(int i = 0; i <= n; i++)
        dis[i] = mod;
    queue<int> qu;
    dis[s] = 0;
    qu.push(s);
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dis[v] == mod)
            {
                dis[v] = dis[u]+1;
                qu.push(v);
            }
        }
    }
}

void dijkstra(int n, ll dis[], ll dis1[], ll dis2[], ll cc)
{
    priority_queue<data> qu;
    for(int i = 1; i <= n; i++)
    {
        dis[i] = dis1[i]+dis2[i];
        qu.push(data(i,dis[i]));
    }
    while(!qu.empty())
    {
        int u = qu.top().u;
        ll cos = qu.top().c;
        qu.pop();
        if(cos>dis[u]) continue;
        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            ll w = cos+cc;
            if(dis[v]<=w) continue;
            dis[v] = w;
            qu.push(data(v,w));
        }
    }
}

ll dis1[MX];
ll dis2[MX];
ll dis3[MX];

ll dis12[MX];
ll dis13[MX];
ll dis23[MX];

ll res[MX];

ll a, b, c;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, n, u, v, p, q, r;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %lld %lld %lld", &n, &a, &b, &c);
        scanf("%d %d %d", &p, &q, &r);
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(n,p,dis1);
        bfs(n,q,dis2);
        bfs(n,r,dis3);
        for(int i = 1; i <= n; i++)
        {
            dis1[i] *= a;
            dis2[i] *= a;
            dis3[i] *= a;
        }
        dijkstra(n,dis12,dis1,dis2,b);
        dijkstra(n,dis13,dis1,dis3,b);
        dijkstra(n,dis23,dis2,dis3,b);

        dijkstra(n,res,dis12,dis3,c);
        ll ans = res[1];
        dijkstra(n,res,dis13,dis2,c);
        ans = min(ans,res[1]);
        dijkstra(n,res,dis23,dis1,c);
        ans = min(ans,res[1]);
        printf("%lld\n", ans);
    }
    return 0;
}


