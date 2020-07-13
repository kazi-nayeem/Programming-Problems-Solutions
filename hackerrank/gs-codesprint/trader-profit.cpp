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

#define MX 50
#define inf 100000000

const ll mod = 1000000007ll;

int arr[MX];
int n;

int dp[MX][20];

int func(int pos, int k)
{
    if(k == 0) return 0;
    if(pos>=n) return 0;
    int & res = dp[pos][k];
    if(res != -1) return res;
    res = func(pos+1,k);
    for(int i = pos+1; i < n; i++)
    {
        res = max(res, func(i+1,k-1)+arr[i]-arr[pos]);
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q, k;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d", &k, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        memset(dp,-1,sizeof dp);
        printf("%d\n", func(0,k));
    }
    return 0;
}


