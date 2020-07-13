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

typedef long long ll;

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

#define MX 300005
#define inf 100000000


typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

ll arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, k;
    scanf("%lld %lld", &n, &k);
    arr[0] = 1;
    ll fact = 1;
    for(int i = 1; i <= k; i++)
    {
        arr[i] = i-1+arr[i-1];;
        //printf("%lld\n", arr[i]);
        fact = (fact*i)%mod;
    }
    ll res = 0;
    for(int i = n; i <= n; i++)
    {
        ll tem = 1;
        for(int j = 1; j <= k; j++)
        {
            tem = (tem*(n-arr[j]+1))%mod;
            //arr[j]++;
        }
        res = (res+tem)%mod;
    }
    res *= BigMod(2,mod-2,mod);
    printf("%lld\n", res%mod);
    return 0;
}


