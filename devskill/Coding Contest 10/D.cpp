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

#define MX 1005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000009ll;

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

ll dp[MX][MX];

ll func(int n, int r)
{
    if(r == 0)
    {
        if(n == 0) return 1;
        return 0;
    }
    if(n < 0) return 0;
    ll & res = dp[n][r];
    if(res != -1) return res;
    res = 0;
    if(n>=r)
        res += func(n-r,r);
    res += func(n,r-1);
    res %= mod;
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te, ti;
    memset(dp,-1,sizeof dp);
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        printf("Case %d: %lld\n", te, func(n-k,k));
    }
    return 0;
}


