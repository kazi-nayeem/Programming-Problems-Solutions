#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define MX 1000050
#define MXP 78502
#define ll long long int

int prime[MXP];
int flag[MX];

void sieve(void);

int main()
{
    sieve();
    ll n, sq, res, m;
    int te, ti;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%lld", &n);
        sq = (ll) sqrt(n);
        m = n;
        res = 1;
        for(int i = 0; prime[i] <= sq ; i++)
        {
            int k = 1;
            while(m % prime[i] == 0)
            {
                k++;
                m /= prime[i];
            }
            if(k > 1)
            {
                sq = (ll) sqrt(m);
                res *= k;
            }
        }
        if(m > 1) res *= 2;
        printf("Case %d: %lld\n", te, res-1);
    }
    return 0;
}

void sieve(void)
{
    int pos = 1;
    prime[0] = 2;
    for(ll i = 3; i < MX; i+=2)
    {
        if(flag[i] == 1) continue;
        prime[pos++] = i;
        ll ad = i<<1;
        for(ll j = i * i; j < MX; j+=ad)
            flag[j] = 1;
    }

    return;
}
