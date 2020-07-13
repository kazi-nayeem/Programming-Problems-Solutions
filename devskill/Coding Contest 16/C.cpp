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

#define MX 1000005
#define inf 100000000

const ll mod = 1000000007ll;

int dp[MX];
int arr[10];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ti, x, y, z, t;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d %d %d %d", &x, &y, &z, &t);
        t -= 3*z+2*y+x;
        if(t<0)
        {
            puts("-1");
            continue;
        }
        memset(dp,0,sizeof dp);
        arr[0] = x+y+z;
        arr[1] = y+z;
        arr[2] = z;
        dp[0] = 1;
        for(int i = 0; i < 3; i++)
        {
            for(int j = arr[i]; j <= t; j++)
            {
                dp[j] |= dp[j-arr[i]];
            }
        }
        for(int i = t; i >= 0; i--)
        {
            if(dp[i])
            {
                printf("%d\n", t-i);
                break;
            }
        }
    }
    return 0;
}

