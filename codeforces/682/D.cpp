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
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

#define MX 1005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1000000007ll;

int dp[MX][MX][12][2], len1, len2;

char str1[MX];
char str2[MX];

int func(int i, int j, int k, int f)
{
    if(k < 0) return -10000000;
    if( i >= len1 || j >= len2) return 0;
    int & res = dp[i][j][k][f];
    if(res != -1) return res;
    res = 0;
    if(str1[i] == str2[j])
    {
        res = func(i+1,j+1,k-f,0)+1;
        res = max(res,func(i+1,j+1,k-f,1)+1);
    }
    res = max(res, func(i+1,j,k,1));
    res = max(res, func(i,j+1,k,1));
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int k;
    scanf("%d %d %d", &len1, &len2, &k);
    scanf("%s", str1);
    scanf("%s", str2);
    memset(dp,-1,sizeof dp);
    printf("%d\n", func(0,0,k,1));
    return 0;
}


