#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
using namespace std;

#define ll long long

const ll mod = 1000000007;

ll bigmod(ll a, ll p, ll m)
{
    if(p == 0) return 1;
    ll res = bigmod(a,p/2,m);
    res = (res*res)%m;
    if((p%2ll) == 1ll)
        res = (res*a)%m;
    return res;
}

char str[100050];

int main()
{
    ll k;
    scanf("%s %I64d", str, &k);
    int len = strlen(str);
    ll res = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] != '0' && str[i] != '5') continue;
        ll tem = (bigmod(2,len*k, mod)-1+mod)%mod;
        tem *= bigmod((bigmod(2,len,mod)-1+mod)%mod,mod-2,mod);
        tem %= mod;
        tem *= bigmod(2,i,mod);
        tem %= mod;
        res += tem;
        res %= mod;
    }
    printf("%I64d\n", res);
    return 0;
}
