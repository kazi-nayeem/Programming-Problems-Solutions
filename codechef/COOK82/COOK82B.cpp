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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


//4-side
//int xx[] = {0,0,-1,1};
//int yy[] = {-1,1,0,0};
//6-side hexagonal
//int xx[] = {2,-2,1,1,-1,-1};
//int yy[] = {0,0,1,-1,1,-1};

#define popc(a) (__builtin_popcount(a))
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
ll BigMod(ll B,ll P,ll M)
{
    ll R=1%M;    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

ll prime[MX];

int pos;

void sieve()
{
    prime[0] = 2;
    pos = 1;
    for(ll  i = 3; i < MX; i+=2)
    {
        if(prime[i]) continue;
        prime[pos++] = i;
        for(ll j = i*i; j < MX; j+=i*2)
            prime[j] = 1;
    }
//    for(int i = 0; i < 100; i++)
//        printf("%d %lld\n", i, prime[i]);
}

map<ll,int> mp;

void add(ll n)
{
    for(int i = 0; prime[i]*prime[i] <= n; i++)
    {
        while(n%prime[i] == 0)
        {
            n /= prime[i];
            mp[prime[i]]++;
        }
    }
    if(n>1) mp[n]++;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    int n;
    ll x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        add(x);
    }
    bool flag = false;
    ll ans = 1ll;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        ll p = it->first;
        int c = it->second;
        if(c%n == 0) continue;
        flag = true;
    }
    if(flag)
    {
        n++;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            ll p = it->first;
            int c = it->second;
            if(c%n == 0) continue;
            flag = true;
            ans *= BigMod(p,n-c%n,mod);
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
    else
        printf("justdoit\n");
    return 0;
}


