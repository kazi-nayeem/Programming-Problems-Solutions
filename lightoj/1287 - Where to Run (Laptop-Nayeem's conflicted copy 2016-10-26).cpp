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

#define MX 20
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

double dp[15][1<<15];
int cs[15][1<<15];
int n, m, te;
vector<pii> adj[MX];
int con[MX];

double func(int mask, int u)
{
    double & res = dp[u][mask];
    int & vs = cs[u][mask];
    if(vs == te) return res;
    res = 0.0;
    vs = te;
    int x = popc((~mask)&con[u]);
    if(x == 0) return res;
    x++;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        memset(con,0,sizeof con);
        int u, v, w;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
            con[u] |= 1<<v;
            con[v] |= 1<<u;
        }
        printf("Case %d: %lf\n", te, func(0,0));
    }
    return 0;
}


