#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long int
#define MX 3582
#define mod 1000000007ll
ll dp[502][502], multi[502];
int prime[502], flag[MX];

ll func(int k, int p);
void sieve(void);

int main()
{
    sieve();
    int te, ti, n, m;
    scanf("%d\n", &ti);
    memset(dp,-1,sizeof dp);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d", &n, &m);
        //printf("ok");
        printf("Case %d: %lld\n", te, (func(n-m,m)*multi[m])%mod);
    }
    return 0;
}

ll func(int k, int p)
{
    //printf("%d %d\n", k, p);
    if(k == 0 && p == 0) return 1;
    if(k < 0 || p <= 0) return 0;
    ll & res = dp[k][p];
    if(res != -1) return res;
    ll ret = func(k-1,p)*prime[p]+func(k,p-1);
    return res = ret%mod;

}
void sieve(void)
{
    prime[1] = 2;
    multi[1] = 1, multi[0] = 1;
    int pos = 2;
    for(int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 1) continue;
        multi[pos] = (ll)(multi[pos-1]*(i-1))%mod;
        prime[pos++] = i;
        int add = i << 1;
        for(int j = i * i; j < MX; j+= add)
            flag[j] = 1;
    }
    //for(int i = 1; i < 100; i++)
        //printf("%lld\n", multi[i]);
}
