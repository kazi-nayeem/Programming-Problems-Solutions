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

#define MX 300005
#define inf 100000000

const double pi = acos(-1.0);
const ll mod = 1000000007ll;

ll diff[MX];
ll diffsort[MX];
ll sum[MX];
ll value[MX];
vector<int> adj[MX];
ll res[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    ll asum = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        asum += a;
        value[i] = a;
        diffsort[i] = diff[i] = b-a;
    }
    sort(diffsort+1,diffsort+n+1);
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1]+diffsort[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll total = 0;
    for(int i = 1; i <= n; i++)
    {
        int pos = lower_bound(diffsort+1,diffsort+n+1,diff[i])-diffsort;
        int baki = n-pos;
        //printf("->>%lld %d %lld\n", sum[pos-1], baki, diff[i]);
        res[i] = sum[pos-1]+asum-value[i]+baki*diff[i]+value[i]*(n-1);
        for(int j = 0; j < adj[i].size(); j++)
        {
            int v = adj[i][j];
            res[i] -= value[i]+value[v]+min(diff[i],diff[v]);
        }
        printf("%lld ", res[i]);
    }

    return 0;
}

