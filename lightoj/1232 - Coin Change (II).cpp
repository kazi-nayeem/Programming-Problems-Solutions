#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX 10002
#define MX 102
#define lli long long int

lli dp[MAX];
int coin[MX];

lli coinchang(int c,int n);

int main()
{
    int co, n, te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        memset(dp, 0, sizeof(dp));
        scanf(" %d %d", &co, &n);
        for(int i = 0; i < co; i++)
            scanf("%d", &coin[i]);
        printf("Case %d: %lld\n", te, coinchang(co,n));
    }
    return 0;
}

lli coinchang(int c,int n)
{
    dp[0] = 1;
    for(int i = 0; i < c; i++)
    {
        for(int j = coin[i]; j <= n; j++)
            dp[j] = (dp[j] + dp[j-coin[i]]) % 100000007;
    }
    return dp[n];
}

