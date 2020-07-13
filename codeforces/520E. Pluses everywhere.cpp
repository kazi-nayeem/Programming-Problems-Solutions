#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
using namespace std;

#define MX 100005

typedef long long ll;

const ll mod = 1000000007;

ll bigmod(ll a, ll p, ll m)
{
    if(p == 0) return 1;
    ll res = bigmod(a,p/2,m);
    res *= res;
    res %= m;
    if(p%2)
        res = (res*a)%m;
    return res;
}

ll fact[MX];
ll ifact[MX];

ll ncr(int n, int r)
{
    if(n < r) return 0;
    ll res = fact[n]*ifact[r];
    res %= mod;
    res *= ifact[n-r];
    res %= mod;
    return res;
}

char str[MX];

int main()
{
    ifact[0] = fact[0] = 1;
    for(int i = 1; i < MX; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        ifact[i] = bigmod(fact[i],mod-2,mod);
        //if(i < 10)
        // printf("%lld %lld\n", fact[i], ifact[i]);
    }

    int n, r;
    scanf("%d%d %s", &n, &r, str);

    ll mul = 0;
    ll res = ncr(n-1,r);
    res *= str[n-1]-'0';
    res %= mod;

    for(int i = n-2; i >= r-1; i--)
    {
        //cout<<"res = " <<res<<endl;

        ll tem = bigmod(10ll,n-2ll-i,mod);
        tem *= ncr(i,r-1);
        tem %= mod;
        //cout<<"tem = "<<tem<<endl;

        mul = (mul+tem)%mod;
       // cout<<"mul = "<<mul<<endl;

        res += (mul *(str[i]-'0'))%mod;
        res %= mod;

        tem = bigmod(10ll,n-1ll-i,mod);
        tem *= ncr(i,r);
        tem %= mod;

        res += (tem *(str[i]-'0'))%mod;
        res %= mod;

        //puts("");
    }
    for(int i = 0; i < r-1; i++)
    {
        res += (mul *(str[i]-'0'))%mod;
        res %= mod;
    }
    cout<<res<<endl;
}
