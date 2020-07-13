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

vector<int> adj[MX];
vector<pii> grop[MX];
int now;
int weig[MX];
int bu[MX];
int flag[MX];

pii dfs(int u)
{
    if(flag[u]) return make_pair(0,0);
    flag[u] = 1;
    pii res = make_pair(0,0);
    for(int i = 0; i < adj[u].size(); i++)
    {
        pii tem = dfs(adj[u][i]);
        res.first += tem.first;
        res.second += tem.second;
    }
    res.first += weig[u];
    res.second += bu[u];
    grop[now].push_back(make_pair(weig[u],bu[u]));
    return res;
}

ll dp[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, w;
    scanf("%d %d %d", &n, &m, &w);
    for(int i = 1; i <= n; i++)
        scanf("%d", &weig[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &bu[i]);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        if(flag[i]) continue;
        now++;
        pii tem = dfs(i);
        grop[now].push_back(tem);
    }
    for(int i = 1; i <= now; i++)
    {
        for(int j = w; j > 0; j--)
        {
            for(int k = 0; k < grop[i].size(); k++)
            {
                if(grop[i][k].first > j) continue;
                dp[j] = max(dp[j],grop[i][k].second+dp[j-grop[i][k].first]);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i <= w; i++)
        res = max(res,dp[i]);
    printf("%I64d\n", res);
    return 0;
}

