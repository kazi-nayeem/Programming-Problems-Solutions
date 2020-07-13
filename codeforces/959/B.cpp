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

#define MX 1000005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

int par[MX];
ll micost[MX];
map<string, int> mp;
char str[MX];
ll cost[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        scanf("%s", str);
        mp[(string) str] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &cost[i]);
    }
    for(int i = 1; i <= k; i++)
    {
        micost[i] = mod*mod;
        int x, p;
        scanf("%d", &p);
        while(p--)
        {
            scanf("%d", &x);
            par[x] = i;
            micost[i] = min(micost[i], cost[x]);
        }
    }
    ll total = 0;
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", str);
        total += micost[par[mp[(string) str]]];
    }
    printf("%lld\n", total);
    return 0;
}
