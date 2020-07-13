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
#include<complex>
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

#define MX 100005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

ll arr[MX];
ll res[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    ll p, q, r;
    scanf("%d %lld %lld %lld", &n, &p, &q, &r);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);
    res[1] = arr[1]*p;
    for(int i = 2; i <= n; i++)
    {
        res[i] = arr[i]*p;
        res[i] = max(res[i], res[i-1]);
    }
    for(int i = 1; i <= n; i++)
    {
        ll now = arr[i]*q+res[i];
        if(i>1)
            res[i] = max(res[i-1], now);
        else
            res[i] = now;
    }
    for(int i = 1; i <= n; i++)
    {
        ll now = arr[i]*r+res[i];
        if(i>1)
            res[i] = max(res[i-1], now);
        else
            res[i] = now;
    }
    printf("%lld\n", res[n]);
    return 0;
}

