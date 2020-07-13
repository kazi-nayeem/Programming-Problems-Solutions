#include<cstdio>
#include<cstring>
using namespace std;

int dp[1005];
int com[1005][505];

int func(int n);
int ncr(int n, int r);

int main()
{
    memset(dp,-1,sizeof dp);
    memset(com,-1,sizeof com);

    int te, ti, n;
    scanf("%d", &ti);

    for(te = 1; te <= ti; te++)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", te, func(n));
    }
    return 0;
}

int func(int n)
{
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int ret = 0;
    for(int i = 1; i <= n; i++)
        ret = (ret+(ncr(n,i)*func(n-i))) % 10056;
    return dp[n] = ret;
}

int ncr(int n, int r)
{
    if(n == r) return 1;
    if(r == 0) return 1;
    if(n <(r<<1)) r = n - r;
    if(com[n][r] != -1) return com[n][r];

    int ret = ncr(n-1,r-1)+ncr(n-1,r);
    return com[n][r] = ret % 10056;
}
