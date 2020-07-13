#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long

const ll mod = 1000000007ll;

//int arr[1005];
ll fact[1000005];
//ll ifact[1000005];

ll bigmod(ll a, ll p)
{
    int pos;
    for(pos = 32; pos >= 0; pos--)
    {
        if((p>>pos)&1ll)
            break;
    }
    ll res = 1ll;
    for(;pos>= 0; pos--)
    {
        res = (res*res)%mod;
        if((p>>pos)&1ll)
            res = (res*a)%mod;
    }
    return res;
}

int main()
{
    fact[0] = 1;
    //ifact[0] = 1;
    for(int i = 1; i < 1000003; i++)
    {
        fact[i] = ((ll)fact[i-1]*i)%mod;
        //ifact[i] = bigmod(fact[i],mod-2);
    }
    int te, ti, n, x, total;
    ll res;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        res = 1ll;
        scanf("%d %d", &n, &total);
        for(int i = 1; i < n; i++)
        {
            scanf("%d", &x);
            res = (res*fact[total+x-1])%mod;
            res = (res*bigmod(fact[total],mod-2))%mod;
            res = (res*bigmod(fact[x-1],mod-2))%mod;
            total += x;
        }
        printf("Case %d: %lld\n", te, res);
    }
    return 0;
}
