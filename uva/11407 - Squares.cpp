#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>

#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

#define MX 1000005
#define MXP 4794
#define ll long long

int dp[10005];

int main()
{
    memset(dp,30,sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= 100; i++)
        for(int j = i*i, ad = j; j <= 10000; j++)
            dp[j] = min(dp[j],dp[j-ad]+1);
    int ti, n;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}

