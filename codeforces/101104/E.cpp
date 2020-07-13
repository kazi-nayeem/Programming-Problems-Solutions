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

int arr[MX];
int dp[MX][MX];

int func(int x, int y)
{
    if(x>y) return 0;
    int & res = dp[x][y];
    if(res != -1) return res;
    res = 0;
    for(int i = x+1; i <= y; i+=2)
    {
        res = max(res,func(x+1,i-1)+func(i+1,y)+(arr[i] == arr[x]));
    }
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te;
    scanf("%d", &te);
    while(te--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        memset(dp,-1,sizeof dp);
        printf("%d\n", func(1,n));
    }
    return 0;
}

/**
2
6
1 2 2 1 3 3
22
1 7 1 2 4 2 4 9 1 1 9 4 5 9 4 5 6 9 2 1 2 9
*/
