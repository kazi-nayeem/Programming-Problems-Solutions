#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
#define MX 31750

char flag[MX];
int num[MX];
void sieve(void)
{
    num[0] = 2;
    int pos = 1;
    for(int i = 3; i < MX; i+=2)
    {
        if(flag[i] == 0)
        {
            num[pos++] = i;
            for(int j = i*i; j < MX; j+=i<<1)
                flag[j] = 1;
        }
    }
}
ll bigmod(ll n, ll p, ll mod)
{
    if(p == 0LL) return 1;
    if((p&1LL))
        return (n*bigmod(n,p-1,mod))%mod;
    ll res = bigmod(n,p/2,mod);
    return (res*res)%mod;
}

bool prime(ll n)
{
    int root = sqrt(n);
    for(int i = 0; num[i] <= root; i++)
        if(n%num[i] == 0) return true;
    return false;
}

int main()
{
    sieve();
    ll p, a;
    while(scanf("%lld%lld", &p, &a) == 2)
    {
        if(p == 0LL && a == 0LL) return 0;
        if(prime(p) && bigmod(a,p,p) == a)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
