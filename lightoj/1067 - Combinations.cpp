#include<cstdio>
using namespace std;

#define MX 1000005
#define mod 1000003
#define ll long long int

ll arr[MX];

ll bigMod(int n, int p)
{
    if(p == 0) return 1;

    ll big = bigMod(n,p/2);

    if(p&1) return (big*big*n)%mod;
    return (big*big)%mod;
}

int main()
{
    arr[0] = 1;
    for(int i = 1; i < MX; i++)
        arr[i] = (arr[i-1]*i)%mod;

    int te, ti, k, n, res;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &k);
        printf("Case %d: %lld\n", te, (arr[n]*bigMod(arr[k],mod-2)*bigMod(arr[n-k],mod-2))%mod);
    }
    return 0;
}
