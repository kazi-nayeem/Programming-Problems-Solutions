#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;

#define ll long long
#define MX 100005
#define inf 100000000

const ll mod = 100000007ll;
ll dp[2][15002];
int te, ti, n, k, s;
ll sum, total;

ll func()
{
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        total = sum = 0;
        int pre = (i+1)&1;
        int now = i&1;
        for(int j = 0; j <= s; j++)
        {
            total = (total+sum)%mod;
            dp[now][j] = total;
            sum = (sum+dp[pre][j])%mod;
            if(k<=j)
            {
                sum = (sum-dp[pre][j-k])%mod;
                sum = (sum+mod)%mod;
                total -= (k*dp[pre][j-k])%mod;
                total = ((total%mod)+mod)%mod;
            }
        }
    }
    return dp[1&n][s];
}

int main()
{
    scanf("%d", &ti);
    for(te = 1; te <= ti; te++)
    {
        scanf("%d%d%d", &n, &k, &s);
        printf("Case %d: %lld\n", te, func());
    }
    return 0;
}

