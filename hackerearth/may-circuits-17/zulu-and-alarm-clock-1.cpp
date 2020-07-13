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

#define MX 100005
#define inf 100000000

const ll mod = 1000000007ll;

struct data
{
    int h, m, s;
};

int calc(data a, data b)
{
    int h = abs(a.h-b.h);
    if(h>12) h = 24-h;
    int m = abs(a.m-b.m);
    if(m>30) m = 60-m;
    int s = abs(a.s-b.s);
    if(s>30) s = 60-s;
    return h+m+s;
}

data cloc[100], alarm[100];
int cost[100][100];
int n, k;

int dp[51][1<<17];

int func(int p, int mask)
{
    if((mask+1) == (1<<k)) return 0;
    if(p>=n) return mod;
    int & res = dp[p][mask];
    if(res != -1) return res;
    res = func(p+1,mask);
    for(int i = 0; i < k; i++)
    {
        if((mask>>i)&1) continue;
        res = min(res,func(p+1,mask|(1<<i))+cost[p][i]);
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, te;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
            scanf("%d:%d:%d", &cloc[i].h, &cloc[i].m, &cloc[i].s);
        for(int i = 0; i < k; i++)
            scanf("%d:%d:%d", &alarm[i].h, &alarm[i].m, &alarm[i].s);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < k; j++)
            {
                cost[i][j] = calc(cloc[i],alarm[j]);
            }
        memset(dp,-1,sizeof dp);
        printf("%d\n", func(0,0));
    }
    return 0;
}

