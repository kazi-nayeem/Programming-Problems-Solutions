#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long int
#define MX 3582
#define mod 1000000007ll
ll dp[502][502];
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
        printf("Case %d: %lld\n", te, func(n,m));
    }
    return 0;
}

ll func(int k, int p)
{
    //printf("%d %d\n", k, p);
    if(k == 0)
    {
        if(p == 0) return 1;
        return 0;
    }
    if(k<p || p <= 0) return 0;
    ll & res = dp[k][p];
    if(res != -1) return res;
    int mx = k-p+1;
    ll ret = 0, tem1 = prime[p], tem2 = 1;
    for(int i = 1; i <= mx; i++)
    {
        ret += (func(k-i,p-1)*(((tem1-tem2)+mod)))%mod;
        tem2 = tem1;
        tem1=(tem1*prime[p])%mod;
    }
    return res = ret%mod;

}
void sieve(void)
{
    prime[1] = 2;
    int pos = 2;
    for(int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 1) continue;
        prime[pos++] = i;
        int add = i << 1;
        for(int j = i * i; j < MX; j+= add)
            flag[j] = 1;
    }
    //for(int i = 1; i < 502; i++)
        //printf("%d\n", prime[i]);
}
