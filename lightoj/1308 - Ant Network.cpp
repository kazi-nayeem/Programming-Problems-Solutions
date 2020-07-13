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

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

int tim[MX], low[MX], timer;
vector<int> adj[MX];

stack<pii> S;
pii ed[MX*2];
int ans = 0;
ull ans2;

void calc_bcc(int u, int v)
{
    int i, j, uu, vv, cur;
    pii now;
    int tot = 0;
    while(!S.empty())
    {
        now = S.top();
        uu = now.first, vv = now.second;
        S.pop();
        ed[tot++] = make_pair(uu,vv);
        if(u == uu && v == vv) break;
        if(v == uu && u == vv) break;
    }
    if(tot<=1) return;
    ans += tot-1;
    ans2 *= tot-1;
}

void bcc(int u, int par)
{
    tim[u] = low[u] = ++timer;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == par) continue;
        S.push(make_pair(u,v));
        if(tim[v] == 0){
            bcc(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v]>=tim[u]) calc_bcc(u,v);
        }else{
            low[u] = min(low[u],low[v]);
        }
    }
}

void BCC(int n)
{
    ans = 0;
    ans2 = 1;
    timer = 0;
    memset(tim,0,sizeof tim);
    for(int i = 1; i <= n; i++)
    {
        if(tim[i] == 0){
            bcc(i,-1);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti, n, m, u, v;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++)
            adj[i].clear();
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            u++;
            v++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        BCC(n);
        printf("Case %d: %d %llu\n", te, n-ans, ans2);
    }
    return 0;
}


