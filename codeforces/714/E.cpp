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

#define MX 3005
#define inf 100000000

const ll mod = 1000000007ll;

ll dp[MX][MX];
ll arr[MX];
int n;

ll func(int i, int j)
{
    if(i == n)
    {
        if(arr[j]+i-j <= arr[i]) return 0;
        return (arr[j]+i-j)-arr[i];
    }
    ll & res = dp[i][j];
    if(res != -1) return res;
    res = mod*mod;
    ll mk = arr[j]+i-j;
    if(mk<=arr[i])
        res = min(res, func(i+1,i));
    res = min(res,func(i+1,j)+abs(mk-arr[i]));
    if(i+1<n && mk+1<=arr[i+1])
    {
        res = min(res,func(i+1,i+1)+abs(arr[i+1]-1-arr[i]));
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    memset(dp,-1,sizeof dp);
    printf("%lld\n", func(0,0));
    return 0;
}

