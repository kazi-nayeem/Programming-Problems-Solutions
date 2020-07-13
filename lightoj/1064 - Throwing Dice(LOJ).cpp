#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
using namespace std;

int dp[26][152];

int rec(int n, int x)
{
    if(n == 0)
    {
        if(x == 0) return 1;
        return 0;
    }
    if(x < 0 || x > n*6) return 0;
    if(dp[n][x] != -1) return dp[n][x];
    dp[n][x] = 0;
    for(int i = 1; i <= 6; i++)
        dp[n][x] += rec(n-1,x-i);
    return dp[n][x];
}

int main()
{
    memset(dp,-1,sizeof dp);
    int te, ti, n, x;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &x);
        int res = 0;
        for(int i = x; i <= n*6; i++)
            res += rec(n,i);
        printf("%d %d\n", res, (int) pow(6,n));
    }
    return 0;
}
