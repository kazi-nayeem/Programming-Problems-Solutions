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
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 300005
#define inf 100000000

const ll mod = 1000000007ll;

ll p[MX];
ll arr[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    p[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        p[i] = (p[i-1]*2)%mod;
    }
    sort(arr+1,arr+n+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ll tem = (arr[i]*p[i-1])%mod;
        ans = (ans+tem)%mod;
        tem = (arr[i]*p[n-i])%mod;
        ans -= tem;
        ans %= mod;
        ans = (ans+mod)%mod;
    }
    printf("%lld\n", ans);
    return 0;
}

