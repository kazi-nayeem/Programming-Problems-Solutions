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

#define MX 5005
#define inf 100000000

const ll mod = 1000000007ll;

int cnt[MX];
int take[MX];
int arr[MX];
int dp[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        int tk = 0, full = 0, tem = 0;
        dp[i] = max(dp[i],dp[i-1]);
        memset(take,0,sizeof take);
        for(int j = i; j <= n; j++)
        {
            if(take[arr[j]] == 0)
            {
                tk++;
            }
            take[arr[j]]++;
            if(take[arr[j]] == cnt[arr[j]])
            {
                full++;
                tem ^= arr[j];
            }
            if(tk == full)
            {
                dp[j] = max(dp[j],dp[i-1]+tem);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}

