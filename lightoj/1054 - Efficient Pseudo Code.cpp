#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstring>
using namespace std;

#define MX 46345
#define MXP 4792
typedef long long int ll;

int prime[MXP];
int flag[MX];
ll mod = 1000000007LL;

void sieve()
{
    prime[0] = 2;
    int pos = 1;
    for(int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 0)
        {
            prime[pos++] = i;
            int aa = i<<1;
            for(int j = i*i; j < MX; j+=aa)
                flag[j] = 1;
        }
    }
    /*printf("%d\n", pos);
    for(int i =0; i < 100; i++)
    printf("%d\n", prime[i]);*/
}

ll bigmod(int n, int p)
{
    ll res = 1;
    for(int te = 31; te >= 0; te--)
    {
        res = (res*res)%mod;
        if((p>>te)&1)
            res = (res*n)%mod;
    }
    return res;
}

int main()
{
    sieve();
    int te, ti, n, m;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &m);
        int sq = sqrt(n);
        ll ans = 1;
        for(int i = 0; i < MXP && sq >= prime[i]; i++)
        {
            int rs = 1;
            while(n%prime[i] == 0)
            {
                rs*=prime[i];
                n/=prime[i];
            }
            if(rs == 1) continue;
            ans *= (((bigmod(rs%mod,m)*prime[i])%mod)+mod-1)%mod;
            ans %= mod;
            ans *= bigmod(prime[i]-1,mod-2);
            ans  %= mod;
            sq = sqrt(n);
        }
        if(n > 1)
        {
            ans *= (bigmod(n,m+1)+mod-1)%mod;
            ans  %= mod;
            ans *= bigmod(n-1,mod-2);
            ans  %= mod;
        }
        printf("Case %d: %lld\n", te, ans);
    }
    return 0;
}
