#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define ll long long

int mod;
int arr[205];
ll int dp[201][20][11];

ll int func(int n, int s, int k)
{
    if(n == 0)
    {
        if(s == 0 && k == 0) return 1;
        return 0;
    }
    if(k < 0) return 0;
    ll int & res = dp[n][s][k];
    if(res != -1LL) return res;
    res = func(n-1,s,k);
    res += func(n-1,((s+(arr[n]%mod))+mod)%mod,k-1);
    return res;
}

int main()
{
    int te = 1, ti, n, q, k;
    scanf("%d", &ti);
    while(ti--)
    {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Case %d:\n", te++);
        for(int i = 0; i < q; i++)
        {
            memset(dp,-1,sizeof dp);
            scanf("%d%d", &mod, &k);
            printf("%lld\n", func(n,0,k));
        }
    }
    return 0;
}
