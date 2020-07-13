#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
using namespace std;

double dp[101];
int arr[101];

double rec(int n)
{
    if(n == 1)
        return (double) arr[1];
    if(dp[n] != -1.0) return dp[n];
    dp[n] = 0;
    int k;
    if(n > 6) k = 6;
    else k = (n-1);
    for(int i = 1; i <= k; i++)
        dp[n] += rec(n-i);
    dp[n] = dp[n]/(k*1.0);
    return dp[n]+=arr[n];
}

int main()
{
    int te, ti, n, x;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) dp[i] = -1.0;
        for(int i = n; i > 0; i--) scanf("%d", &arr[i]);
        double res = rec(n);
        printf("Case %d: %lf\n", te, res);
    }
    return 0;
}

