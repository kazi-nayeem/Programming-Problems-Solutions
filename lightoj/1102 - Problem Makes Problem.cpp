#include<cstdio>
using namespace std;

#define ll long long

const ll mod = 1000000007LL;

ll big_mod(ll p, ll n)
{
    if(p == 0LL) return 1;
    if(p&1LL)
        return (n*big_mod(p-1,n))%mod;
    ll res = big_mod(p/2,n);
    return (res*res)%mod;
}

#define MX 2000005

ll fact[MX];

int main()
{
    fact[0] = 1;
    for(int i = 1; i < MX; i++)
        fact[i] = (fact[i-1]*i)%mod;
    int te, ti;
    ll n, k, res;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld%lld", &n, &k);
        res = fact[n+k-1];
        res *= big_mod(mod-2,fact[k-1]);
        res %= mod;
        res *= big_mod(mod-2,fact[n]);
        res %= mod;
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}
