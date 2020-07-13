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

vector<pair<int,int> > adj[MX];
int flag[MX];
ll value[MX];
int par[MX];

void dfs(int u, ll p)
{
    if(value[u] < p) return;
    if(flag[u]) return;
    flag[u] = 1;
    ll ne = max(0ll,p);
    for(int i = 0; i < adj[u].size(); i++)
    {
        dfs(adj[u][i].first,ne+adj[u][i].second);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &value[i]);
    }
    for(int i = 2; i <= n; i++)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        adj[i].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(i,w));
    }
    dfs(1,0);
    int res = 0;
    for(int i= 1; i <= n; i++)
    {
        if(flag[i] == 0) res++;
        //printf("%d %d %d\n", par[i], flag[i], i);
    }
    printf("%d\n", res);
    return 0;
}


