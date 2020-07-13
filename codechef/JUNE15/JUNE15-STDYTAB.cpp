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

#define MX 2005
#define inf 100000000

typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1000000000ll;


ll ncr[2*MX][2*MX];
ll dp[MX][MX];

int main()
{
    for(int i = 0; i < 2*MX; i++)
    {
        ncr[i][i] = ncr[i][0] = 1;
    }
    for(int i = 1; i < 2*MX; i++)
    {
        for(int j = 1; j < i; j++)
            ncr[i][j] = (ncr[i-1][j-1]+ncr[i-1][j])%mod;
    }
    /*for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
            printf("%lld ", ncr[i][j]);
        puts("");

    }*/
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        memset(dp,0,sizeof dp);
        for(int i = 0; i <= m; i++) dp[0][i] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                dp[i][j] = dp[i-1][j]*ncr[j+m-1][m-1]+dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
        printf("%lld\n", dp[n][m]);
    }
    return 0;
}


