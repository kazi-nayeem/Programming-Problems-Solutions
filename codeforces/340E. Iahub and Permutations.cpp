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
using namespace std;

#define MX 100005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

ll dp[2050];
ll fact[2050];
int flag[2050];
int arr[2050];
ll mod =1000000007ll;

ll func(int m, int n)
{
    dp[0] = 1;
    dp[1] = n;
    for(int i = 2; i <= m; i++)
    {
        ll &res = dp[i];
        res = dp[i-1];
        res += dp[i-2];
        res *= (i-1);
        res %= mod;
        res += (dp[i-1]*n)%mod;
        res %= mod;
    }
    return dp[m];
}

int main()
{
    int n, a = 0,x;
    scanf("%d", &n);
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;

        scanf("%d", &x);
        arr[i] = x;
        if(x != -1)
            flag[x]++;
        if(x == i)
        {
            puts("0");
            return 0;
        }
    }
    int both = 0;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] == -1)
        {
            a++;
            if(flag[i] == 0) both++;
        }
    }
    memset(dp,-1,sizeof dp);
    //printf("%d %d\n", both, a);
    printf("%I64d\n", (func(both,a-both)*fact[a-both])%mod);
    return 0;
}


