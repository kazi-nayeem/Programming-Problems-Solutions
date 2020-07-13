#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX 7500

int dp[MAX][5];

int coinchang(int i,int n);
const int coin[5] = {1, 5, 10, 25, 50};

int main()
{
    int n;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &n) == 1)
        printf("%d\n", coinchang(0,n));
    return 0;
}

int coinchang(int i,int n)
{
    if(i >= 5)
    {
        if(n == 0) return 1;
        return 0;
    }
    if(dp[n][i] != -1) return dp[n][i];
    int ret1 = 0, ret2;
    if(n-coin[i] >= 0) ret1 = coinchang(i,n-coin[i]);
    ret2 = coinchang(i+1,n);
    return dp[n][i] = ret1 + ret2;
}
