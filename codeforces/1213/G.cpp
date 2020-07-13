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
#include<complex>
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

#define MX 200005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

struct data
{
    int u, v, w;
    bool operator < (const data &p) const
    {
        return w<p.w;
    }
};

data arr[MX];
int par[MX];
int cnt[MX];
pii query[MX];
ll answer[MX];

int find_par(int u)
{
    if(u == par[u])
        return u;
    return par[u] = find_par(par[u]);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].w);
    }
    for(int i = 0; i <= n; i++)
    {
        par[i] = i;
        cnt[i] = 1;
    }

    for(int i = 1; i <= q; i++)
    {
        scanf("%d", &query[i].first);
        query[i].second = i;
    }
    sort(arr+1, arr+n);
    sort(query+1, query+1+q);
    ll sum = 0;
    int pos = 1;
    for(int i = 1; i <= q; i++)
    {
        while(pos<n && arr[pos].w<=query[i].first)
        {
            int u = find_par(arr[pos].u);
            int v = find_par(arr[pos].v);
            sum += (ll) cnt[u]*cnt[v];
            par[u] = v;
            cnt[v] += cnt[u];
            cnt[u] = 0;
            pos++;
        }
        answer[query[i].second] = sum;
    }
    for(int i = 1; i <= q; i++)
        printf("%lld ", answer[i]);
    return 0;
}

