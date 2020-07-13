#include<cstdio>
using namespace std;

#define ll long long int

ll mod, n;

ll bigmod(int p)
{
    if(p == 0) return 1;
    if(p&1 == 1)
        return (n*bigmod(p-1))%mod;
    ll res = bigmod(p/2);
    return (res*res)%mod;
}

int main()
{
    int te, ti, k, tem;
    ll res;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%lld%d%lld", &n, &k, &mod);
        res = 0;
        for(ll i = 0; i < n; i++)
        {
            scanf("%d", &tem);
            res += tem;
        }
        res %= mod;
        res *= bigmod(k-1);
        res %= mod;
        res *= k;
        res %= mod;
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}
