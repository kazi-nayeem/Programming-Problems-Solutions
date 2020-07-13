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

#define MX 205
#define MX2 12800
#define inf 100000000

const ll mod = 1000000007ll;

int two[MX];
int five[MX];
map<pii,int> dp[205][205];


int func(int n, int k, int t, int f)
{
    if(k == 0) return 0;
    if(n == 0) return -10000000;
    if(k>n) return -10000000;
    pii now = make_pair(t,f);
    if(dp[n][k].find(now) != dp[n][k].end()) return dp[n][k][now];
    int res = func(n-1,k,t,f);
    int tt = t+two[n];
    int ff = f+five[n];
    int tem = func(n-1,k-1,tt-min(tt,ff),ff-min(tt,ff))+min(tt,ff);
    res = max(tem,res);
    return dp[n][k][now] = res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    ll x;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%I64d", &x);
        while(x%2 == 0)
        {
            two[i]++;
            x /= 2;
        }
        while(x%5 == 0)
        {
            five[i]++;
            x /= 5;
        }
    }
    printf("%d\n", func(n,k,0,0));
    return 0;
}
