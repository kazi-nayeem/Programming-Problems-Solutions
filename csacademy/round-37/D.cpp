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
ll BigMod(ll B,ll P,ll M)
{
    ll R=1%M;    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

vector<int> adj[MX];
vector<int> node[MX];
int flag[MX];
ll dp[MX];
int lev[MX];

void calc(int u, int l, int cur)
{
    int prlev = node[l-1].size();
    bool prco = false;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(flag[v] == 0) continue;
        if(lev[u] == lev[v]) cur--;
        else
        {
            prco = true;
            prlev--;
        }
    }
    dp[u] = BigMod(2,cur,mod);
    if(prco)
        dp[u] *= BigMod(2,prlev,mod);
    else if(prlev == 0)
        dp[u] = 0;
    else
        dp[u] *= (BigMod(2,prlev,mod)-1+mod)%mod;
    dp[u] %= mod;
    flag[u] = 1;
    //printf("%d %lld %d %d %d\n",u, dp[u], cur, prlev, prco);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    int mxlev = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &lev[i]);
        node[lev[i]].push_back(i);
        mxlev = max(mxlev,lev[i]);
        if(lev[i] == 0 && i != 1)
        {
            printf("0\n");
            return 0;
        }
    }
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if(abs(lev[u]-lev[v]) > 1)
        {
            printf("0\n");
            return 0;
        }
        if(lev[u]>=lev[v])
            adj[u].push_back(v);
        if(lev[v]>=lev[u])
            adj[v].push_back(u);
    }
    dp[1] = 1;
    for(int i = 1; i <= mxlev; i++)
    {
        for(int j = 0; j < node[i].size(); j++)
        {
            int u = node[i][j];
            calc(u,i,j);
        }
    }
    ll ans = 1;
    for(int i = 1; i <= n; i++)
        ans = (ans*dp[i])%mod;
    printf("%lld\n", ans%mod);
    return 0;
}

