#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define lli long long int

lli dp[31][31];

lli func(int n, int k);

int main()
{
    memset(dp,-1,sizeof dp);
    int n, k , te, ti;
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d %d", &n, &k);
        printf("Case %d: %lld\n", te, func(n,k));
    }
    return 0;
}

lli func(int n, int k)
{
    if(k > n) return 0;
    if(n == 0)
    {
        if(k == 0) return 1;
        return 0;
    }
    if(k < 0) return 0;
    lli &res = dp[n][k];
    if(res != -1) return res;
    lli ret = func(n-1,k-1)*(n+n-k);
    ret+= func(n-1,k);
    return res = ret;
}
