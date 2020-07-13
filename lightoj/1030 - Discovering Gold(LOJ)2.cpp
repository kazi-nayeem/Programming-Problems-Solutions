#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
using namespace std;

double dp[152];
int arr[105];
int h;

int rec(int n)
{
    if(n == h)
        return arr[n];
    if(dp[n] != -1.0) return dp[n];
    dp[n] = 0;
    int k = 0;
    for(int i = 1; (i <= 6) && (i+n <= h); i++, k++)
        dp[n] += rec(n+i)+arr[n];
    dp[n] /= k;
    return dp[n];
}

int main()
{
    int te, ti, n, x;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        for(int i = 0; i < 105; i++) dp[i] = -1.0;
        scanf("%d", &n, &x);
        h = n;
        for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        double res = rec(n);
        printf("Case %d: %.8lf\n", te, res);
    }
    return 0;
}

