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

ll bigmod(ll a, ll p, ll mod)
{
    if(p == 0ll) return 1ll;
    ll res = bigmod(a,p/2ll,mod);
    res = (res*res)%mod;
    if((p%2ll) == 1ll)
        res = (res*a)%mod;
    return res;
}

ll fact[MX];
ll ifact[MX];

ll ncr(int n, int r)
{
    if(n < r) return 0;
    if(n == r) return 1ll;
    ll res = (fact[n]*ifact[n-r])%mod;
    res = (res*ifact[r])%mod;
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fact[0] = 1;
    ifact[0] = 1;
    for(ll i = 1; i < MX; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        ifact[i] = bigmod(fact[i],mod-2, mod);
        //printf("%lld\n", ncr(i,i));
    }
    int te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int t = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf(" %d", &x);
            if(x == 0) t++;
        }
        ll res = 0;
        int ad = 2;
        if(t > 0) ad = 1;
        for(int i = 0; i <= k; i+=ad)
        {
            res += ncr(n-t,k-i);
            res %= mod;
        }
        printf("%lld\n", res);
    }
    return 0;
}


