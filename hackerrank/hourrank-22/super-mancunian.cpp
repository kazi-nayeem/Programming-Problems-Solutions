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

#define MX 1000005
#define inf 100000000

const ll mod = 1000000007ll;

struct data
{
    int u, v;
    ll w;
    bool operator < (const data &p) const
    {
        return w < p.w;
    }
};

int par[MX];

int find_par(int u)
{
    if(par[u] == u) return u;
    return par[u] = find_par(par[u]);
}

data arr[MX];
int n, m;
ll res, mxe;

void MST()
{
    ll total = 0;
    mxe = 0;
    for(int i = 0; i <= n; i++)
        par[i] = i;
    sort(arr,arr+m);
    for(int i = 0; i < m; i++)
    {
        int u = find_par(arr[i].u);
        int v = find_par(arr[i].v);
        if(u == v) continue;
        par[u] = v;
        mxe = max(mxe,arr[i].w);
        total += arr[i].w;
    }
    res = total - mxe;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
        scanf("%d %d %lld", &arr[i].u, &arr[i].v, &arr[i].w);
    MST();
    int com = 0;
    for(int i = 0; i <= n; i++) par[i] = i;
    for(int i = 0; i < m; i++)
    {
        int u = find_par(arr[i].u);
        int v = find_par(arr[i].v);
        if(u == v) continue;
        if(arr[i].w<mxe) par[u] = v;
        else com++;
    }
    printf("%lld %d\n", res, com);
    return 0;
}


