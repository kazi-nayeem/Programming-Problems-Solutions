#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MX 100005
#define ll long long

ll int dp[MX];
ll int mod = 1000000007;

int main()
{
    int t, k;
    scanf("%d%d", &t, &k);
    dp[0] = 1;
    for(int i = 1; i < MX; i++)
    {
        dp[i] += dp[i-1];
        if(i>=k)
            dp[i] += dp[i-k];
        dp[i] %= mod;
    }
    for(int i = 1; i < MX; i++)
    {
        dp[i] += dp[i-1];
        dp[i] %= mod;
    }
    while(t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        ll int total = dp[b]-dp[a-1];
        printf("%I64d\n", ((total+mod)%mod));
    }
    return 0;
}
