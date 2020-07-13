//#include <bits/stdc++.h>

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

ll bigmod(ll a, ll p, ll mod)
{
    if(p == 0) return 1;
    ll res = bigmod(a,p/2,mod);
    res = (res*res)%mod;
    if(p%2 == 1)
        res = (res*a)%mod;
    return res;
}

vector<int> divi[MX];

void sieve()
{
    for(int i = 1; i < MX; i++)
    {
        for(int j = i; j < MX; j+=i)
            divi[j].push_back(i);
    }
    /*for(int i = 1; i < 100; i++)
    {
        printf("%d ", i);
        for(int j = 0; j < divi[i].size(); j++)
            printf(" %d", divi[i][j]);
        puts("");
    }*/
}

ll last[MX];
ll prv[MX];
ll inprv[MX];
double fir[MX];
double logi[MX];

void add(int pos, ll v)
{
    int sz = divi[pos].size();
    double l = log10(v);
    for(int i = 0; i < sz; i++)
    {
        int now = divi[pos][i];
        last[now] *= (inprv[pos]*v)%mod;
        last[now] %= mod;
        fir[now] += l-logi[pos];
    }
    prv[pos] = v;
    inprv[pos] = bigmod(v,mod-2, mod);
    logi[pos] = l;
}

void alter(int n)
{
    ll arr[100];
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 1)
        {
            scanf("%lld", &arr[b]);
        }
        else
        {
            ll res = 1;
            for(int i = 1; i <= n; i+=b)
            {
                res *= arr[i];
            }
            ll tem = res;
            while(tem>=10)
            {
                tem /= 10;
            }
            printf("%lld %lld\n", tem, res%mod);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    scanf("%d", &n);
    if(n <= 10)
    {
        alter(n);
        return 0;
    }
    sieve();
    for(int i = 0; i <= n; i++)
    {
        last[i] = 1;
        prv[i] = 1;
        inprv[i] = 1;
        fir[i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        ll x;
        scanf("%lld", &x);
        add(i-1,x);
    }
    scanf("%d", &q);
    while(q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 1)
        {
            ll x;
            scanf("%lld", &x);
            add(b-1,x);
        }
        else
        {
            double tem = fir[b]+logi[0];
            tem -= floor(tem);
            printf("%d ", (int) pow(10,tem));
            printf("%lld\n", (last[b]*prv[0])%mod);
        }
        /*for(int i = 1; i <= n; i++)
            printf("%lld\n", (last[i]*prv[0])%mod);*/
    }
    return 0;
}


